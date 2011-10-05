#include "RtCalcThread.hpp"
#include "RtCalcThreadPool.hpp"
#include "RtCalcThreadEventListener.hpp"

namespace Rt
{
  namespace Calc
  {
    Thread::Thread(ThreadPool& threadPool) :
      _threadPool(threadPool),
      _listener(NULL)
    {

    }
    
    Thread::~Thread()
    {
      delete _listener;
    }

    void Thread::run()
    {
      _listener = new ThreadEventListener(*this);
      _listener->connect(&_threadPool, SIGNAL(newTask()), SLOT(onNewTask()));
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

  }
}
