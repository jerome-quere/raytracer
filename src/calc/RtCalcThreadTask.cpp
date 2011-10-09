#include "RtCalcThreadTask.hpp"
#include "RtCalcCalculator.hpp"

namespace Rt
{
  namespace Calc
  {
    ThreadTask::ThreadTask(const Math::Line& line, const Conf::Conf& conf, Color& color) :
      _line(line),
      _conf(conf),
      _color(color),
      _lastTask(false)
    {
    }

    void	ThreadTask::run()
    {
      _color = Calculator::pixelColor(_conf, _line);
    }
    
    void	ThreadTask::lastTask(bool b)
    {
      _lastTask = b;
    }

    bool	ThreadTask::lastTask() const
    {
      return _lastTask;
    }

  }
}
