#include "RtConfConf.hpp"
#include <stdexcept>

namespace Rt
{
  namespace Conf
  {
    Conf::Conf() :
      _3d(false)
    {
    }
    
    Conf::Conf(const Conf& obj)
    {
      operator=(obj);
    }

    Conf::~Conf()
    {
    }

    Conf& Conf::operator=(const Conf& obj)
    {
      _objects = obj._objects;
      _eye = obj._eye;
      _width = obj._width;
      _height = obj._height;
      _3d = obj._3d;
      return (*this);
    }

    unsigned int	Conf::imageWidth() const
    {
      return (_width);
    }

    unsigned int	Conf::imageHeight() const
    {
      return (_height);
    }

    bool		Conf::is3dEnable() const
    {
      return (_3d);
    }

    const Object::Eye&	Conf::eye() const
    {
      if (!_eye)
	{
	  throw (new std::runtime_error("Eye is not set"));
	}
      return (*(_eye.data()));
    }

    Conf::ObjectIterator	Conf::objectBegin() const
    {
      return (_objects.begin());
    }

    Conf::ObjectIterator	Conf::objectEnd() const
    {
      return (_objects.end());
    }    

  }
}
