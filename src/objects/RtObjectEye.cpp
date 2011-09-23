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

  }
}
