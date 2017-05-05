//     $Date: 2017-03-13 08:12:38 +1100 (Mon, 13 Mar 2017) $
// $Revision: 821 $
//   $Author: Peter $

// Question 2
#include "Ass-01.h"

int read_pcm_wavefile(pcm_wavefile_header_type *header, char **data, char *filename)
{
	FILE* fp;
	fp = fopen(filename, "rb");

	if(fp == 0)
	{
		printf("\n\t\t\t\tFILE READ ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}

	//reads in all files
	fread((*header).ChunkID, sizeof(header->ChunkID), 1, fp);
	fread(&(*header).ChunkSize, sizeof(uint32_t), 1, fp);
	fread((*header).Format, sizeof(header->Format), 1, fp);
	fread((*header).Subchunk1ID, sizeof(header->Subchunk1ID), 1, fp);
	fread(&(*header).Subchunk1Size, sizeof(header->Subchunk1Size), 1, fp);
	fread(&(*header).AudioFormat, sizeof(header->AudioFormat), 1, fp);
	fread(&(*header).NumChannels, sizeof(header->NumChannels), 1, fp);
	fread(&(*header).SampleRate, sizeof(header->SampleRate), 1, fp);
	fread(&(*header).ByteRate, sizeof(header->ByteRate), 1, fp);
	fread(&(*header).BlockAlign, sizeof(header->BlockAlign), 1, fp);
	fread(&(*header).BitsPerSample, sizeof(header->BitsPerSample), 1, fp);
	fread((*header).Subchunk2ID, sizeof(header->Subchunk2ID), 1, fp);
	fread(&(*header).Subchunk2Size, sizeof(header->Subchunk2Size), 1, fp);


	//ERROR CHECKING ChunkID compares each byte in ChunkID and compares it to its expected value
	if((header->ChunkID[0] != 'R') | (header->ChunkID[1] != 'I') | (header->ChunkID[2] != 'F') | (header->ChunkID[3] != 'F'))
	{
		printf("\n\t\t\t\tChunkID: ERROR\n\n\n");
		fclose(fp);
		return FALSE;	//FALSE == -1
	}
	else
	{
		printf("\n\t\t\t\tChunkID: %c%c%c%c\n", header->ChunkID[0], header->ChunkID[1], header->ChunkID[2], header->ChunkID[3]);
	}

	//ChunkSise ERROR Checking
	if(((header->ChunkSize - header->Subchunk2Size-36) == 0)||((header->ChunkSize - header->Subchunk2Size-36) == 0))
	{
		printf("\t\t\t\tChunkSize: %i\n", header->ChunkSize);
	}
	else
	{
		printf("\t\t\t\tChunkSize: ERROR\n\n\n");
		fclose(fp);
		return FALSE;	//FALSE == -1
	}

	//Format Error Checking compares each byte in Format and compares it to its expected value
	if((header->Format[0] != 'W') | (header->Format[1] != 'A') | (header->Format[2] != 'V') | (header->Format[3] != 'E'))
	{
		printf("\t\t\t\tFormat: ERROR\n\n\n");
		fclose(fp);
		return FALSE;	//FALSE == -1
	}
	else
	{
		printf("\t\t\t\tFormat: %c%c%c%c\n", header->Format[0], header->Format[1], header->Format[2], header->Format[3]);
	}

	//Format Error Checking compares each byte in Format and compares it to its expected value
	if((header->Subchunk1ID[0] != 'f') | (header->Subchunk1ID[1] != 'm') | (header->Subchunk1ID[2] != 't'))
	{
		printf("\t\t\t\tSubchunk1ID: ERROR\n\n\n");
		fclose(fp);
		return FALSE;	//FALSE == -1
	}
	else
	{
		printf("\t\t\t\tSubchunk1ID: %c%c%c\n", header->Subchunk1ID[0], header->Subchunk1ID[1], header->Subchunk1ID[2]);
	}

	//SubchunkSize ERROR CHECKING
	if(header->Subchunk1Size != 16)
	{
		printf("\t\t\t\tSubchunk1Size: ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}
	else
	{
		printf("\t\t\t\tSubchunk1Size: %i\n", header->Subchunk1Size);
	}

	printf("\t\t\t\tAudioFormat: %i\n", header->AudioFormat);
	printf("\t\t\t\tNumChannels: %i\n", header->NumChannels);
	printf("\t\t\t\tSampleRate: %i\n", header->SampleRate);

	//ByteRate ERROR Checking
	if(header->ByteRate != (header->SampleRate)*(header->NumChannels) * ((header->BitsPerSample)/8))
	{
		printf("\t\t\t\tByteRate: ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}
	else
	{
		printf("\t\t\t\tByteRate: %i\n", header->ByteRate);
	}

	//BlckAlign ERROR Checking
	if(header->BlockAlign != (header->NumChannels) * ((header->BitsPerSample)/8))
	{
		printf("\tBlockAlign: ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}
	else
	{
		printf("\t\t\t\tBlockAlign: %i\n", header->BlockAlign);
	}

	printf("\t\t\t\tBitsPerSample: %i\n", header->BitsPerSample);

	//Subchunk2ID ERROR Checking
	if((header->Subchunk2ID[0] != 'd') | (header->Subchunk2ID[1] != 'a') | (header->Subchunk2ID[2] != 't') | (header->Subchunk2ID[3] != 'a'))
	{
		printf("\t\t\t\tSubchunk2ID: ERROR\n\n\n");
		fclose(fp);
		return FALSE;	//FALSE == -1
	}
	else
	{
		printf("\t\t\t\tSubchunk2ID: %c%c%c%c\n", header->Subchunk2ID[0], header->Subchunk2ID[1], header->Subchunk2ID[2], header->Subchunk2ID[3]);
	}

	//Subchunk2Size ERROR Checking
	if(header->Subchunk2Size != (header->ChunkSize) - 36)
	{
		printf("\t\t\t\tSubchunk2Size: ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}
	else
	{
		printf("\t\t\t\tSubchunk2Size: %i\n\n\n", header->Subchunk2Size);
		*data = malloc(header->Subchunk2Size * sizeof(uint8_t));
	}

	fread(*data, sizeof(uint8_t), header->Subchunk2Size, fp);
	fclose(fp);
	return TRUE;	//TRUE == 0
}

int write_pcm_wavefile(pcm_wavefile_header_type *header, char *data, char *filename)
{
	FILE *fp;
	fp = fopen(filename, "wb");

	//OPEN FILE ERROR
	if(fp == 0)
	{
		printf("\n\t\t\t\tFILE OPEN ERROR\n\n\n");
		fclose(fp);
		return FALSE;
	}

	//write header to new file
	fwrite(header, sizeof(pcm_wavefile_header_type), 1, fp);

	//write data to new file
	fwrite(data, sizeof(uint8_t), sizeof(uint8_t)*header->Subchunk2Size, fp);

	fclose(fp);

  return TRUE;
}
