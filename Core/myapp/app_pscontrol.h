#ifndef CPROJECT_APP_PSCONTROL_H
#define CPROJECT_APP_PSCONTROL_H
/*小车运行状态枚举*/
enum{

    enSTOP = 0,
    enRUN,
    enBACK,
    enLEFT,
    enRIGHT,
    enUPLEFT,
    enUPRIGHT,
    enDOWNLEFT,
    enDOWNRIGHT,
    enTLEFT,
    enTRIGHT

};
uint8_t app_ps2_deal(void);
void app_CarstateOutput(void);

extern int g_CarState; //  1前2后3左4右0停止
extern int CarSpeedControl;
#define LCarSpeed   20
#define RCarSpeed   20
#endif
