/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/27/11 19:35:14                                         *
 *  Last update on 11/27/11 21:03:00                                         *
 *                                                                           *
 *****************************************************************************/

#include "RtObjectLight.hpp"

namespace Rt
{
  namespace Object
  {
    Light::Light(const Math::Point& position,
		 const Math::Double& intensity,
		 const Calc::Color& color) :
      _position(position),
      _intensity(intensity),
      _color(color)
    {
    }

    Light::~Light()
    {
    }

    const Math::Point&	Light::position() const
    {
      return (_position);
    }

    const Math::Double&	Light::intensity() const
    {
      return (_intensity);
    }

    const Calc::Color&  Light::color() const
    {
      return (_color);
    }

  }
}
