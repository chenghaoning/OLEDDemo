/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"


/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Peripheral_Set(void); 

/* Public variables-----------------------------------------------------------*/
MyInit_t MyInit = 
{
	Peripheral_Set
};

/* Private function prototypes------------------------------------------------*/      


/*
	* @name   Peripheral_Set
	* @brief  Õ‚…Ë…Ë÷√
	* @param  None
	* @retval None      
*/
static void Peripheral_Set()
{
//    TIM_Coder_Start();
//    TIM8_PWM_Start();
//    TIM6_Int_Start();
    u8g2Init(&u8g2);
    oled_init();
    Hcsr04Init(&htim2,TIM_CHANNEL_1);
//    PS2_SetInit();
}

/********************************************************
  End Of File
********************************************************/
