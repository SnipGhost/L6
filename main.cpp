//-----------------------------------------------------------------------------
#include <math.h>
#include "printing.h"
using namespace std;
//-----------------------------------------------------------------------------
const int STEP = 20; // Изнчальное кол-во шагов для вычисления интеграла
const int NMAX = 20; // Ограничение на количество итераций (2^NMAX * STEP)
//-----------------------------------------------------------------------------
typedef double (*TPF)(const double &); // Функция для интегрирования
typedef double (*TPI)(const double &, const double &); // Точный интеграл
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
double IntRect(TPF f, double a, double b, double EPS, int &n)
{
	long int step_count = STEP;
	double s = 0, sd, r;
	do {
		++n;
		sd = s;
		s = 0;
		double h = (b - a) / step_count;
		for (long int i = 1; i <= step_count; ++i) {
			double x = a + (i-1)*h + h/2;
			s += f(x);
		}
		s *= h;
		r = fabs(s - sd) / 3;
		step_count *= 2;
	} while (r >= EPS/10 && n < NMAX);
	n = step_count;
	return s;
}
//-----------------------------------------------------------------------------
double IntTrap(TPF f, double a, double b, double EPS, int &n)
{
	int step_count = STEP;
	double s = 0, sd = 0, r;
	do {
		++n;
		sd = s;
		s = f(a);
		double h = (b - a) / step_count;
		for (int i = 1; i < step_count; ++i) {
			double x = a + i*h;
			s += 2*f(x);
		}
		s += f(a + step_count*h);
		s *= (0.5 * h);
		r = fabs(s - sd) / 3;
		step_count *= 2;
	} while (r >= EPS/10 && n < NMAX);
	n = step_count;
	return s;
}
//-----------------------------------------------------------------------------
int main()
{
	double a, b, eps;
	InputData(a, b, eps);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	I_print  res[4];
	TPF function[4] = {f1, f2, f3, f4};
	TPI integral[4] = {fi1, fi2, fi3, fi4};
	char * title[4] = {(char*)"y=x \0", (char*)"y=sin(22x)\0",
                           (char*)"y=x^4 \0", (char*)"y=arctg(x)\0"};
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (int i = 0; i < 4; ++i) {
		int n = 0;
		res[i].i_sum = IntRect(function[i], a, b, eps, n);
		res[i].i_toch = integral[i](a, b);
		res[i].n = n;
		res[i].name = title[i];
	}
	PrintTabl(res, 4);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (int i = 0; i < 4; ++i) {
		int n = 0;
		res[i].i_sum = IntTrap(function[i], a, b, eps, n);
		res[i].i_toch = integral[i](a, b);
		res[i].n = n;
		res[i].name = title[i];
	}
	PrintTabl(res, 4);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	return 0;
}
//-----------------------------------------------------------------------------
