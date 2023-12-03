// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

//Local Header files
#include "controlBox.h"

// Qt header files
#include <QBoxLayout>
#include <QSlider>
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>

// cite https://doc.qt.io/qt-6/qtwidgets-widgets-sliders-example.html
ControlBox::ControlBox(QWidget* parent)
{
    // Create a wrapper for controls
    QWidget* controller = new QWidget;
    setCentralWidget(controller);

    // creating child widgets
    QWidget* controllerTop = new QWidget;
    controllerTop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    controlLabel = new QLabel(tr("<i>Choose prototype settings."));
    controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    controlLabel->setAlignment(Qt::AlignCenter);

    QWidget* controllerBottom = new QWidget(controller);
    controllerBottom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    customDialog = new CustomDialog;

    // setting up duct buttons
    //trying to tie to dialog
    Button* buttonOne = createButton("Duct One", &ControlBox::buttonClicked);
    QLabel* buttonOneTitle = new QLabel("Duct One:", controller);
    buttonOneTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    // TODO Manipulate with backend code
    connect(buttonOne, &Button::clicked, customDialog, &CustomDialog::controlManipulated);

    Button* buttonTwo = createButton("Duct Two", &ControlBox::buttonClicked);
    QLabel* buttonTwoTitle = new QLabel("Duct Two:", controller);
    buttonTwoTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    // TODO Manipulate with backend code
    connect(buttonTwo, &Button::clicked, customDialog, &CustomDialog::controlManipulated);

    Button* buttonThree = createButton("Duct Three", &ControlBox::buttonClicked);
    QLabel* buttonThreeTitle = new QLabel("Duct Three:", controller);
    buttonThreeTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    //TODO Manipulate with backend code
    connect(buttonThree, &Button::clicked, customDialog, &CustomDialog::controlManipulated);

    // Set fixed size for the buttons
    buttonOne->setFixedSize(80, 30);  // Adjust the size as needed
    buttonTwo->setFixedSize(80, 30);  // Adjust the size as needed
    buttonThree->setFixedSize(80, 30);  // Adjust the size as needed

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->setContentsMargins(5, 5, 450, 5);
    buttonLayout->addWidget(buttonOneTitle);
    buttonLayout->addWidget(buttonOne);
    buttonLayout->addWidget(buttonTwoTitle);
    buttonLayout->addWidget(buttonTwo);
    buttonLayout->addWidget(buttonThreeTitle);
    buttonLayout->addWidget(buttonThree);
    
    // create a child widget inside box for sittfness slider
    HorizontalSlider* stiffness = new HorizontalSlider(controller);

    QLabel* sliderTitle = new QLabel("Stiffness:", controller);
    sliderTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    connect(stiffness, &QSlider::sliderReleased, customDialog, &CustomDialog::controlManipulated);
    //TODO Connect to backend code and add update

    // Create a layout for the stiffness slider and its title
    QVBoxLayout* stiffnessLayout = new QVBoxLayout;
    stiffnessLayout->addWidget(sliderTitle);
    stiffnessLayout->addWidget(stiffness);

    QVBoxLayout* controlLayout = new QVBoxLayout;
    controlLayout->setContentsMargins(5, 20, 500, 500);
    controlLayout->addWidget(controllerTop);
    controlLayout->addWidget(controlLabel);
    controlLayout->addLayout(buttonLayout);
    controlLayout->addLayout(stiffnessLayout);
    controlLayout->addWidget(controllerBottom);

    controller->setLayout(controlLayout);

    // Set a border to each child widget
    controllerTop->setStyleSheet("QWidget { border: 1px solid black; }");
    controlLabel->setStyleSheet("QWidget { border: 1px solid black; }");
    controllerBottom->setStyleSheet("QWidget { border: 1px solid black; }");
    stiffness->setStyleSheet("QWidget { border: 1px solid black; }");

};

template<typename PointerToMemberFunction>
Button* ControlBox::createButton(const QString& text, const PointerToMemberFunction& member)
{
    Button* button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}

//TODO Check this is being used or not
void ControlBox::buttonClicked()
{
    // Provide the implementation for the buttonClicked function
    // For example, you can add the following line to print a message
    qDebug() << "Button Clicked";
}


ControlBox::~ControlBox()
{
    delete customDialog;
}


