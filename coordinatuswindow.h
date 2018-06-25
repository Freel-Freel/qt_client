#ifndef COORDINATUSWINDOW_H
#define COORDINATUSWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "gparcer/coordinatus.h"
#include "thermoplot.h"
//#include "gconsole.h"

#include <ui_mainwindow.h>

namespace Ui {
class MainWindow;
}

class CoordinatusWindow : public QObject
{
    Q_OBJECT
public:
    explicit CoordinatusWindow(QObject *parent = 0);

    CoordinatusWindow(Ui::MainWindow* ui);

//    void setGconsole(GConsole& g){this->gconsole = &g; }

    void update(const Status_t *status, QObject *pgconsole);

signals:

public slots:
//    void update();
//    void update(Status_t);


private:
    Ui::MainWindow* uic;

    Coordinatus* coordinatus;
    void setupCoordinatus();

//    GConsole* gconsole;

};

#endif // COORDINATUSWINDOW_H
