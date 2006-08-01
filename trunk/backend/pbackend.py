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

  def delBild(self,BildID):
    self.Data["Items"].__delitem__(BildID)

  # Match like {Attr : [(Val, matchType),...], ...}
  def listBilder(self,Match):
    pass # TODO: implement
      
