
#include <QApplication>
#include "RtGuiController.hpp"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
  
  Rt::Gui::Controller controller;
  
  return (app.exec());
}
