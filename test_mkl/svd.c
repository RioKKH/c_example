#include <stdio.h>
// #include <mkl_cblas.h>
#include "mkl.h"

int main()
{
	MKL_INT i=0, j=0;
	double A[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	MKL_INT m = 3, n = 2;
	double U[9], S[2], VT[4];
	MKL_INT ldu = 3, ldvt = 2, info;

	// SVD計算
	dgesvd("A", "A", &m, &n, A, &m, S, U, &ldu, VT, &ldvt, &info);
	
	if (info == 0)
	{
		printf("u:\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				printf("%.2f ", U[i * ldu + j]);
			}
			printf("\n");
		}

		printf("\nSingular Values:\n");
		for (i = 0; i < ((m < n) ? m : n); i++)
		{
			printf("%.2f\n", S[i]);
		}

		printf("\nV^T:\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%.2f ", VT[i * ldvt + j]);
			}
			printf("\n");
		}
	} else {
		printf("Error in dgesvd\n");
	}

	return 0;
}
