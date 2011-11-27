
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
      virtual QVector<Point> intersection(const Line&) const = 0;
      virtual Vector	     normalVector(const Point&) const = 0;
      virtual std::string    toString() const = 0;

      friend std::ostream& operator<<(std::ostream&, const Object&);

    };
  }
}

#endif
