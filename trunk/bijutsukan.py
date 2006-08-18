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
		self.pBackend = backend.pBackend(os.path.abspath(os.path.expanduser("~/.bijutsuStorage")))
		
        def onAddImage(self, widget):
		fdlg = frontend.singleFileChooser()
		fname, fresult = fdlg.run()
		if fresult == -5:
			cdlg = frontend.singleInputDialog(fname)
			bild, cresult = cdlg.run()
			if cresult == -5:
				self.pBackend.storeBild(bild)
				
	

        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
