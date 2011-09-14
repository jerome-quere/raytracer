
#ifndef _RT_MATH_SPHERE_
#define _RT_MATH_SPHERE_

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
      
      virtual QVector<Point> operator&(const Line&) const;



    private:

      Point	_center;
      Double	_rayon;
      
    };
  }

}


#endif
