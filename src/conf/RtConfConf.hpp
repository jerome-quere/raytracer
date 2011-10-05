#ifndef _RT_CONF_CONF_
#define _RT_CONF_CONF_

#include "RtObjectObject.hpp"
#include "RtObjectEye.hpp"

#include <QVector>
#include <QSharedPointer>

namespace Rt
{
  namespace Conf
  {
    class Conf
    {
      friend class Loader;
      

    public:
      Conf();
      Conf(const Conf&);
      ~Conf();
      
      Conf& operator=(const Conf&);
      
      unsigned int	imageWidth() const;
      unsigned int	imageHeight() const;
      bool		is3dEnable() const;
      const Object::Eye& eye() const;
      Object::Eye	leftEye();
      Object::Eye	leftRight();


    private:

      unsigned int			       _width;
      unsigned int			       _height;
      bool				       _3d;
      QSharedPointer<Object::Eye>	       _eye;
      QVector<QSharedPointer<Object::Object> > _objects;

    };
  }
}

#endif
