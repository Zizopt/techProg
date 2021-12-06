#include "multMElem.h"

double** multMElem(double** a, int na, int ma, double** b, int nb, int mb)
{
	if(a==0||b==0||na==0||ma==0||nb==0||mb==0)
		return 0;
	if (na != nb || ma!=mb)
		return 0;
	double** ret = new double* [na];
	for (int i = 0; i < na; i++)
		ret[i] = new double[ma];
	
	for (int i = 0; i < na; i++)
		for (int j = 0; j < ma; j++)
			ret[i][j] = a[i][j] * b[i][j];

	return ret;
}