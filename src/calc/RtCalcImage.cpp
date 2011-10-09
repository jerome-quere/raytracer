#include "RtCalcImage.hpp"

namespace Rt
{
  namespace Calc
  {
    Image::Image(unsigned int w, unsigned int h) :
      _width(w),
      _height(h)
    {
      _image = new Color* [w]();
      for (unsigned int i = 0 ; i < w ; i++)
	{
	  _image[i] = new Color [h]();
	}
    }

    Image::~Image()
    {
      for (unsigned int i = 0 ; i < _width ; i++)
	{
	  delete [] _image[i]; 
	}
      delete [] _image;
    }

    unsigned int Image::width() const
    {
      return (_width);
    }

    unsigned int Image::height() const
    {
      return (_height);
    }

    
    const Color*	Image::operator[](int x) const
    {
      return _image[x];
    }

    Color*		Image::operator[](int x)
    {
      return _image[x];
    }

    
    QImage              Image::toQImage() const
    {
      QImage image(_width, _height, QImage::Format_RGB32);
      
      image.fill(0x00000000);
      for (unsigned int x = 0 ; x < _width ; x++)
	{
	  for (unsigned int y = 0 ; y < _height ; y++)
	    {
	      image.setPixel(x, y, _image[x][y].rgb());
	    }
	}
      return (image);
    }

  }
}
