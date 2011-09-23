
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

    bool Loader::parseDouble(const QDomElement& node, Math::Double& value)
    {
      QDomText text = node.firstChild().toText();

      if (text.isNull())
	{
	  return (false);
	}
      value = strtol(text.nodeValue().toStdString().c_str(), NULL, 10);
      return (true);
    }

    bool Loader::parsePoint(const QDomElement& node, Math::Point& point)
    {
      Math::Double x, y, z;

      QDomElement xNode = node.elementsByTagName("x").at(0).toElement();
      QDomElement yNode = node.elementsByTagName("y").at(0).toElement();
      QDomElement zNode = node.elementsByTagName("z").at(0).toElement();
      
      if (parseDouble(xNode, x) && parseDouble(yNode, y) && parseDouble(zNode, z))
	{
	  point.setXYZ(x, y, z);
	  return (true);
	}
      return (false);
    }

    bool Loader::parseSphere(const QDomElement& sphere)
    {
      Math::Point  c;
      Math::Double r;

      QDomElement center = sphere.elementsByTagName("center").at(0).toElement();
      QDomElement rayon = sphere.elementsByTagName("rayon").at(0).toElement();
      
      if (parsePoint(center, c) && parseDouble(rayon, r))
	{
	  Math::Sphere s(c, r);
	  std::cout << s << std::endl;
	  QSharedPointer<Object::Object> object(new Object::Sphere(s));

	  _objects.push_back(object);
	  return (true);
	}
      return (false);
    }

    bool Loader::parsePlane(const QDomElement& plane)
    {
      Math::Double a, b, c, d;
      
      QDomElement aNode = plane.elementsByTagName("a").at(0).toElement();
      QDomElement bNode = plane.elementsByTagName("b").at(0).toElement();
      QDomElement cNode = plane.elementsByTagName("c").at(0).toElement();
      QDomElement dNode = plane.elementsByTagName("d").at(0).toElement();
      
      if (parseDouble(aNode, a) && parseDouble(bNode, b) && 
	  parseDouble(cNode, c) && parseDouble(dNode, d))
	{
	  Math::Plane p(a, b, c, d);
	  std::cout << p << std::endl;
	  QSharedPointer<Object::Object> object(new Object::Plane(p));
	  
	  _objects.push_back(object);
	  return (true);
	}
      return (false);
    }    
  }
}
