
#ifndef _RT_OBJECT_OBJECT_
#define _RT_OBJECT_OBJECT_

#include "RtCalcColor.hpp"
#include "RtMathObject.hpp"

namespace Rt
{
  namespace Object
  {
    class Object
    {
    public:

      Calc::Color color() const;
      void	  color(const Calc::Color&);

      virtual const Math::Object&	math() const = 0;

    protected:
      
      Object();

    private:
      
      Calc::Color	_color;
    };
  }
}

#endif
