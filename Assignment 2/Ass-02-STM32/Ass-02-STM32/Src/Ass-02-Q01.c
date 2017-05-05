//     $Date: 2017-04-04 04:00:13 +1000 (Tue, 04 Apr 2017) $
// $Revision: 872 $
//   $Author: Peter $

#include "Ass-02.h"
#include "usart.h"
//
// REPLACE THE EXAMPLE CODE WITH YOUR CODE
//Initialise the Command List using the Structure type of command_s

volatile uint8_t Debug = 0;

const command_s CommandList[] = {
		{(int8_t *)"add", &Add_Function, (int8_t *)"add <num_1> +...+ <num_n>"},
		{(int8_t *)"sub", &Sub_Function,(int8_t *) "sub <num_1> -...- <num_n>"},
		{(int8_t *)"mul", &Mul_Function, (int8_t *)"mul <num_1> *...* <num_n>"},
		{(int8_t *)"div", &Div_Function,(int8_t *) "div <num_1> /<num_2>"},
		{(int8_t *)"help", &Help_Function, (int8_t *)"help [command]: Prints help information for a command"},
		{(int8_t *)"debug", &Debug_Function, (int8_t *)"debug <on|off>"},
		{(int8_t *)"clear", &Clear_Function, (int8_t *)"clears the terminal window"},
		{(int8_t *)"clc", &Clear_Function, (int8_t *)"clears the terminal window"},
		{NULL, NULL, NULL}
};

/*
 * Function: Add_Function
 * ----------------------------
 *   Returns the Add of all the arguments passed into the function
 *
 *	ArgNum = number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Clear_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	//printf("IN the Clear function\n\r");
	printf("\014");
	printf("ELEC3730 Assignment 2\n\r");
	return -1;

}




/*
 * Function: Add_Function
 * ----------------------------
 *   Returns the Add of all the arguments passed into the function
 *
 *	ArgNum = number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Add_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	float result=0;
	uint8_t i;
	//printf("IN the ADD function\n\r");
	if(ArgNum > 2){
		for(i = 1; i<ArgNum; i++){
			//Convert the input the string to a float and add to result
			result += atof((char*)ArgStrings[i]);
		}
		printf("Result = %f\n\r",result);
	}
	else{
		//No enough arguments have been entered
		printf("Not enough arguments have been entered for the add function,\n\renter 'add help' for help\n\r");
	}

	return -1;

}


/*
 * Function: Sub_Function
 * ----------------------------
  *	Calculates the Subtraction between String A - String B  - ...- String N
 *
 *	Returns -1
 *
 *	INPUTS:
 *	ArgNum =number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Sub_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	float result =0;
	uint8_t i;
	//printf("IN the Sub function\n\r");
	if(ArgNum > 2){
		//Checks correct number of arguments have been entered
		result = atof((char*)ArgStrings[1]);
		for(i = 2; i<ArgNum; i++){
			result = result - atof((char*)ArgStrings[i]);
		}
		printf("Result = %f\n\r",result);
	}
	else{
		printf("Not enough arguments have been entered for the sub function,\n\renter 'help sub' for help\n\r");
	}

	return -1;

}

/*
 * Function: Mul_Function
 * ----------------------------
 *	Calculates the Multiplication between String A * String B  * ...* String N
 *	Returns -1
 *
 *	INPUTS:
 *	ArgNum =number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Mul_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	float result =1;
	int8_t ERR = 0;
	uint8_t i, j;
	//printf("IN the Mul function\n\r");
	if(ArgNum>2){
		for(i=1; i<ArgNum; i++){
			result *= atof((char*)ArgStrings[i]);
			j = 0;
			while(ArgStrings[i][j] != '\0')
			{
				//printf("arg %i\n\r", ArgStrings[i][j]);
				if(ArgStrings[i][j] < 48 || ArgStrings[i][j] > 57)
				{
					printf("ERROR: Opperator Expects number in arg %i\n\r", i);
					printf("Interpreted Value: %g\n\r", atof((char*)ArgStrings[i]));
					ERR = 1;
					break;
				}
				j++;
			}
		}
		if(ERR == 1)
		{
			printf("Possible Result from interpreted arguments : %g\n\r",result);
			ERR = 0;
		}
		else
		{
			printf("Result : %g\n\r",result);
		}
	}
	else{
		printf("Not enough arguments entered for the mul function,\n\r enter 'help mul' for help\n\r");
	}

	return -1;
}






/*
 * Function: Div_Function
 * ----------------------------
 *	Calculates the Division of String A and String B
 *	Returns -1
 *
 *	INPUTS:
 *	ArgNum =number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Div_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	float result;
	//printf("IN the Div function\n\r");
	uint8_t i,j;
	int8_t ERR = 0;
	if(ArgNum>3){
		//To many arguments have been entered
		printf("Too many arguments have been entered for the divide operator,\n\r type 'help div' for help\n\r");
	}
	if(ArgNum>2){ //Correct number of arguments have been entered for the divide function
		for(i=1; i<ArgNum; i++){
			j = 0;
			//Loop through each input string until NULL terminator is reached
			while(ArgStrings[i][j] != '\0')
			{
				//Check each character in the string is a ASCII CODE for a number
				if(ArgStrings[i][j] < 48 || ArgStrings[i][j] > 57)
				{
					//Character in the string was found to contain a Number character ASCII value
					//Report error and break out of loop
					printf("ERROR: Opperator Expects number in arg %i\n\r", i);
					printf("Interpreted Value: %g\n\r", atof((char*)ArgStrings[i]));
					ERR = 1;
					break;
				}
				j++;
			}
			//Do the calculaion
			result = atof((char*)ArgStrings[1])/atof((char*)ArgStrings[2]);
		}
		if(ERR == 1)
		{
			printf("Possible Result from interpreted arguments : %g\n\r",result);
			ERR = 0;
		}
		else
		{
			printf("Result : %g\n\r",result);
		}
	}
	else{
		//Not enough arguements have been entered
		printf("Not enough arguments entered for the mul function,\n\r enter 'help mul' for help\n\r");
	}
	return -1;

}

/*
 * Function: Help_Function
 * ----------------------------
 *   Prints out the help description of a specific function,
 *   or the entire list of possible commands in the command line interface
 *
 *	 ArgNum =number of arguments expected for calculation
 *	 *ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Help_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	uint8_t j,i;
	//printf("IN the Help function\n\r");
	if(ArgNum == 1){
		printf("\tCommand\tHelp\n\r");
		//Steps through all of the Commands
		for(i = 0; CommandList[i].NameString != 0;i++){
			printf("\t%s\t%s\n\r",CommandList[i].NameString,CommandList[i].HelpString);
		}
	}
	else{
		//Loop through all the arguments and print there corresponding help strings
		for(i=1; i<ArgNum;i++){
			//Loop through all the functions and find which function string matches the entered input string
			for(j=0;CommandList[j].NameString != NULL; j++){
				if(strcasecmp((char *)ArgStrings[i],(char *) CommandList[j].NameString) == 0){
					printf("%s\n\r",(char *) CommandList[j].HelpString);
				}
			}
		}

	}

	return -1;
}


/*
 * Function:Debug_Function
 * ----------------------------
 *   Prints out the help description of a specific function
 *  Returns: Debug_State ==1 ON// Debug_State == 0 OFF
 *
 *  Inputs:
 *	ArgNum =number of arguments expected for calculation
 *	*ArgString[] = array of pointers to the start of the argument words
 *
 */
int8_t Debug_Function(uint8_t ArgNum, uint8_t *ArgStrings[]){
	//Check that only 2 arguments are entered
	if(ArgNum >2){
		printf("Too many arguments entered for the debug function,\r\ntype 'help debug' for help\r\n");
	}
	else if(ArgNum>1){
		//Correct amount of arguments have been entered, determine which state to toggle too
		//Check the input String, to determine which State to toggle Debug_State to
		if(strcasecmp((char *)ArgStrings[1],"On")==0){
			printf("Debug has been turned on\n\r");
			Debug = 1;
		}
		else if(strcmp((char *)ArgStrings[1],"SENSUAL")==0){
			printf("GEEEET RICKITY REEEEEKKKED\n\r");
			Debug = 2;
		}
		else if(strcasecmp((char *)ArgStrings[1],"Off")==0){
			printf("Debug has been turned off\n\r");
			Debug = 0;
		}
		else{
			printf("Input argument has not been found,\r\ntype 'help debug' for help\r\n");

		}
	}
	else{
		printf("Not enough arguments have been entered for the debug function,\r\ntype 'help debug' for help\r\n");
	}

	return -1;
}


void CommandLineParserInit(void)
{
  // Print welcome message
  printf("\014");
  printf("ELEC3730 Assignment 2\n\r");
  printf("Command Line Parser Example\n\r");

}



/*
 * Function: CommandLineParserProcess
 * ----------------------------
 *  Returns void
 *
 *	This function is used to implement the command line interface, when called it fist check to see if the uartReceive buffer has data if so
 *	it will check to see if it is a character or enter value then leave the function.
 *	If it was a enter value, this means a command and arguments has been entered and further action should be take.
 *
 *
 */
void CommandLineParserProcess(void)
{
  uint8_t c; //Holds the current input from the uartBuffer, awaiting for further process
  static uint8_t ArrOfChars[MAXBUFF]; //Holds the complete string of input from the serial communication
  static uint8_t i = 0; //Used to increment how many times a user has interface with the command line up until a enter command
  uint8_t j, count; //Variables used to evaluate the command line input
  uint8_t **array_of_words_pp; //Pointer to a array which holds pointers to strings

  // Check for input and echo back
  if (HAL_UART_Receive(&huart2, &c, 1, 0x0) == HAL_OK)
  {
	//Echo to PUTTY and toggle LED
    printf("%c", c);
    HAL_GPIO_TogglePin(GPIOD, LD4_Pin); // Toggle LED4

    //Check that the current input Character isn't enter and that the bufferlimit hasnt been exceeded
    if(c != 13 && i<100){
    	//All conditions are fine
    	ArrOfChars[i]= c; //Load the character into the input string if not enter
    	i++; //increment the counter
    }
    else{
    	//Either Overflow of data or Enter was pressed
    	if(i == 100){
    		//Overflow has occured, continue process with this string size
    		printf("\nError to many characters entered in command line\n\r");
    	}
    	//Proceed and terminate string with a null character
    	ArrOfChars[i]='\0';
    	i = 0; //start from beginning again
    	printf("\nThe input string was '%s'\n\r",ArrOfChars);

    	//Now handle the input string and print the results
    	count = string_parser(ArrOfChars, &array_of_words_pp);
    	//Print the number of arguments entered
    	printf("--> count = %d\r\n", count);
		if(count != 0){
			//Print out the individual words if arguments entered is larger than 0
    		for (j=0;j<count;j++)
			{
			  printf("---> %2d: '%s'\r\n", j+1, (array_of_words_pp)[j]);
			}

    		//**********************************************************************//
    		//Find out which command was entered and do calculation
        	for(j=0;  CommandList[j].NameString != NULL; j++){
    			if(strcasecmp((char *)array_of_words_pp[0],(char *) CommandList[j].NameString) == 0){
        			//Now do the correct operation based on the match
        			(*CommandList[j].Function_p)(count, array_of_words_pp);
    			}
        	}
		}
		else{
			//Let the user know that they must input commands
			printf("No arguments where entered, type 'list' for commands list,\n\ror 'help command' for specific functions\n\r");
		}
		//Free mememory after the calculation process has occured
    	if (count != 0)
       	{
       	  free(array_of_words_pp[0]);
       	  free(array_of_words_pp);
       	}
    }

  }
}



uint8_t string_parser(uint8_t *inp, uint8_t **array_of_words[])
{
	uint16_t i, j;
	uint8_t *string_copy;
	uint8_t word_count = 0;
	uint8_t flag= 0; //Determines if a Char has been encountered yet in a string

	//printf("function() '%17s'\n",inp);
	//printf("function() Address of array_of_words = %u and value stored in it =%u \n", (uint32_t)array_of_words,(uint32_t)*array_of_words);
	//Copy the string across
	string_copy = malloc(sizeof(uint8_t)*(strlen((const char*)inp)+1));
	strcpy((char *)string_copy,(char *)inp);
	//printf("Address of the start of the copied string = %u\n", (uint32_t)&string_copy);
	//printf("\tCopied string = '%s'\n", string_copy);
	//Find out the word count
	i = 0;
	while(*(inp+i) != '\0'){
		if( (*(inp+i) !=' ') && (*(inp+i) != '\0')){
			if(flag == 0){
				word_count++;
				flag = 1;
			}
		}
		else{
			flag = 0;
		}
		i++;
	}
	//printf("\tNumber of words = %d\n", word_count);
	*array_of_words = malloc(sizeof(char *)*word_count); //Allocate the pointers array

	//Go through the copied string and place a null in the space locations and assing the first word location to array of words
	i=0;
	j =0;
	while(*(string_copy+i) != '\0'){
		if(*(string_copy+i) == ' '){
			//Equal to a space so place a '\0'
			*(string_copy+i)= '\0';
			i++;
		}
		else{
			//Start of the word has been hit
			//printf("Address of first letter word = %u\t Character= %c\n",(uint32_t)&string_copy[i],string_copy[i]);
			(*array_of_words)[j] = &string_copy[i];
			j++;
			while((*(string_copy+i) != ' ' )&& (*(string_copy+i) != '\0' )){
				//Go through till end of the current word
				i++;
			}
		}
	}

	return word_count;
}











