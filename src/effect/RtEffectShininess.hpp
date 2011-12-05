/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     12/04/11 22:35:36                                         *
 *  Last update on 12/05/11 00:47:20                                         *
 *                                                                           *
 *****************************************************************************/

#ifndef _RTEFFECTSHININESS_HPP_
#define _RTEFFECTSHININESS_HPP_

#include "RtConfConf.hpp"
#include "RtCalcIntersection.hpp"

namespace Rt
{
  namespace Effect
  {
    class Shininess
    {
    public:

      Shininess(const Conf::Conf&);


      virtual Calc::Color apply(const Calc::Intersection&,
				const Calc::Color& color) const;

    private:

      Conf::Conf	_conf;

    };
  }
}

#endif /* _RTEFFECTSHININESS_HPP_ */
