// Include header files
#include "Wilbur.h"
#include <QWidget>
#include <QContextMenuEvent>
#include <QLabel>
#include <QMessageBox>
#include <QSlider>
#include <QStackedWidget>

// setting up Qt version through Qt Visual Studio Tools
// https://doc.qt.io/qtvstools/qtvstools-how-to-add-qt-versions.html
// setting Qt version for project 
// https://doc.qt.io/qtvstools/qtvstools-how-to-select-qt-versions-for-project.html

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Create a wrapper a holder for the menubar
    //cite: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/mainwindows/menus?h=6.6
    QWidget* menuBar = new QWidget;
    setCentralWidget(menuBar);
    QWidget* topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option."));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget* bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout* menuLayout = new QVBoxLayout;
    menuLayout->setContentsMargins(5, 5, 5, 5);
    menuLayout->addWidget(topFiller);
    menuLayout->addWidget(infoLabel);
    menuLayout->addWidget(bottomFiller);
    menuBar->setLayout(menuLayout);

    createActions();
    createMenus();

    // Create a wrapper for controls
     QWidget* controller = new QWidget;
     setCentralWidget(controller);
     QWidget* controllerTop = new QWidget;
     controllerTop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

     controlLabel = new QLabel(tr("<i>Choose prototype settings."));
     controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
     controlLabel->setAlignment(Qt::AlignTop);

     QWidget* controllerBottom = new QWidget;
     controllerBottom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     // create a child widget inside box for sittfness slider
     QWidget* stiffnessSlider = new QWidget;
     //stiffnessSlider->
     QVBoxLayout* controlLayout = new QVBoxLayout;
     controlLayout->setContentsMargins(5, 5, 5, 5);
     controlLayout->addWidget(controllerTop);
     controlLayout->addWidget(controlLabel);
     controlLayout->addWidget(controllerBottom);
     //controlLayout->chi
     controller->setLayout(controlLayout);


    showMaximized();
    setWindowTitle(tr("WilburMain", "Wilbur"));
    /*setMinimumSize(160, 160);
    resize(480, 320);*/
    //ui.setupUi(this);

    //horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Viscocity"));
}

//Destructor Wilbur - Main Windor
MainWindow::~MainWindow()
{
    
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent* event)
{
    //implementation of context menu
    QMenu menu(this);
    //menu.addAction(cutAct);
    menu.addAction(copyAct);
    //menu.addAction(pasteAct);
    menu.exec(event->globalPos());


}
#endif // QT_NO_CONTEXTMENU
void MainWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::print()
{
    infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
        tr("The <b>Menu</b> example shows how to create "
            "menu-bar menus and context menus."));
}

void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void MainWindow::createActions()
{
    //create new file
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    //open existing file
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
        "clipboard"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    //editMenu->addAction(undoAct);
    //editMenu->addAction(redoAct);
    //editMenu->addSeparator();
    //editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    //editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);


}

// Constructor ParamGrid
ParamGrid::ParamGrid(QWidget *parent) : QGridLayout(parent)
{

}

//Deconstructor ParamGrid
ParamGrid::~ParamGrid()
{

}


