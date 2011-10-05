#include "RtCalcGenerator.hpp"
#include "RtCalcCalculator.hpp"

namespace Rt
{
  namespace Calc
  {
    Generator::Generator(const Conf::Conf& conf) :
      _conf(conf),
      _image(conf.imageWidth(), conf.imageHeight()),
      _imageLeft(NULL),
      _imageRight(NULL),
      _threadPool(10)
    {
      if (_conf.is3dEnable())
	{
	  _imageLeft = new Image(conf.imageWidth(), conf.imageHeight());
	  _imageRight = new Image(conf.imageWidth(), conf.imageHeight());
	}
      connect(&_threadPool, SIGNAL(done()), SLOT(onThreadPoolDone()));
    }
    
    const Image& Generator::generate()
    {
      generate(_image, _conf.eye());
      return (_image);
    }

    void	Generator::generate(Image& image, const Object::Eye& eye)
    {
      ThreadTask* task;
      Math::Point screen;
      Math::Line  line;

      for (unsigned int x = 0 ; x < image.width() ; x++)
	{
	  for (unsigned int y = 0 ; y < image.height() ; y++)
	    {
	      screen = Calculator::screenPoint(eye, image.width(), image.height(), x, y);
	      line = Math::Line(eye.position(), screen);
	      task = new ThreadTask(line, _conf, image[x][y]);
	      if (x == image.width() - 1 && y == image.height() - 1)
		{
		  task->lastTask(true);
		}
	      _threadPool.addTask(task);
	    }
	}
    }
    
    void	 Generator::onThreadPoolDone()
    {
      std::cout << "Done" << std::endl;
    }
  }
}
