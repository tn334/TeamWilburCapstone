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

    //print existing file
    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the log"));
    connect(printAct, &QAction::triggered, this, &FileMenuModel::print);

    fileMenu = parent->addMenu(tr("&File"));
    //fileMenu->addAction(newAct);
    fileMenu->addAction(exportAct);
    //fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
}

FileMenuModel::~FileMenuModel()
{
    delete exportAct;
    delete printAct;
}

void FileMenuModel::exportLog()
{
	logPtr->exportLog();
}

// Created with AI
void FileMenuModel::print()
{
    // Create a QPrinter object
    QPrinter printer;

    // Create a QPrintDialog to allow the user to select print options
    QPrintDialog dialog(&printer, this);

    // If the user accepts the print dialog
    //if (dialog.exec() == QDialog::Accepted) {
    //     Create a QPainter object to draw on the printer
    //    QPainter painter(&printer);

    //     Start printing
    //    QTextDocument doc;

    //     Retrieve content from the action log and set it to the QTextDocument
    //    QString actionLogContent = logPtr->exportLog(); // Assuming there's a method to retrieve log content
    //    doc.setPlainText(actionLogContent);

    //     Print the QTextDocument
    //    doc.print(&printer);

         //End printing
}
