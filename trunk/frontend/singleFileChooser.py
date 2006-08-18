import sys
import pygtk
import gtk
import gtk.glade
import os.path
import frontend
import backend

gladefile = "glade/bijutsukan.glade"

class singleFileChooser:
    def __init__(self):
	self.wTree = gtk.glade.XML(gladefile, "singleFileChooser")
        self.dlg = self.wTree.get_widget("singleFileChooser")
        
    def run(self):
      result = self.dlg.run()
      fname = self.dlg.get_filename()
      self.dlg.destroy()
      
      return fname, result

