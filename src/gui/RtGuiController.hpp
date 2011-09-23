

#ifndef _RT_GUI_CONTROLLER_
#define _RT_GUI_CONTROLLER_

#include <QObject>
#include <QString>
#include "RtGuiMainWindow.hpp"
#include "RtObjectObject.hpp"
#include "RtGuiConfFileDialog.hpp"

namespace Rt
{
  namespace Gui
  {
    class Controller : public QObject
    {

      Q_OBJECT;

    public:
      
      Controller();
      ~Controller();
      
      bool loadConfFile(const QString&);

    private slots:
      
      void onConfFileSelected(const QString& file);
      void onMenuBarFileOpen();

    private:

      MainWindow				_window;
      ConfFileDialog				_confFileDialog;
      QVector<QSharedPointer<Object::Object> > _objects;
      
    };
  }
}

#endif
