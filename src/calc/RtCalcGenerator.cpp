#include "RtCalcGenerator.hpp"

namespace Rt
{
  namespace Calc
  {
    Generator::Generator(const Conf::Conf& conf) :
      _conf(conf),
      _image(conf.imageWidth(), conf.imageHeight())
    {
    }

    const Image& Generator::generate()
    {
      return (_image);
    }
  }
}
