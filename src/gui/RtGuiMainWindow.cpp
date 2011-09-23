
#include "RtGuiMainWindow.hpp"

#include <iostream>

namespace Rt
{
  namespace Gui
  {
    MainWindow::MainWindow() :
      _ui(new Ui::MainWindow)
    {
      _ui->setupUi(this);
      connect(_ui->actionOpen, SIGNAL(triggered()), SIGNAL(onMenuBarFileOpen()));
    }

    MainWindow::~MainWindow()
    {
      delete _ui;
    }
  }
}
