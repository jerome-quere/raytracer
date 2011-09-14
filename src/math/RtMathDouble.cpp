
#include <cmath>
#include "RtMathDouble.hpp"

namespace Rt
{

  namespace Math
  {
    const double Double::error_margin = 0.00000001;

    Double::Double(double value) :
      _value(value)
    {  
    }

    Double::~Double()
    {
    }

    Double::Double(const Double& obj) :
      _value(obj._value),
      _squareFill(obj._squareFill),
      _square(obj._square),
      _sqrtFill(obj._sqrtFill),
      _sqrt(obj._sqrt)
    {
    }

    Double& Double::operator=(const Double& obj)
    {
      _value = obj._value;
      _squareFill = obj._squareFill;
      _square = obj._square;
      _sqrtFill = obj._sqrtFill;
      _sqrt = obj._sqrt;
      return (*this);
    }

    Double& Double::operator=(const double& value)
    {
      _value = value;
      return (*this);
    }

    Double Double::operator+(const Double& obj) const
    {
      return (Double(_value + obj._value));
    }

    Double Double::operator-(const Double& obj) const
    {
      return (Double(_value - obj._value));
    }

    Double Double::operator-() const
    {
      return (Double(-_value));
    }

    Double Double::operator/(const Double& obj) const
    {
      return (Double(_value / obj._value));
    }

    Double Double::operator*(const Double& obj) const
    {
      return (Double(_value * obj._value));
    }

    bool Double::operator!=(const Double& obj) const
    {
      return (!operator==(obj));
    }

    bool Double::operator==(const Double& obj) const
    {
      double dif = _value - obj._value;
  
      if (dif > Double::error_margin || dif < -Double::error_margin)
	{
	  return (false);
	}
      return (true);
    }

    bool Double::operator<=(const Double& obj) const
    {
      if (_value < obj._value || operator==(obj))
	{
	  return (true);
	}
      return(false);
    }

    bool Double::operator<(const Double& obj) const
    {
      if (_value < obj._value && operator!=(obj))
	{
	  return (true);
	}
      return(false);
    }

    bool Double::operator>=(const Double& obj) const
    {
      if (_value > obj._value || operator==(obj))
	{
	  return (true);
	}
      return(false);
    }

    bool Double::operator>(const Double& obj) const
    {
      if (_value > obj._value && operator!=(obj))
	{
	  return (true);
	}
      return(false);
    }

    Double Double::pow(int powNum) const
    {
      if (powNum != 2)
	{
	  return (::pow(_value, powNum));
	}
      if (!_squareFill)
	{
	  _square = _value * _value;
	  _squareFill = true;
	}
      return _squareFill;
    }

    Double Double::sqrt() const
    {
      if (!_sqrtFill)
	{
	  _sqrt = ::sqrt(_value);
	  _sqrtFill = true;
	}
      return (_sqrt);
    }

    Double operator*(const double& nb1, const Double& nb2)
    {
      return (Double(nb1 * nb2._value));
    }

    std::ostream& operator<<(std::ostream& stream, const Double& obj)
    {
      stream << obj._value;
      return (stream);
    }

  }
}