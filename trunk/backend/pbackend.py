import pickle
import bild

class pBackend(object):
  def __init__(self, pPath):
    self.pPath = pPath
    self.Data = pickle.load(self.pPath)

  def listAttributes(self):
    return self.Data["Attributes"]

  def listAttributeValues(self,Attr):
    attrList = []
    for bild in self.Data["Items"]:
      try:
        attrList.append( bild.Attributes[Attr] )
      except:
        pass # TODO: add some errorhandling
    return attrList

  def getBild(self,BildID):
    return self.Data["Items"][BildID]
    
  def getBildBin(self,BildID):
    myBild = self.getBild(BildID)
    return open( myBild.Path ).read()

  def storeBild(self,Bild):
    try:
      myBild = self.Data["Items"][BildID]
      myBild.Path = Bild.Path
      myBild.URI = Bild.URI
      myBild.Name = Bild.Name
      myBild.Description = Bild.Description
      myBild.Exif = Bild.Exif
      myBild.Attributes = Bild.Attributes      
    except:
      self.Data["Items"][Bild.BildID] = Bild
      self.__save__()

  def __save__(self):
    pickle.dump(self.Data,self.pPath)

  def delBild(self,BildID):
    self.Data["Items"].__delitem__(BildID)
    self.__safe__()

  # Match like {Attr : [(Val, matchType),...], ...}
  def listBilder(self,Match):
    Bilds = self.Data["Items"]
    results = []
    for item in Bilds:
      # all match requests against all attributes
      for attr, val in Match.iteritems():
        for a, v in item.Attributes.iteritems():
          # if the current bild attribute is the attribute the match wants
          if a==attr:

            # if its a list loop it
            if type(v)==type([]):
              for item in v:
                # looping all results for this match
                for item in val:
                  res, typ = item
                  # all match types
                  if typ == "exact":
                    if res == v:
                      results.append(item)
                  if typ == "contains":
                    if v in res:
                      results.append(item)
                  #TODO: implement match types

            # if its a dict
            if type(v) == type({}):
              pass #TODO: are there dicts in Bild.Attributes? if so implement listBilder matching for it
            # if its a string
            if type(v) == type(""):
              # all match types
              if typ == "exact":
                if res == v:
                  results.append(item)
              if typ == "contains":
                if v in res:
                  results.append(item)
            #TODO: implement match types
                      
          else:
            pass #next item
      
    return results  
