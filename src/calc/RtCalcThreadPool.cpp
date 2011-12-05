#include <QMutexLocker>
#include "RtCalcThreadPool.hpp"

namespace Rt
{
  namespace Calc
  {
    ThreadPool::ThreadPool(unsigned int nbThread) :
      _nbThread(nbThread)
    {
      Thread* thread;

      _threads.reserve(nbThread);
      for (unsigned int i = 0 ; i < _nbThread ; i++)
	{
	  thread = new Thread(*this);
	  thread->start();
	  _threads.push_back(thread);
	}
    }

    ThreadPool::~ThreadPool()
    {
      for (int i = 0 ; i < _threads.size() ; i++)
	{
	  delete _threads[i];
	}
    }

    ThreadTask* ThreadPool::getNextTask()
    {
      QMutexLocker locker(&_mutex);
      if (_queue.empty())
	{
	  return (NULL);
	}
      _nbTaskDone.ref();
      calcPercent();
      return (_queue.dequeue());
    }

    void	ThreadPool::addTask(ThreadTask* task)
    {
      QMutexLocker locker(&_mutex);
      _nbTaskTotal.ref();
      _queue.enqueue(task);
      newTask();
      calcPercent();
    }

    void	ThreadPool::calcPercent()
    {
      int	percent = ((float)_nbTaskDone / (float)_nbTaskTotal) * 100.0;

      if (_percent != percent)
	{
	  _percent = percent;
	  percentUpdate(_percent);
	}
    }

  }
}
