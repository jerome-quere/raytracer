/*****************************************************************************
 *                                                                           *
 *  This file is part of the project raytracer.                              *
 *  Made by Jerome Quere < contact@jeromequere.fr >                          *
 *  Created on     11/24/11 15:19:55                                         *
 *  Last update on 11/24/11 15:39:35                                         *
 *                                                                           *
 *****************************************************************************/

#include "RtMathObject.hpp"
#include <QString>

namespace Rt
{
  namespace Math
  {
    std::ostream& operator<<(std::ostream& stream, const Object& obj)
    {
      stream << obj.toString() << std::endl;
      return (stream);
    }

  }
}
