#pragma once
#ifndef WILBUR_H
#define WILBUR_H

//Header files
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMainWindow>
#include "ui_Wilbur.h"
#include <QGridLayout>

// for menu
QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //initialize visocity slider
    //SlidersGroup *horizontalSliders;
    //void createMenus();

protected:
    // Context Menu
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

    //menuBar slots
private slots:
    void newFile();
    void open();
    void save();
    void print();
    void copy();
    void about();
    void aboutQt();

private:
    // MenuBar
    void createActions();
    void createMenus();
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;
    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* copyAct;
    QAction* exitAct;
    QLabel* infoLabel;
    QAction* aboutAct;
    QAction* aboutQtAct;
    Ui::WilburClass ui;
    // controller
    QLabel* controlLabel;
};

class ParamGrid : public QGridLayout, MainWindow
{
    //What is this
    Q_OBJECT

public:
    //Constructor
    ParamGrid(QWidget *parent = nullptr);
    //Deconstructor
    ~ParamGrid();

private:
    
};

#endif // WILBUR_H