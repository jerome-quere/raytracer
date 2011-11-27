/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/27/11 19:30:22                                         *
 *  Last update on 11/27/11 20:28:03                                         *
 *                                                                           *
 *****************************************************************************/

#ifndef _RT_OBJECT_LIGHT_HPP_
#define _RT_OBJECT_LIGHT_HPP_

#include "RtMathPoint.hpp"
#include "RtMathDouble.hpp"
#include "RtCalcColor.hpp"

namespace Rt
{
  namespace Object
  {
    class Light
    {

    public:

      Light(const Math::Point&, const Math::Double&, const Calc::Color&);
      ~Light();

      const Math::Point&	position() const;
      const Math::Double&	intensity() const;
      const Calc::Color&	color() const;

    private:

      Math::Point	_position;
      Math::Double	_intensity;
      Calc::Color	_color;
    };
  }
}


#endif /* _RTOBJECTLIGHT_HPP_ */
