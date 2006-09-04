import pickle
import bild
from types import *
import re

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
    self.__save__()

  # Match like {Attr : [(Val, matchType),...], ...}
  def listBilder(self,match):
    bilds = self.Data["Items"]
    results = []
    if match == {}:
      return bilds
    # match like {a(ttr): m(atch)}
    for a, m in match.iteritems():
      print m
      # bilds like {(bild)id: b(ild)}
      for id, b in bilds:
        # b.Attributes like {ba(bild.attribute): bav(bild attribute value)}
        for ba, bav in b.Attributes.iteritems():
          if ba == a:
            # m like [v(alue), t(ype)
            for v, t in m.iteritems():
              # exact matching - type of value doesnt matter. == does it all
              if t=="exact":
                if v==bav:
                  results.append(b)
              elif t=="contains":
                if type(bav) is StringType or type(bav) is ListType:
                  if v in bav: # TODO: what happens if v is a list?
                    results.append(b)
                elif type(bav) is DictType:
                  if v in bav.keys() or v in bav.values(): # TODO: what happens if v is a dict?
                    results.append(b)
              elif t=="regex":
                if type(bav) is StringType:
                  res=re.compile(v).search(bav)
                  if res!=None:
                    results.append(b)
                elif type(bav) is ListType:
                  reg=re.compile(v)
                  for item in bav:
                    res=reg.search(item)
                    if res != None:
                      results.append(b) # TODO: 2 times ... ?
                elif type(bav) is DictType:
                  reg=re.compile(v)
                  for x,z in bav.iteritems():
                    res1=reg.search(x)
                    res2=reg.search(y)
                    if res1 != None:
                      results.append(b) # TODO: 2 times ... ?
                    if res2 != None:
                      results.append(b)
                else:
                  pass # cant match ...
              else:
                pass # wrong match type
    #TODO remove dups!      
    return results  
