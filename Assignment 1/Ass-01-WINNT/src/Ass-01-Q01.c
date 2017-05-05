//     $Date: 2017-03-13 08:12:38 +1100 (Mon, 13 Mar 2017) $
// $Revision: 821 $
//   $Author: Peter $

// Question 1

#include "Ass-01.h"

int read_coefficients(int *coeff_num, double **coeff_values, char *filename)
{

	FILE *fp; //declares pointer for start of file

	fp = fopen(filename, "rb");	//opens binary file to read

	if(fp == 0)
	{
		printf("FILE READ ERROR\n");
		return FALSE;//false defined in headder -1
	}

	fread(coeff_num, sizeof(int), 1, fp); //reads the first value of the binary file (fp) into coeff_num

	*coeff_values = malloc((*coeff_num)*sizeof(double));	//allocates a block of memory for coeff_values of the correct size

	//compares the expected size of the coeff_values (from the first integer 'n') array with the actual size
	if(fread(*coeff_values, sizeof(double), *coeff_num, fp) != *coeff_num)
	{
		printf("ERROR\n");
		return FALSE;
	}

	fclose(fp);
	return TRUE;//true defined in headder 0
}
