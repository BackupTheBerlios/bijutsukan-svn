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
        prevButton = self.wTree.get_widget("prevButton")
        nextButton = self.wTree.get_widget("nextButton")
        entryUI = self.wTree.get_widget("entryUI")
        nameEntry = self.wTree.get_widget("nameEntry")
        nameButton = self.wTree.get_widget("nameButton")
        nameLabel = self.wTree.get_widget("nameLabel")
        dateCalendar = self.wTree.get_widget("dateCalendar")
        dateButton = self.wTree.get_widget("dateButton")
        dateLabel = self.wTree.get_widget("dateLabel")
        categoryInput = self.wTree.get_widget("categoryInput")
        categoryButton = self.wTree.get_widget("categoryButton")
        categoryLabel = self.wTree.get_widget("categoryLabel")
        categoryEdit = self.wTree.get_widget("categoryEdit")
        tagsEntry = self.wTree.get_widget("tagsEntry")
        tagsAddButton = self.wTree.get_widget("tagsAddButton")
        tagsDelButton = self.wTree.get_widget("tagsDelButton")
        tagsSelected = self.wTree.get_widget("tagsSelected")
        personsEntry = self.wTree.get_widget("personsEntry")
        personsAddButton = self.wTree.get_widget("personsAddButton")
        personsDelButton = self.wTree.get_widget("personsDelButton")
        personsSelected = self.wTree.get_widget("personsSelected")
        objectsEntry = self.wTree.get_widget("objectsEntry")
        objectsAddButton = self.wTree.get_widget("objectsAddButton")
        objectsDelButton = self.wTree.get_widget("")
        objectsSelected = self.wTree.get_widget("")
        positionsEntry = self.wTree.get_widget("")
        positionsAddButton = self.wTree.get_widget("")
        positionsDelButton = self.wTree.get_widget("")
        positionsSelected = self.wTree.get_widget("")
        placesEntry = self.wTree.get_widget("")
        placesAddButton = self.wTree.get_widget("")
        placesDelButton = self.wTree.get_widget("")
        placesSelected = self.wTree.get_widget("")
        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
