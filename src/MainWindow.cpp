#include "include/MainWindow.h"
#include "ui_MainWindow.h"
#include "iostream"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
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

    Convertor convert;
    QFile BaseConfig("BaseConfig.txt");
     if(BaseConfig.open(QIODevice::ReadOnly)){
          ui->DialogWindow->setText("File Opened");
          while (!BaseConfig.atEnd()){
             QString line = BaseConfig.readLine();

             if (line.length() == 0) continue;
             if (line[0] == '/') continue;
             if (line[0] == '\n') continue;

             if (line == "[Instrument]\n"){
                 DAQConfig *pConfig = new DAQConfig;
                 line = BaseConfig.readLine();
                 pConfig->instrument_type = convert.InstrumentStringToEnum(line);
                 line = BaseConfig.readLine();
                 pConfig->connection_type = convert.ConnectionStringToEnum(line);
                 line = BaseConfig.readLine();
                 pConfig->address = line.toUtf8().constData();
                 line = BaseConfig.readLine();
                 pConfig->name = line.toUtf8().constData();
                 fDAQConfigs->push_back(pConfig);

                 continue;

             }
         }
     }
}



MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_Initialize_clicked()
{
    fTCTController->Initialize(fDAQConfigs);
}
