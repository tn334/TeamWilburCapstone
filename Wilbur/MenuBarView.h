#pragma once
#ifndef MENUBARVIEW_H
#define MENUBARVIEW_H

// Local Header Files
#include "FileMenuModel.h"
#include "HelpMenuModel.h"

// Qt Headers
#include <QAction>
#include <QGridLayout>
#include <QMenuBar>
#include <QMainWindow>
#include <QPalette>

class MenuBarView : public QMenuBar
{
	Q_OBJECT

public:
	MenuBarView(QMainWindow* parent = nullptr, ActionLogModel* actionLog = nullptr);
	~MenuBarView();

private:
	FileMenuModel* fileMenu;
	HelpMenuModel* helpMenu;
	//QGridLayout* menuLayout;

	QMenuBar* menuBar;
	ActionLogModel* log;
};

#endif // !MENUBARVIEW_H



