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

    unsigned int  Color::rgb() const
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

    void Color::rgb(unsigned int color)
    {
      _red = Color::redFromColor(color);
      _green = Color::greenFromColor(color);
      _blue = Color::blueFromColor(color);
    }

    Color Color::operator*(const Math::Double& mult) const
    {
      Color c(*this);

      c._red = c._red * mult.value();
      c._green = c._green * mult.value();
      c._blue = c._blue * mult.value();
      return (c);
    }

    Color Color::operator+(const Color& obj) const
    {
      unsigned char red, green, blue;

      red = (_red + obj._red > 255) ? (255) : (_red + obj._red);
      green = (_green + obj._green > 255) ? (255) : (_green + obj._green);
      blue = (_blue + obj._blue > 255) ? (255) : (_blue + obj._blue);
      return (Color(red, green, blue));
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

      ptr[3] = 0xff;
      ptr[2] = red;
      ptr[1] = green;;
      ptr[0] = blue;
      return (color);
    }

    std::ostream& operator<<(std::ostream& stream, const Color& color)
    {
      stream << "0x" << std::hex;
      if (color._red < 0x10)
	stream << "0";
      stream << (int)color._red;
      if (color._green < 0x10)
	stream << "0";
      stream << (int)color._green;
      if (color._blue < 0x10)
	stream << "0";
      stream << (int)color._blue;
      stream << std::dec;
      return (stream);
    }

  }
}
