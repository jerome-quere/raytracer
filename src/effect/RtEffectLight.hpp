/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/25/11 20:38:42                                         *
 *  Last update on 11/27/11 21:15:09                                         *
 *                                                                           *
 *****************************************************************************/

#ifndef _RTEFFECTLIGHT_HPP_
#define _RTEFFECTLIGHT_HPP_

#include "RtEffectEffect.hpp"
#include "RtConfConf.hpp"

namespace Rt
{
  namespace Effect
  {
    class Light : public Effect
    {
    public:

      Light(const Conf::Conf&);


      virtual Calc::Color apply(const Calc::Intersection&,
				const Calc::Color& color) const;

    private:

      Conf::Conf	_conf;

    };
  }
}


#endif /* _RTEFFECTLIGHT_HPP_ */
