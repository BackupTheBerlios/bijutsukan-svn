import sys
import pygtk
import gtk
import gtk.glade

gladefile = "glade/bijutsukan.glade"
                
class Bijutsukan:
	def __init__(self):
		self.wTree = gtk.glade.XML(gladefile, "mainWindow") 
		self.wTree.signal_autoconnect({
                    "on_mainWindow_destroy" : gtk.main_quit,
		    "onAddImage" : self.onAddImage
                    })
		
        def onAddImage(self, widget):
            dlg = singleInputDialog()
            result, foo = dlg.run()
            print result
            print foo



class singleInputDialog:
    def __init__(self):
        self.wTree = gtk.glade.XML(gladefile, "singleInputDialog")
        self.dlg = self.wTree.get_widget("singleInputDialog")
        self.wTree.signal_autoconnect({})
        self.Bild=None
        
    def run(self):
        result = self.dlg.run()
        self.mapResults()
        self.dlg.destroy()
        return result, self.Bild

    def mapResults(self):
        stepsTree = self.wTree.get_widget("stepsTree")
        availTree = self.wTree.get_widget("availTree")
        entryUI = self.wTree.get_widget("entryUI")
        nameEntry = self.wTree.get_widget("nameEntry")
        nameLabel = self.wTree.get_widget("nameLabel")
        dateCalendar = self.wTree.get_widget("dateCalendar")
        dateLabel = self.wTree.get_widget("dateLabel")
        categoryInput = self.wTree.get_widget("categoryInput")
        categoryLabel = self.wTree.get_widget("categoryLabel")
        tagsEntry = self.wTree.get_widget("tagsEntry")
        tagsSelected = self.wTree.get_widget("tagsSelected")
        personsEntry = self.wTree.get_widget("personsEntry")
        personsSelected = self.wTree.get_widget("personsSelected")
        objectsEntry = self.wTree.get_widget("objectsEntry")
        objectsSelected = self.wTree.get_widget("objectsSelected")
        positionsEntry = self.wTree.get_widget("positionsEntry")
        positionsSelected = self.wTree.get_widget("positionsSelected")
        placesEntry = self.wTree.get_widget("placesEntry")
        placesSelected = self.wTree.get_widget("placesSelected")
        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
