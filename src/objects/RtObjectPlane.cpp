
#include "RtObjectPlane.hpp"

namespace Rt
{
  namespace Object
  {
    Plane::Plane(const Math::Plane& plane) : 
      _plane(plane)
    {
    }

    Plane::~Plane()
    {
    }

    const Math::Object&	Plane::math() const
    {
      return (_plane);
    }

  }
}
