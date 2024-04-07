#include "MenuBarView.h"

MenuBarView::MenuBarView(QMainWindow* parent, ActionLogModel* actionLog) : QMenuBar(parent)
{
	menuBar = new QMenuBar(this);

	// Apply stylesheet to customize appearance
	setStyleSheet("QMenuBar { background-color: #333333; color: white; }"
		"QMenuBar::item:selected { background-color: #444444; }");

	toggleActionLog = new QAction("Toggle Action Log", this);
	toggleActionLog->setCheckable(true);
	// connect checkable action to enable action log
	connect(toggleActionLog, &QAction::triggered, this, &MenuBarView::toggleLogVisibility);

	log = actionLog;

	fileMenu = new FileMenuModel(this, log);
	helpMenu = new HelpMenuModel(this);	

	addMenu(fileMenu);
	addMenu(helpMenu);
	addAction(toggleActionLog);

}

MenuBarView::~MenuBarView()
{

}

void MenuBarView::toggleLogVisibility()
{
	bool visible = toggleActionLog->isChecked();
	emit actionLogVisibilityChanged(visible);
}