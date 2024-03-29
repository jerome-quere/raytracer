

#include "RtObjectSphere.hpp"

namespace Rt
{
  namespace Object
  {
    Sphere::Sphere(const Math::Sphere& sphere) : 
      _sphere(sphere)
    {
      
    }

    Sphere::~Sphere()
    {

    }

    const Math::Object&	Sphere::math() const
    {
      return(_sphere);
    }
  }
}
