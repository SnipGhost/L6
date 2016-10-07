//----------------------------------------------------------------------------
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//-----------------------------------------------------------------------------
// f1: y = x
// f2: y = sin(22x)
// f3: y = x^4
// f4: y = arctg(x)
//-----------------------------------------------------------------------------
inline double f1(const double &x) { return x; }
inline double f2(const double &x) { return sin(22*x); }
inline double f3(const double &x) { return x*x*x*x; }
inline double f4(const double &x) { return atan(x); }
//-----------------------------------------------------------------------------
inline double fi1(const double &a, const double &b)
{ return (b*b - a*a) / 2.0; }
//-----------------------------------------------------------------------------
inline double fi2(const double &a, const double &b)
{ return (cos(a*22.0) - cos(b*22.0)) / 22.0; }
//-----------------------------------------------------------------------------
inline double fi3(const double &a, const double &b)
{ return (b*b*b*b*b - a*a*a*a*a) / 5.0; }
//-----------------------------------------------------------------------------
inline double fi4(const double &a, const double &b)
{ return ( b*atan(b) - a*atan(a) - (log(b*b+1)-log(a*a+1)) / 2.0 ); }
//-----------------------------------------------------------------------------
#endif // FUNCTIONS_H
//-----------------------------------------------------------------------------