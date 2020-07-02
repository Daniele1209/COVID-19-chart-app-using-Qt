#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Chart_qt_app.h"

class Chart_qt_app : public QMainWindow
{
    Q_OBJECT

public:
    Chart_qt_app(QWidget *parent = Q_NULLPTR);

private:
    Ui::Chart_qt_appClass ui;
};
