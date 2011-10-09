#ifndef _RT_CALC_CALCULATOR_
#define _RT_CALC_CALCULATOR_

#include "RtObjectEye.hpp"
#include "RtMathPoint.hpp"
#include "RtCalcColor.hpp"
#include "RtConfConf.hpp"
#include "RtMathLine.hpp"
#include "RtCalcIntersection.hpp"

namespace Rt
{
  namespace Calc
  {
    class Calculator
    {
    public:
      
      static Math::Point screenPoint(const Object::Eye&, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
      static Color pixelColor(const Conf::Conf& conf, const Math::Line& line);
      static Intersection closestObject(const Conf::Conf conf, const Math::Line& line);
      
    };
  }
}

#endif
