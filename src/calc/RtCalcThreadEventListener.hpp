#ifndef _RT_CALC_THREAD_EVENT_LISTENER_
#define _RT_CALC_THREAD_EVENT_LISTENER_

#include <QObject>

namespace Rt
{
  namespace Calc
  {
    class Thread;

    class ThreadEventListener : public QObject
    {
      Q_OBJECT;

      friend class Thread;

      private slots:

	void onNewTask();
      
      private:

	ThreadEventListener(Thread&);

	Thread&	_thread;
    };
  } 
}

#endif
