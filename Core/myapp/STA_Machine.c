/* Includes ------------------------------------------------------------------*/
#include "MyApplication.h"

/* Private define-------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes------------------------------------------------*/
static void Fun_STA1(void);
static void Fun_STA2(void);
static void Fun_STA3(void);
static void Fun_STA4(void);
static void Fun_STA5(void);

/* Public variables-----------------------------------------------------------*/
//�ṹ�嶨��    
STA_Machine_t   STA_Machine = 
{
	STA4,
	
	Fun_STA1,
	Fun_STA2,
	Fun_STA3,
	Fun_STA4,
	Fun_STA5,
};

/*
	* @name   Fun_STA1 - 5
	* @brief  ״̬����
	* @param  None
	* @retval None      
*/
void Fun_STA1()
{
    if (1)
    {

        Speed_FR=3000;
        Speed_BR=4000;
        Speed_BL=3044;
        Speed_BR=4000;
        oled_display();
        app_CarstateOutput();
//        Car_Run(100);
        //״̬���л���״̬2
//        STA_Machine.ucSTA_Machine_Status = STA2;
    }
}

void Fun_STA2()
{
    Car_Stop();
    if (Hcsr04Read() < 10)
    {
        HAL_Delay(10);
        if (Hcsr04Read() < 10)
        {
            Car_Stop();
            HAL_Delay(50);
            Car_Back(CarSpeedControl);
            HAL_Delay(1000);
            Car_Stop();
            STA_Machine.ucSTA_Machine_Status = STA3;
        }
    }
    else { Car_Run(CarSpeedControl); }
    oled_display();
}

void Fun_STA3()
{
    Car_Stop();
    Car_SpinLeft(LCarSpeed,RCarSpeed);
    HAL_Delay(500);
    Car_Stop();
    if (Hcsr04Read() < 20)
    {
        HAL_Delay(10);
        if (Hcsr04Read() < 20)
        {
            Fun_STA3();
        }
    }
    else{STA_Machine.ucSTA_Machine_Status = STA1;}
}

void Fun_STA4()
{
    Car_Stop();
    app_ps2_deal();
    app_CarstateOutput();
    oled_display();
	//״̬���л���״̬5
//	STA_Machine.ucSTA_Machine_Status = STA1;
}

void Fun_STA5()
{

	//״̬���л�����ʼ״̬1
//	STA_Machine.ucSTA_Machine_Status = STA1;
}
/********************************************************
  End Of File
********************************************************/
