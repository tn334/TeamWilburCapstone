#pragma once
#ifndef FILEMENUMODEL_H
#define FILEMENUMODEL_H

// Local Header File
#include "ActionLogModel.h"
//Qt Header Files
#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QTextDocument>  

class FileMenuModel : public QMenu
{
	Q_OBJECT

public:
	FileMenuModel(QMenuBar* parent = nullptr, ActionLogModel* actionLog = nullptr);
	~FileMenuModel();

private slots:
	void exportLog();
	void print();

private:
	QAction* exportAct;
	QAction* printAct;

	QMenu* fileMenu;

	ActionLogModel* logPtr;
};

#endif // !FILEMENUMODEL_H
