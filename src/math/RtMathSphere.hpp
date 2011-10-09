
#ifndef _RT_MATH_SPHERE_
#define _RT_MATH_SPHERE_

#include <iostream>
#include "RtMathObject.hpp"

namespace Rt
{
  namespace Math
  {
    class Sphere : public Object
    {
    public:
      
      Sphere(const Point&, const Double&);
      ~Sphere();
      Sphere(const Sphere&);
      Sphere& operator=(const Sphere&);

      Point& center();
      Double& rayon();

      const Point& center() const;
      const Double& rayon() const;

      void center(const Point&);
      void rayon(const Double&);
      
      virtual QVector<Point> intersection(const Line&) const;


      friend std::ostream& operator<<(std::ostream&, const Sphere&);
      
    private:

      Point	_center;
      Double	_rayon;
      
    };
  }

}


#endif
