// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "textHandler.h"

TextHandler::TextHandler() {
    // Initialize if needed
}

void TextHandler::controlManipulated(std::string objectName, bool currentState, int valueChanged) {
    // Your logic to process button press and update text
    QString objectText;

    // check for button
    if (objectName == "buttonOne" || objectName == "buttonTwo" || objectName == "buttonThree") 
    {
        objectText = QString("%1 is changed to %2").arg(QString::fromStdString(objectName)).arg(currentState ? "Open" : "Closed");
    }
    else 
    {
        objectText = QString("Prototype Stiffness is at %1%").arg(valueChanged);
    }
    textList.append(objectText);
}

void TextHandler::processSliderChange() {
    // Your logic to process slider change and update text

    //TODO: Link to slider value changed
    //Later change to function call
    QString sliderText = "Slider changed: Value is updated";
    textList.append(sliderText);
}

QStringList TextHandler::getAllText() const {
    return textList;
}