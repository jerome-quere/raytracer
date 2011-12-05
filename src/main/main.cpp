
#include <QApplication>
#include "RtGuiController.hpp"

#include "RtConfLoader.hpp"
#include "RtConfConf.hpp"
#include "RtCalcGenerator.hpp"
#include "RtMathDouble.hpp"
#include "RtCalcImage.hpp"

int main(int argc, char** argv)
{
  QApplication app(argc, argv);


 //Rt::Gui::Controller controller;

  Rt::Conf::Loader loader;

  std::cout << "####### Create Conf" << std::endl;
  loader.load("conf/conf.xml");

  Rt::Conf::Conf conf = loader.conf();

  std::cout << "####### Begin Generate" << std::endl;
  Rt::Calc::Generator g(conf);

  g.generate();

  return (app.exec());
}
