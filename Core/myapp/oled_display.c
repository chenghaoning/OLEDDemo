#include "MyApplication.h"

u8g2_t u8g2;
void oled_init(void )
{
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
}

void oled_key(char key[])
{
    uint8_t PS2_KEY = 0, X1=0,Y1=0,X2=0,Y2=0;
    __set_PRIMASK(1);  //关中断；
    PS2_KEY = PS2_DataKey();	 //手柄按键捕获处理
    __set_PRIMASK(0);//开中断
    switch(PS2_KEY)
    {
        case PSB_SELECT: 	strcpy( key, "PSB_SELECT");  break;
        case PSB_L3:     	strcpy( key, "PSB_L3"); break;
        case PSB_R3:     	strcpy( key, "PSB_R3");  break;
        case PSB_START:  	strcpy( key, "PSB_START");  break;
        case PSB_PAD_UP: 	strcpy( key, "PSB_PAD_UP");  break;
        case PSB_PAD_RIGHT:	strcpy( key, "PSB_PAD_RIGHT");  break;
        case PSB_PAD_DOWN:	strcpy( key, "PSB_PAD_DOWN");  break;
        case PSB_PAD_LEFT:	strcpy( key, "PSB_PAD_LEF");  break;
        case PSB_L2:
        {strcpy( key, "PSB_L2"); }break;
        case PSB_R2:
        {strcpy( key, "PSB_R2");}  break;
        case PSB_L1:     strcpy( key, "PSB_L1");  break;
        case PSB_R1:      strcpy( key, "PSB_R1");  break;
        case PSB_TRIANGLE:	strcpy( key, "PSB_TRIANGLE"); break; 							//灭火
        case PSB_CIRCLE:  	strcpy( key, "PSB_CIRCLE");  break;  	//舵机转
        case PSB_CROSS:    strcpy( key, "PSB_CROSS");  break; 					//鸣笛
        case PSB_SQUARE:  strcpy( key, "PSB_SQUARE");  break;  	//舵机转
        default: strcpy( key, "none"); break;
    }
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_chinese3);
//    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawStr(&u8g2,10,50,key);
    u8g2_SendBuffer(&u8g2);
}

void oled_display()
{
    char distance[6],speed[4],key[20]="none",target[4];
    Hcsr04Start();
    HAL_Delay(200);
    sprintf(distance,":%.1f",Hcsr04Read());
    sprintf(speed,":%d",CarSpeedControl);
    sprintf(target,":%d",Get_TIM4_Speed());
    oled_key(key);
    u8g2_ClearBuffer(&u8g2);
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_gb2312);
    u8g2_DrawGlyph(&u8g2,10,14,0x901F);
    u8g2_DrawGlyph(&u8g2,40,14,0x5ea6);
    u8g2_DrawGlyph(&u8g2,10,30,0x8ddd);
    u8g2_DrawGlyph(&u8g2,40,30,0x79bb);
    u8g2_DrawStr(&u8g2,10,50,key);
    u8g2_SetFont(&u8g2,u8g2_font_fub14_tn);
    u8g2_DrawStr(&u8g2,60,32,distance);
    u8g2_DrawStr(&u8g2,60,16,target);
    u8g2_SendBuffer(&u8g2);
}