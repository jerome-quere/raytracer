#ifndef _RT_CALC_THREAD_
#define _RT_CALC_THREAD_

#include <QThread>

namespace Rt
{
  namespace Calc
  {
    class ThreadPool;

    class Thread : public QThread
    {
      Q_OBJECT;

    public:

      Thread(ThreadPool&);
      ~Thread();

    protected:

      void run();
      void processTaskQueue();

    private slots:

      void onNewTask();

    private:

      ThreadPool&	_threadPool;
    };
  }
}

#endif
