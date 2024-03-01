#pragma once
#ifndef FLOWRATEVIEW_H
#define FLOWRATEVIEW_H

#include <QLineEdit>

class FlowRateView : public QLineEdit
{
	Q_OBJECT
public:
	explicit FlowRateView(QWidget* parent = nullptr);
	~FlowRateView();

private:

};

#endif // FLOWRATEVIEW_H

