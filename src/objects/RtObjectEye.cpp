#include <cmath>
#include "RtObjectEye.hpp"

namespace Rt
{
  namespace Object
  {
    Eye::Eye(const Math::Point& position, const Math::Vector& direction) :
      _position(position),
      _direction(direction)
    {
    }

    Eye::~Eye()
    {
    }

    Eye::Eye(const Eye& obj) :
      _position(obj._position),
      _direction(obj._direction)
    {
    }

    const Math::Vector& Eye::direction() const
    {
      return (_direction);
    }

    const Math::Point& Eye::position() const
    {
      return (_position);
    }

    const Math::Double Eye::yAlpha() const
    {
      if (_direction.z() == 0)
	{
	  return (0);
	}
      
      if (_direction.x() == 0)
	{
	  if (_direction.z() < 0)
	    return (-M_PI_2);
	  else
	    return (M_PI_2);
	}

      return (atan((_direction.z() / _direction.x()).value()));      
    }

    const Math::Double Eye::zAlpha() const
    {

      if (_direction.y() == 0)
	{
	  return (0);
	}
      
      if (_direction.x() == 0)
	{
	  if (_direction.y() > 0)
	    return (-M_PI_2);
	  else
	    return (M_PI_2);
	}

      return (atan((_direction.y() / _direction.x()).value()));
    }
   
  }
}
