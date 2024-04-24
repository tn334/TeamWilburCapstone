#include "FileMenuModel.h"

FileMenuModel::FileMenuModel(QMenuBar* parent, ActionLogModel* actionLog) : QMenu(parent)
{
    //instantiate logPtr
    logPtr = actionLog;

    //export existing file
    exportAct = new QAction(tr("&Export Log..."), this);
    exportAct->setShortcuts(QKeySequence::SaveAs);
    exportAct->setStatusTip(tr("Export control log"));
    connect(exportAct, &QAction::triggered, this, &FileMenuModel::exportLog);

    fileMenu = parent->addMenu(tr("&File"));
	fileMenu->setStyleSheet("QMenu::item:selected {background-color: #444444;}"
		"QMenu {background-color: #333333;}");

    fileMenu->addAction(exportAct);
    fileMenu->addSeparator();
}

FileMenuModel::~FileMenuModel()
{
    delete exportAct;
}

void FileMenuModel::exportLog()
{
	logPtr->exportLog();
}