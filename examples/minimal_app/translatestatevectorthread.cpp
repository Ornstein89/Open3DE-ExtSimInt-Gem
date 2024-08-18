#include "translatestatevectorthread.h"
#include <QDebug>
#include <QUdpSocket>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <QDateTime>
#include <QTime>

TranslateStatevectorThread::TranslateStatevectorThread(const IPC_TYPE ipc_type, QObject *parent)
    : QThread{parent}
    , m_ipc_type(ipc_type)
{

}

TranslateStatevectorThread::~TranslateStatevectorThread()
{
    requestInterruption();
    wait();
}

void TranslateStatevectorThread::run()
{

    switch (m_ipc_type) {
    case IPC_TYPE::UDP:
        run_udp(); //TODO вводить
        break;
    case IPC_TYPE::SHARED_MEMORY:
        run_sharedmem();
        break;
    default:
        return;
    }
}

void TranslateStatevectorThread::run_udp()
{
    QUdpSocket udpsocket;
    QTime time1 = QTime::currentTime();
    while(true){
        if(isInterruptionRequested())
        {
            qDebug() << "isInterruptionRequested()";
            break;
        }

        //TODO моделирование параметров движения
        double phase = remainder(QTime::currentTime().msecsTo(time1) / 1000.0, 2.0 * M_PI );
        double x = sin(phase);
        double y = cos(phase);
        double z = 100.0;
        double statevec[12] = {0.0};
        statevec[0] = x;
        statevec[1] = y;
        statevec[2] = z;
        //TODO отправка
        QByteArray data(reinterpret_cast<char*>(statevec), sizeof(statevec));
        char buffer[1024] = {0};
        sprintf_s(buffer, 1024, "%f %f %f",
                  *reinterpret_cast<double*>(data.data()),
                  *reinterpret_cast<double*>(data.data()+8),
                  *reinterpret_cast<double*>(data.data() + 16));
        qDebug() << buffer;
        udpsocket.writeDatagram(data, QHostAddress::LocalHost, 45454);
        QThread::msleep(100);
    }
}

void TranslateStatevectorThread::run_sharedmem()
{
    const char * sharedmemoryname = "StatevectorSharedMemory";
    shared_memory_object::remove(sharedmemoryname);
    managed_shared_memory segment(create_only, sharedmemoryname, 65536);

    while(true){
        if(isInterruptionRequested())
        {
            qDebug() << "isInterruptionRequested()";
            break;
        }

        //TODO моделирование параметров движения


        //TODO отправка
    }
    shared_memory_object::remove(sharedmemoryname);
}
