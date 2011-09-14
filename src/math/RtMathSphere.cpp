
#include "RtMathSphere.hpp"
#include "RtMathLine.hpp"
#include "RtMathVector.hpp"
#include "RtMathEquationSolver.hpp"

namespace Rt
{
  namespace Math
  {
        Sphere::Sphere(const Point& center, const Double& rayon) :
      _center(center),
      _rayon(rayon)
    {
    }

    Sphere::~Sphere()
    {
    }

    Sphere::Sphere(const Sphere& obj) :
      _center(obj._center),
      _rayon(obj._rayon)
    {
    }

    Sphere& Sphere::operator=(const Sphere& obj)
    {
      _center = obj._center;
      _rayon = obj._rayon;
      return (*this);
    }

    Point& Sphere::center()
    {
      return _center;
    }

    Double& Sphere::rayon()
    {
      return _rayon;
    }
    
    const Point& Sphere::center() const
    {
      return _center;
    }

    const Double& Sphere::rayon() const
    {
      return  _rayon;
    }
    
    void Sphere::center(const Point& center)
    {
      _center = center;
    }

    void Sphere::rayon(const Double& rayon)
    {
      _rayon = rayon;
    }

    QVector<Point> Sphere::operator&(const Line& line) const
    {
      QVector<Point> points;

      Double a = line.vector().x().pow(2) + line.vector().y().pow(2) + line.vector().z().pow(2);
      Double b = 2 * (line.vector().x() * (line.point().x() - _center.x()) + 
		      line.vector().y() * (line.point().y() - _center.y()) +
		      line.vector().z() * (line.point().z() - _center.z()));
      Double c = _center.x().pow(2) + _center.y().pow(2) + _center.z().pow(2) - 2 * (line.point().x() * _center.x() -
										     line.point().y() * _center.y() -
										     line.point().z() * _center.z()) - _rayon.pow(2);
      QVector<Double> solution = EquationSolver::secondDegree(a, b, c);
      
      if (solution.size() >= 1)
	{
	  points.push_back(Point(line.point().x() + solution[0] * line.vector().x(),
				 line.point().y() + solution[0] * line.vector().y(),
				 line.point().z() + solution[0] * line.vector().z()));
	}
      if (solution.size() >= 2)
	{
	  points.push_back(Point(line.point().x() + solution[1] * line.vector().x(),
				 line.point().y() + solution[1] * line.vector().y(),
				 line.point().z() + solution[1] * line.vector().z()));
	}
      return (points);
    }
  }
}