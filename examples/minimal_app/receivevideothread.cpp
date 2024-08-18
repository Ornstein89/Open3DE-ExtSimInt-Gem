#include "receivevideothread.h"

ReceiveVideoThread::ReceiveVideoThread(const IPC_TYPE ipc_type, QObject *parent)
    : QThread{parent}
    , m_ipc_type(ipc_type)
{

}

void ReceiveVideoThread::run()
{

}
