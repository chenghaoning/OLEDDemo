/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void pwm_set(uint32_t,TIM_TypeDef* ,void(*Callback)(uint32_t,TIM_TypeDef* ));  
static void HAL_delay_us(__IO uint32_t delay);
Public_t public = 
{
	pwm_set,
    HAL_delay_us
};



#define CPU_FREQUENCY_MHZ    72	
static void HAL_delay_us(__IO uint32_t delay)
{
    int last, curr, val;
    int temp;

    while (delay != 0)
    {
        temp = delay > 900 ? 900 : delay;
        last = SysTick->VAL;
        curr = last - CPU_FREQUENCY_MHZ * temp;
        if (curr >= 0)
        {
            do
            {
                val = SysTick->VAL;
            }
            while ((val < last) && (val >= curr));
        }
        else
        {
            curr += CPU_FREQUENCY_MHZ * 1000;
            do
            {
                val = SysTick->VAL;
            }
            while ((val <= last) || (val > curr));
        }
        delay -= temp;
    }
}
//---------------------------------pwm_set----------------------------------

static void pwm_set(uint32_t date,TIM_TypeDef* TIMx ,void(*Callback)(uint32_t,TIM_TypeDef* ))
{
	(*Callback)(date,TIMx);
}

/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/
#if 1

#include <stdio.h>
//#include "main.h"
int _write(int fd, char *ptr, int len) {
//    HAL_USART_Transmit(&huart1, (uint8_t *) ptr, len, 0xFFFF);
    return len;
}

#endif

/********************************************************
  End Of File
********************************************************/
