#ifndef _RT_MATH_TRANSLATION_
#define _RT_MATH_TRANSLATION_

#include "RtMathVector.hpp"
#include "RtMathPoint.hpp"

namespace Rt
{
  namespace Math
  {
    class Transformation
    {

    public:
    
      Transformation(const Vector& = Vector(), const Double& xAlpha = 0, const Double& yAlpha = 0, const Double& zAlpha = 0);
      ~Transformation();
      
      Point	apply(const Point&) const;
      Point	reverse(const Point&) const;


    private:
      
      Point	rotateX(const Double& xAlpha, const Point& point) const;
      Point	rotateY(const Double& yAlpha, const Point& point) const;
      Point	rotateZ(const Double& zAlpha, const Point& point) const;

      Vector	_vector;
      Double	_xAlpha;
      Double	_yAlpha;
      Double	_zAlpha;
            
    };
  }
}

#endif
