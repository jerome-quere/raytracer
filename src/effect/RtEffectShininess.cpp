/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     12/04/11 22:36:41                                         *
 *  Last update on 12/05/11 01:07:06                                         *
 *                                                                           *
 *****************************************************************************/

#include "RtEffectShininess.hpp"

namespace Rt
{
  namespace Effect
  {
    Shininess::Shininess(const Conf::Conf& conf) :
      _conf(conf)
    {
    }

    Calc::Color Shininess::apply(const Calc::Intersection& inter,
			     const Calc::Color& color) const
    {
      Calc::Color  shininess;
      Math::Double alpha;
      Math::Vector normal, light, reflexionVect, visionVect, normalVect;


      if (inter.object()->reflexion() == 0)
	return (color);

      for (auto it = _conf.lightBegin() ; it != _conf.lightEnd() ; ++it)
	{
	  light = (*it)->position() - inter.point();
	  visionVect = inter.line().vector();
	  normalVect = inter.object()->math().normalVector(inter.point());
	  reflexionVect = visionVect - normalVect * 2 * (visionVect * normalVect);
	  alpha = reflexionVect.alpha(light);
	  if (alpha.cos() > 0)
	    {
	      alpha = alpha.cos().pow(20) * inter.object()->reflexion();
	      shininess.red((alpha * (*it)->color().red()).value());
	      shininess.green((alpha * (*it)->color().green()).value());
	      shininess.blue((alpha * (*it)->color().blue()).value());
	    }
	}
      return (color + shininess);
    }
  }
}
