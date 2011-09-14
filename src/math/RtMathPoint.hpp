
#ifndef _RT_MATH_POINT_
#define _RT_MATH_POINT_

#include <iostream>
#include "RtMathDouble.hpp"
#include "RtMathVector.hpp"

namespace Rt
{

  namespace Math
  {

    /**
     * @brief This class represent a point with 3d position.
     */
    class Point
    {

    public:
      Point(const Double& x = 0, const Double& y = 0, const Double& z = 0);
      Point(const Point&);
      ~Point();
      Point& operator=(const Point&);

      const Double& x() const;
      const Double& y() const;
      const Double& z() const;
  
      Point& x(const Double&);
      Point& y(const Double&);
      Point& z(const Double&);
      Point& setXYZ(const Double&, const Double&, const Double&);
  
      Point operator+(const Vector&) const;
      Point operator-(const Vector&) const;
      Vector operator-(const Point&) const;

      friend std::ostream& operator<<(std::ostream&, const Point&);

    private:
      Double _x;
      Double _y;
      Double _z;
    };

  }
}
#endif
