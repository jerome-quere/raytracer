/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/27/11 23:26:24                                         *
 *  Last update on 11/27/11 23:29:55                                         *
 *                                                                           *
 *****************************************************************************/

#ifndef _RTEFFECTREFLEXION_HPP_
#define _RTEFFECTREFLEXION_HPP_

#include "RtEffectEffect.hpp"
#include "RtConfConf.hpp"

namespace Rt
{
  namespace Effect
  {
    class Reflexion : public Effect
    {
    public:

      Reflexion(const Conf::Conf&);

      virtual Calc::Color apply(const Calc::Intersection&,
				const Calc::Color& color) const;

    private:

      Conf::Conf	_conf;

    };
  }
}

#endif /* _RTEFFECTREFLEXION_HPP_ */
