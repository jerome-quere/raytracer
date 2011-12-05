#include "RtCalcThread.hpp"
#include "RtCalcThreadPool.hpp"

namespace Rt
{
  namespace Calc
  {
    Thread::Thread(ThreadPool& threadPool) :
      _threadPool(threadPool)
    {
      QObject::moveToThread(this);
    }

    Thread::~Thread()
    {
    }

    void Thread::run()
    {
      QObject::connect(&_threadPool, SIGNAL(newTask()),
		       this, SLOT(onNewTask()));
      exec();
    }

    void Thread::processTaskQueue()
    {
      ThreadTask *task;

      while ((task = _threadPool.getNextTask()))
	{
	  task->run();
	  if (task->lastTask())
	    {
	      _threadPool.done();
	    }
	  delete task;
	}
    }

    void Thread::onNewTask()
    {
      processTaskQueue();
    }

  }
}
