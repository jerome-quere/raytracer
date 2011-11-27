

#ifndef _RT_MATH_DOUBLE_
#define _RT_MATH_DOUBLE_

#include <iostream>

namespace Rt
{

  namespace Math
  {

    /**
     * @brief This clas is the implemantation of a dumble number uin otrder to automaticly
     * manage inpresition with double var
     */
    class Double
    {
      static const double error_margin;

    public:
      Double(const double value = 0);
      ~Double();
      Double(const Double&);
      Double& operator=(const Double&);
      Double& operator=(const double& value);
      Double operator+(const Double&) const;
      Double& operator+=(const Double&);
      Double operator-(const Double&) const;
      Double operator-() const;
      Double operator/(const Double&) const;
      Double operator*(const Double&) const;
      bool operator!=(const Double&) const;
      bool operator==(const Double&) const;
      bool operator<=(const Double&) const;
      bool operator<(const Double&) const;
      bool operator>=(const Double&) const;
      bool operator>(const Double&) const;

      Double pow(int) const;
      Double sqrt() const;

      Double sin() const;
      Double cos() const;

      double value() const;
  
      friend Double operator*(const double&, const Double&);
      friend std::ostream& operator<<(std::ostream&, const Double&);

    private:

      double _value;
    
      mutable bool		_squareFill;
      mutable double            _square;
      mutable bool		_sqrtFill;
      mutable double            _sqrt;
      mutable bool		_sinFill;
      mutable double            _sin;
      mutable bool		_cosFill;
      mutable double            _cos;
    };

  }
}
#endif
