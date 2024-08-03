#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <boost/interprocess/sync/interprocess_semaphore.hpp>

#include <QStandardItemModel>
using namespace boost::interprocess;

struct SharedMemoryBuffer {
    interprocess_semaphore mutex;
    int width;
    int height;
    uchar data[1024*100];
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // temprarily disable UDP
    QStandardItemModel *model =
        qobject_cast<QStandardItemModel *>(ui->cmbIPCMethod->model());
    QStandardItem *item = model->item(1);
    item->setFlags(item->flags() & ~Qt::ItemIsEnabled);

    on_cmbIPCMethod_currentIndexChanged(ui->cmbIPCMethod->currentIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    //TODO начало передачи координат
    //TODO начало приёма видео
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

