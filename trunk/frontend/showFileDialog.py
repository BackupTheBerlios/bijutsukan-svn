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
    pbuf = tmp.get_pixbuf().scale_simple(400, 400,gtk.gdk.INTERP_NEAREST)
    self.image.set_from_pixbuf(pbuf)

    self.name.set_text("Name: %s"%self.Bild.Attributes["name"])
    self.filename.set_text("Filename: %s"%self.Bild.Path)
    self.category.set_text("Category: %s"%self.Bild.Attributes["category"])

    self.tagsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.tags.append_column(self.tagsColumn)
    self.tagsModel = gtk.ListStore(str)
    self.tags.set_model(self.tagsModel)

    self.personsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.persons.append_column(self.personsColumn)
    self.personsModel = gtk.ListStore(str)
    self.persons.set_model(self.personsModel)

    self.objectsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.objects.append_column(self.personsColumn)
    self.objectsModel = gtk.ListStore(str)
    self.objects.set_model(self.personsModel)

    self.placesColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.places.append_column(self.placesColumn)
    self.placesModel = gtk.ListStore(str)
    self.places.set_model(self.placesModel)

    self.positionsColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
    self.positions.append_column(self.placesColumn)
    self.positionsModel = gtk.ListStore(str)
    self.positions.set_model(self.placesModel)

    self.descriptionBuffer = gtk.TextBuffer()
    self.descriptionBuffer.set_text(self.Bild.Attributes["description"])
    self.description.set_buffer(self.descriptionBuffer)

    


  def getWidgets(self):
    self.image = self.wTree.get_widget("image")
    self.filename = self.wTree.get_widget("filename")
    self.name = self.wTree.get_widget("name")
    self.category = self.wTree.get_widget("category")
    self.tags = self.wTree.get_widget("tags")
    self.persons = self.wTree.get_widget("persons")
    self.objects = self.wTree.get_widget("objects")
    self.places = self.wTree.get_widget("places")
    self.positions = self.wTree.get_widget("positions")
    self.description = self.wTree.get_widget("description")    


