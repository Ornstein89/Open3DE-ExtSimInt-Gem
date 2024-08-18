#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "translatestatevectorthread.h"
#include "receivevideothread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_cmbIPCMethod_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    TranslateStatevectorThread * m_statevec_thread = nullptr;
    ReceiveVideoThread * m_video_thread = nullptr;
};
#endif // MAINWINDOW_H
