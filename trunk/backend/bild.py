import md5
import pbackend

class Bild(object):
  def __init__(self,
               Path="",
               URI="",
               Name="",
               Date="",
               Description="",
               Exif={},
               Category="",
               Tags=[],
               Persons=[],
               Objects=[],
               Places=[],
               Positions=[],
               SupplementalAttributes={},
               BildID = None
               ):
    self.Path=Path
    self.URI=URI
    self.Attributes=pbackend.attrDict

    self.Attributes["name"]=Name
    self.Attributes["date"]=Date
    self.Attributes["description"]=Description
    self.Attributes["exif"]=Exif
    self.Attributes["persons"]=Category
    self.Attributes["tags"]=Tags
    self.Attributes["objects"]=Objects
    self.Attributes["places"]=Places
    self.Attributes["positions"]=Positions
    for k,v in SupplementalAttributes:
      self.Attributes[k]=v
    
    if BildID == None:
      self.__genBildID__()

  def __genBildID__(self):
    self.File = open(self.Path)
    self.BildID = md5.new( self.File.read() ).hexdigest()
    self.File.close()
    del self.File
    self.File=""

  def getBildBin(self):
    try:
      self.File = open(self.Path)
      tmp=self.File.read()
      self.File.close()
      del self.File
      self.File=""
      return tmp
    except IOError, (errno, strerror):
    	print "I/O error(%s): %s: %s" % (errno, self.Path, strerror)
	return None
    except:
    	print "Unexpected error:", sys.exc_info()[0]
	raise
  
