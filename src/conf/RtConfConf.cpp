#include "RtConfConf.hpp"

namespace Rt
{
  namespace Conf
  {
    Conf::Conf()
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
      return (*this);
    }

    int	Conf::imageWidth() const
    {
      return (0);
    }

    int	Conf::imageHeight() const
    {
      return (0);
    }
  }
}
