/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年05月13日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include	<gsl/gsl_sf_bessel.h>
#include	<gsl/gsl_poly.h>
#include	<gsl/gsl_const_mksa.h>

int main(int argc, const char *argv[]) {
	std::cout << "gsl testing" << std::endl;

	double x = 5.0;
	double y = gsl_sf_bessel_J0 (x);
	printf ("J0(%g) = %.18e\n", x, y);

	/* w = c1z^0 + c2z^1 + c3z^2 */
	/* maxlen = 3 */
#define maxlen 3
	double z   = 1.;
	double c[maxlen] = { 1,2,3 }; 
	double w   = gsl_poly_eval(c,maxlen,z);
	std::cout << w << std::endl;

	/* 常量 每小时秒数*/
	std::cout << GSL_CONST_MKSA_HOUR << std::endl;
	/* 常量 每星期秒数*/
	std::cout << GSL_CONST_MKSA_WEEK << std::endl;

	return EXIT_SUCCESS;
}
