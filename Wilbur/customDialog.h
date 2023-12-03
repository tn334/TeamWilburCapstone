#pragma once
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QApplication>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>

class CustomDialog : public QDialog
{
	Q_OBJECT

public:
	CustomDialog(QWidget* parent = nullptr);
	~CustomDialog();

private slots:
	void updateText();

private:
	void initUI() {
		/*QWidget* centralWidget = new QWidget(this);

		QVBoxLayout* dialogLayout = new QVBoxLayout(centralWidget);

		textEdit = new QTextEdit(this);
		dialogLayout->addWidget(textEdit);

		QPushButton* updateButton = new QPushButton("Update Text", this);
		connect(updateButton, &QPushButton::clicked, this, &CustomDialog::updateText);
		dialogLayout->addWidget(updateButton);*/
	}

	QString getUpdatedText() {
		// Replace this with your actual function logic to get the updated text
		return "New text from function call\n";
	}

	QTextEdit* textEdit;
};

#endif // CUSTOMDIALOG_H

