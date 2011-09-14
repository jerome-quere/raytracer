
#include "RtMathPoint.hpp"

namespace Rt
{

  namespace Math
  {

    Point::Point(const Double& x, const Double& y, const Double& z) :
      _x(x),
      _y(y),
      _z(z)
    {
      std::cout << "Point Construct" << std::endl;
    }

    Point::Point(const Point& obj) :
      _x(obj._x),
      _y(obj._y),
      _z(obj._z)
    {
    }

    Point::~Point()
    {
      std::cout << "Destruct " << std::endl;
    }

    Point& Point::operator=(const Point& obj)
    {
      _x = obj._x;
      _y = obj._y;
      _z = obj._z;
      return (*this);
    }

    const Double& Point::x() const
    {
      return (_x);
    }

    const Double& Point::y() const
    {
      return (_y);
    }

    const Double& Point::z() const
    {
      return (_z);
    }

    Point& Point::x(const Double& x)
    {
      _x = x;
      return (*this);
    }

    Point& Point::y(const Double& y)
    {
      _y = y;
      return (*this);
    }

    Point& Point::z(const Double& z)
    {
      _z = z;
      return (*this);
    }

    Point& Point::setXYZ(const Double& x, const Double& y, const Double& z)
    {
      _x = x;
      _y = y;
      _z = z;
      return (*this);
    }


    Point Point::operator+(const Vector& vec) const
    {
      Point res;
  
      res.x(_x + vec.x());
      res.y(_y + vec.y());
      res.z(_z + vec.z());
      return (res);
    }

    Point Point::operator-(const Vector& vec) const
    {
      Point res;
  
      res.x(_x - vec.x());
      res.y(_y - vec.y());
      res.z(_z - vec.z());
      return (res);
    }


    Vector Point::operator-(const Point& point) const
    {
      Vector res;
  
      res.x(_x - point.x());
      res.y(_y - point.y());
      res.z(_z - point.z());
      return (res);
    }


    std::ostream& operator<<(std::ostream& stream, const Point& obj)
    {
      stream << "3DPoint{" << obj._x << ", " << obj._y << ", " << obj._z << '}';
      return (stream);
    }

  }
}
