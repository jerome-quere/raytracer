
#include <QFile>
#include <QHash>

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
    
    Conf  Loader::conf() const
    {
      return (_conf);
    }


     bool Loader::parse()
     {
       QDomElement root = _document.documentElement().toElement();

       QHash<QString, bool (Loader::*)(const QDomElement&) > actions;
       actions["objects"] = &Loader::parseObjects;
       actions["eye"] = &Loader::parseEye;
       actions["width"] = &Loader::parseWidth;
       actions["height"] = &Loader::parseHeight;
       actions["3d"] = &Loader::parse3d;
       QDomNodeList childs = root.childNodes();

       for (unsigned int i = 0 ; i < childs.length() ; i++)
	 {
	   if (actions.find(childs.at(i).nodeName()) != actions.end())
	     {
	       bool (Loader::*t)(const QDomElement&) = actions[childs.at(i).nodeName()];
	       if (!(this->*t)(childs.at(i).toElement()))
		 {
		   return (false);
		 }
	     }
	 }       
       return (true);
     }
    
    bool Loader::parseWidth(const QDomElement& width)
    {
      Math::Double w;

      if (!parseDouble(width, w))
	{
	  return (false);
	}
      _conf._width = w.value();
      return(true);
    }

    bool Loader::parseHeight(const QDomElement& height)
    {
      Math::Double h;

      if (!parseDouble(height, h))
	{
	  return (false);
	}
      _conf._height = h.value();
      return(true);
    }    
    
    bool Loader::parse3d(const QDomElement& node)
    {
      bool enable;
      
      if (parseBool(node, enable))
	{
	  return (false);
	}
      _conf._3d = enable;
      return (true);
    }

    bool Loader::parseEye(const QDomElement& eye)
     {
       QDomElement position = eye.elementsByTagName("position").at(0).toElement();
       QDomElement direction = eye.elementsByTagName("direction").at(0).toElement();

       Math::Point point;
       Math::Vector vector;

       if (parsePoint(position, point) && parseVector(direction, vector))
	 {
	   std::cout << "Eye { position: " << point << " direction: " << vector << std::endl;
	  _conf._eye = QSharedPointer<Object::Eye>(new Object::Eye(point, vector));
	  return (true);
	}
      return (false);
    }

    bool Loader::parseObjects(const QDomElement& objects)
    {
      QDomNodeList nodesList = objects.childNodes();
      
      for (unsigned int i = 0 ; i < nodesList.length() ; i++)
	{
	  if (!parseObject(nodesList.at(i).toElement()))
	    {
	      return (false);
	    }
	}
      return (true);
    }
    
    bool Loader::parseObjectProperty(const QDomElement& object, Object::Object* ptr)
    {
      QHash<QString, bool (Loader::*)(const QDomElement&, Object::Object*) > actions;
      actions["color"] = &Loader::parseObjectColor;
      
      QDomNodeList childs = object.childNodes();
      
      for (unsigned int i = 0 ; i < childs.length() ; i++)
	{
	  if (actions.find(childs.at(i).nodeName()) != actions.end())
	    {
	      bool (Loader::*t)(const QDomElement&, Object::Object*) = 
		actions[childs.at(i).nodeName()];
	       
	      if (!(this->*t)(childs.at(i).toElement(), ptr))
		 {
		   return (false);
		 }
	     }
	 }       
       return (true);
    }

    bool Loader::parseObject(const QDomElement& object)
    {
      Object::Object*	ptr;
      QHash<QString, bool (Loader::*)(const QDomElement&, Object::Object*&) > actions;
      QString type = object.attributes().namedItem("type").nodeValue();

      actions["sphere"] = &Loader::parseSphere;
      actions["plane"] = &Loader::parsePlane;

      if (actions.find(type) != actions.end())
	 {
	   bool (Loader::*t)(const QDomElement&, Object::Object*&) = actions[type];
	   if (!(this->*t)(object, ptr))
	     {
	       return (false);
	     }
	 }      
      if (!parseObjectProperty(object, ptr))
	{
	  return (false);
	}
       return (true);
    }

    bool Loader::parseObjectColor(const QDomElement& colorNode, Object::Object* ptr)
    {
      Calc::Color color;
      
      if (parseColor(colorNode, color))
	{
	  std::cout << color << std::endl;
	  ptr->color(color);
	  return (true);
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

    bool Loader::parseBool(const QDomElement& node, bool& value)
    {
      QDomText text = node.firstChild().toText();

      if (text.isNull())
	{
	  return (false);
	}
      value = (text.nodeValue() == "true") ? (true) : (false);
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
    
    bool Loader::parseVector(const QDomElement& node, Math::Vector& vector)
    {
      Math::Double x, y, z;

      QDomElement xNode = node.elementsByTagName("x").at(0).toElement();
      QDomElement yNode = node.elementsByTagName("y").at(0).toElement();
      QDomElement zNode = node.elementsByTagName("z").at(0).toElement();
      
      if (parseDouble(xNode, x) && parseDouble(yNode, y) && parseDouble(zNode, z))
	{
	  vector.setXYZ(x, y, z);
	  return (true);
	}
      return (false);
    }

    bool Loader::parseColor(const QDomElement& node, Calc::Color& color)
    {
      char code[3] = {0};
      QDomText text = node.firstChild().toText();

      if (text.isNull())
	{
	  return (false);
	}
      
      QString value = text.nodeValue();
      if (value.length() != 6)
	{
	  return (false);
	}
      code[0] = value[0].toAscii();
      code[1] = value[1].toAscii();
      color.red(strtol(code, NULL, 16));
      code[0] = value[2].toAscii();
      code[1] = value[3].toAscii();
      color.green(strtol(code, NULL, 16));
      code[0] = value[4].toAscii();
      code[1] = value[5].toAscii();
      color.blue(strtol(code, NULL, 16));
      return (true);
    }

    bool Loader::parseSphere(const QDomElement& sphere, Object::Object*& ptr)
    {
      Math::Point  c;
      Math::Double r;

      QDomElement center = sphere.elementsByTagName("center").at(0).toElement();
      QDomElement rayon = sphere.elementsByTagName("rayon").at(0).toElement();
      
      if (parsePoint(center, c) && parseDouble(rayon, r))
	{
	  Math::Sphere s(c, r);
	  std::cout << s << std::endl;
	  ptr = new Object::Sphere(s);
	  QSharedPointer<Object::Object> object(ptr);
	  _conf._objects.push_back(object);
	  return (true);
	}
      return (false);
    }

    bool Loader::parsePlane(const QDomElement& plane, Object::Object*& ptr)
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
	  ptr = new Object::Plane(p);
	  QSharedPointer<Object::Object> object(ptr);
	  
	  _conf._objects.push_back(object);
	  return (true);
	}
      return (false);
    }    
  }
}
