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
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &HelpMenuModel::aboutQt);

    helpMenu = parent->addMenu(tr("&Help"));
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
    QMessageBox::about(this, tr("About Menu"),
        tr("The <b>Menu</b> example shows how to create "
            "menu-bar menus and context menus."));
}

void HelpMenuModel::aboutQt()
{
    
}