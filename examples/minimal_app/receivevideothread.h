#ifndef RECEIVEVIDEOTHREAD_H
#define RECEIVEVIDEOTHREAD_H

#include <QThread>

#include <boost/interprocess/sync/interprocess_semaphore.hpp>
using namespace boost::interprocess;

struct SharedVideoStructure {
    interprocess_semaphore mutex;
    int width;
    int height;
    uchar data[1024*100];
};

class ReceiveVideoThread : public QThread
{
public:
    enum IPC_TYPE {
        UDP,
        SHARED_MEMORY
    };
    explicit ReceiveVideoThread(const IPC_TYPE ipc_type, QObject *parent = nullptr);

protected:
    void run() override;

private:
    IPC_TYPE m_ipc_type;
};

#endif // RECEIVEVIDEOTHREAD_H
