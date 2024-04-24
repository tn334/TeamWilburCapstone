#include "HelpMenuModel.h"

HelpMenuModel::HelpMenuModel(QMenuBar* parent) : QMenu(parent)
{
    //about application guide
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &HelpMenuModel::about);

    //about Qt guide
    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, this, &HelpMenuModel::aboutQt);

    helpMenu = parent->addMenu(tr("&Help"));
	helpMenu->setStyleSheet("QMenu::item:selected {background-color: #444444;}"
					"QMenu {background-color: #333333;}");
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

HelpMenuModel::~HelpMenuModel()
{
    delete aboutAct;
    delete aboutQtAct;
}

void HelpMenuModel::about()
{
	QMessageBox aboutMsgBox;

	aboutMsgBox.setWindowTitle("About Menu");
	aboutMsgBox.setText("TAdaaa");
	aboutMsgBox.setStyleSheet("background-color: #333333; ");

	aboutMsgBox.exec();
}

void HelpMenuModel::aboutQt()
{
	QMessageBox aboutQtMsgBox;
	
	// Set message box details such as title, colors
	aboutQtMsgBox.setWindowTitle("About Qt");
	aboutQtMsgBox.setStyleSheet("background-color: #333333;");

	// Allow message box to include clickable links
	aboutQtMsgBox.setTextFormat(Qt::RichText);

	// Set the text for the message box
	aboutQtMsgBox.setText(
			 QString("This program uses Qt version: %1.<br><br>"
	  "Qt is a C++ toolkit for cross-platform application development.<br><br>"
	  "Qt is available under multiple licensing options designed to "
		         "accomodate the needs of our various users.<br><br>"
	  "Please see <a href='https://www.qt.io/licensing'>qt.io/licensing</a> "
								   "for an overview of Qt licensing.<br><br>"
	  "Copyright (C) 2023 The Qt Company Ltd and other contributors.<br><br>"
	  "Qt and the Qt logo are trademarks of The Qt Company Ltd.<br><br>"
	  "Qt is The Qt Company Ltd product developed as an open source project. "
	  "See <a href='https://www.qt.io'>qt.io</a> for more information.").arg(
															  QT_VERSION_STR));

	// Open the message box in a separate window
	aboutQtMsgBox.exec();
}