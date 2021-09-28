#include "MyApplication.h"

u8g2_t u8g2;
void oled_init(void )
{
    u8g2Init(&u8g2);
    u8g2_ClearBuffer(&u8g2);
}

void oled_distance()
{
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_chinese3);
    u8g2_DrawGlyph(&u8g2,10,30,0x8ddd);
    u8g2_DrawGlyph(&u8g2,40,30,0x79bb);
    char temps;
    sprintf(&temps,":%d",CarSpeedControl);
    u8g2_SetFont(&u8g2,u8g2_font_fub14_tn);
    u8g2_DrawStr(&u8g2,60,32,&temps);
    u8g2_SendBuffer(&u8g2);
}
void oled_speed()
{
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_chinese3);
    u8g2_DrawGlyph(&u8g2,10,14,0x901F);
    u8g2_DrawGlyph(&u8g2,40,14,0x5ea6);
    char temps;
    sprintf(&temps,":%d",CarSpeedControl);
    u8g2_SetFont(&u8g2,u8g2_font_fub14_tn);
    u8g2_DrawStr(&u8g2,60,16,&temps);
    u8g2_SendBuffer(&u8g2);
}

void oled_key()
{
    char temps="none";
    uint8_t PS2_KEY = 0;
    PS2_KEY = PS2_DataKey();
    switch(PS2_KEY)
    {
        case PSB_SELECT: 	temps="PSB_SELECT";  break;
        case PSB_L3:     	temps="PSB_L3";  break;
        case PSB_R3:     	temps="PSB_R3";  break;
        case PSB_START:  	temps="PSB_START";  break;
        case PSB_PAD_UP: 	temps="PSB_PAD_UP";  break;
        case PSB_PAD_RIGHT:	temps="PSB_PAD_RIGHT";  break;
        case PSB_PAD_DOWN:	temps="PSB_PAD_DOWN";  break;
        case PSB_PAD_LEFT:	temps="PSB_PAD_LEFT \n";  break;
        case PSB_L2:
        {temps="PSB_L2";}break;
        case PSB_R2:
        {temps="PSB_R2";}  break;
        case PSB_L1:     temps="PSB_L1";  break;
        case PSB_R1:      temps="PSB_R1";  break;
        case PSB_TRIANGLE:	temps="PSB_TRIANGLE"; break; 							//灭火
        case PSB_CIRCLE:  	temps="PSB_CIRCLE";  break;  	//舵机转
        case PSB_CROSS:    temps="PSB_CROSS";  break; 					//鸣笛
        case PSB_SQUARE:  temps="PSB_SQUARE";  break;  	//舵机转
        default: temps="none"; break;
    }
    u8g2_SetFont(&u8g2,u8g2_font_wqy16_t_chinese3);
    u8g2_DrawStr(&u8g2,10,50,&temps);
    u8g2_SendBuffer(&u8g2);
}