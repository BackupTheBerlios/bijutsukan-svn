import md5

class Bild(object):
  def __init__(self,
               Path="",
               URI="",
               Name="",
               Description="",
               Exif={},
               Attributes={},
               BildID = None
               ):
    self.Path=Path
    self.URI=URI
    self.Name=Name
    self.Description=Description
    self.Exif=Exif
    self.Attributes=Attributes
    if BildID == None:
      self.genBildID()
    

    def genBildID():
      self.File = open(self.Path).read()
      self.BildID = md5.new( self.File ).hexdigest()
