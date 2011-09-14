
#ifndef _RT_MATH_OBJECT_
#define _RT_MATH_OBJECT_

#include <QVector>
#include "RtMathPoint.hpp"

namespace Rt
{
  namespace Math
  {
    class Line;

    class Object
    {
    public:
      virtual QVector<Point> operator&(const Line&) const = 0;
    };
   
  }
}

#endif
