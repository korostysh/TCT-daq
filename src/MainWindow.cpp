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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fDAQConfigs = new std::vector<DAQConfig*>;
    fTCTController = new TCTController;

    LoadConfig();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadConfig()
{
    Convertor convert;
    QFile BaseConfig("BaseConfig.txt");

    if(BaseConfig.open(QIODevice::ReadOnly)){
        ui->DialogWindow->setText("File Opened");

        for(auto config_word: *fDAQConfigs) delete config_word;
        fDAQConfigs->clear();

        while (!BaseConfig.atEnd())
        {
            QString line = BaseConfig.readLine();

            if (line.length() == 0) continue;
            if (line[0] == '/') continue;
            if (line[0] == '\n') continue;

            if (line == "[Instrument]\n")
            {
                DAQConfig *cConfig = new DAQConfig;
                line = BaseConfig.readLine();
                cConfig->instrument_type = convert.InstrumentStringToEnum(line);
                line = BaseConfig.readLine();
                cConfig->connection_type = convert.ConnectionStringToEnum(line);
                line = BaseConfig.readLine();
                cConfig->address = line.toUtf8().constData();
                line = BaseConfig.readLine();
                cConfig->name = line.toUtf8().constData();
                fDAQConfigs->push_back(cConfig);

                continue;
            }
        }

        FillHardware();
    }
    else
    {
        ui->DialogWindow->setText("Error: config file not found");
    }
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
        case InstrumentType::VoltageSource:
            type = "VoltageSource";
            break;
        case InstrumentType::Osciloscope:
            type = "Osciloscope";
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
    QString QStr = QString::fromStdString(ss.str());
    ui->DialogWindow->setText(QStr);
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

    QString QStr = QString::fromStdString(ss.str());
    ui->DialogWindow->setText(QStr);


}

void MainWindow::on_MoveXMinus_clicked()
{

}

void MainWindow::on_MoveXPlus_clicked()
{
    ui->XAxisPosition->setValue(ui->XAxisPosition->value()+ui->XStep->value());
    ui->SetCoordinate->clicked(true);
}

void MainWindow::on_MoveYPlus_clicked()
{
    ui->YAxisPosition->setValue(ui->YAxisPosition->value()+ui->YStep->value());
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
}

void MainWindow::on_load_config_clicked()
{
    LoadConfig();
}
