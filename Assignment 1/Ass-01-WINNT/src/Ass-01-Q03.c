//     $Date: 2017-03-13 08:12:38 +1100 (Mon, 13 Mar 2017) $
// $Revision: 821 $
//   $Author: Peter $

#include "Ass-01.h"
int filter(char *filter_filename, char *input_wavefilename, char *output_wavefilename)
{

	pcm_wavefile_header_type header;
	int coeff_num;
	double *coeff_values;
	double buff; //the data used when calculating filtered data
	char *dataIn; //data read in from Q2 as char*
	int16_t *output; //data to be written to filtered wav file
	int16_t *data; //data type casted from dataIn

	//Error check for read_coefficients
	if(read_coefficients(&coeff_num, &coeff_values, &(*filter_filename)) == FALSE)
	{
		printf("ERROR");
		return FALSE;
	}

	//Error check for read_pcm_wavefile
	if(read_pcm_wavefile(&header, &dataIn, &(*input_wavefilename)) == FALSE)
	{
		printf("ERROR");
		return FALSE;
	}

	//allocate data under output
	output = malloc(header.Subchunk2Size);

	data = (int16_t *)dataIn; //typecast data to int16_t to capture both samples

	printf("\nsubchunk2size:\t%d\n", header.Subchunk2Size);

	for(int i = 0; i < (header.Subchunk2Size)/2; i ++)
	{
		buff = 0;
		for(int j = 0; j <= i && j < coeff_num; j ++)
		{
			//calculate new data
			buff = (buff + (double)data[i-j]*(coeff_values[j]));

		}
		output[i] = (uint16_t)buff;//cast calculated data(buff) to uint16_t
	}

	//write data to new output file
	if(write_pcm_wavefile(&header, (char*)output, output_wavefilename) == -1)
	{
		printf("ERROR WRITING");
	}

	free(data);

  return 0;
}
