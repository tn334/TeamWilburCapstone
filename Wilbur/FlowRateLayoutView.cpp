#include "FlowRateLayoutView.h"

FlowRateLayoutView::FlowRateLayoutView(ConnectionButtonView* connectionButton, QWidget* parent) 
    : QWidget(parent), connectButton(connectionButton)
{
	previousValue = 0;

    QHBoxLayout* layout = new QHBoxLayout(this);

	setToolTip("Press Enter to log Flow Rate changes");

    flowSpinBox = new QDoubleSpinBox();
    flowSpinBox->setSingleStep(0.01);
    flowSpinBox->setMaximumWidth(75);
    flowSpinBox->setFixedHeight(20);
    flowSpinBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    flowUnitLabel = new QLabel("m<sup>3</sup>/s");
    flowUnitLabel->setStyleSheet("font: bold 12px; ");

    layout->addWidget(flowSpinBox);
    layout->addWidget(flowUnitLabel);

    setLayout(layout);

	connect(flowSpinBox, &QDoubleSpinBox::valueChanged, 
								this, &FlowRateLayoutView::handleValueChanged);
};

FlowRateLayoutView::~FlowRateLayoutView()
{
	delete flowSpinBox;
	delete flowUnitLabel;
}

// function implementation
QDoubleSpinBox *FlowRateLayoutView::getSpinBox() const { return flowSpinBox; }

QLabel *FlowRateLayoutView::getUnitLabel() const { return flowUnitLabel; }

void FlowRateLayoutView::handleValueChanged()
{
    if (!connectButton->getState())
    {
		QMessageBox msgBox;
		QPalette palette = msgBox.palette();

		// Disconnect value changed signal to allow reset for value back to 0
		disconnect(flowSpinBox, &QDoubleSpinBox::valueChanged,
								this, &FlowRateLayoutView::handleValueChanged);

		// Set the value of the spin box back to 0
		flowSpinBox->setValue(0.00);

		// Connect value changed signal again to allow for future inputs
		connect(flowSpinBox, &QDoubleSpinBox::valueChanged,
								this, &FlowRateLayoutView::handleValueChanged);

		msgBox.setWindowTitle("Warning");
		msgBox.setText("The prototype is not connected!");

		// Set text color
		palette.setColor(QPalette::Text, Qt::white); // Change text color to red
		msgBox.setPalette(palette);

		// Set background colors to light gray
		msgBox.setStyleSheet("QMessageBox { background-color: #333333; }"
								 "QPushButton { background-color: #333333; }"); 

		// Open warning message box
		msgBox.exec();

		return;
    }

	if (spinBoxValue != previousValue)
	{
		spinBoxValue = flowSpinBox->value();

		previousValue = spinBoxValue;
	}

}