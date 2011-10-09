#include "RtCalcIntersection.hpp"

namespace Rt
{
  namespace Calc
  {
    Intersection::Intersection() :
      _object(NULL)
    {
    }

    Intersection::~Intersection()
    {
    }


    Intersection::Intersection(Object::Object* object, const Math::Line& line, const Math::Point& point) :
      _object(object),
      _line(line),
      _point(point)
    {
    }
    
    Intersection::Intersection(const Intersection& obj) :
      _object(obj._object),
      _line(obj._line),
      _point(obj._point)
    {
    }

    Intersection& Intersection::operator=(const Intersection& obj)
    {
      _object = obj._object;
      _line = obj._line;
      _point = obj._point;
      return (*this);
    }

    Object::Object* Intersection::object() const
    {
      return (_object);
    }

    const Math::Line&	Intersection::line() const
    {
      return (_line);
    }

    const Math::Point& Intersection::point() const
    {
      return (_point);
    }

    bool Intersection::empty() const
    {
      return (_object == NULL);
    }

  }
}
