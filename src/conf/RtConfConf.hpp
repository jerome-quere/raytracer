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
      
      int	imageWidth() const;
      int	imageHeight() const;


    private:

      QSharedPointer<Object::Eye>	       _eye;
      QVector<QSharedPointer<Object::Object> > _objects;

    };
  }
}

#endif
