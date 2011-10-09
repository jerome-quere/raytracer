
#include "RtMathLine.hpp"
#include "RtMathPlane.hpp"

namespace Rt
{
  namespace Math
  {
    Plane::Plane() :
      _a(0),
      _b(0),
      _c(0),
      _d(0)
    {

    }

    Plane::Plane(const Double& a, const Double& b, const Double& c, const Double& d) :
      _a(a),
      _b(b),
      _c(c),
      _d(d)
    {

    }

    Plane::~Plane()
    {
    }

    Plane::Plane(const Plane& obj) :
      _a(obj._a),
      _b(obj._b),
      _c(obj._c),
      _d(obj._d)
    {
    }

    Plane& Plane::operator=(const Plane& obj)
    {
      _a = obj._a;
      _b = obj._b;
      _c - obj._c;
      _d = obj._d;
      return (*this);
    }

    Double& Plane::a()
    {
      return _a;
    }

    Double& Plane::b()
    {
      return _b;
    }

    Double& Plane::c()
    {
      return _c;
    }

    Double& Plane::d()
    {
      return _d;
    }
    
    const Double& Plane::a() const
    {
      return _a;
    }

    const Double& Plane::b() const
    {
      return _b;
    }

    const Double& Plane::c() const
    {
      return _c;
    }

    const Double& Plane::d() const
    {
      return _d;
    }
    
    void Plane::a(const Double& a)
    {
      _a = a;
    }

    void Plane::b(const Double& b)
    {
      _b = b;
    }

    void Plane::c(const Double& c)
    {
      _c = c;
    }

    void Plane::d(const Double& d)
    {
      _d = d;
    }
    
    QVector<Point> Plane::intersection(const Line&line) const
    {
      QVector<Point> points;
      Double solution;
      Double div = _a * line.vector().x() + _b * line.vector().y() + _c * line.vector().z();
      
      if (div == 0)
	{
	  return (points);
	}
      solution = - (_d + _a * line.point().x() + _b * line.point().y() + _c * line.point().z()) / div;
      points.push_back(Point(line.point().x() + solution * line.vector().x(),
			     line.point().y() + solution * line.vector().y(),
			     line.point().z() + solution * line.vector().z()));
      return (points);
    }

    std::ostream& operator<<(std::ostream& stream, const Rt::Math::Plane& plane)
    {
      stream << "Plane {a:" << plane._a << " b:" << plane._b 
	     << " c:" << plane._c << " d:" << plane._d << "} ";
      return (stream);
    }
  }
}



