
#ifndef _RT_3D_VECTOR_
#define _RT_3D_VECTOR_

#include "RtMathDouble.hpp"

namespace Rt
{
  
  namespace Math
  {

    /**
     * @brief This clas represent a vector in 3 dimention
     */
    class Vector
    {

    public:

      Vector(const Double& x = 0, const Double& y = 0, const Double& z = 0);
      Vector(const Vector&);
      ~Vector();
      Vector& operator=(const Vector&);
      Vector operator-() const;
      Double operator*(const Vector&) const;

      const Double& x() const;
      const Double& y() const;
      const Double& z() const;
  
      Vector& x(const Double&);
      Vector& y(const Double&);
      Vector& z(const Double&);
      Vector& setXYZ(const Double&, const Double&, const Double&);

      const Double& norm() const;
  
      friend std::ostream& operator<<(std::ostream&, const Vector&);


    private:
      
      Double _x;
      Double _y;
      Double _z;

      mutable bool   _normFill;
      mutable Double _norm;
    };

  }

}
#endif
