#include "multM.h"

double** multM(double** a, int na, int ma, double** b, int nb, int mb, int &nr, int &mr)
{
	if (ma != nb)
		return 0;
	nr = na;
	mr = mb;
	double** ret = new double*[nr];
	for (int i = 0; i < nr; i++)
		ret[i] = new double[mr];
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < mr; j++)
			ret[i][j] = 0;

	for (int i = 0; i < nr; i++)
	{
		for (int j = 0; j < mr; j++)
		{
			for (int ii = 0; ii < ma; ii++)
					ret[i][j] += a[i][ii] * b[ii][j];
		}
	}
	return ret;
}