/* Includes ------------------------------------------------------------------*/
#include "..\myapp\MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim == (&htim2))
    {
        Hcsr04TimOverflowIsr(&htim);
    }

    if (htim == (&htim6))
    {

        speed_read_TimIcIsr(&htim);
    }
    if (htim == (&htim7))
    {

    }

}
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    Hcsr04TimIcIsr(htim);
}
//-----------------------------------------u8g2库回调函数-------------------------------------------

//--------------------------------------pwm_set回调函数-------------------------------------------------------
extern void set_freq(uint32_t freq_MHz ,TIM_TypeDef* TIMx)
{
	uint16_t Period;
	uint16_t Prescaler;				
	uint32_t TIMxCLK;	//如果定时器频率不一样
/* 	if ((TIMx == TIM1) || (TIMx == TIM8) || (TIMx == TIM9) || (TIMx == TIM10) || (TIMx == TIM11))
	{
		TIMxCLK = SystemCoreClock;
	}
	else	
	{
		TIMxCLK = SystemCoreClock / 2;
	}
	TIMxCLK = SystemCoreClock; */
	
	if (freq_MHz < 100)
		{
			Prescaler = 10000 - 1;							/* 分频比 = 10000 */
			Period =  (TIMxCLK / 10000) / freq_MHz  - 1;		/* 自动重装的值 */
		}
	else if (freq_MHz < 3000)
		{
			Prescaler = 100 - 1;							/* 分频比 = 100 */
			Period =  (TIMxCLK / 100) / freq_MHz  - 1;			/* 自动重装的值 */
		}
	else												/* 大于4K的频率，无需分频 */
		{
			Prescaler = 0;									/* 分频比 = 1 */
			Period = TIMxCLK / freq_MHz - 1;					/* 自动重装的值 */
		}
    TIMx->ARR = Period; 
    TIMx->EGR = TIM_EGR_UG;  
}
extern void set_dutycircle(uint32_t dutycycle,TIM_TypeDef* TIMx)
{
	uint32_t pulse;
	pulse=TIMx->ARR*dutycycle /100;
	TIMx->CCR1=pulse;
    TIMx->EGR = TIM_EGR_UG; 
}
/* Public variables-----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/      

/********************************************************
  End Of File
********************************************************/
