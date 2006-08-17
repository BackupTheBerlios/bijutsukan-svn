import sys
import pygtk
import gtk
import gtk.glade
import os.path
import backend
import frontend

gladefile = "glade/bijutsukan.glade"
                
class Bijutsukan:
	def __init__(self):
		self.wTree = gtk.glade.XML(gladefile, "mainWindow") 
		self.wTree.signal_autoconnect({
                    "on_mainWindow_destroy" : gtk.main_quit,
		    "onAddImage" : self.onAddImage
                    })
		
        def onAddImage(self, widget):
            dlg = frontend.singleInputDialog("/home/daddel9/foo.jpg")
            bild, result = dlg.run()
	    print bild
	    print bild.Attributes

        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
