#include "RtCalcThread.hpp"
#include "RtCalcThreadEventListener.hpp"

namespace Rt
{
  namespace Calc
  {

    ThreadEventListener::ThreadEventListener(Thread& thread) :
      _thread(thread)
    {
    }
    
    void ThreadEventListener::onNewTask()
    {
      _thread.processTaskQueue();
    }

  }
}
