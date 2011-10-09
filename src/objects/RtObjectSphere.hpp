
#ifndef _RT_OBJECT_SPHERE_
#define _RT_OBJECT_SPHERE_

#include "RtMathSphere.hpp"
#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Object
  {
    class Sphere : public Object
    {
    public:
      
      Sphere(const Math::Sphere&);
      ~Sphere();
      
      const Math::Object&	math() const;
     
    private:
      
      Math::Sphere	_sphere;
      
    };
  }
}

#endif
