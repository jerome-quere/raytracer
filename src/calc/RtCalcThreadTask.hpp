#ifndef _RT_CALC_THREAD_TASK_
#define _RT_CALC_THREAD_TASK_

#include "RtMathPoint.hpp"
#include "RtMathLine.hpp"
#include "RtCalcColor.hpp"
#include "RtConfConf.hpp"

namespace Rt
{
  namespace Calc
  {
    class ThreadTask
    {
    public:

      ThreadTask(const Math::Line&, const Conf::Conf&, Color&);

      void	run();
      void	lastTask(bool);
      bool       lastTask() const;

    private:

      Math::Line	_line;
      const Conf::Conf&	_conf;
      Color&		_color;
      bool		_lastTask;

    };
  }
}

#endif
