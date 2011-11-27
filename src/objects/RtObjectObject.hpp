
#ifndef _RT_OBJECT_OBJECT_
#define _RT_OBJECT_OBJECT_

#include "RtCalcColor.hpp"
#include "RtMathObject.hpp"

namespace Rt
{
  namespace Object
  {
    class Object
    {
    public:

      const Calc::Color& color() const;
      void	   color(const Calc::Color&);

      const Math::Double& shininess() const;
      void  shininess(const Math::Double&);

      const Math::Double& reflexion() const;
      void  reflexion(const Math::Double&);

      virtual const Math::Object&	math() const = 0;

    protected:

      Object();

    private:

      Calc::Color	_color;
      Math::Double	_shininess;
      Math::Double	_reflexion;
    };
  }
}

#endif
