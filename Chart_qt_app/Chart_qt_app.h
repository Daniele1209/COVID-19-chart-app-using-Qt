#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Chart_qt_app.h"
#include "Repository.h"
#include <QtCharts/QBarSet>

using namespace QtCharts;

class Chart_qt_app : public QMainWindow
{
    Q_OBJECT

public:
    Chart_qt_app(Repo& r, QWidget *parent = Q_NULLPTR);

private:
    Ui::Chart_qt_appClass ui;
    Repo& repo;
    Country country;

public:
    void connectSignalsAndSlots();
    void create_chart_nc();
    void create_chart_nd();
    void create_chart_tc();
    void create_chart_td();
};
