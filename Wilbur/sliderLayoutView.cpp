// Header Files
#include "SliderLayoutView.h"

// Slider layout constructor
SliderLayoutView::SliderLayoutView(ConnectionButtonView* connectionButton, QWidget* parent)
	: QWidget(parent), connectButton(connectionButton)
{
    // create slider
    stiffnessSlider = new StiffnessSliderView(connectButton, this);

    // creating title
    title = new QLabel("Nipple Stiffness Control:");

    // set parent of title and its settings
    title->setParent(parent);
    title->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    title->setStyleSheet("font: bold 14px;");

    // Setting OFF Label settings
    labelOff = new QLabel("Off");
    labelOff->setParent(parent);
    labelOff->setStyleSheet("font: bold 14px;");

	// Setting LOW Label settings
    labelLow = new QLabel("Low");
    labelLow->setParent(parent);
    labelLow->setStyleSheet("font: bold 14px;");

	// Setting MEDIUM Label settings
    labelMedium = new QLabel("Medium");
    labelMedium->setParent(parent);
    labelMedium->setStyleSheet("font: bold 14px;");

	// Setting HIGH Label settings
    labelHigh = new QLabel("High");
    labelHigh->setParent(parent);
    labelHigh->setStyleSheet("font: bold 14px;");

    // initialize grid layout
    stiffSliderLayout = new QGridLayout(this);

    // Add title
    stiffSliderLayout->addWidget(title, 0, 0, 1, 1, Qt::AlignLeft);

    // Add spacing
    stiffSliderLayout->addItem(new QSpacerItem(20, 50, QSizePolicy::Expanding, QSizePolicy::Preferred), 0, 1); // Adjust the size as needed
    
	// Add Labels
    stiffSliderLayout->addWidget(labelOff, 1, 0, 1, 1);
    stiffSliderLayout->addWidget(labelLow, 1, 1, 1, 1, Qt::AlignLeft);
    stiffSliderLayout->addWidget(labelMedium, 1, 3, 1, 1, Qt::AlignRight);
    stiffSliderLayout->addWidget(labelHigh, 1, 5, 1, 1, Qt::AlignRight);
    
	// Add Slider
    stiffSliderLayout->addWidget(stiffnessSlider, 2, 0, 1, 6);
}

// Destructor
SliderLayoutView::~SliderLayoutView()
{
	// Delete instantiated labels
    delete title;
    delete labelOff;
    delete labelLow;
    delete labelMedium;
    delete labelHigh;
    // delete slider
    delete stiffSliderLayout;
}

void SliderLayoutView::resizeEvent(QResizeEvent* event) {
    // get the new size of the parent widget
    QSize newSize = event->size();

    // calculate the positions of the labels
	int xInset = 14;
    int xOff = 10; // some offset from the left edge
    int yOff = 10; // some offset from the top edge
    int xLow = newSize.width() / 3; // position of the low label
    int xMedium = newSize.width() / 8 * 5; // position of the medium label
    int xHigh = newSize.width() / 20 * 19 ; // position of the high label
    
	// move the labels to the new positions
    labelOff->move(xOff, yOff + title->height());
    labelLow->move(xLow, yOff + title->height());
    labelMedium->move(xMedium, yOff + title->height());

	// Check if calculation value is close to being equal to window being in
	// screen (600 through 690)
	if (xHigh - xInset > 600 )
	{
		// Place label at specified location
		labelHigh->move(xHigh + xOff, yOff + title->height());
	}

	// Otherwise, assume window is close to being or is minimized
	else
	{
		// Place label at specified location
		labelHigh->move(xHigh - xInset, yOff + title->height());
	}
}