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
//½á¹¹Ìå¶¨Òå    
STA_Machine_t   STA_Machine = 
{
	STA1,
	
	Fun_STA1,
	Fun_STA2,
	Fun_STA3,
	Fun_STA4,
	Fun_STA5,
};

/*
	* @name   Fun_STA1 - 5
	* @brief  ×´Ì¬º¯Êý
	* @param  None
	* @retval None      
*/
void Fun_STA1()
{
//    Car_Stop();
    if (1)
    {
        oled_display();
        //×´Ì¬»úÇÐ»»ÖÁ×´Ì¬2
//        STA_Machine.ucSTA_Machine_Status = STA2;
    }
}

void Fun_STA2()
{
//    Car_Stop();
//    if (Hcsr04Read() < 10) {
//        Car_Stop();
//        HAL_Delay(50);
//        Car_Back(CarSpeedControl);
//        HAL_Delay(1000);
//        Car_Stop();
//        STA_Machine.ucSTA_Machine_Status = STA3;
//    }
//    else { Car_Run(CarSpeedControl); }
//    oled_distance();
//    oled_speed();
}

void Fun_STA3()
{
//    Car_Stop();
//    Car_SpinLeft(LCarSpeed,RCarSpeed);
//    HAL_Delay(1000);
//    Car_Stop();
//    if (Hcsr04Read() < 20) {
//        Fun_STA3();
//    }
//    else{STA_Machine.ucSTA_Machine_Status = STA1;}
}

void Fun_STA4()
{
    app_ps2_deal();
//    app_CarstateOutput();
    oled_distance();
    oled_speed();
	//×´Ì¬»úÇÐ»»ÖÁ×´Ì¬5
//	STA_Machine.ucSTA_Machine_Status = STA1;
}

void Fun_STA5()
{

    oled_key();
    HAL_Delay(100);
	//×´Ì¬»úÇÐ»»ÖÁ³õÊ¼×´Ì¬1
//	STA_Machine.ucSTA_Machine_Status = STA1;
}
/********************************************************
  End Of File
********************************************************/
