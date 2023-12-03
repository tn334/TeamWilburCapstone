#pragma once
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>

class DialogueWindow : public QMainWindow
{
	Q_OBJECT

public:
	DialogueWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
		initUI();
	}

private slots:
	void updateText() {
		// Call function here and get the string to update the text
		QString newText = getUpdatedText();

		// Apend the new text to the existing text in the text box
		textEdit->append(newText);
	}

private:
	void initUI() {
		QWidget* centralWidget = new QWidget(this);
		setCentralWidget(centralWidget);

		QVBoxLayout* layout = new QVBoxLayout(centralWidget);

		textEdit = new QTextEdit(this);
		layout->addWidget(textEdit);

		QPushButton* updateButton = new QPushButton("Update Text", this);
		connect(updateButton, &QPushButton::clicked, this, &DialogueWindow::updateText);
		layout->addWidget(updateButton);
	}

	QString getUpdatedText() {
		// Replace this with your actual function logic to get the updated text
		return "New text from function call\n";
	}

	QTextEdit* textEdit;
};

