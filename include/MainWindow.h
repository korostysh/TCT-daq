#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include "include/Definition.h"
#include "include/TCTController.h"
#include "include/Convertor.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:

    void on_SetCoordinate_clicked();

    void on_SetTranslationStageSpeed_clicked();

    void on_MoveXMinus_clicked();

    void on_MoveXPlus_clicked();

    void on_MoveYPlus_clicked();

    void on_MoveZPlus_clicked();

    void on_initialize_clicked();

    void on_load_config_clicked();

private:
    Ui::MainWindow *ui;

    TCTController *fTCTController;
    std::vector<DAQConfig*> *fDAQConfigs = 0;
    std::map<std::string,QToolButton*> fStatuses;

    void LoadConfig();
    void FillHardware();
    void UpdateStatuses();
    std::string GetConnectionTypeString(ConnectionType pConnectionType);
    std::string GetInstrumentTypeString(InstrumentType pInstrumentType);


};

#endif // MAINWINDOW_H
