#ifndef _RT_CALC_GENERATOR_
#define _RT_CALC_GENERATOR_

#include <QObject>

#include "RtConfConf.hpp"
#include "RtCalcImage.hpp"
#include "RtCalcThreadPool.hpp"

namespace Rt
{
  namespace Calc
  {
    class Generator : public QObject
    {
      Q_OBJECT;

    public:

      Generator(const Conf::Conf&);
      const Image& generate();
      void	   generate(Image&, const Object::Eye&);

      const Image& image() const;

    private slots:

      void onThreadPoolDone();

    private:

      Conf::Conf	_conf;
      Image		_image;
      Image*		_imageLeft;
      Image*		_imageRight;
      ThreadPool	_threadPool;
    };
  }
}

#endif
