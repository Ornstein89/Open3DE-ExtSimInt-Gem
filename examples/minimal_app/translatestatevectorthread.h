#ifndef TRANSLATESTATEVECTORTHREAD_H
#define TRANSLATESTATEVECTORTHREAD_H

#include <QThread>

#include <boost/interprocess/sync/interprocess_semaphore.hpp>
using namespace boost::interprocess;

struct SharedStateVectorStructure {
    interprocess_semaphore mutex;
    double statevec[12];
};


class TranslateStatevectorThread : public QThread
{
public:
    enum IPC_TYPE {
        UDP,
        SHARED_MEMORY
    };
    explicit TranslateStatevectorThread(const IPC_TYPE ipc_type, QObject *parent = nullptr);
    ~TranslateStatevectorThread();

protected:
    void run() override;
    void run_udp();
    void run_sharedmem();
private:
    IPC_TYPE m_ipc_type;
};

#endif // TRANSLATESTATEVECTORTHREAD_H
