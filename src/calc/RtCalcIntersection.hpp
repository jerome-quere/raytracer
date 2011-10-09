#ifndef _RT_CLAC_INTERSECTION_
#define _RT_CLAC_INTERSECTION_

#include "RtObjectObject.hpp"
#include "RtMathLine.hpp"
#include "RtMathPoint.hpp"

namespace Rt
{
  namespace Calc
  {
    class Intersection
    {
    public:
      
      Intersection();
      ~Intersection();
      
      Intersection(Object::Object*, const Math::Line&, const Math::Point&);
      Intersection(const Intersection&);

      Intersection& operator=(const Intersection&);

      Object::Object* object() const;
      const Math::Line&	line() const;
      const Math::Point& point() const;

      bool empty() const;

    private:

      Object::Object*	_object;
      Math::Line	_line;
      Math::Point	_point;

    };
  }
}

#endif
