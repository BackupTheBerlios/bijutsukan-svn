import pygtk
import gtk
import gtk.glade

gladefile = "glade/bijutsukan.glade"


class showFileDialog:
  def __init__(self, bild):
    self.Bild = bild
    self.wTree = gtk.glade.XML(gladefile, "showFileDialog")
    self.dlg = self.wTree.get_widget("showFileDialog")
    self.getWidgets()
    self.createGUI()
    self.dlg.reshow_with_initial_size()

  def createGUI(self):
    tmp = gtk.gdk.PixbufLoader()
    tmp.write(self.Bild.getBildBin())
    pbuf = tmp.get_pixbuf().scale_simple(250, 250,gtk.gdk.INTERP_NEAREST)
    self.image.set_from_pixbuf(pbuf)

    self.name.set_text("Name: %s"%self.Bild.Attributes["name"])
    #self.filename.set_text("Filename: %s"%self.Bild.Path)
    self.category.set_text("Category: %s"%self.Bild.Attributes["category"])

    self.tagsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.tags.append_column(self.tagsColumn)
    self.tagsModel = gtk.ListStore(str)
    self.tags.set_model(self.tagsModel)
    for item in self.Bild.Attributes["tags"]:
      self.tagsModel.append(item)

    self.personsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.persons.append_column(self.personsColumn)
    self.personsModel = gtk.ListStore(str)
    self.persons.set_model(self.personsModel)
    for item in self.Bild.Attributes["persons"]:
      self.personsModel.append(item)
    

    self.objectsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.objects.append_column(self.objectsColumn)
    self.objectsModel = gtk.ListStore(str)
    self.objects.set_model(self.objectsModel)
    for item in self.Bild.Attributes["objects"]:
      self.objectsModel.append(item)

    self.placesColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.places.append_column(self.placesColumn)
    self.placesModel = gtk.ListStore(str)
    self.places.set_model(self.placesModel)
    for item in self.Bild.Attributes["places"]:
      self.placesModel.append(item)

    self.positionsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.positions.append_column(self.positionsColumn)
    self.positionsModel = gtk.ListStore(str)
    self.positions.set_model(self.positionsModel)
    for item in self.Bild.Attributes["positions"]:
      self.positionsModel.append(item)

    self.exifColumns = [
      gtk.TreeViewColumn("Exif Name", gtk.CellRendererText(), text=0),
      gtk.TreeViewColumn("Exif Value", gtk.CellRendererText(), text=1)
      ]
    self.exif.append_column(self.exifColumns[0])
    self.exif.append_column(self.exifColumns[1])
    self.exifModel = gtk.ListStore(str,str)
    self.exif.set_model(self.exifModel)
    for k,v in self.Bild.Attributes["exif"].iteritems():
      self.exifModel.append([k,v])


    self.descriptionBuffer = gtk.TextBuffer()
    self.descriptionBuffer.set_text(self.Bild.Attributes["description"])
    self.description.set_buffer(self.descriptionBuffer)

    


  def getWidgets(self):
    self.image = self.wTree.get_widget("image")
    #self.filename = self.wTree.get_widget("filename")
    self.name = self.wTree.get_widget("name")
    self.category = self.wTree.get_widget("category")
    self.tags = self.wTree.get_widget("tags")
    self.persons = self.wTree.get_widget("persons")
    self.objects = self.wTree.get_widget("objects")
    self.places = self.wTree.get_widget("places")
    self.positions = self.wTree.get_widget("positions")
    self.description = self.wTree.get_widget("description")
    self.exif = self.wTree.get_widget("exif")
    


