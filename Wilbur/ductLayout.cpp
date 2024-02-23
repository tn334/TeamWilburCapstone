#include "DuctLayout.h"
DuctLayout::DuctLayout(QWidget* parent)
{
	// declare label names
	buttonLabelOne = new QLabel("Duct One:");
	buttonLabelTwo = new QLabel("Duct Two:");
	buttonLabelThree = new QLabel("Duct Three:");

	// instantiate buttons for ducts 1-3
	buttonOne = new DuctButton();
	buttonTwo = new DuctButton();
	buttonThree = new DuctButton();
};

DuctLayout::~DuctLayout()
{
}