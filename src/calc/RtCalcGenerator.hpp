#ifndef _RT_CALC_GENERATOR_
#define _RT_CALC_GENERATOR_

#include "RtConfConf.hpp"
#include "RtCalcImage.hpp"

namespace Rt
{
  namespace Calc
  {
    class Generator
    {
    public:
      
      Generator(const Conf::Conf&);
      const Image& generate();

    private:

      Conf::Conf	_conf;
      Image		_image;
      
    };
  }
}

#endif
