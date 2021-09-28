#include "MyApplication.h"

u8g2_t u8g2;
void oled_init(void )
{
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
}

void oled_distance()
{
    char temps;
    sprintf(&temps,":%d",Hcsr04Read());
    u8g2_SetFont(&u8g2,u8g2_font_fub14_tn);
    u8g2_DrawStr(&u8g2,60,32,&temps);
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_gb2312);
    u8g2_DrawGlyph(&u8g2,10,30,0x8ddd);
    u8g2_DrawGlyph(&u8g2,40,30,0x79bb);
    u8g2_SendBuffer(&u8g2);
}
void oled_speed()
{
    char temps;
    sprintf(&temps,":%d",CarSpeedControl);
    u8g2_SetFont(&u8g2,u8g2_font_fub14_tn);
    u8g2_DrawStr(&u8g2,60,16,&temps);
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_gb2312);
    u8g2_DrawGlyph(&u8g2,10,14,0x901F);
    u8g2_DrawGlyph(&u8g2,40,14,0x5ea6);
    u8g2_SendBuffer(&u8g2);
}

void oled_key()
{
    char temps[20]="none";
    uint8_t PS2_KEY = 4;
//    __set_PRIMASK(1);  //关中断；
//    PS2_KEY = PS2_DataKey();	 //手柄按键捕获处理
//    __set_PRIMASK(0);//开中断
    switch(PS2_KEY)
    {
        case PSB_SELECT: 	strcpy( temps, "abcdefgh");  break;
        case PSB_L3:     	strcpy( temps, "PSB_L3"); break;
        case PSB_R3:     	strcpy( temps, "PSB_R3");  break;
        case PSB_START:  	strcpy( temps, "PSB_START");  break;
        case PSB_PAD_UP: 	strcpy( temps, "PSB_PAD_UP");  break;
        case PSB_PAD_RIGHT:	strcpy( temps, "PSB_PAD_RIGHT");  break;
        case PSB_PAD_DOWN:	strcpy( temps, "PSB_PAD_DOWN");  break;
        case PSB_PAD_LEFT:	strcpy( temps, "PSB_PAD_LEF");  break;
        case PSB_L2:
        {strcpy( temps, "PSB_L2");}break;
        case PSB_R2:
        {strcpy( temps, "PSB_R2");}  break;
        case PSB_L1:     strcpy( temps, "PSB_L1");  break;
        case PSB_R1:      strcpy( temps, "PSB_R1");  break;
        case PSB_TRIANGLE:	strcpy( temps, "PSB_TRIANGLE"); break; 							//灭火
        case PSB_CIRCLE:  	strcpy( temps, "PSB_CIRCLE");  break;  	//舵机转
        case PSB_CROSS:    strcpy( temps, "PSB_CROSS");  break; 					//鸣笛
        case PSB_SQUARE:  strcpy( temps, "PSB_SQUARE");  break;  	//舵机转
        default: strcpy( temps, "none"); break;
    }
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_chinese3);
    u8g2_DrawStr(&u8g2,10,50,temps);
    u8g2_SendBuffer(&u8g2);
}