#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // temprarily disable UDP
    // QStandardItemModel *model =
    //     qobject_cast<QStandardItemModel *>(ui->cmbIPCMethod->model());
    // QStandardItem *item = model->item(1);
    // item->setFlags(item->flags() & ~Qt::ItemIsEnabled);

    on_cmbIPCMethod_currentIndexChanged(ui->cmbIPCMethod->currentIndex());

    m_statevec_thread = new TranslateStatevectorThread(
        TranslateStatevectorThread::IPC_TYPE::UDP);
    QObject::connect(
        m_statevec_thread, &TranslateStatevectorThread::finished,
        [&](){
            ui->btnStart->setText("Start");
        });

    double statevec[12] = {0.0};
    statevec[0] = 1234.0;
    statevec[1] = 4567.0;
    statevec[2] = 100.0;
    //TODO отправка
    QByteArray data(reinterpret_cast<char*>(statevec), sizeof(statevec));
    qDebug() << "sizeof(statevec) = " << sizeof(statevec);
    qDebug() << "data = " << data;
    char buffer[1024] = {0};
    sprintf_s(buffer, 1024, "%f %f %f",
              *reinterpret_cast<double*>(data.data()),
              *reinterpret_cast<double*>(data.data()+8),
              *reinterpret_cast<double*>(data.data() + 16));
    qDebug() << buffer;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    //TODO начало передачи координат
    //TODO начало приёма видео
    if(m_statevec_thread->isRunning()){
        m_statevec_thread->requestInterruption();
    }
    else{
        m_statevec_thread->start();
        ui->btnStart->setText("Stop");
    }
}


void MainWindow::on_cmbIPCMethod_currentIndexChanged(int index)
{
    if(index==1){
        ui->edtUdpAddress->setEnabled(true);
        ui->edtUdpAddress->setText("udp://:1234");
    }else{
        ui->edtUdpAddress->setText("Disabled (for UDP only)");
        ui->edtUdpAddress->setEnabled(false);
    }
}

