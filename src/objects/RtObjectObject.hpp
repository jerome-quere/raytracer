
#ifndef _RT_OBJECT_OBJECT_
#define _RT_OBJECT_OBJECT_

namespace Rt
{
  namespace Object
  {
    class Object
    {
    public:

      int color() const;

    protected:
      
      Object();

    private:
      
      int	_color;
    };
  }
}

#endif
