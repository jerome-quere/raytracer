
#ifndef _RT_GUI_MAIN_WINDOW_
#define _RT_GUI_MAIN_WINDOW_

#include <QMainWindow>
#include "ui_RtGuiMainWindow.h"

namespace Rt
{
  namespace Gui
  {
    class MainWindow : public QMainWindow
    {
      Q_OBJECT;

    public:
      MainWindow();
      ~MainWindow();

      
    signals:

      void onMenuBarFileOpen();
 
    private:
      
      Ui::MainWindow*	_ui;

    };
  }
}

#endif
