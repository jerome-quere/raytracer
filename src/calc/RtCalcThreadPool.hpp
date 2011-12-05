#ifndef _RT_CALC_THREAD_POOL_
#define _RT_CALC_THREAD_POOL_

#include <QQueue>
#include <QMutex>

#include "RtCalcThread.hpp"
#include "RtCalcThreadTask.hpp"

namespace Rt
{
  namespace Calc
  {
    class ThreadPool : public QObject
    {
      Q_OBJECT;

      friend class Thread;

    public:
      ThreadPool(unsigned int _nbThread);
      ~ThreadPool();

      void	addTask(ThreadTask*);


    protected:

      ThreadTask* getNextTask();

    signals:

      void	newTask();
      void	done();
      void	percentUpdate(int percent);

    private:

      void	calcPercent();

      QVector<Thread*>		    _threads;
      unsigned int		    _nbThread;
      QMutex			    _mutex;
      QQueue<ThreadTask *>	    _queue;

      QAtomicInt		    _nbTaskDone;
      QAtomicInt		    _nbTaskTotal;
      QAtomicInt		    _percent;
    };
  }
}

#endif
