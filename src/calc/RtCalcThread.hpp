#ifndef _RT_CALC_THREAD_
#define _RT_CALC_THREAD_

#include <QThread>
#include "RtCalcThreadEventListener.hpp"

namespace Rt
{
  namespace Calc
  {
    class ThreadPool;

    class Thread : public QThread
    {
      friend class ThreadEventListener;

    public:

      Thread(ThreadPool&);
      ~Thread();

    protected:

      void run();
      void processTaskQueue();

    private:

      ThreadPool&	_threadPool;
      ThreadEventListener*	_listener;
    };
  }
}

#endif
