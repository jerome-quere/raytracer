#include <cmath>
#include "RtCalcCalculator.hpp"
#include "RtMathConstant.hpp"
#include "RtMathTransformation.hpp"
#include "RtCalcIntersection.hpp"
#include "RtEffectLight.hpp"
#include "RtEffectReflexion.hpp"
#include "RtEffectShininess.hpp"

#include <QDebug>
namespace Rt
{
  namespace Calc
  {
    Math::Point	Calculator::screenPoint(const Object::Eye& eye,
					unsigned int width,
					unsigned int height,
					unsigned int x,
					unsigned int y)
    {
      Math::Point p;
      Math::Transformation trans(eye.position().toVector(), 0, -eye.yAlpha(), -eye.zAlpha());      

      p.x() = (width / 2) / (sin(Math::PI4.value()));
      p.y() = -((int)width / 2) + (int)x;
      p.z() = ((int)height / 2) - (int)y;

      p = trans.apply(p);
      return (p);
    }

    Color Calculator::calcEffect(const Conf::Conf& conf,
				 const Intersection& intersection)
    {
      Effect::Light  light(conf);
      Effect::Shininess  shininess(conf);
      Effect::Reflexion reflexion(conf);

      return (shininess.apply(intersection,
	      reflexion.apply(intersection,
	      light.apply(intersection,
   	      intersection.object()->color()))));
    }

    Color Calculator::pixelColor(const Conf::Conf& conf, const Math::Line& line)
    {
      Intersection intersection;

      intersection = closestObject(conf, line);
      if (!intersection.empty())
	{
	  return (calcEffect(conf, intersection));
	}
      return (Color());
    }

    Intersection Calculator::closestObject(const Conf::Conf conf, const Math::Line& line)
    {
      Conf::Conf::ObjectIterator it = conf.objectBegin();
      QVector<Math::Point> inter;
      Object::Object*	   object;
      Math::Double	   closestDistance;
      Math::Vector	   interVector;
      Intersection	   intersection;

      closestDistance = -1;
      while (it != conf.objectEnd())
	{
	  object = it->data();
	  inter = object->math().intersection(line);
	  for (int i = 0 ; i < inter.size() ; i++)
	    {
	      interVector = inter[i] - line.point();

	      if (interVector * line.vector() > 0 &&
		  (closestDistance < 0 || interVector.norm() < closestDistance))
		{
		  closestDistance = interVector.norm();
		  intersection = Intersection(object, line, inter[i]);
		}
	    }
	  it++;
	}
      return (intersection);
    }
  }
}
