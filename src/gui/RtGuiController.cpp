#include "RtGuiController.hpp"
#include "RtConfLoader.hpp"

namespace Rt
{
  namespace Gui
  {
    Controller::Controller()
    {    
      _window.show();
    }

    Controller::~Controller()
    {

    }

    bool Controller::loadConfFile(const QString& path)
    {
      Conf::Loader loader;

      if (loader.load(path))
	{
	  _objects = loader.objects();
	  return (true);
	}
      return (false);
    }
  }
}
