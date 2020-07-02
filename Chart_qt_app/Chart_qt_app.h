#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Chart_qt_app.h"
#include "Repository.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMessageBox>

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
    QMainWindow* chart_window;

    void connectSignalsAndSlots();
    void create_chart_nc();
    void create_chart_nd();
    void create_chart_tc();
    void create_chart_td();
};
