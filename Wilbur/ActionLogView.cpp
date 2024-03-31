#include "ActionLogView.h"

ActionLogView::ActionLogView(ActionLogModel* actionLogModel, QWidget* parent) : QWidget(parent)
{
	// set widget background color
	//this->setStyleSheet("background-color: #666666;");

	QFrame* frame = new QFrame(this);
	frame->setFrameShape(QFrame::Box); // set shape to a box
	//frame->setStyleSheet("border: .5px solid black;");
	frame->setFrameShadow(QFrame::Raised);
	frame->setLineWidth(1); // set the width of the frames border
	frame->setMidLineWidth(0);

	// set the background color
	frame->setAutoFillBackground(true);

	// create the layout
	QVBoxLayout* frameLayout = new QVBoxLayout(frame);

	// create a titleLabel for the display
	titleLabel = new QLabel("Action Log", this);
	titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setStyleSheet("font: bold 14px; ");

	// set size of titleLabel to make it small like a basic title
	titleLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	titleLabel->setContentsMargins(0, 0, 0, 0);

	// create a label for the display
	actionLabel = new QLabel(frame);
	// set properties for the label
	actionLabel->setWordWrap(true);
	actionLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	actionLabel->setStyleSheet("font: 14px;");

	// Add label to layout
	frameLayout->addWidget(actionLabel);

	// set layout for frame
	frame->setLayout(frameLayout);
	// create ActionLog display custom widget

	// add ActionLog widget to layout

	// set the layout for the main widget
	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(titleLabel);
	mainLayout->addWidget(frame, 1, 0, 1, 6);

	// set margins for main layout
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->setSpacing(0);

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