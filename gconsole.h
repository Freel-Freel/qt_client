#ifndef GCONSOLE_H
#define GCONSOLE_H

#include <QObject>
#include <QScopedPointer>

#include <ui_mainwindow.h>
#include "gparcer/sgcode.h"
#include "exchange/threadexchange.h"
#include "gparcer/comdata.h"
#include "profiles/profile.h"

namespace Ui {
class MainWindow;
}

extern QMutex thermo_gmutex;

class GConsole : public QObject
{
    Q_OBJECT
public:
    explicit GConsole(QObject *parent = 0);

    GConsole(Ui::MainWindow *&ui);


private slots:
    void updateStatus(const Status_t* status);
    void failedStatus();


public slots:
    void on_pushButton_linestep_clicked();
    void on_textEdit_command_cursorPositionChanged();


private:
    Ui::MainWindow* uia;

    int oldBlockNumber;

//    ComData _comdata;
     ComData* req_builder;

    ThreadExchange thread;

    /**
     * Разбор одной строки.
     * @brief GcodeWorker::parceString
     * @param src
     * @return
     */
    sGcode* parceString(char *src, int *error);

//bool    GConsole::buildComData(sGcode* sgcode)
    bool buildComData(sGcode* sgcode);


    void setupGconsole();

    void setupThread();

//    Profile* profile;

};

#endif // GCONSOLE_H