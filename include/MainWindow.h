#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include "include/Definition.h"
#include "include/TCTController.h"
#include "include/Convertor.h"
#include "QFile"
#include "Python.h"


namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private Q_SLOTS:

    void on_SetCoordinate_clicked();

    void on_SetTranslationStageSpeed_clicked();

    void on_MoveXMinus_clicked();

    void on_MoveXPlus_clicked();

    void on_MoveYPlus_clicked();

    void on_MoveZPlus_clicked();

    void on_initialize_clicked();

    void on_load_config_clicked();

    void on_MoveYMinus_clicked();

    void on_MoveZMinus_clicked();

    void on_XStart_valueChanged(double arg1);

    void on_XStepDAQ_valueChanged(double arg1);

    void on_XStepNum_valueChanged(double arg1);

    void on_YStart_valueChanged(double arg1);

    void on_YStepDAQ_valueChanged(double arg1);

    void on_YStepNum_valueChanged(double arg1);

    void on_ZStart_valueChanged(double arg1);

    void on_ZStepDAQ_valueChanged(double arg1);

    void on_ZStepNum_valueChanged(double arg1);

    void on_Source1Start_valueChanged(double arg1);

    void on_Source1Step_valueChanged(double arg1);

    void on_Source1NumofSteps_valueChanged(double arg1);



    void on_Source2Start_valueChanged(double arg1);

    void on_Source2Step_valueChanged(double arg1);

    void on_Source2NumofSteps_valueChanged(double arg1);

    void on_start_daq_clicked();

    void on_save_config_clicked();

private:
    Ui::MainWindow *ui;

    TCTController *fTCTController;
    std::vector<DAQConfig*> *fDAQConfigs = 0;
    std::map<std::string,QToolButton*> fStatuses;

    void saveToFile(QFile *file);
    void LoadConfig(QFile *BaseConfig);
    void FillHardware();
    void ClearSoftware();
    void UpdateStatuses();
    void SetDAQ_Parametrs_Stage (TranslationStage *pStage);
    void SetDAQ_Parametrs_Voltage1(VoltageSource *pVoltageSource1);
    void SetDAQ_Parametrs_Voltage2 (VoltageSource *pVoltageSource2);
    std::string GetConnectionTypeString(ConnectionType pConnectionType);
    std::string GetInstrumentTypeString(InstrumentType pInstrumentType);
    void EnableButtons();


};

#endif // MAINWINDOW_H
