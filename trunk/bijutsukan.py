import sys
import pygtk
pygtk.require("2.0")
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
			"onMainQuit":gtk.main_quit,
			"on_mainWindow_destroy" : gtk.main_quit,
			"onAddImage" : self.onAddImage,
			"onMainRowClick":self.onMainRowClick,
			"onMainDelete":self.onMainDelete
			})
		self.Backend = backend.pBackend(os.path.abspath(os.path.expanduser("~/.bijutsuStorage")))
		self.getWidgets()
		self.createGUI()
		self.getBilds()

	def onMainRowClick(self, widget, column, view):
		self.showFileDialog = frontend.showFileDialog(self.bilds[column[0]])
	
	def onMainDelete(self, widget):
		selection = self.mainView.get_selection()
		selected = selection.get_selected_rows()[1][0][0]
		self.Backend.delBild(self.bilds[selected].BildID)
		self.getBilds()
		
		
        def onAddImage(self, widget):
		fdlg = frontend.singleFileChooser()
		fname, fresult = fdlg.run()
		if fresult == -5:
			cdlg = frontend.singleInputDialog(fname)
			bild, cresult = cdlg.run()
			if cresult == -5:
				self.Backend.storeBild(bild)
		self.getBilds()

	def createGUI(self):
		self.mainViewColumns = [
			gtk.TreeViewColumn("Thumbnail", gtk.CellRendererPixbuf(), pixbuf=0),
			gtk.TreeViewColumn("Name", gtk.CellRendererText(), text=1),
			gtk.TreeViewColumn("Category", gtk.CellRendererText(), text=2)
			]
		for column in self.mainViewColumns:
			self.mainView.append_column(column)
		self.mainViewModel = gtk.ListStore(gtk.gdk.Pixbuf, str, str)
		self.mainView.set_model(self.mainViewModel)
		self.getBilds()

	def getWidgets(self):
		self.mainView = self.wTree.get_widget("mainView")

	def getBilds(self):
		self.mainViewModel.clear()
		self.bilds=[]
		for k, item in self.Backend.listBilder({}).iteritems():
			self.bilds.append(item)
			tmp = gtk.gdk.PixbufLoader()
			tmp.write(item.getBildBin())
			pbuf = tmp.get_pixbuf().scale_simple(100, 100 ,gtk.gdk.INTERP_NEAREST)
			self.mainViewModel.append([
				pbuf,
				item.Attributes["name"],
				item.Attributes["category"]
				])	

        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
