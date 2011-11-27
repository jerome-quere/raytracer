
#ifndef _RT_MATH_PLANE_
#define _RT_MATH_PLANE_

#include "RtMathObject.hpp"

namespace Rt
{
  namespace Math
  {
    class Plane : public Object
    {
    public:

      Plane();
      Plane(const Double&, const Double&, const Double&, const Double&);
      ~Plane();
      Plane(const Plane&);
      Plane& operator=(const Plane&);

      Double& a();
      Double& b();
      Double& c();
      Double& d();

      const Double& a() const;
      const Double& b() const;
      const Double& c() const;
      const Double& d() const;

      void a(const Double&);
      void b(const Double&);
      void c(const Double&);
      void d(const Double&);

      virtual QVector<Point> intersection(const Line&) const;
      virtual Vector	     normalVector(const Point&) const;
      virtual std::string    toString() const;

    private:

      Double	_a;
      Double	_b;
      Double	_c;
      Double	_d;
    };
  }

}


#endif
