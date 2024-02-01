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
    //QWidget* controllerTop = new QWidget;
    //controllerTop->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    controlLabel = new QLabel(tr("<i>Choose prototype settings."));
    controlLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    controlLabel->setAlignment(Qt::AlignCenter);

    QWidget* controllerBottom = new QWidget(controller);
    controllerBottom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    //add instance of customDialog
    customDialog = new CustomDialog(this);

    // setting up duct buttons
    // TODO integrate backend code
    //&ControlBox::handleButtonClicked replaced by [this](){handleButtonClicked
    buttonOne = createButton("Duct One", [this]() {handleButtonPressed(0);  });
    QLabel* buttonOneTitle = new QLabel("Duct One:", controller);
    buttonOneTitle->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    // TODO Manipulate with backend code
    connect(buttonOne, &Button::clicked, customDialog, [this]() {controlManipulated("buttonOne", 0);  });

    buttonTwo = createButton("Duct Two", [this]() {handleButtonPressed(1);  });
    QLabel* buttonTwoTitle = new QLabel("Duct Two:", controller);
    buttonTwoTitle->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    // TODO Manipulate with backend code
    connect(buttonTwo, &Button::clicked, customDialog, [this]() {controlManipulated("buttonTwo", 0);  });

    buttonThree = createButton("Duct Three", [this]() {handleButtonPressed(2);  });
    QLabel* buttonThreeTitle = new QLabel("Duct Three:", controller);
    buttonThreeTitle->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    //TODO Manipulate with backend code
    connect(buttonThree, &Button::clicked, customDialog, [this]() {controlManipulated("buttonThree", 0);  });

    // Set fixed size for the buttons
    buttonOne->setFixedSize(80, 30);  // Adjust the size as needed
    buttonTwo->setFixedSize(80, 30);  
    buttonThree->setFixedSize(80, 30);   
    
    // Horizontal inner box for buttons and labels
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    // Not implemented correctly
    buttonLayout->setContentsMargins(0, 0, 300, 0);
    buttonLayout->addWidget(buttonOneTitle);
    buttonLayout->addWidget(buttonOne);
    buttonLayout->addWidget(buttonTwoTitle);
    buttonLayout->addWidget(buttonTwo);
    buttonLayout->addWidget(buttonThreeTitle);
    buttonLayout->addWidget(buttonThree);
    
    // create a child widget inside box for stiffness slide
    stiffness = createSlider("Stiffness:", "StiffnessSlider");
    stiffness->adjustSize();
    QLabel* sliderTitle = new QLabel("Stiffness:", this);
    sliderTitle->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    /*connect(stiffness, &HorizontalSlider::sliderReleased, this, [this]() {
        controlManipulated("StiffnessSlider", stiffness->value());
        });*/
    
    //TODO Connect to backend code and add update
    QHBoxLayout* sliderLayout = new QHBoxLayout;
    sliderLayout->addWidget(sliderTitle);
    sliderLayout->addWidget(stiffness);
    
    // Control Layout for buttons and sliders
    QVBoxLayout* controllerLayout = new QVBoxLayout;
    // fix size of controller box
    //controllerLayout->
    controllerLayout->addLayout(buttonLayout);
    controllerLayout->addLayout(sliderLayout);
    //QVBoxLayout* stiffnessLayout = new QVBoxLayout;
    //sliderLayout->addWidget(sliderTitle);
    //sliderLayout->addWidget(stiffness);
    // Add row to object Layout for slider
    //buttonLayout->addLayout(sliderLayout);


    //TODO RENAME LAYOUT OBJECT
    QVBoxLayout* controlLayout = new QVBoxLayout;
    
    //controlLayout->setContentsMargins(5, 5, 500, 450);
    controlLayout->setSizeConstraint(QLayout::SetFixedSize);
    
    //controlLayout->addWidget(controllerTop);
    controlLayout->addWidget(controlLabel);
    controlLayout->addLayout(controllerLayout);
    //controlLayout->addLayout(stiffnessLayout);
    controlLayout->addWidget(controllerBottom);

    controller->setLayout(controlLayout);

    // Set a border to each child widget
    //controllerTop->setStyleSheet("QWidget { border: 1px solid black; }");
    controlLabel->setStyleSheet("QWidget { border: 1px solid black; }");
    controllerBottom->setStyleSheet("QWidget { border: 1px solid black; }");
    stiffness->setStyleSheet("QWidget { border: 1.5px solid black; }");

};

template<typename PointerToMemberFunction>
Button* ControlBox::createButton(const QString& text, const PointerToMemberFunction& member)
{
    Button* button = new Button(text);
    connect(button, &Button::clicked, this, member);
    //TRY THIS TOMORROW
    //connect(buttonThree, &Button::clicked, customDialog, [this]() {controlManipulated("buttonThree", 0);  });
    return button;
}


HorizontalSlider* ControlBox::createSlider(const QString& title, const QString& objectName) {
    HorizontalSlider* slider = new HorizontalSlider(this);
    //Remove broken title b/c title hovers inches above actual object
    //QLabel* sliderTitle = new QLabel(title, this);
    //sliderTitle->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);

    // Disconnect any existing connections for the slider
    disconnect(slider, &HorizontalSlider::sliderReleased, this, nullptr);

    connect(slider, &HorizontalSlider::sliderReleased, this, [this, objectName, slider]() {
        controlManipulated(objectName.toStdString(), slider->value());
        });

    return slider;
}

void ControlBox::handleButtonPressed(int valveNumber)
{
    bool newState;
    // Get the current state of the button
    if (valveNumber == 0)
    {
        newState = buttonOne->getState();
    }
    else if (valveNumber == 1)
    {
        newState = buttonTwo->getState();
    }
    else
    {
        newState = buttonThree->getState();
    }

     // Set to true for open, false for closed
    demoSimulator.setValve(valveNumber , newState);

    // Optionally, you can update the UI or do additional tasks here
}

void ControlBox::controlManipulated(std::string objectName, int newValue)
{
    bool newState;
    
    if (objectName == "buttonOne" || objectName == "buttonTwo" || objectName == "buttonThree")
    {
        // Get the current state of the button
        if (objectName == "buttonOne")
        {
            newState = buttonOne->getState();
        }
        else if (objectName == "buttonTwo")
        {
            newState = buttonTwo->getState();
        }
        else
        {
            newState = buttonThree->getState();
        }
         
        
    }
    else
    {
        std::string objectName = "PumpSlider"; // Provide an appropriate name
        newState = true; // You need to determine the current state based on your logic

    }

    customDialog->controlManipulated(objectName, newState, newValue);
    // Set the main window as the parent of the dialog
    customDialog->setParent(this);

    // Show the existing customDialog without blocking
    customDialog->show();
    customDialog->setAttribute(Qt::WA_ShowWithoutActivating);
}

//TODO Check this is being used or not
void ControlBox::buttonClicked()
{
    // Provide the implementation for the buttonClicked function
    // For example, you can add the following line to print a message
    qDebug() << "Button Clicked";
}

void ControlBox::handleSliderValueChanged(int value) {
    // Handle the slider value change here
    // Trigger setPump function in demoSimulator
    float sliderValue = static_cast<float>(value) / stiffness->maximum();
    bool success = demoSimulator.setPump(sliderValue); // Assuming setPump is designed to take a float value
    if (success) {
        // Call controlManipulation with the correct arguments
        // You need to define the correct arguments based on your requirements
        // For example, assuming controlManipulation takes a string, a boolean, and an int
        std::string objectName = "PumpSlider"; // Provide an appropriate name
        bool currentState = true; // You need to determine the current state based on your logic
        int valueChanged = value; // You might need to adjust this based on your requirements

        // Call controlManipulation with the updated values
        
    }
}

ControlBox::~ControlBox()
{
    delete customDialog;
}


