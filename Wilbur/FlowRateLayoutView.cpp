#include "FlowRateLayoutView.h"

FlowRateLayoutView::FlowRateLayoutView(QWidget* parent) : QWidget(parent) {
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

};

FlowRateLayoutView::~FlowRateLayoutView()
{
	delete flowSpinBox;
	delete flowUnitLabel;
}

// function implementation
QDoubleSpinBox *FlowRateLayoutView::getSpinBox() const { return flowSpinBox; } // must return something

QLabel *FlowRateLayoutView::getUnitLabel() const { return flowUnitLabel; }


// @TODO: Need to handle value change of milk viscocity
//void FlowRateLayoutView::handleValueChanged()
//{
//
//}