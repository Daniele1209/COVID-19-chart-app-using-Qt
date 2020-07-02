#include "Chart_qt_app.h"

Chart_qt_app::Chart_qt_app(Repo& r, QWidget *parent)
    : repo(r), QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("COVID-19 Chart app");
    QIcon icon1("covid.png");
    this->setWindowIcon(icon1);
    this->chart_window = new QMainWindow;
    this->connectSignalsAndSlots();
}

void Chart_qt_app::connectSignalsAndSlots() {
    QObject::connect(ui.button_nc, &QPushButton::clicked, this, &Chart_qt_app::create_chart_nc);
    QObject::connect(ui.button_nd, &QPushButton::clicked, this, &Chart_qt_app::create_chart_nd);
    QObject::connect(ui.button_tc, &QPushButton::clicked, this, &Chart_qt_app::create_chart_tc);
    QObject::connect(ui.button_td, &QPushButton::clicked, this, &Chart_qt_app::create_chart_td);
    QObject::connect(ui.button_exit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Chart_qt_app::create_chart_nc() {
    vector<Country> countries = this->repo.get_countries();
    vector<int> values;
    vector<string> names;
    for (auto& t : countries)
        if (t.get_name() != "World") {
            names.push_back(t.get_name());
            values.push_back(t.get_totalc());
        }
    QString str = QString::number(values.size());
    QMessageBox::information(0, "Error !", str);
    QString str2 = QString::number(names.size());
    QMessageBox::information(0, "Error !", str2);
    QBarSet* set0 = new QBarSet("Countries");
    for(int val : values)
        *set0 << val;
    QBarSeries* series = new QBarSeries();
    series->append(set0);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("New Cases Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (auto t : names) {
        categories << t.c_str();
    }
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, 500000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette pal = qApp->palette();
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    qApp->setPalette(pal);
    this->chart_window->setCentralWidget(chartView);
    this->chart_window->resize(1000, 500);
    this->chart_window->show();

}
void Chart_qt_app::create_chart_nd() {
    vector<Country> countries = this->repo.get_countries();
    vector<int> values;
    vector<string> names;
    for (auto& t : countries)
        if (t.get_name() != "World") {
            names.push_back(t.get_name());
            values.push_back(t.get_newd());
        }

}
void Chart_qt_app::create_chart_tc() {
    vector<Country> countries = this->repo.get_countries();
    vector<int> values;
    vector<string> names;
    for (auto& t : countries)
        if (t.get_name() != "World") {
            names.push_back(t.get_name());
            values.push_back(t.get_totalc());
        }

}
void Chart_qt_app::create_chart_td() {
    vector<Country> countries = this->repo.get_countries();
    vector<int> values;
    vector<string> names;
    for (auto& t : countries)
        if (t.get_name() != "World") {
            names.push_back(t.get_name());
            values.push_back(t.get_totald());
        }

}