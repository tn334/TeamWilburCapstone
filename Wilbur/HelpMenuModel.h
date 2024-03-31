#pragma once
#ifndef HELPMENUMODEL_H
#define HELPMENUMODEL_H

// Qt Headers
#include <QAction>
#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QMessageBox>

class HelpMenuModel : public QMenu
{
	Q_OBJECT
public:
	HelpMenuModel(QMenuBar* parent = nullptr);
	~HelpMenuModel();

private slots:
	void about();
	void aboutQt();

private:
	QAction* aboutAct;
	QAction* aboutQtAct;

	QMenu* helpMenu;
};

#endif // !HELPMENUMODEL_H



