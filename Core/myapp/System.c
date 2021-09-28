/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/
static void Run(void); 
static void Error_handler(void);
static void Assert_Failed(void);
	
/* Public variables-----------------------------------------------------------*/
System_t System = 
{
	Run,
	Error_handler,
	Assert_Failed
};

/* Private function prototypes------------------------------------------------*/      

/*
	* @name   Run
	* @brief  系统运行
	* @param  None
	* @retval None      
*/
static void Run()
{
	//运行状态机
	switch(STA_Machine.ucSTA_Machine_Status)
	{
		case STA1: STA_Machine.Fun_STA1();	break;
		case STA2: STA_Machine.Fun_STA2();	break;
		case STA3: STA_Machine.Fun_STA3();	break;
		case STA4: STA_Machine.Fun_STA4();	break;
		case STA5: STA_Machine.Fun_STA5();	break;
		default: STA_Machine.ucSTA_Machine_Status = STA1;
	}
}

/*
	* @name   Error_Handler
	* @brief  系统错误处理
	* @param  None
	* @retval None      
*/
static void Error_handler()
{
	/* User can add his own implementation to report the HAL error return state */
}

/*
	* @name   Assert_Failed
	* @brief  函数参数错误处理
	* @param  None
	* @retval None      
*/
static void Assert_Failed()
{
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}
/********************************************************
  End Of File
********************************************************/
