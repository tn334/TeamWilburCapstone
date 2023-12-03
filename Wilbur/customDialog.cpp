// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "customDialog.h"

CustomDialog::CustomDialog(QWidget* parent)
    : QDialog(parent)
{
    initUI();
}

// Slot implementation
void CustomDialog::updateText() {
    // Call function here and get the string to update the text
    QString newText = getUpdatedText();

    // Append the new text to the existing text in the text box
    textEdit->append(newText);
}

CustomDialog::~CustomDialog()
{
    // Clean up resources if needed
}