#include "Chart_qt_app.h"

Chart_qt_app::Chart_qt_app(Repo& r, QWidget *parent)
    : repo(r), QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("COVID-19 Chart app");
    QIcon icon1("covid.png");
    this->setWindowIcon(icon1);
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
            values.push_back(t.get_newc());
        }

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