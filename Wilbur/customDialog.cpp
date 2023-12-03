// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "customDialog.h"

CustomDialog::CustomDialog(QWidget* parent)
    : QDialog(parent)
{
    initUI();
}

void CustomDialog::initUI()
{
    QVBoxLayout* dialogLayout = new QVBoxLayout(this);

    QLabel* titleLabel = new QLabel("Simulator:", this);
    titleLabel->setAlignment(Qt::AlignCenter); // Adjust alignment as needed
    titleLabel->setFont(QFont("Arial", 16, QFont::Bold)); // Adjust font as needed
    dialogLayout->addWidget(titleLabel);

    textEdit = new QTextEdit(this);
    dialogLayout->addWidget(textEdit);
    setLayout(dialogLayout);

    

    // Connect slider signal to slot
    // Assuming you have a QSlider named slider
    //connect(slider, &QSlider::valueChanged, this, &CustomDialog::handleSliderChange);
}

void CustomDialog::controlManipulated() {
    textHandler.controlManipulated();
    // Optionally update the text in the QTextEdit immediately
    textEdit->setPlainText(textHandler.getAllText().join("\n"));

    // Show the dialog
    this->exec();
}
