#include "ActionLogView.h"

ActionLogView::ActionLogView(ActionLogModel* actionLogModel, QWidget* parent) : QWidget(parent)
{
	QFrame* frame = new QFrame(this);
	frame->setFrameShape(QFrame::Box); // set shape to a box
	frame->setLineWidth(1); // set the width of the frames border
	frame->setMidLineWidth(0);

	// create the layout
	QVBoxLayout* layout = new QVBoxLayout(frame);

	// create a label for the display
	actionLabel = new QLabel(frame);
	// set properties for the label
	actionLabel->setWordWrap(true);
	actionLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	// Add label to layout
	layout->addWidget(actionLabel);

	// set layout for frame
	frame->setLayout(layout);
	// create ActionLog display custom widget

	// add ActionLog widget to layout

	// set the layout for the main widget
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(frame);

	// set the main layout for the action log view widget
	setLayout(mainLayout);

	connect(actionLogModel, &ActionLogModel::actionAdded, this, [this, actionLogModel]() {
		// get list of actions from model and append
		QString actionsText = actionLogModel->getListOfActions().join("\n");
		// set the text of the label to the joined actions text
		actionLabel->setText(actionsText);
		});

		// set initial text for label
		actionLabel->setText(actionLogModel->getListOfActions().join("\n"));
}