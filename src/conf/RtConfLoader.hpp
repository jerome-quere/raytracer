
#ifndef _RT_CONF_LOADER_
#define _RT_CONF_LOADER_

#include <QString>
#include <QVector>
#include <QDomNode>
#include <QDomDocument>
#include <QSharedPointer>

#include "RtConfConf.hpp"

#include "RtMathDouble.hpp"
#include "RtMathPoint.hpp"
#include "RtMathVector.hpp"
#include "RtObjectObject.hpp"
#include "RtObjectEye.hpp"

namespace Rt
{
  namespace Conf
  {
    class Loader
    {
    public:
      Loader();
      
      bool load(const QString&);
      Conf conf() const;
      
    private:
      
      bool parse();
      bool parseInt(const QDomElement&, int&);
      bool parseDouble(const QDomElement&, Math::Double&);
      bool parseBool(const QDomElement&, bool&);
      bool parsePoint(const QDomElement&, Math::Point&);
      bool parseVector(const QDomElement&, Math::Vector&);
      bool parseWidth(const QDomElement&);
      bool parseHeight(const QDomElement&);
      bool parse3d(const QDomElement&);
      bool parseEye(const QDomElement&);
      bool parseObjects(const QDomElement&);
      bool parseObject(const QDomElement&);
      bool parseSphere(const QDomElement&);
      bool parsePlane(const QDomElement&);


      QDomDocument    _document;
      Conf	      _conf;
    };
  }
}

#endif
