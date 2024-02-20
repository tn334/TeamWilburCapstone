#include "sliderLayout.h"

SliderLayout::SliderLayout(QWidget* parent)
	: QWidget(parent)
{
    //create slider
    stiffnessSlider = new StiffnessSlider(this);

    //creating title
    title = new QLabel("Nipple Stiffness Control:");
    //set parent of title
    title->setParent(parent);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    title->setStyleSheet("font: bold 12px;");
    //Setting Label Style
    labelOff = new QLabel("Off");
    labelOff->setParent(parent);
    labelOff->setStyleSheet("font: bold 12px;");
    labelLow = new QLabel("Low");
    labelLow->setParent(parent);
    labelLow->setStyleSheet("font: bold 12px;");
    labelMedium = new QLabel("Medium");
    labelMedium->setParent(parent);
    labelMedium->setStyleSheet("font: bold 12px;");
    labelHigh = new QLabel("High");
    labelHigh->setParent(parent);
    labelHigh->setStyleSheet("font: bold 12px;");

    // create and initialize the layout
    sLayout = new QGridLayout(this);
    sLayout->addWidget(title, 0, 0, 1, 1, Qt::AlignLeft);
    sLayout->addWidget(labelOff, 1, 0, 1, 1);
    sLayout->addWidget(labelLow, 1, 1, 1, 1, Qt::AlignLeft);
    sLayout->addWidget(labelMedium, 1, 3, 1, 1, Qt::AlignRight);
    sLayout->addWidget(labelHigh, 1, 5, 1, 1, Qt::AlignRight);
    sLayout->addWidget(stiffnessSlider, 2, 0, 1, 6);

}

SliderLayout::~SliderLayout()
{
    delete title;
    delete labelOff;
    delete labelLow;
    delete labelMedium;
    delete labelHigh;
    delete sLayout;
}

void SliderLayout::resizeEvent(QResizeEvent* event) {
    // get the new size of the parent widget
    QSize newSize = event->size();
    // calculate the positions of the labels
    int xOff = 10; // some offset from the left edge
    int yOff = 10; // some offset from the top edge
    int xLow = newSize.width() / 3; // position of the low label
    int xMedium = newSize.width() / 8 * 5; // position of the medium label
    int xHigh = newSize.width() / 20 * 19 ; // position of the high label
    // move the labels to the new positions
    title->move(xOff, yOff);
    labelOff->move(xOff, yOff + title->height());
    labelLow->move(xLow, yOff + title->height());
    labelMedium->move(xMedium, yOff + title->height());
    labelHigh->move(xHigh, yOff + title->height());
}

//void SliderLayout::updateTitle(int value)
//{
//    //TODO add call to update value of slider (tie together)
//    if (value == 0) {
//        title->setText("Nipple Stiffness Control: Off");
//    }
//    else if (value <= 33) {
//        title->setText("Nipple Stiffness Control: Low");
//    }
//    else if (value <= 66) {
//        title->setText("Nipple Stiffness Control: Medium");
//    }
//    else {
//        title->setText("Nipple Stiffness Control: High");
//    }
//}