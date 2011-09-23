#include "RtGuiController.hpp"
#include "RtConfLoader.hpp"

#include <iostream>

namespace Rt
{
  namespace Gui
  {
    Controller::Controller()
    {    
      _window.show();

      connect(&_window, SIGNAL(onMenuBarFileOpen()), SLOT(onMenuBarFileOpen()));
      connect(&_confFileDialog, SIGNAL(fileSelected(const QString&)),
	      SLOT(onConfFileSelected(const QString&)));

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

    void Controller::onConfFileSelected(const QString& file)
    {
      loadConfFile(file);
      _confFileDialog.hide();
    }

    void Controller::onMenuBarFileOpen()
    {
      _confFileDialog.show();
    }

  }
}
