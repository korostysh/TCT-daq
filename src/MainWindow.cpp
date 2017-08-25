#include "include/MainWindow.h"
#include "ui_MainWindow.h"
#include "iostream"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QToolButton"
#include "ostream"
#include <sstream>
#include "instruments/include/TranslationStage.h"
#include "include/Instrument.h"
#include <QFileDialog>
#include <QDebug>
#include "instruments/include/Oscilloscope.h"
#include "instruments/include/VoltageSource.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fDAQConfigs = new std::vector<DAQConfig*>;
    fTCTController = new TCTController;
    QFile *fConfFile = new QFile("BaseConfig.txt");
    LoadConfig(fConfFile);
    delete fConfFile;

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadConfig(QFile *BaseConfig)
{
    Convertor convert;
    QTextStream textStream(BaseConfig);
    if(BaseConfig->open(QIODevice::ReadOnly)){


        for(auto config_word: *fDAQConfigs) delete config_word;
        fDAQConfigs->clear();
        QString word = "START";
        while (word != "[ENDCONFIG]")
        {
            textStream >> word;
            if (word.length() == 0) continue;
            if (word[0] == '/') continue;
            if (word[0] == '\n') continue;

            if (word == "[TranslationStage]")
            {

                DAQConfig *cConfig = new DAQConfig;

                while (word != "[TranslationStageEnd]"){
                    textStream >> word;
                    if (word == "InstrumentType="){
                        textStream >> word;
                        cConfig->instrument_type = convert.InstrumentStringToEnum(word);
                    }
                    else if ( word == "ConnectionType="){
                        textStream >> word;
                        cConfig->connection_type = convert.ConnectionStringToEnum(word);
                    }
                    else if ( word == "Adress="){
                        textStream >> word;
                         cConfig->address = word.toUtf8().constData();
                    }
                    else if ( word == "Name="){
                        textStream >> word;
                        cConfig->name = word.toUtf8().constData();
                    }
                    else if ( word == "X="){
                        textStream >> word;
                        ui->XAxisPosition->setValue(word.toDouble(false));
                    }
                    else if ( word == "Y="){
                        textStream >> word;
                        ui->YAxisPosition->setValue(word.toDouble(false));
                    }
                    else if ( word == "Z="){
                        textStream >> word;
                        ui->ZAxisPosition->setValue(word.toDouble(false));
                    }
                    else if ( word == "XStart="){
                        textStream >> word;
                        ui->XStart->setValue(word.toDouble(false));
                    }
                    else if ( word == "YStart="){
                        textStream >> word;
                        ui->YStart->setValue(word.toDouble(false));
                    }
                    else if ( word == "ZStart="){
                        textStream >> word;
                        ui->ZStart->setValue(word.toDouble(false));
                    }
                    else if ( word == "XSpeed="){
                        textStream >> word;
                        ui->XSpeed->setValue(word.toDouble(false));
                    }
                    else if ( word == "YSpeed="){
                        textStream >> word;
                        ui->YSpeed->setValue(word.toDouble(false));
                    }
                    else if ( word == "ZSpeed="){
                        textStream >> word;
                        ui->ZSpeed->setValue(word.toDouble(false));
                    }
                    else if ( word == "XStep="){
                        textStream >> word;
                        ui->XStep->setValue(word.toDouble(false));
                    }
                    else if ( word == "YStep="){
                        textStream >> word;
                        ui->YStep->setValue(word.toDouble(false));
                    }
                    else if ( word == "ZStep="){
                        textStream >> word;
                        ui->ZStep->setValue(word.toDouble(false));
                    }
                    else if ( word == "ZStepDAQ="){
                        textStream >> word;
                        ui->ZStepDAQ->setValue(word.toDouble(false));
                    }
                    else if ( word == "YStepDAQ="){
                        textStream >> word;
                        ui->YStepDAQ->setValue(word.toDouble(false));
                    }
                    else if ( word == "XStepDAQ="){
                        textStream >> word;
                        ui->XStepDAQ->setValue(word.toDouble(false));
                    }
                    else if ( word == "XNumberOfSteps="){
                        textStream >> word;
                        ui->XStepNum->setValue(word.toDouble(false));
                    }
                    else if ( word == "YNumberOfSteps="){
                        textStream >> word;
                        ui->YStepNum->setValue(word.toDouble(false));
                    }
                    else if ( word == "ZNumberOfSteps="){
                        textStream >> word;
                        ui->ZStepNum->setValue(word.toDouble(false));
                    }
                    else if ( word == "StageDelay="){
                        textStream >> word;
                        ui->StageDelay->setValue(word.toDouble(false));
                    }

                }
                fDAQConfigs->push_back(cConfig);
                continue;
            }
            else if (word == "[VoltageSource1]")
            {

                DAQConfig *cConfig = new DAQConfig;

                while (word != "[VoltageSource1End]"){
                    textStream >> word;
                    if (word == "InstrumentType="){
                        textStream >> word;
                        cConfig->instrument_type = convert.InstrumentStringToEnum(word);
                    }
                    else if ( word == "ConnectionType="){
                        textStream >> word;
                        cConfig->connection_type = convert.ConnectionStringToEnum(word);
                    }
                    else if ( word == "Adress="){
                        textStream >> word;
                         cConfig->address = word.toUtf8().constData();
                    }
                    else if ( word == "Name="){
                        textStream >> word;
                        cConfig->name = word.toUtf8().constData();
                    }
                    else if ( word == "Bias="){
                        textStream >> word;
                        ui->BiasV1->setValue(word.toDouble(false));
                    }
                    else if ( word == "IncreaseStep="){
                        textStream >> word;
                        ui->BiasStepV1->setValue(word.toDouble(false));
                    }
                    else if ( word == "Delay="){
                        textStream >> word;
                        ui->BiasDelayV1->setValue(word.toDouble(false));
                    }
                    else if ( word == "NumOfSteps="){
                        textStream >> word;
                        ui->Source1NumofSteps->setValue(word.toDouble(false));
                    }
                    else if ( word == "StartVoltage="){
                        textStream >> word;
                        ui->Source1Start->setValue(word.toDouble(false));
                    }
                    else if ( word == "StepVoltage="){
                        textStream >> word;
                        ui->Source1Step->setValue(word.toDouble(false));
                    }


                }
                fDAQConfigs->push_back(cConfig);
            }
            else if (word == "[VoltageSource2]")
            {

                DAQConfig *cConfig = new DAQConfig;

                while (word != "[VoltageSource2End]"){
                    textStream >> word;
                    if (word == "InstrumentType="){
                        textStream >> word;
                        cConfig->instrument_type = convert.InstrumentStringToEnum(word);
                    }
                    else if ( word == "ConnectionType="){
                        textStream >> word;
                        cConfig->connection_type = convert.ConnectionStringToEnum(word);
                    }
                    else if ( word == "Adress="){
                        textStream >> word;
                         cConfig->address = word.toUtf8().constData();
                    }
                    else if ( word == "Name="){
                        textStream >> word;
                        cConfig->name = word.toUtf8().constData();
                    }
                    else if ( word == "Bias="){
                        textStream >> word;
                        ui->BiasV2->setValue(word.toDouble(false));
                    }
                    else if ( word == "IncreaseStep="){
                        textStream >> word;
                        ui->BiasStepV2->setValue(word.toDouble(false));
                    }
                    else if ( word == "Delay="){
                        textStream >> word;
                        ui->BiasDelayV2->setValue(word.toDouble(false));
                    }
                    else if ( word == "NumOfSteps="){
                        textStream >> word;
                        ui->Source2NumofSteps->setValue(word.toDouble(false));
                    }
                    else if ( word == "StartVoltage="){
                        textStream >> word;
                        ui->Source2Start->setValue(word.toDouble(false));
                    }
                    else if ( word == "StepVoltage="){
                        textStream >> word;
                        ui->Source2Step->setValue(word.toDouble(false));
                    }
                }
                fDAQConfigs->push_back(cConfig);
            }
            else if (word == "[Oscilloscope]")
            {

                DAQConfig *cConfig = new DAQConfig;

                while (word != "[OscilloscopeEnd]"){
                    textStream >> word;
                    if (word == "InstrumentType="){
                        textStream >> word;
                        cConfig->instrument_type = convert.InstrumentStringToEnum(word);
                    }
                    else if ( word == "ConnectionType="){
                        textStream >> word;
                        cConfig->connection_type = convert.ConnectionStringToEnum(word);
                    }
                    else if ( word == "Adress="){
                        textStream >> word;
                         cConfig->address = word.toUtf8().constData();
                    }
                    else if ( word == "Name="){
                        textStream >> word;
                        cConfig->name = word.toUtf8().constData();
                    }
                }
                fDAQConfigs->push_back(cConfig);
            }
        }

        FillHardware();
    }

}


void MainWindow::ClearSoftware(){
    QLayout *old_layout = ui->groupStatus->layout();
    QLayout *sublayout;
    QWidget * widget;
    QLayoutItem *item;
    while ((item = old_layout->takeAt(0))) {
        if ((sublayout = item->layout()) != 0) {delete sublayout;}
        else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
        else {delete item;}
    }

    // then finally
    delete old_layout;
}


void MainWindow::FillHardware()
{


    QVBoxLayout *general_layout = new QVBoxLayout;
    fStatuses.clear();

    for (auto config_word : *fDAQConfigs)
    {
        QWidget *stats_widget = new QWidget;
        stats_widget->setMinimumSize(260,75);
        stats_widget->setMaximumHeight(75);

        QHBoxLayout *stats_layout = new QHBoxLayout;

        QToolButton *config_button = new QToolButton;
        config_button->setMaximumSize(40,40);
        config_button->setMinimumSize(40,40);
        config_button->setIcon(QIcon("../icons/settings.png"));
        config_button->setIconSize(QSize(0.9*(config_button->width()), 0.9*(config_button->height())));
        //ui->config_button->setStyleSheet("margin:15px;");
        stats_layout->addWidget(config_button);

        QVBoxLayout *infos_layout = new QVBoxLayout;
        QLabel *label_type = new QLabel(GetInstrumentTypeString(config_word->instrument_type).c_str());
        label_type->setMaximumSize(120,25);
        label_type->setMinimumSize(120,25);
        label_type->setStyleSheet("font-weight: bold;");
        QLabel *label_name = new QLabel(config_word->name.c_str());
        label_name->setMaximumSize(120,25);
        label_name->setMinimumSize(120,25);
        label_name->setStyleSheet("font-size: 8pt;");
        QLabel *label_connection = new QLabel(GetConnectionTypeString(config_word->connection_type).c_str());
        label_connection->setMaximumSize(120,25);
        label_connection->setMinimumSize(120,25);
        label_connection->setStyleSheet("font-size: 8pt;");

        infos_layout->addWidget(label_type);
        infos_layout->addWidget(label_name);
        infos_layout->addWidget(label_connection);
        stats_layout->addItem(infos_layout);

        QToolButton *status_led = new QToolButton;
        status_led->setMaximumSize(60,60);
        status_led->setMinimumSize(60,60);
        status_led->setIcon(QIcon("../icons/state_grey.png"));
        status_led->setIconSize(QSize(0.9*status_led->width(), 0.9*status_led->height()));
        status_led->setStyleSheet("QToolButton{border: none;outline: none;}");
        stats_layout->addWidget(status_led);

        stats_widget->setLayout(stats_layout);
        general_layout->addWidget(stats_widget);

        fStatuses[config_word->name] = status_led;
    }

    ui->groupStatus->setLayout(general_layout);
}

void MainWindow::UpdateStatuses()
{
    for (auto cInstrument : *fTCTController->GetInstruments()) {
        StatusType cStatus = cInstrument->GetStatus();
        for(auto cMapEntry : fStatuses) {
            if(cMapEntry.first == cInstrument->GetName()) {
                if (cStatus == StatusType::Error) {
                    cMapEntry.second->setIcon(QIcon("../icons/state_red.png"));
                }
                else if (cStatus == StatusType::Ready) {
                    cMapEntry.second->setIcon(QIcon("../icons/state_green.png"));
                }
                else if (cStatus == StatusType::Uninitialized) {
                    cMapEntry.second->setIcon(QIcon("../icons/state_grey.png"));
                }
                else {
                    cMapEntry.second->setIcon(QIcon("../icons/state_red.png"));
                }
            }
        }
    }
}

std::string MainWindow::GetConnectionTypeString(ConnectionType pConnectionType)
{
    std::string type = "Unkwnown";
    switch (pConnectionType) {
        case ConnectionType::GPIB:
            type = "GPIB";
            break;
        case ConnectionType::USB:
            type = "USB";
            break;
        case ConnectionType::TCPIP:
            type = "TCPIP";
            break;
        case ConnectionType::VICP:
            type = "VICP";
            break;
        case ConnectionType::UNKNOWN:
            type = "UNKNOWN";
            break;
        default:
            type = "UNKNOWN";
            break;
    }
    return type;
}

std::string MainWindow::GetInstrumentTypeString(InstrumentType pInstrumentType)
{
    std::string type = "Unkwnown";
    switch (pInstrumentType) {

        case InstrumentType::VoltageSource1:
            type = "VoltageSource1";
            break;
        case InstrumentType::VoltageSource2:
            type = "VoltageSource2";
            break;
        case InstrumentType::Oscilloscope:
            type = "Oscilloscope";
            break;
        case InstrumentType::TranslationStage:
            type = "TranslationStage";
            break;
        case InstrumentType::RotationStage:
            type = "RotationStage";
            break;
        case InstrumentType::Laser:
            type = "Laser";
            break;
        case InstrumentType::TemperatureController:
            type = "TemperatureController";
            break;
        case InstrumentType::Unknown:
            type = "UNKNOWN";
            break;
        default:
            type = "UNKNOWN";
            break;
    }
    return type;
}

void MainWindow::SetDAQ_Parametrs_Stage (TranslationStage *pStage){




    PositionType        pStagePosition;
    PositionType        pStageStartPosition;
    PositionStep        pStageStepDAQ;
    PositionStep        pStageStep;
    PositionNumofSteps  pNumOfSteps;
    StageSpeedType      pStageSpeed;
    double              pStageDelay;

    pStageDelay = ui->StageDelay->value();

    pStage->SetStageDelay(pStageDelay);

    pStageSpeed.xSpeed = ui->XSpeed->value();
    pStageSpeed.ySpeed = ui->YSpeed->value();
    pStageSpeed.zSpeed = ui->ZSpeed->value();

    pStage->SetStageSpeed(pStageSpeed);

    pStagePosition.x = ui->XAxisPosition->value();
    pStagePosition.y = ui->YAxisPosition->value();
    pStagePosition.z = ui->ZAxisPosition->value();

    pStage->SetPosition(pStagePosition);

    pStageStartPosition.x = ui->XStart->value();
    pStageStartPosition.y = ui->YStart->value();
    pStageStartPosition.z = ui->ZStart->value();

    pStage->SetStartPosition(pStageStartPosition);

    pStageStepDAQ.xStep = ui->XStepDAQ->value();
    pStageStepDAQ.yStep = ui->YStepDAQ->value();
    pStageStepDAQ.zStep = ui->ZStepDAQ->value();

    pStage->SetPositionStepDAQ(pStageStepDAQ);

    pStageStep.xStep = ui->XStep->value();
    pStageStep.yStep = ui->YStep->value();
    pStageStep.zStep = ui->ZStep->value();

    pStage->SetPositionStep(pStageStep);

    pNumOfSteps.xNumOfSteps = ui->XStepNum->value();
    pNumOfSteps.yNumOfSteps = ui->YStepNum->value();
    pNumOfSteps.zNumOfSteps = ui->ZStepNum->value();

    pStage->SetPositionNumofSteps(pNumOfSteps);


}
void MainWindow::SetDAQ_Parametrs_Voltage1 (VoltageSource *pVoltageSource1){




    VoltageSourceStruct pVoltageSource1Setup;
    VoltageDAQ          pVoltageDAQ1;


    pVoltageSource1Setup.bias = ui->BiasV1->value();
    pVoltageSource1Setup.delay = ui->BiasDelayV1->value();
    pVoltageSource1Setup.increase_step = ui->BiasStepV1->value();

    pVoltageSource1->SetVoltageParametrs(pVoltageSource1Setup);

    pVoltageDAQ1.StartVoltage = ui->Source1Start->value();
    pVoltageDAQ1.StepVoltage = ui->Source1Step->value();
    pVoltageDAQ1.NumOfSteps = ui->Source1NumofSteps->value();

    pVoltageSource1->SetVoltageDAQParametrs(pVoltageDAQ1);


}
void MainWindow::SetDAQ_Parametrs_Voltage2 (VoltageSource *pVoltageSource2){





    VoltageSourceStruct pVoltageSource2Setup;
    VoltageDAQ          pVoltageDAQ2;


    pVoltageDAQ2.StartVoltage = ui->Source2Start->value();
    pVoltageDAQ2.StepVoltage = ui->Source2Step->value();
    pVoltageDAQ2.NumOfSteps = ui->Source2NumofSteps->value();

    pVoltageSource2->SetVoltageDAQParametrs(pVoltageDAQ2);

    pVoltageSource2Setup.bias = ui->BiasV2->value();
    pVoltageSource2Setup.delay = ui->BiasDelayV2->value();
    pVoltageSource2Setup.increase_step = ui->BiasStepV2->value();

    pVoltageSource2->SetVoltageParametrs(pVoltageSource2Setup);

}


void MainWindow::on_SetCoordinate_clicked()
{
    PositionType pPosition;
    pPosition.x = ui->XAxisPosition->value();
    pPosition.y = ui->YAxisPosition->value();
    pPosition.z = ui->ZAxisPosition->value();

    TranslationStage *pStage = fTCTController->GetTranslationStage();

    pStage->SetPosition(pPosition);
    std::ostringstream ss;
    ss << "X position = " << pStage->GetPosition().x << "   ";
    ss << "Y position = " << pStage->GetPosition().y << "   ";
    ss << "Z position = " << pStage->GetPosition().z << "   ";


}

void MainWindow::on_SetTranslationStageSpeed_clicked()
{
    PositionType pPosition;
    StageSpeedType pStageSpeed;

    pPosition.x = ui->XAxisPosition->value();
    pPosition.y = ui->YAxisPosition->value();
    pPosition.z = ui->ZAxisPosition->value();

    pStageSpeed.xSpeed = ui->XSpeed->value();
    pStageSpeed.ySpeed = ui->YSpeed->value();
    pStageSpeed.zSpeed = ui->ZSpeed->value();

    TranslationStage *pStage = fTCTController->GetTranslationStage();

    pStage->SetPosition(pPosition);
    pStage->SetStageSpeed(pStageSpeed);

    std::ostringstream ss;
    ss << "X position = " << pStage->GetPosition().x << "   ";
    ss << "Y position = " << pStage->GetPosition().y << "   ";
    ss << "Z position = " << pStage->GetPosition().z << "   ";

    ss << "X axis speed = " << pStage->GetStageSpeed().xSpeed << "   ";
    ss << "Y axis speed = " << pStage->GetStageSpeed().ySpeed << "   ";
    ss << "Z axis speed = " << pStage->GetStageSpeed().zSpeed << "   ";





}

void MainWindow::EnableButtons(){
    ui->MoveXMinus->setEnabled(true);
    ui->MoveYMinus->setEnabled(true);
    ui->MoveZMinus->setEnabled(true);
    ui->MoveXPlus->setEnabled(true);
    ui->MoveYPlus->setEnabled(true);
    ui->MoveZPlus->setEnabled(true);
    ui->SetCoordinate->setEnabled(true);
    ui->SetTranslationStageSpeed->setEnabled(true);
    ui->start_daq->setEnabled(true);
    ui->save_config->setEnabled(true);
}

void MainWindow::on_MoveXMinus_clicked()
{
     ui->XAxisPosition->setValue(ui->XAxisPosition->value()-ui->XStep->value());
     ui->SetCoordinate->clicked(true);
}

void MainWindow::on_MoveXPlus_clicked()
{
    ui->XAxisPosition->setValue(ui->XAxisPosition->value()+ui->XStep->value());
    ui->SetCoordinate->clicked(true);
}

void MainWindow::on_MoveYMinus_clicked()
{
    ui->YAxisPosition->setValue(ui->YAxisPosition->value()-ui->YStep->value());
    ui->SetCoordinate->clicked(true);
}
void MainWindow::on_MoveYPlus_clicked()
{
    ui->YAxisPosition->setValue(ui->YAxisPosition->value()+ui->YStep->value());
    ui->SetCoordinate->clicked(true);
}
void MainWindow::on_MoveZMinus_clicked()
{
    ui->ZAxisPosition->setValue(ui->ZAxisPosition->value()-ui->ZStep->value());
    ui->SetCoordinate->clicked(true);
}

void MainWindow::on_MoveZPlus_clicked()
{
    ui->ZAxisPosition->setValue(ui->ZAxisPosition->value()+ui->ZStep->value());
    ui->SetCoordinate->clicked(true);
}

void MainWindow::on_initialize_clicked()
{
    fTCTController->Initialize(fDAQConfigs);
    UpdateStatuses();
    EnableButtons();

}

void MainWindow::on_load_config_clicked()
{
    ClearSoftware();
    fDAQConfigs->clear();
    fStatuses.clear();
    UpdateStatuses();
    QString filename = QFileDialog::getOpenFileName();
    if (filename == "") return;

    QFile *F = new QFile(filename, this);
    LoadConfig(F);
    delete F;
}



void MainWindow::on_XStart_valueChanged(double arg1)
{
    float XFinal;
    std::ostringstream ss;
    XFinal = ui->XStart->value()+ui->XStepDAQ->value()*ui->XStepNum->value();
    ss << XFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->XFinal->setText(QStr);
}

void MainWindow::on_XStepDAQ_valueChanged(double arg1)
{
    float XFinal;
    std::ostringstream ss;
    XFinal = ui->XStart->value()+ui->XStepDAQ->value()*ui->XStepNum->value();
    ss << XFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->XFinal->setText(QStr);

}

void MainWindow::on_XStepNum_valueChanged(double arg1)
{
    float XFinal;
    std::ostringstream ss;
    XFinal = ui->XStart->value()+ui->XStepDAQ->value()*ui->XStepNum->value();
    ss << XFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->XFinal->setText(QStr);
}

void MainWindow::on_YStart_valueChanged(double arg1)
{
    float YFinal;
    std::ostringstream ss;
    YFinal = ui->YStart->value()+ui->YStepDAQ->value()*ui->YStepNum->value();
    ss << YFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->YFinal->setText(QStr);

}

void MainWindow::on_YStepDAQ_valueChanged(double arg1)
{
    float YFinal;
    std::ostringstream ss;
    YFinal = ui->YStart->value()+ui->YStepDAQ->value()*ui->YStepNum->value();
    ss << YFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->YFinal->setText(QStr);

}

void MainWindow::on_YStepNum_valueChanged(double arg1)
{
    float YFinal;
    std::ostringstream ss;
    YFinal = ui->YStart->value()+ui->YStepDAQ->value()*ui->YStepNum->value();
    ss << YFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->YFinal->setText(QStr);

}

void MainWindow::on_ZStart_valueChanged(double arg1)
{
    float ZFinal;
    std::ostringstream ss;
    ZFinal = ui->ZStart->value()+ui->ZStepDAQ->value()*ui->ZStepNum->value();
    ss << ZFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->ZFinal->setText(QStr);

}

void MainWindow::on_ZStepDAQ_valueChanged(double arg1)
{
    float ZFinal;
    std::ostringstream ss;
    ZFinal = ui->ZStart->value()+ui->ZStepDAQ->value()*ui->ZStepNum->value();
    ss << ZFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->ZFinal->setText(QStr);
}

void MainWindow::on_ZStepNum_valueChanged(double arg1)
{
    float ZFinal;
    std::ostringstream ss;
    ZFinal = ui->ZStart->value()+ui->ZStepDAQ->value()*ui->ZStepNum->value();
    ss << ZFinal;
    QString QStr = QString::fromStdString(ss.str());
    ui->ZFinal->setText(QStr);
}

void MainWindow::on_Source1Start_valueChanged(double arg1)
{
    float Source1;
    std::ostringstream ss;
    Source1 = ui->Source1Start->value()+ui->Source1Step->value()*ui->Source1NumofSteps->value();
    ss << Source1;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source1Final->setText(QStr);

}

void MainWindow::on_Source1Step_valueChanged(double arg1)
{
    float Source1;
    std::ostringstream ss;
    Source1 = ui->Source1Start->value()+ui->Source1Step->value()*ui->Source1NumofSteps->value();
    ss << Source1;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source1Final->setText(QStr);

}

void MainWindow::on_Source1NumofSteps_valueChanged(double arg1)
{
    float Source1;
    std::ostringstream ss;
    Source1 = ui->Source1Start->value()+ui->Source1Step->value()*ui->Source1NumofSteps->value();
    ss << Source1;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source1Final->setText(QStr);
}





void MainWindow::on_Source2Start_valueChanged(double arg1)
{
    float Source2;
    std::ostringstream ss;
    Source2 = ui->Source2Start->value()+ui->Source2Step->value()*ui->Source2NumofSteps->value();
    ss << Source2;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source2Final->setText(QStr);
}

void MainWindow::on_Source2Step_valueChanged(double arg1)
{
    float Source2;
    std::ostringstream ss;
    Source2 = ui->Source2Start->value()+ui->Source2Step->value()*ui->Source2NumofSteps->value();
    ss << Source2;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source2Final->setText(QStr);
}

void MainWindow::on_Source2NumofSteps_valueChanged(double arg1)
{
    float Source2;
    std::ostringstream ss;
    Source2 = ui->Source2Start->value()+ui->Source2Step->value()*ui->Source2NumofSteps->value();
    ss << Source2;
    QString QStr = QString::fromStdString(ss.str());
    ui->Source2Final->setText(QStr);
}

void MainWindow::on_start_daq_clicked()
{
    for (auto cInstrument : *fTCTController->GetInstruments()) {
        //cInstrument->GetTy
        StatusType cStatus = cInstrument->GetStatus();

    }
    TranslationStage *pStage = fTCTController->GetTranslationStage();
    VoltageSource    *pVoltageSource1 = fTCTController->GetVoltageSource1();
    VoltageSource    *pVoltageSource2 = fTCTController->GetVoltageSource2();

    SetDAQ_Parametrs_Stage(pStage);
    SetDAQ_Parametrs_Voltage1(pVoltageSource1);
    SetDAQ_Parametrs_Voltage2(pVoltageSource2);

    StageSpeedType               pStageSpeed = pStage->GetStageSpeed();
    PositionStep                 pStageStep   = pStage->GetPositionStep();
    PositionNumofSteps           PStageNumberOfSteps = pStage->GetPositionNumofSteps();
    PositionType                 pStagePosion = pStage->GetPosition();
    float                        pStageDelay = pStage->GetStageDelay();
    VoltageSourceStruct          pVoltageSource1Parameters = pVoltageSource1->GetVoltageParaemetrs();
    VoltageSourceStruct          pVoltageSource2Parameters = pVoltageSource2->GetVoltageParaemetrs();
    VoltageDAQ                   pVolageSource1DAQ = pVoltageSource1->GetVoltageDAQParaemetrs();
    VoltageDAQ                   pVolageSource2DAQ = pVoltageSource2->GetVoltageDAQParaemetrs();



/*
    for (int V1Num = 0; V1Num < pVoltageSource1->GetVoltageDAQParaemetrs(). ){
        for (int V2Num = 0){
            for (int YNum = 0){
                for (int ZNum = 0){
                    for (int XNum = 0){

                    }
                }
            }
        }
    }

*/

}

void MainWindow::on_save_config_clicked()
{
    QString filename = QFileDialog::getSaveFileName();
    if (filename == "") return;

    QFile *F = new QFile(filename, this);
    if (!F->open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"Error happend while trying to open file "<<filename;
        return;
    }

    saveToFile(F);
    delete F;
}

void MainWindow::saveToFile(QFile *file)
{
   Convertor convert;
   QTextStream outFile(file);
    for (auto cInstrument : *fTCTController->GetInstruments()) {
        if(cInstrument->GetInstrumentType() == InstrumentType::TranslationStage){
            if(cInstrument->GetStatus() == StatusType::Ready){
                TranslationStage *pStage = fTCTController->GetTranslationStage();
                SetDAQ_Parametrs_Stage(pStage);


                StageSpeedType               pStageSpeed = pStage->GetStageSpeed();
                PositionStep                 pStageStep   = pStage->GetPositionStep();
                PositionStep                 pStageStepDAQ   = pStage->GetPositionStepDAQ();
                PositionNumofSteps           PStageNumberOfSteps = pStage->GetPositionNumofSteps();
                PositionType                 pStagePosion = pStage->GetPosition();
                PositionType                 pStageStartPosion = pStage->GetStartPosition();
                float                        pStageDelay = pStage->GetStageDelay();

                //Translation Stage write;
                outFile << "[TranslationStage]"<<"\n";
                outFile << "InstrumentType= " << convert.InstrumentEnumToString(pStage->GetInstrumentType()) << "\n";
                outFile << "ConnectionType= " << convert.ConnectionEnumToString(pStage->GetConnectionType()) << "\n";
                outFile << "Adress= " << QString::fromUtf8(pStage->GetAddress().c_str()) << "\n";
                outFile << "Name= " << QString::fromUtf8(pStage->GetName().c_str()) << "\n";
                outFile << "X= " << pStagePosion.x << "\n";
                outFile << "Y= " << pStagePosion.y << "\n";
                outFile << "Z= " << pStagePosion.z << "\n";
                outFile << "XStart= " << pStageStartPosion.x << "\n";
                outFile << "YStart= " << pStageStartPosion.y << "\n";
                outFile << "ZStart= " << pStageStartPosion.z << "\n";
                outFile << "XSpeed= " << pStageSpeed.xSpeed << "\n";
                outFile << "YSpeed= " << pStageSpeed.ySpeed << "\n";
                outFile << "ZSpeed= " << pStageSpeed.zSpeed << "\n";
                outFile << "XStep= "  << pStageStep.xStep << "\n";
                outFile << "YStep= "  << pStageStep.yStep << "\n";
                outFile << "ZStep= "  << pStageStep.zStep << "\n";
                outFile << "XStepDAQ= "  << pStageStepDAQ.xStep << "\n";
                outFile << "YStepDAQ= "  << pStageStepDAQ.yStep << "\n";
                outFile << "ZStepDAQ= "  << pStageStepDAQ.zStep << "\n";
                outFile << "XNumberOfSteps= " << PStageNumberOfSteps.xNumOfSteps << "\n";
                outFile << "YNumberOfSteps= " << PStageNumberOfSteps.yNumOfSteps << "\n";
                outFile << "ZNumberOfSteps= " << PStageNumberOfSteps.zNumOfSteps << "\n";
                outFile << "StageDelay= " << pStageDelay << "\n";
                outFile << "[TranslationStageEnd]" << "\n";


                delete pStage;
            }
        }
        else if(cInstrument->GetInstrumentType() == InstrumentType::VoltageSource1){
            if(cInstrument->GetStatus() == StatusType::Ready){
                 VoltageSource    *pVoltageSource1 = fTCTController->GetVoltageSource1();

                 SetDAQ_Parametrs_Voltage1(pVoltageSource1);

                 VoltageSourceStruct          pVoltageSource1Parameters = pVoltageSource1->GetVoltageParaemetrs();
                 VoltageDAQ                   pVolageSource1DAQ = pVoltageSource1->GetVoltageDAQParaemetrs();


                 //Voltage Source 1 write
                 outFile << "[VoltageSource1]" << "\n";
                 outFile << "InstrumentType= " << convert.InstrumentEnumToString(pVoltageSource1->GetInstrumentType()) << "\n";
                 outFile << "ConnectionType= " << convert.ConnectionEnumToString(pVoltageSource1->GetConnectionType()) << "\n";
                 outFile << "Adress= " << QString::fromUtf8(pVoltageSource1->GetAddress().c_str()) << "\n";
                 outFile << "Name= " << QString::fromUtf8(pVoltageSource1->GetName().c_str()) << "\n";
                 outFile << "Bias= " << pVoltageSource1Parameters.bias << "\n";
                 outFile << "Delay= " << pVoltageSource1Parameters.delay<< "\n";
                 outFile << "IncreaseStep= " << pVoltageSource1Parameters.increase_step << "\n";
                 outFile << "NumOfSteps= " << pVolageSource1DAQ.NumOfSteps << "\n";
                 outFile << "StartVoltage= " << pVolageSource1DAQ.StartVoltage << "\n";
                 outFile << "StepVoltage= " << pVolageSource1DAQ.StepVoltage << "\n";
                 outFile << "[VoltageSource1End]" << "\n";


                delete pVoltageSource1;
            }
        }
        else if(cInstrument->GetInstrumentType() == InstrumentType::VoltageSource2){
            if(cInstrument->GetStatus() == StatusType::Ready){
                 VoltageSource    *pVoltageSource2 = fTCTController->GetVoltageSource2();

                 SetDAQ_Parametrs_Voltage2(pVoltageSource2);

                 VoltageSourceStruct          pVoltageSource2Parameters = pVoltageSource2->GetVoltageParaemetrs();
                 VoltageDAQ                   pVolageSource2DAQ = pVoltageSource2->GetVoltageDAQParaemetrs();

                 //Votage Source 2 write
                 outFile << "[VoltageSource2]" << "\n";
                 outFile << "InstrumentType= " << convert.InstrumentEnumToString(pVoltageSource2->GetInstrumentType()) << "\n";
                 outFile << "ConnectionType= " << convert.ConnectionEnumToString(pVoltageSource2->GetConnectionType()) << "\n";
                 outFile << "Adress= " << QString::fromUtf8(pVoltageSource2->GetAddress().c_str()) << "\n";
                 outFile << "Name= " << QString::fromUtf8(pVoltageSource2->GetName().c_str()) << "\n";
                 outFile << "Bias= " << pVoltageSource2Parameters.bias << "\n";
                 outFile << "Delay= " << pVoltageSource2Parameters.delay<< "\n";
                 outFile << "IncreaseStep= " << pVoltageSource2Parameters.increase_step << "\n";
                 outFile << "NumOfSteps= " << pVolageSource2DAQ.NumOfSteps << "\n";
                 outFile << "StartVoltage= " << pVolageSource2DAQ.StartVoltage << "\n";
                 outFile << "StepVoltage= " << pVolageSource2DAQ.StepVoltage << "\n";
                 outFile << "[VoltageSource2End]" << "\n";


                 delete pVoltageSource2;
            }
        }
        else if(cInstrument->GetInstrumentType() == InstrumentType::Oscilloscope){
            if(cInstrument->GetStatus() == StatusType::Ready){
                Oscilloscope     *pOscilloscope   = fTCTController->GetOscilloscope();
                //Oscilloscope write
                outFile << "[Oscilloscope]" << "\n";
                outFile << "InstrumentType= " << convert.InstrumentEnumToString(pOscilloscope->GetInstrumentType()) << "\n";
                outFile << "ConnectionType= " << convert.ConnectionEnumToString(pOscilloscope->GetConnectionType()) << "\n";
                outFile << "Adress= " << QString::fromUtf8(pOscilloscope->GetAddress().c_str()) << "\n";
                outFile << "Name= " << QString::fromUtf8(pOscilloscope->GetName().c_str()) << "\n";
                outFile << "[OscilloscopeEnd]" << "\n";

                delete pOscilloscope;

            }
        }
    }






















    outFile << "[ENDCONFIG]";
}
