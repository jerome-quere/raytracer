
#include "RtMathVector.hpp"

namespace Rt
{

  namespace Math
  {

    Vector::Vector(const Double& x, const Double& y, const Double& z) :
      _x(x),
      _y(y),
      _z(z)
    {
    }

    Vector::Vector(const Vector& obj) :
      _x(obj._x),
      _y(obj._y),
      _z(obj._z)
    {
    }

    Vector::~Vector()
    {
    }

    Vector& Vector::operator=(const Vector& obj)
    {
      _x = obj._x;
      _y = obj._y;
      _z = obj._z;
      return (*this);
    }

    const Double& Vector::x() const
    {
      return (_x);
    }

    const Double& Vector::y() const
    {
      return (_y);
    }

    const Double& Vector::z() const
    {
      return (_z);
    }

    Vector& Vector::x(const Double& x)
    {
      _x = x;
      return (*this);
    }

    Vector& Vector::y(const Double& y)
    {
      _y = y;
      return (*this);
    }

    Vector& Vector::z(const Double& z)
    {
      _z = z;
      return (*this);
    }

    Vector& Vector::setXYZ(const Double& x, const Double& y, const Double& z)
    {
      _x = x;
      _y = y;
      _z = z;
      return (*this);
    }

    std::ostream& operator<<(std::ostream& stream, const Vector& obj)
    {
      stream << "3DVector{" << obj._x << ", " << obj._y << ", " << obj._z << '}';
      return (stream);
    }

  }
}
