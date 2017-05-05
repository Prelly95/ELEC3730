//     $Date: 2017-03-13 08:12:38 +1100 (Mon, 13 Mar 2017) $
// $Revision: 821 $
//   $Author: Peter $

#include "Ass-01.h"

int string_parser(char *inp, char **array_of_words[])
{
	//error check state of file
	if(*inp == '\0')
	{
		printf("ERROR NULL STRING\n");
		return 0;
	}

	int wordCount = 0;//counts tokens in inp string
	char *temp;//temporary array to edit inp array without changing it
	char input = 0;//switch case variable
	uint8_t count = 0;//lenght of inp string

	//find inp string length
	count = strlen(inp);

	//allocate memory under temp
	temp = malloc(sizeof(char)*count);

	//copy inp into temp
	strcpy(temp, inp);

	printf("\n");//formatting

	//switch case to find word count
	for(int i = 0; i < count; i++)
	{
		switch(input)
		{
		case 1://space case
			if(*(temp + i) == ' ')//space to space
			{
				input = 1;//do nothing
			}
			else if(*(temp + i) != ' ' && *(temp + i) != '\0')//space to char
			{
				wordCount++;//space to letter means new word
				input = 2;
			}
			else if(*(temp + i) == '\0')//space to null
			{
				//do nothing
			}
			break;
		case 2://char case
			if(*(temp + i) == ' ')//char to space
			{
				input = 1;//do nothing
			}
			else if(*(temp + i) != ' ' && *(temp + i) != '\0')
			{
				input = 2;//do nothing
			}
			break;

		default://start case
			if(*(temp + i) == ' ')
			{
				input = 1;
			}
			else if(*(temp + i) != ' ' && *(temp + i) != '\0')
			{
				input = 2;
			}
			else if(*(temp + i) == '\0')
			{

			}
			break;
		}
	}

	*array_of_words = (char**)malloc((wordCount+1)*sizeof(char**));//allocate data after word count is known

	int charCount;

	input = 0;//reset case index
	wordCount = 0;//reset word count

	for(int i = 0; i < count; i++)
		{
			switch(input)
			{
			case 1://space case
				if(temp[i] == ' ')//space to space
				{
					input = 1;
				}
				else if(temp[i] != ' ' && temp[i] != '\0')//space to char
				{
					*(*array_of_words + wordCount) = &(temp[i]);//pointer to start of each word
					charCount++;//add one to char count
					wordCount++;//add one to word count
					input = 2;
				}
				else if(temp[i] == '\0')//space to null
				{
					input = 0;
				}
				break;
			case 2://chr case
				if(temp[i] == ' ')//char to space
				{
					temp[i] = '\0';//letter to space is end of word, set to null
					input = 1;
				}
				else if(temp[i] != ' ' && temp[i] != '\0')
				{
					input = 2;
				}
				else if(temp[i] == '\0')
				{
					input = 0;
				}
				break;

			default://start case
				if(temp[i] == ' ')
				{
					input = 1;
				}
				else if(temp[i] != ' ' && temp[i] != '\0')
				{
					input = 2;
					*(*array_of_words + wordCount) = &(temp[i]);//point array to start of words
					wordCount++;
				}
				else if(temp[i] == '\0')//null string
				{
				}
				break;
			}
		}

	free(temp);//clear temp data
	return wordCount;//return number of words
}
