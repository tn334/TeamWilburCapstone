#include "FlowRateLayoutView.h"

FlowRateLayoutView::FlowRateLayoutView(ConnectionButtonView* connectionButton, QWidget* parent) 
    : QWidget(parent), connectButton(connectionButton)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

	setToolTip("Click to enter Flow Rate");

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
QDoubleSpinBox *FlowRateLayoutView::getSpinBox() const { return flowSpinBox; } // must return something

QLabel *FlowRateLayoutView::getUnitLabel() const { return flowUnitLabel; }

void FlowRateLayoutView::handleValueChanged()
{
    if (!connectButton->getState())
    {
		//set value back to 0 value
		flowSpinBox->setValue(0.00);

		QMessageBox msgBox;
		msgBox.setWindowTitle("Warning");
		msgBox.setText("The prototype is not connected!");

		// Set text color
		QPalette palette = msgBox.palette();
		palette.setColor(QPalette::Text, Qt::white); // Change text color to red
		msgBox.setPalette(palette);

		// Set background color
		msgBox.setStyleSheet("QMessageBox { background-color: #333333; }"
			"QPushButton { background-color: #333333; }"); // Change background color to light gray

		msgBox.exec();
		//QMessageBox::warning(this, "Warning", "The Application is not connected to the Prototype!");
		return;
    }
	spinBoxValue = flowSpinBox->value();
}