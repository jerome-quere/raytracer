#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Object
  {
    int Object::color() const
    {
      return (_color);
    }

    Object::Object() :
      _color(0)
    {
    }
    
  }
}
