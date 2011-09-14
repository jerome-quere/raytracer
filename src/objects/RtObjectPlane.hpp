
#ifndef _RT_OBJECT_PLANE_
#define _RT_OBJECT_PLANE_

#include "RtObjectObject.hpp"
#include "RtMathPlane.hpp"

namespace Rt
{
  namespace Object
  {
    class Plane : public Object
    {
    public:
      
      Plane(const Math::Plane&);
      ~Plane();
     
    private:
      
      Math::Plane	_plane;
      
    };
  }
}

#endif
