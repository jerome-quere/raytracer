
#ifndef _RT_CALC_IMAGE_
#define _RT_CALC_IMAGE_

#include <QImage>
#include "RtCalcColor.hpp"

namespace Rt
{
  namespace Calc
  {
    class Image
    {
    public:

      Image(unsigned int with, unsigned int height);
      ~Image();
      
      unsigned int	width() const;
      unsigned int	height() const;

      const Color*	operator[](int x) const;
      Color*		operator[](int x);

      QImage toQImage() const;

    private:
      
      unsigned int	_width;
      unsigned int	_height;
      Color**		_image;	
      
    };
  }
}


#endif
