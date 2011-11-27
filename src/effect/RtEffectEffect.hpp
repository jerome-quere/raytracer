/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/25/11 20:40:34                                         *
 *  Last update on 11/25/11 21:10:37                                         *
 *                                                                           *
 *****************************************************************************/

#ifndef _RTEFFECTEFFECT_HPP_
#define _RTEFFECTEFFECT_HPP_

#include "RtCalcColor.hpp"
#include "RtCalcIntersection.hpp"

namespace Rt
{
  namespace Effect
  {
    class Effect
    {
    public:

      virtual ~Effect() {};

      virtual Calc::Color apply(const Calc::Intersection&,
				const Calc::Color& color) const = 0;

    };
  }
}


#endif /* _RTEFFECTEFFECT_HPP_ */
