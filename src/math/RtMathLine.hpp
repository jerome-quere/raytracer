
#ifndef _RT_MATH_LINE_
#define _RT_MATH_LINE_

#include <iostream>

#include "RtMathPoint.hpp"
#include "RtMathVector.hpp"
#include "RtMathObject.hpp"

namespace Rt
{

  namespace Math
  {

    /**
     * @brief this class represent a straight line in 3d
     */
    class Line
    {

    public:
      Line();
      Line(const Point&, const Vector&);
      Line(const Point&, const Point&);
      ~Line();
      Line(const Line&);
      Line& operator=(const Line&);

      const Point& point() const;
      const Vector& vector() const;
      Point& point();
      Vector& vector();
      void point(const Point&);
      void vector(const Vector&);
      
      friend std::ostream& operator<<(std::ostream&, const Line&);

    private:
  
      Point  _point;
      Vector _vector;

    };

  }
}
#endif
