//
//
///**
//* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
//* @file         protcol.c
//* @author       liusen
//* @version      V1.0
//* @date         2017.08.18
//* @brief        协议解析总入口
//* @details
//* @par History  见如下说明
//*
//* version:	liusen_20170818
//*/
//
//#include "MyApplication.h"
//
//
//
//uint8_t ProtocolString[80] = {0};
//int CarSpeedControl = 30;
//
//
//
//
//#define 	run_car     '1'//按键前
//#define 	back_car    '2'//按键后
//#define 	left_car    '3'//按键左
//#define 	right_car   '4'//按键右
//#define 	stop_car    '0'//按键停
//
//int g_CarState = enSTOP; //  1前2后3左4右0停止
//
///**
//* Function       StringFind
//* @author        liusen
//* @date          2017.08.18
//* @brief         字符串查找
//* @param[in]     pSrc:源字符串; pDst:查找的字符串; v_iStartPos:源字符串起始位置
//* @param[out]    void
//* @retval        void
//* @par History   无
//*/
//
//int StringFind(const char *pSrc, const char *pDst, int v_iStartPos)
//{
//    int i, j;
//    for (i = v_iStartPos; pSrc[i]!='\0'; i++)
//    {
//        if(pSrc[i]!=pDst[0])
//            continue;
//        j = 0;
//        while(pDst[j] !='\0' && pSrc[i+j]!='\0')
//        {
//            j++;
//            if(pDst[j]!=pSrc[i+j])
//                break;
//        }
//        if(pDst[j]=='\0')
//            return i;
//    }
//    return -1;
//}
//
//
///**
//* Function       ProtocolCpyData
//* @author        liusen
//* @date          2017.08.18
//* @brief         串口数据拷贝到新的buf中防止处理过程中被新数据覆盖
//* @param[in]     void
//* @param[out]    void
//* @retval        void
//* @par History   无
//*/
//void ProtocolCpyData(void)
//{
////    memcpy(ProtocolString, inputString, g_packnum + 1);
////    memset(inputString, 0x00, sizeof(inputString));
//}
//
///**
//* Function       Protocol
//* @author        liusen
//* @date          2017.08.18
//* @brief         协议入口
//* @param[in]     void
//* @param[out]    void
//* @retval        void
//* @par History   无
//*/
//void Protocol(void)
//{
//    ProtocolCpyData();
//
//    /*解析模式切换*/
//    //先判断是否是模式选择
//    if(StringFind((const char *)ProtocolString, (const char *)"MODE", 0) > 0
//       && StringFind((const char *)ProtocolString, (const char *)"4WD", 0) > 0)
//    {
//
//        if (ProtocolString[10] == '0') //停止模式
//        {
//            Car_Stop();
//            g_CarState = enSTOP;
//        }
//
//        memset(ProtocolString, 0x00, sizeof(ProtocolString));
//        return;
//    }
//
//    //解析上位机发来的通用协议指令,并执行相应的动作
//    //如:$1,0,0,0,0,0,0,0,0,0#    小车前进
//    if (StringFind((const char *)ProtocolString, (const char *)"4WD", 0) == -1)
//    {
//        //小车原地左旋右旋判断
//        if (ProtocolString[3] == '1')      //小车原地左旋
//        {
//            g_CarState = enTLEFT;
//        }
//        else if (ProtocolString[3] == '2') //小车原地右旋
//        {
//            g_CarState = enTRIGHT;
//        }
//        else
//        {
//            g_CarState = enSTOP;
//        }
//
//        //小车加减速判断
//        if (ProtocolString[7] == '1')    //加速，每次加600
//        {
//            CarSpeedControl += 600;
//            if (CarSpeedControl > 7200)
//            {
//                CarSpeedControl = 7200;
//            }
//        }
//        if (ProtocolString[7] == '2')	//减速，每次减600
//        {
//            CarSpeedControl -= 600;
//            if (CarSpeedControl < 3600)
//            {
//                CarSpeedControl = 3600;
//            }
//        }
//        //小车的前进,后退,左转,右转,停止动作
//        if (g_CarState != enTLEFT && g_CarState != enTRIGHT)
//        {
//            switch (ProtocolString[1])
//            {
//                case run_car:   g_CarState = enRUN;  break;
//                case back_car:  g_CarState = enBACK;  break;
//                case left_car:  g_CarState = enLEFT;  break;
//                case right_car: g_CarState = enRIGHT;  break;
//                case stop_car:  g_CarState = enSTOP;  break;
//                default: g_CarState = enSTOP; break;
//            }
//        }
//
//        memset(ProtocolString, 0x00, sizeof(ProtocolString));
//
//        //根据小车状态做相应的动作
//        switch (g_CarState)
//        {
//            case enSTOP: Car_Stop(); break;
//            case enRUN: Car_Run(CarSpeedControl); break;
//            case enLEFT: Car_Left(CarSpeedControl); break;
//            case enRIGHT: Car_Right(CarSpeedControl); break;
//            case enBACK: Car_Back(CarSpeedControl); break;
//            case enTLEFT: Car_SpinLeft(CarSpeedControl, CarSpeedControl); break;
//            case enTRIGHT: Car_SpinRight(CarSpeedControl, CarSpeedControl); break;
//            default: Car_Stop(); break;
//        }
//    }
//
//
//}
//
//
