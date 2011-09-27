
#ifndef _RT_OBJECT_EYE_
#define _RT_OBJECT_EYE_

#include "RtMathPoint.hpp"
#include "RtMathVector.hpp"

namespace Rt
{
  namespace Object
  {
    class Eye
    {

    public:
      Eye(const Math::Point&, const Math::Vector&);
      ~Eye();
      Eye(const Eye&);
     
    private:
      
      Math::Point	_position;
      Math::Vector	_direction;
 
    };
  }
}

#endif
