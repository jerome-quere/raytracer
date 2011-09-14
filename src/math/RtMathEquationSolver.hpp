

#ifndef _RT_MATH_EQUATION_SOLVER_
#define _RT_MATH_EQUATION_SOLVER_

#include <QVector>
#include "RtMathDouble.hpp"

namespace Rt
{
  namespace Math
  {
    class EquationSolver
    {

    public:
      static QVector<Double> secondDegree(const Double& a, const Double& b, const Double& c);

    private:
      
      EquationSolver();

    };
  }
}

#endif
