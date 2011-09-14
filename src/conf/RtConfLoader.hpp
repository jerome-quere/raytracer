
#ifndef _RT_CONF_LOADER_
#define _RT_CONF_LOADER_

#include <QString>
#include <QVector>
#include <QDomNode>
#include <QDomDocument>
#include <QSharedPointer>

#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Conf
  {
    class Loader
    {
    public:
      Loader();
      
      bool load(const QString&);
      const QVector<QSharedPointer<Object::Object> >& objects() const;
      
    private:
      
      bool parse();
      bool parseObject(const QDomElement&);
      bool parseSphere(const QDomElement&);
      bool parsePlane(const QDomElement&);

      QDomDocument			       _document;
      QVector<QSharedPointer<Object::Object> > _objects;
    };
  }
}

#endif
