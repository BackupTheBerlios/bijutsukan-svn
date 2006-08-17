import sys
import pygtk
import gtk
import gtk.glade
import os.path
import backend

gladefile = "glade/bijutsukan.glade"
                
class Bijutsukan:
	def __init__(self):
		self.wTree = gtk.glade.XML(gladefile, "mainWindow") 
		self.wTree.signal_autoconnect({
                    "on_mainWindow_destroy" : gtk.main_quit,
		    "onAddImage" : self.onAddImage
                    })
		
        def onAddImage(self, widget):
            dlg = singleInputDialog("/home/daddel9/foo.jpg")
            result = dlg.run()



class singleInputDialog:
    def __init__(self, bildPath):
	self.wTree = gtk.glade.XML(gladefile, "singleInputDialog")
        self.dlg = self.wTree.get_widget("singleInputDialog")
	self.getWidgets()

	self.path = bildPath
	self.creatBild()
	self.createGUI()
	self.initVars()
    
        self.wTree.signal_autoconnect({
		"onInputNextButton":self.onInputNextButton,
		"onInputPrevButton":self.onInputPrevButton,
		"onInputSelectPosition":self.onInputSelectPosition,
		"onTagsButton":self.onTagsButton,
		"onPersonsButton":self.onPersonsButton,
		"onObjectsButton":self.onObjectsButton,
		"onPlacesButton":self.onPlacesButton,
		"onPositionsButton":self.onPositionsButton,
		"onTagsDel":self.onTagsDelete,
		"onPersonsDel":self.onPersonsDelete,
		"onObjectsDel":self.onObjectsDelete,
		"onPositionsDel":self.onPositionsDelete,
		"onPlacesDel":self.onPlacesDelete
		})


    def onTagsDelete(self, widget):
	    selection = self.tagsSelected.get_selection()
	    selected = selection.get_selected()
	    self.tagsSelectedModel.remove(selected[1])

    def onPersonsDelete(self, widget):
	    selection = self.personsSelected.get_selection()
	    selected = selection.get_selected()
	    self.personsSelectedModel.remove(selected[1])

    def onObjectsDelete(self, widget):
	    selection = self.objectsSelected.get_selection()
	    selected = selection.get_selected()
	    self.objectsSelectedModel.remove(selected[1])

    def onPlacesDelete(self, widget):
	    selection = self.placesSelected.get_selection()
	    selected = selection.get_selected()
	    self.placesSelectedModel.remove(selected[1])

    def onPositionsDelete(self, widget):
	    selection = self.positionsSelected.get_selection()
	    selected = selection.get_selected()
	    self.positionsSelectedModel.remove(selected[1])



    def onPositionsButton(self, widget):
	    self.positionsSelectedModel.append([self.positionsEntry.get_text()])
	    self.positionsList.append(self.positionsEntry.get_text())


    def onPlacesButton(self, widget):
	    self.placesSelectedModel.append([self.placesEntry.get_text()])
	    self.placesList.append(self.placesEntry.get_text())

    def onObjectsButton(self, widget):
	    self.objectsSelectedModel.append([self.objectsEntry.get_text()])
	    self.objectsList.append(self.objectsEntry.get_text())

    def onPersonsButton(self, widget):
	    self.personsSelectedModel.append([self.personsEntry.get_text()])
	    self.personsList.append(self.personsEntry.get_text())

    def onTagsButton(self, widget):
	    self.tagsSelectedModel.append([self.tagsEntry.get_text()])
	    self.tagsList.append(self.tagsEntry.get_text())

    def onInputSelectPosition(self, widget, column, view):
	    self.entryUI.set_current_page(column[0])
	    
    def onInputNextButton(self, widget):
	    self.entryUI.next_page()
	    cpage = self.entryUI.get_current_page()
	    self.stepsTree.get_selection().select_path((cpage))
	    
    def onInputPrevButton(self, widget):
	    self.entryUI.prev_page()
	    cpage = self.entryUI.get_current_page()
	    self.stepsTree.get_selection().select_path((cpage))

    def initVars(self):
	    self.tagsList=[]
	    self.personsList=[]
	    self.objectsList=[]
	    self.placesList=[]
	    self.positionsList=[]

    def creatBild(self):
	if os.path.exists(self.path):
		self.bild = backend.Bild(Path=self.path)
		# TODO: do something with exifs
	else:
		print "BIIG ERROR!"

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

	self.tagsSelectedColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.tagsSelected.append_column(self.tagsSelectedColumn)
	self.tagsSelectedModel = gtk.ListStore(str)
	self.tagsSelected.set_model(self.tagsSelectedModel)
	
	self.personsSelectedColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.personsSelected.append_column(self.personsSelectedColumn)
	self.personsSelectedModel = gtk.ListStore(str)
	self.personsSelected.set_model(self.personsSelectedModel)

	self.objectsSelectedColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.objectsSelected.append_column(self.objectsSelectedColumn)
	self.objectsSelectedModel = gtk.ListStore(str)
	self.objectsSelected.set_model(self.objectsSelectedModel)

	self.placesSelectedColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.placesSelected.append_column(self.placesSelectedColumn)
	self.placesSelectedModel = gtk.ListStore(str)
	self.placesSelected.set_model(self.placesSelectedModel)

	self.positionsSelectedColumn = gtk.TreeViewColumn("", gtk.CellRendererText(), text=0)
	self.positionsSelected.append_column(self.positionsSelectedColumn)
	self.positionsSelectedModel = gtk.ListStore(str)
	self.positionsSelected.set_model(self.positionsSelectedModel)

    
        
    def run(self):
	result = self.dlg.run()
	self.bild.Attributes["name"] = self.nameEntry.get_text()
	self.bild.Attributes["date"] = str(self.dateCalendar.get_date())
	self.bild.Attributes["category"] = self.categoryInput.get_active_text()
	self.bild.Attributes["tags"] = self.tagsList
	self.bild.Attributes["persons"] = self.personsList
	self.bild.Attributes["objects"] = self.objectsList
	self.bild.Attributes["positions"] = self.positionsList
	self.bild.Attributes["places"] = self.placesList
	
        self.dlg.destroy()

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
