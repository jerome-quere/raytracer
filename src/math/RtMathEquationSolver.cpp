
#include "RtMathEquationSolver.hpp"

namespace Rt
{
  namespace Math
  {
    EquationSolver::EquationSolver()
    {
    }

    QVector<Double> EquationSolver::secondDegree(const Double& a, const Double& b, const Double& c)
    {
      QVector<Double> solution;
      Double delta = b.pow(2) - a * c * Double(4);
  
      if (delta < 0)
	{
	  return (solution);
	}
      else if (delta == 0)
	{
	  solution.push_back(-b / (2 * a));
	}
      else
	{
	  solution.push_back((-b - delta.sqrt()) / (2 * a));
	  solution.push_back((-b + delta.sqrt()) / (2 * a));
	}
      return (solution);
    }

  }
}
