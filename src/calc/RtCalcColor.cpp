#include "RtCalcColor.hpp"

namespace Rt
{
  namespace Calc
  {

    Color::Color() :
      _red(0),
      _green(0),
      _blue(0)
    {
    }

    Color::Color(unsigned int color) :
      _red(Color::redFromColor(color)),
      _green(Color::greenFromColor(color)),
      _blue(Color::blueFromColor(color))
    {
    }

    Color::Color(unsigned char red, unsigned char green, unsigned char blue) :
      _red(red),
      _green(green),
      _blue(blue)
    {
    }
      
    unsigned char Color::red() const
    {
      return (_red);
    }

    unsigned char Color::green() const
    {
      return (_green);
    }

    unsigned char Color::blue() const
    {
      return (_blue);
    }

    unsigned int  Color::color() const
    {
      return (Color::colorFromRGB(_red, _green, _blue));
    }
    
    void Color::red(unsigned char red)
    {
      _red = red;
    }

    void Color::green(unsigned char green)
    {
      _green = green;
    }

    void Color::blue(unsigned char blue)
    {
      _blue = blue;
    }

    void Color::color(unsigned int color)
    {
      _red = Color::redFromColor(color);
      _green = Color::greenFromColor(color);
      _blue = Color::blueFromColor(color);
    }
    
    unsigned char Color::redFromColor(unsigned int color)
    {
      unsigned char * ptr = (unsigned char*)(&color);
      return (ptr[1]);
    }

    unsigned char Color::greenFromColor(unsigned int color)
    {
      unsigned char * ptr = (unsigned char*)(&color);
      return (ptr[2]);
    }

    unsigned char Color::blueFromColor(unsigned int color)
    {
      unsigned char * ptr = (unsigned char*)(&color);
      return (ptr[3]);
    }

    unsigned int Color::colorFromRGB(unsigned char red, unsigned char green, unsigned char blue)
    {
      unsigned int color;
      unsigned char * ptr = (unsigned char*)(&color);

      ptr[1] = red;
      ptr[2] = green;;
      ptr[3] = blue;
      return (color);
    }

    std::ostream& operator<<(std::ostream& stream, const Color& color)
    {
      stream << "0x00" << std::hex;
      if (color._red < 0x10)
	stream << "0";
      stream << color._red;
      if (color._green < 0x10)
	stream << "0";
      stream << color._green;
      if (color._blue < 0x10)
	stream << "0";
      stream << color._blue;
      stream << std::dec;
      return (stream);
    }

  }
}
