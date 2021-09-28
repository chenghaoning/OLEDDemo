#ifndef __PUBLIC_H_
#define __PUBLIC_H_

/* Public define-------------------------------------------------------------*/

//定义枚举类型 -> TRUE/FALSE位
typedef enum 
{
  FALSE = 0U, 
  TRUE = !FALSE
} FlagStatus_t;

typedef enum 
{
  FAILED = 0U, 
  PASSED = !FAILED
} TestStatus_t;

typedef struct
{
	void (*pwm_set)(uint32_t,TIM_TypeDef* ,void(*Callback)(uint32_t,TIM_TypeDef* ));  
  void (*HAL_delay_us)(__IO uint32_t delay);
}Public_t;


/* extern variables-----------------------------------------------------------*/
extern Public_t public;
extern void set_freq(uint32_t freq_MHz ,TIM_TypeDef* TIMx);
extern void set_dutycircle(uint32_t dutycycle,TIM_TypeDef* TIMx);

//定义结构体类型
/*******预编译宏定义*******/
//#define Monitor_Run_Code   //代码运行监控器 
//#define Hardware_TEST      //硬件测试

#endif
/********************************************************
  End Of File
********************************************************/
