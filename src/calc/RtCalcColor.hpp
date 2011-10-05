
#ifndef _RT_CALC_COLOR_
#define _RT_CALC_COLOR_

#include <iostream>

namespace Rt
{
  namespace Calc
  {
    class Color
    {
    public:
      Color();
      Color(unsigned int color);
      Color(unsigned char red, unsigned char green, unsigned char blue);
      
      unsigned char red() const;
      unsigned char green() const;
      unsigned char blue() const;
      unsigned int  rgb() const;

      void red(unsigned char red);
      void green(unsigned char green);
      void blue(unsigned char blue);
      void rgb(unsigned int color);

      static unsigned char redFromColor(unsigned int color);
      static unsigned char greenFromColor(unsigned int color);
      static unsigned char blueFromColor(unsigned int color);
      static unsigned int colorFromRGB(unsigned char red, unsigned char green, unsigned char blue);
      
      friend std::ostream& operator<<(std::ostream& stream, const Color&);

    private:

      unsigned char _red;
      unsigned char _green;
      unsigned char _blue;
    };
  }
}

#endif
