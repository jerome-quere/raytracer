/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/25/11 20:57:12                                         *
 *  Last update on 11/27/11 23:41:32                                         *
 *                                                                           *
 *****************************************************************************/

#include "RtEffectLight.hpp"
#include "RtMathConstant.hpp"

namespace Rt
{
  namespace Effect
  {
    Light::Light(const Conf::Conf& conf) :
      _conf(conf)
    {
    }

    Calc::Color Light::apply(const Calc::Intersection& intersection,
			     const Calc::Color& color) const
    {
      Math::Vector normal,light;
      Math::Double alpha , shininess;

      int red = 0,
	green = 0,
	blue = 0;


      normal = intersection.object()->math().normalVector(intersection.point());
      shininess = intersection.object()->shininess();
      for (auto it = _conf.lightBegin() ; it != _conf.lightEnd() ; ++it)
	{
	  light = (*it)->position() - intersection.point();
	  alpha = normal.alpha(light);
	  if (alpha.cos() > 0)
	    {
	      red += (color.red() * (1 - shininess.value()) +
			(*it)->color().red() * shininess.value()) *
		(*it)->intensity().value() * alpha.cos().value();

	      green += (color.green() * (1 - shininess.value()) +
			(*it)->color().green() * shininess.value()) *
		(*it)->intensity().value() * alpha.cos().value();

	      blue += (color.blue() * (1 - shininess.value()) +
		       (*it)->color().blue() * shininess.value()) *
		(*it)->intensity().value() * alpha.cos().value();
	    }
	}

      red = (red > 255) ? (255) : (red);
      green = (green > 255) ? (255) : (green);
      blue = (blue > 255) ? (255) : (blue);

      return (Calc::Color(red, green, blue));
    }

  }
}
