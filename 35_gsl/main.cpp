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

int main(int argc, const char *argv[]) {
	std::cout << "gsl testing" << std::endl;

	double x = 5.0;
	double y = gsl_sf_bessel_J0 (x);
	printf ("J0(%g) = %.18e\n", x, y);

	return EXIT_SUCCESS;
}
