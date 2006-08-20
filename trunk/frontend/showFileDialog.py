import pygtk
import gtk
import gtk.glade

gladefile = "glade/bijutsukan.glade"


class showFileDialog:
  def __init__(self, bild):
    self.Bild = bild
    self.wTree = gtk.glade.XML(gladefile, "showFileDialog")
    self.dlg = self.wTree.get_widget("ShowFileDialog")
    self.createGUI()

  def createGUI(self):
    tmp = gtk.gdk.PixbufLoader()
    tmp.write(self.Bild.getBildBin())
    pbuf = tmp.get_pixbuf().scale_simple(600, 600,gtk.gdk.INTERP_NEAREST)
    self.image.set_from_pixbuf(pbuf)

    


  def getWidgets(self):
    self.image = self.wTree.get_widget("image")
    self.filename = self.wTree.get_widget("filname")
    self.name = self.wTree.get_widget("name")
    self.category = self.wTree.get_widget("category")
    self.tags = self.wTree.get_widget("tags")
    self.persons = self.wTree.get_widget("persons")
    self.objects = self.wTree.get_widget("objects")
    self.places = self.wTree.get_widget("places")
    self.positions = self.wTree.get_widget("positions")
    self.description = self.wTree.get_widget("description")
    


