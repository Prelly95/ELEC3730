//     $Date: 2017-04-04 04:00:13 +1000 (Tue, 04 Apr 2017) $
// $Revision: 872 $
//   $Author: Peter $

#include "Ass-02.h"

//
// REPLACE THE EXAMPLE CODE WITH YOUR CODE
//



void Ass_02_Main(void)
{
  uint16_t i=0;
//  uint8_t Debug = 0; //Intiailise Debug state as OFF
   // Initialise
  CommandLineParserInit();
  CalculatorInit();

  // Loop indefinitely
  while (1)
  {
    CommandLineParserProcess();
    CalculatorProcess();
    if (i++ > 10000)
    {
      HAL_GPIO_TogglePin(GPIOD, LD3_Pin); // Toggle LED3
      i=0;
    }
  }
}
