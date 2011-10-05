
#include "RtMathLine.hpp"

namespace Rt
{

  namespace Math
  {

    Line::Line() :
      _point(),
      _vector()
    {  
    }


    Line::Line(const Point& point, const Vector& vector):
      _point(point),
      _vector(vector)
    {

    }

    Line::Line(const Point& pointA, const Point& pointB):
      _point(pointA)
    {
      _vector = pointB - pointA;
    }

    Line::~Line()
    {
    }

    Line::Line(const Line& obj) :
      _point(obj._point),
      _vector(obj._vector)
    {

    }

    Line& Line::operator=(const Line& obj)
    {
      _point = obj._point;
      _vector = obj._vector;
      return (*this);
    }

    const Point& Line::point() const
    {
      return (_point);
    }

    const Vector& Line::vector() const
    {
      return (_vector);
    }

    Point& Line::point()
    {
      return (_point);
    }

    Vector& Line::vector()
    {
      return (_vector);
    }

    void Line::point(const Point& point)
    {
      _point = point;
    }

    void Line::vector(const Vector& vector)
    {
      _vector = vector;
    }
    
    QVector<Point> Line::operator&(const Object& obj)
    {
      return (obj & *this);
    }

    std::ostream& operator<<(std::ostream& stream, const Line& obj)
    {
      stream << "Line{" << obj._point << ", " << obj._vector << "}";
      return (stream);
    }

  }
}
