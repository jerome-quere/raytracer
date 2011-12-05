#include "RtCalcGenerator.hpp"
#include "RtCalcCalculator.hpp"
#include "RtMathTransformation.hpp"

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
      QObject::connect(&_threadPool, SIGNAL(done()),
		       this, SLOT(onThreadPoolDone()));

      QObject::connect(&_threadPool, SIGNAL(percentUpdate(int)),
		       this, SLOT(onThreadPoolPercentUpdate(int)));
    }

    void Generator::generate()
    {
      if (_conf.is3dEnable())
	{
	  Object::Eye rightEye = _conf.eye().rightEye();
	  Object::Eye leftEye  = _conf.eye().leftEye();
	  generate(*_imageRight, rightEye);
	  generate(*_imageLeft, leftEye);
	}
      else
	{
	  generate(_image, _conf.eye());
	}
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

    const Image&	Generator::image() const
    {
      return (_image);
    }

    void	 Generator::onThreadPoolDone()
    {

      if (_conf.is3dEnable())
	{
	  int dec = 10;

	  for (unsigned int x =  dec ; x < _imageRight->width() - dec ; x++)
	    {
	      for (unsigned int y = 0 ; y < _imageRight->height() ; y++)
		{
		  _image[x - dec][y].red((*_imageLeft)[x][y].red());
		  _image[x - dec][y].green((*_imageRight)[x - dec][y].green());
		  _image[x - dec][y].blue((*_imageRight)[x - dec][y].blue());
		  (*_imageRight)[x][y].red(0);
		  (*_imageLeft)[x][y].green(0);
		  (*_imageLeft)[x][y].blue(0);
		}
	    }
	  QImage image = _imageRight->toQImage();
	  image.save("r.jpg", NULL, 100);
	  QImage image2 = _imageLeft->toQImage();
	  image2.save("l.jpg", NULL, 100);
	}

      QImage image3 = _image.toQImage();
      image3.save("img.jpg", NULL, 100);


      std::cout << "Done" << std::endl;
      exit(0);
    }

    void	Generator::onThreadPoolPercentUpdate(int percent)
    {
    }
  }
}
