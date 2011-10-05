#include <cmath>
#include "RtCalcCalculator.hpp"
#include "RtMathTransformation.hpp"

namespace Rt
{
  namespace Calc
  {
    Math::Point	Calculator::screenPoint(const Object::Eye& eye, 
					unsigned int width, 
					unsigned int height, 
					unsigned int x,
					unsigned int y)
    {
      Math::Point p;
      Math::Transformation trans(eye.position().toVector(), 0, -eye.yAlpha(), -eye.zAlpha());      
      
      p.x() = 100;
      p.y() = -((int)width / 2) + (int)x;
      p.z() = ((int)height / 2) - (int)y;

      p = trans.apply(p);
      return (p);
    }
  }
}
