
#include "RtGuiMainWindow.hpp"

namespace Rt
{
  namespace Gui
  {
    MainWindow::MainWindow() :
      _ui(new Ui::MainWindow)
    {
      _ui->setupUi(this);
    }

    MainWindow::~MainWindow()
    {
      delete _ui;
    }
  }
}
