#ifndef _RT_CONF_CONF_
#define _RT_CONF_CONF_

#include "RtObjectObject.hpp"
#include "RtObjectLight.hpp"
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

      typedef QVector<QSharedPointer<Object::Object> >::const_iterator
      ObjectIterator;

      typedef QVector<QSharedPointer<Object::Light> >::const_iterator
      LightIterator;

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

      ObjectIterator	objectBegin() const;
      ObjectIterator	objectEnd() const;

      LightIterator	lightBegin() const;
      LightIterator	lightEnd() const;

    private:

      unsigned int			       _width;
      unsigned int			       _height;
      bool				       _3d;
      QSharedPointer<Object::Eye>	       _eye;
      QVector<QSharedPointer<Object::Object> > _objects;
      QVector<QSharedPointer<Object::Light> >  _lights;

    };
  }
}

#endif
