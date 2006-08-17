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
		"onInputPrevButton":self.onInputPrevButton,
		"onInputSelectPosition":self.onInputSelectPosition
		})
        self.Bild=None
	self.createGUI()

    def createGUI(self):
	self.entryUI.set_current_page(0)

	self.stepsTreeColumn = gtk.TreeViewColumn("Steps", gtk.CellRendererText(), text=0)
	self.stepsTree.append_column(self.stepsTreeColumn)
	self.stepsTreeModel = gtk.ListStore(str)
	self.stepsTree.set_model(self.stepsTreeModel)
	for item in ["General Information","Name","Date","Category","Exif","Tags","Persons","Objects","Places","Positions"]:
		self.stepsTreeModel.append([item])

	self.availTreeColumn = gtk.TreeViewColumn("Available", gtk.CellRendererText(), text=0)
	self.availTree.append_column(self.availTreeColumn)
	self.availTreeModel = gtk.ListStore(str)
	self.availTree.set_model(self.availTreeModel)


    def onInputSelectPosition(self, widget, column, view):
	    self.entryUI.set_current_page(column[0])
	    
    def onInputNextButton(self, widget):
	    self.entryUI.next_page()
	    cpage = self.entryUI.get_current_page()
	    self.stepsTree.get_selection().select_path((cpage))
	    
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
