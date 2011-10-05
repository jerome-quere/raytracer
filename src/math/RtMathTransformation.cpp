#include "RtMathTransformation.hpp"
#include <cmath>
namespace Rt
{
  namespace Math
  {
    Transformation::Transformation(const Vector& vector, const Double& xAlpha, 
				   const Double& yAlpha, const Double& zAlpha) :
      _vector(vector),
      _xAlpha(xAlpha),
      _yAlpha(yAlpha),
      _zAlpha(zAlpha)
    {
    }

    Transformation::~Transformation()
    {
    }

    Point	Transformation::apply(const Point& point) const
    {
       Point p = point;

      p = rotateX(_xAlpha, p);
      p = rotateY(_yAlpha, p);
      p = rotateZ(_zAlpha, p);

      return (p + _vector);
    }
    
    Point	Transformation::reverse(const Point& point) const
    {
      Point p = point - _vector;
            
      p = rotateZ(-_zAlpha, p);
      p = rotateY(-_yAlpha, p);
      p = rotateX(-_xAlpha, p);

      return (p);
    }

    
    Point	Transformation::rotateX(const Double& xAlpha, const Point& point) const
    {
      Point p;

      p.x() = point.x();
      p.y() = point.y() * xAlpha.cos() - point.z() * xAlpha.sin();
      p.z() = point.y() * xAlpha.sin() + point.z() * xAlpha.cos();

      return (p);
    }

    Point	Transformation::rotateY(const Double& yAlpha, const Point& point) const
    {
      Point p;
      
      p.x() = point.z() * yAlpha.sin() + point.x() * yAlpha.cos();
      p.y() = point.y();
      p.z() = point.z() * yAlpha.cos() - point.x() * yAlpha.sin();
      return (p);
    }

    Point	Transformation::rotateZ(const Double& zAlpha, const Point& point) const
    {
      Point p;
      
      p.x() = point.x() * zAlpha.cos() - point.y() * zAlpha.sin();
      p.y() = point.x() * zAlpha.sin() + point.y() * zAlpha.cos();
      p.z() = point.z();
      return (p);
    }


  }
}
