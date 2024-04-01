#include "MenuBarView.h"

MenuBarView::MenuBarView(QMainWindow* parent, ActionLogModel* actionLog) : QMenuBar(parent)
{
	//menuBar = new QMenuBar(parent);
		// Apply stylesheet to customize appearance
	setStyleSheet("QMenuBar { background-color: #333333; color: white; }"
		"QMenuBar::item:selected { background-color: #444444; }");
	log = actionLog;

	fileMenu = new FileMenuModel(this, log);
	helpMenu = new HelpMenuModel(this);	

	addMenu(fileMenu);
	addMenu(helpMenu);

	//parent->setMenuBar(menuBar);

	//// Create label and set its style and alignment
	//infoLabel = new QLabel(tr("<i>Choose a menu option."));
	//infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
	//infoLabel->setAlignment(Qt::AlignCenter);
}

MenuBarView::~MenuBarView()
{

}