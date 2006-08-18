import pickle
import bild

attrList = [
  "name",
  "description",
  "exif",
  "tags",
  "persons",
  "objects",
  "places",
  "positions"
  ]
attrDict = {
  "name":"",
  "description":"",
  "exif":{},
  "tags":[],
  "persons":[],
  "objects":[],
  "places":[],
  "positions":[]
  }



class pBackend(object):
  def __init__(self, pPath):
    self.pPath = pPath
    try:
      self.Data = pickle.load(open(self.pPath))
    except:
      self.Data={
        "Attributes":attrList,
        "Items":{},
        }
      self.__save__()

  def listAttributes(self):
    return self.Data["Attributes"]

  def listAttributeValues(self,Attr):
    attrList = []
    for id, bild in self.Data["Items"].iteritems():
      try:
        attrList.append( bild.Attributes[Attr] )
      except:
        pass
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
      print myBild
    except:
      self.Data["Items"][Bild.BildID] = Bild
      self.__save__()

  def __save__(self):
    pickle.dump(self.Data,open(self.pPath,"w"))

  def delBild(self,BildID):
    self.Data["Items"].__delitem__(BildID)
    self.__safe__()

  # Match like {Attr : [(Val, matchType),...], ...}
  def listBilder(self,Match):
    Bilds = self.Data["Items"]
    results = []
    if Match == {}:
      return Bilds
    for k, item in Bilds.iteritems():
      # all match requests against all attributes
      for attr, val in Match.iteritems():
        for a, v in item.Attributes.iteritems():
          # if the current bild attribute is the attribute the match wants
          if a==attr:
            
            typ = val[1] #match type
            res = val[0] #match 
            
            if type(v)==type(""):
              if typ=="exact":
                if v == val:
                  results.append(item)
              if typ=="contains":
                if val in v:
                  results.append(item)

            # if its a list loop it
            if type(v)==type([]):
              for item in v:
                # looping all results for this match
                for item in val:
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
              pass #TODO: implement dicts
            
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
