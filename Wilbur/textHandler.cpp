// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "textHandler.h"

TextHandler::TextHandler() {
    // Initialize if needed
}

void TextHandler::controlManipulated() {
    // Your logic to process button press and update text
    
    //TODO: Link to button presss
    
    //Later change to function call
    QString buttonText = "Button to Duct One pressed: Some action";
    textList.append(buttonText);
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