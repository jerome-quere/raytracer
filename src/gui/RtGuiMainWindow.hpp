
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
    public:
      MainWindow();
      ~MainWindow();

    private:
      
      Ui::MainWindow*	_ui;

    };
  }
}

#endif
