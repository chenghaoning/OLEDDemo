
/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ps2Control.c
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        ps2业务控制流程源文件
* @details
* @par History
*
* version:		liusen_20170717
*/

#include "MyApplication.h"

int g_CarState = enSTOP; //  1前2后3左4右0停止
int CarSpeedControl = 30;

/**
* Function       app_ps2_deal
* @author        liusen
* @date          2017.08.23
* @brief         PS2协议处理
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_ps2_deal(void)
{
    uint8_t PS2_KEY = 0, X1=0,Y1=0,X2=0,Y2=0;


    __set_PRIMASK(1);  //关中断；
    PS2_KEY = PS2_DataKey();	 //手柄按键捕获处理
    __set_PRIMASK(0);//开中断

    switch(PS2_KEY)
    {
        case PSB_SELECT: 	printf("PSB_SELECT \n");  break;
        case PSB_L3:     	g_CarState = enSTOP;  printf("PSB_L3 \n");  break;
        case PSB_R3:     	g_CarState = enSTOP;	 printf("PSB_R3 \n");  break;
        case PSB_START:  	printf("PSB_START \n");  break;
        case PSB_PAD_UP: 	g_CarState = enRUN;   printf("PSB_PAD_UP \n");  break;
        case PSB_PAD_RIGHT:	g_CarState = enRIGHT; printf("PSB_PAD_RIGHT \n");  break;
        case PSB_PAD_DOWN:	g_CarState = enBACK;  printf("PSB_PAD_DOWN \n");  break;
        case PSB_PAD_LEFT:	g_CarState = enLEFT;  printf("PSB_PAD_LEFT \n");  break;
        case PSB_L2:
        {
            CarSpeedControl += 100;
            if (CarSpeedControl > 7200)
            {
                CarSpeedControl = 7199;
            }

            printf("PSB_L2 \n");

        }break;
        case PSB_R2:
        {
            CarSpeedControl -= 100;
            if (CarSpeedControl < 30)
            {
                CarSpeedControl = 30;
            }
            printf("PSB_R2 \n");

        }  break;
        case PSB_L1:      	printf("PSB_L1 \n");  break;
        case PSB_R1:      	printf("PSB_R1 \n");  break;
        case PSB_TRIANGLE:	printf("PSB_TRIANGLE \n"); break; 							//灭火
        case PSB_CIRCLE:  	g_CarState = enRIGHT; printf("PSB_CIRCLE \n");  break;  	//舵机转
        case PSB_CROSS:     printf("PSB_CROSS \n");  break; 					//鸣笛
        case PSB_SQUARE:  	g_CarState = enLEFT; printf("PSB_SQUARE \n");  break;  	//舵机转
        default: g_CarState = enSTOP; break;
    }
    //获取模拟值
    if(PS2_KEY == PSB_L1 || PS2_KEY == PSB_R1)
    {
        X1 = PS2_AnologData(PSS_LX);
        Y1 = PS2_AnologData(PSS_LY);
        X2 = PS2_AnologData(PSS_RX);
        Y2 = PS2_AnologData(PSS_RY);
        /*左摇杆*/
        if (Y1 < 5 && X1 > 80 && X1 < 180) //上
        {
            g_CarState = enRUN;

        }
        else if (Y1 > 230 && X1 > 80 && X1 < 180) //下
        {
            g_CarState = enBACK;

        }
        else if (X1 < 5 && Y1 > 80 && Y1 < 180) //左
        {
            g_CarState = enLEFT;

        }
        else if (Y1 > 80 && Y1 < 180 && X1 > 230)//右
        {
            g_CarState = enRIGHT;

        }
        else if (Y1 <= 80 && X1 <= 80) //左上
        {
            g_CarState = enUPLEFT;

        }
        else if (Y1 <= 80 && X1 >= 180) //右上
        {
            g_CarState = enUPRIGHT;

        }
        else if (X1 <= 80 && Y1 >= 180) // 左下
        {
            g_CarState = enDOWNLEFT;

        }
        else if (Y1 >= 180 && X1 >= 180) //右下
        {
            g_CarState = enDOWNRIGHT;

        }
        else//停
        {
            g_CarState = enSTOP;
        }
    }
}

//void app_CarstateOutput(void)
//{
////根据小车状态做相应的动作
//    switch (g_CarState)
//    {
//        case enSTOP: Car_Stop(); break;
//        case enRUN: Car_Run(CarSpeedControl); break;
//        case enLEFT: Car_Left(CarSpeedControl); break;
//        case enRIGHT: Car_Right(CarSpeedControl); break;
//        case enBACK: Car_Back(CarSpeedControl); break;
//        case enTLEFT: Car_SpinLeft(CarSpeedControl, CarSpeedControl); break;
//        case enTRIGHT: Car_SpinRight(CarSpeedControl, CarSpeedControl); break;
//
//        case enUPLEFT:break;//左上转
//        case enDOWNLEFT:break;//左下转
//        case enUPRIGHT:break;//右上转
//        case enDOWNRIGHT:break;//右下转
//        default: Car_Stop(); break;
//    }
//
//}
