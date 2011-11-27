/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/27/11 23:27:17                                         *
 *  Last update on 11/28/11 00:38:48                                         *
 *                                                                           *
 *****************************************************************************/

#include "RtEffectReflexion.hpp"
#include "RtCalcCalculator.hpp"

namespace Rt
{
  namespace Effect
  {
    Reflexion::Reflexion(const Conf::Conf& conf) :
      _conf(conf)
    {
    }


    Calc::Color Reflexion::apply(const Calc::Intersection& inter,
		      const Calc::Color& color) const
    {
      Math::Vector reflexionVect, visionVect, normalVect;
      Math::Line   reflexionLine;
      Calc::Color  reflexionColor;


      if (inter.object()->reflexion() == 0)
	return (color);


      visionVect = inter.line().vector();
      normalVect = inter.object()->math().normalVector(inter.point());
      reflexionVect = visionVect - normalVect * 2 * (visionVect * normalVect);


      Math::Point interPoint = inter.point() + (reflexionVect /
						(reflexionVect.norm() * 1000));
      reflexionLine = Math::Line(interPoint, reflexionVect);
      reflexionColor = Calc::Calculator::pixelColor(_conf, reflexionLine);

      return (reflexionColor * (inter.object()->reflexion()) +
	      color * (Math::Double(1) - inter.object()->reflexion()));

    }

  }
}
