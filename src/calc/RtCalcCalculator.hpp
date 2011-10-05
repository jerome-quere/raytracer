#ifndef _RT_CALC_CALCULATOR_
#define _RT_CALC_CALCULATOR_

#include "RtObjectEye.hpp"
#include "RtMathPoint.hpp"

namespace Rt
{
  namespace Calc
  {
    class Calculator
    {
    public:
      
      static Math::Point screenPoint(const Object::Eye&, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
    };
  }
}

#endif
