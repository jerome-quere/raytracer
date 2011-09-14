

#ifndef _RT_GUI_CONTROLLER_
#define _RT_GUI_CONTROLLER_

#include <QString>
#include "RtGuiMainWindow.hpp"
#include "RtObjectObject.hpp"

namespace Rt
{
  namespace Gui
  {
    class Controller
    {

    public:
      
      Controller();
      ~Controller();
      
      bool loadConfFile(const QString&);

    private:

      MainWindow				_window;
      QVector<QSharedPointer<Object::Object> > _objects;
      
    };
  }
}

#endif
