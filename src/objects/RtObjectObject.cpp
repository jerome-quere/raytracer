#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Object
  {
    const Calc::Color& Object::color() const
    {
      return (_color);
    }

    void	Object::color(const Calc::Color& color)
    {
      _color = color;
    }

    const Math::Double& Object::shininess() const
    {
      return (_shininess);
    }

    void  Object::shininess(const Math::Double& value)
    {
      _shininess = value;
    }

    const Math::Double& Object::reflexion() const
    {
      return (_reflexion);
    }

    void  Object::reflexion(const Math::Double& value)
    {
      _reflexion = value;
    }

    Object::Object() :
      _color(0)
    {
    }
  }
}
