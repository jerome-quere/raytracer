
#include <QFile>

#include "RtConfLoader.hpp"
#include "RtMathDouble.hpp"
#include "RtMathPoint.hpp"
#include "RtMathPlane.hpp"
#include "RtMathSphere.hpp"
#include "RtObjectSphere.hpp"
#include "RtObjectPlane.hpp"

namespace Rt
{
  namespace Conf
  {
    Loader::Loader()
    {
    }

    bool Loader::load(const QString& path)
    {
      QFile file (path);

      if (!file.open(QIODevice::ReadOnly))
	{
	  return (false);
	}
      if (!_document.setContent(&file))
	{
	  file.close();
	  return false;
	}
      file.close();
      return (parse()); 
    }

    const QVector<QSharedPointer<Object::Object> >& Loader::objects() const
    {
      return _objects;
    }


    bool Loader::parse()
    {
      QDomNode root = _document.documentElement();
      QDomNode objects = root.toElement().elementsByTagName("objects").at(0);
      
      if (objects.isNull())
	{
	  return (false);
	}

      QDomNodeList objectsList = objects.childNodes();
      
      for (unsigned int i = 0 ; i < objectsList.length() ; i++)
	{
	  if (!parseObject(objectsList.at(i).toElement()))
	    {
	      return (false);
	    }
	}
      return (true);
    }

    bool Loader::parseObject(const QDomElement& object)
    {
      QString type = object.attributes().namedItem("type").nodeValue();
      
      if (type == "sphere")
	{
	  return (parseSphere(object));
	}
      else if (type == "plane")
	{
	  return (parsePlane(object));
	}
      return (false);
    }

    bool Loader::parseSphere(const QDomElement& sphere)
    {
      QDomNode center = sphere.elementsByTagName("center").at(0);
      QDomNode rayon = sphere.elementsByTagName("rayon").at(0);
      
      Math::Double x,y, z, r;
      x = strtol(center.attributes().namedItem("x").nodeValue().toStdString().c_str(), NULL, 10);
      y = strtol(center.attributes().namedItem("y").nodeValue().toStdString().c_str(), NULL, 10);
      z = strtol(center.attributes().namedItem("z").nodeValue().toStdString().c_str(), NULL, 10);
      r = strtol(rayon.nodeValue().toStdString().c_str(), NULL, 10);
      
      Math::Sphere s(Math::Point(x, y, z), r);
      
      QSharedPointer<Object::Object> object(new Object::Sphere(s));
      _objects.push_back(object);
      return (true);
    }

    bool Loader::parsePlane(const QDomElement& plane)
    {
      Math::Double a = strtol(plane.elementsByTagName("a").at(0).nodeValue().toStdString().c_str(), NULL, 10);
      Math::Double b = strtol(plane.elementsByTagName("b").at(0).nodeValue().toStdString().c_str(), NULL, 10);
      Math::Double c = strtol(plane.elementsByTagName("c").at(0).nodeValue().toStdString().c_str(), NULL, 10);
      Math::Double d = strtol(plane.elementsByTagName("d").at(0).nodeValue().toStdString().c_str(), NULL, 10);
      
      Math::Plane p(a, b, c, d);
      
      QSharedPointer<Object::Object> object(new Object::Plane(p));
      _objects.push_back(object);
      return (true);
    }


    
  }
}
