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



class singleInputDialog:
    def __init__(self):
        self.wTree = gtk.glade.XML(gladefile, "singleInputDialog")
        self.dlg = self.wTree.get_widget("singleInputDialog")
	self.getWidgets()
        self.wTree.signal_autoconnect({
		"onInputNextButton":self.onInputNextButton,
		"onInputPrevButton":self.onInputPrevButton
		})
        self.Bild=None
	self.createGUI()

    def createGUI(self):
	self.entryUI.set_current_page(0)
	self.stepsTreeColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.stepsTree.append_column(self.stepsTreeColumn)
	self.stepsTreeModel = gtk.ListStore(str)
	self.stepsTree.set_model(self.stepsTreeModel)
	self.stepsTreeModel.append(["General Information"])
	self.stepsTreeModel.append(["Name"])
	self.stepsTreeModel.append(["Date"])
	self.stepsTreeModel.append(["Category"])
	self.stepsTreeModel.append(["Exif"])
	self.stepsTreeModel.append(["Tags"])
	self.stepsTreeModel.append(["Persons"])
	self.stepsTreeModel.append(["Objects"])
	self.stepsTreeModel.append(["Places"])
	self.stepsTreeModel.append(["Positions"])
    
	
	

    def onInputNextButton(self, widget):
	    self.entryUI.next_page()

    def onInputPrevButton(self, widget):
	    self.entryUI.prev_page()
        
    def run(self):
        result = self.dlg.run()
        self.dlg.destroy()
        return result, self.Bild

    def getWidgets(self):
	self.stepsTree = self.wTree.get_widget("stepsTree")
        self.availTree = self.wTree.get_widget("availTree")
        self.entryUI = self.wTree.get_widget("entryUI")
        self.nameEntry = self.wTree.get_widget("nameEntry")
        self.nameLabel = self.wTree.get_widget("nameLabel")
        self.dateCalendar = self.wTree.get_widget("dateCalendar")
        self.dateLabel = self.wTree.get_widget("dateLabel")
        self.categoryInput = self.wTree.get_widget("categoryInput")
        self.categoryLabel = self.wTree.get_widget("categoryLabel")
        self.tagsEntry = self.wTree.get_widget("tagsEntry")
        self.tagsSelected = self.wTree.get_widget("tagsSelected")
        self.personsEntry = self.wTree.get_widget("personsEntry")
        self.personsSelected = self.wTree.get_widget("personsSelected")
        self.objectsEntry = self.wTree.get_widget("objectsEntry")
        self.objectsSelected = self.wTree.get_widget("objectsSelected")
        self.positionsEntry = self.wTree.get_widget("positionsEntry")
        self.positionsSelected = self.wTree.get_widget("positionsSelected")
        self.placesEntry = self.wTree.get_widget("placesEntry")
        self.placesSelected = self.wTree.get_widget("placesSelected")
        
            
if __name__ == "__main__":
	bijutsukan = Bijutsukan()
	gtk.main()
