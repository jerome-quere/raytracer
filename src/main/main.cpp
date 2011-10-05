
#include <QApplication>
#include "RtGuiController.hpp"

#include "RtConfLoader.hpp"
#include "RtConfConf.hpp"
#include "RtCalcGenerator.hpp"
#include "RtMathDouble.hpp"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);
 

  //Rt::Gui::Controller controller;
  
  Rt::Conf::Loader loader;
  
  loader.load("conf/conf.xml");

  Rt::Conf::Conf conf = loader.conf();
  
  Rt::Calc::Generator g(conf);

  g.generate();
  
  return (app.exec());
}
