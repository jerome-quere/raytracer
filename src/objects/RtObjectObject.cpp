#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Object
  {
    Calc::Color Object::color() const
    {
      return (_color);
    }

    void	Object::color(const Calc::Color& color)
    {
      _color = color;
    }

    Object::Object() :
      _color(0)
    {
    }
    


  }
}
