#include "..\myapp\MyApplication.h"

volatile float kp = 5.0;
volatile float ki = 1.0;

#define outMax    7199
#define outMin    -7199
#define TARGET 150

int Num=0;
int Speed_FL=0;
int Speed_FR=0;
int Speed_BL=0;
int Speed_BR=0;
/**************************************
*函数名:  PID_Compute_TIM1
* 注释 :  TIM1
* 用途 :  右前轮PID函数
**************************************/
volatile float output1;
volatile float error0_TIM1, error1_TIM1, error2_TIM1;

float PID_Compute_TIM1(float Setpoint1, float ADC_Buf1)
{
    float PIout1 = 0;
    float P_num=1.0,I_num=1.0;

    error0_TIM1 = Setpoint1 - ADC_Buf1;          //取本次误差

    PIout1 = kp*error0_TIM1*P_num - ki * error1_TIM1*I_num;

    output1 += PIout1;

    if(output1 > outMax) 		                   //输出范围限定
    {
        output1 = outMax;
    }
    else if(output1 < outMin)
    {
        output1 = outMin;
    }
    else
    {
        output1 = output1;
    }

    error2_TIM1 = error1_TIM1;		            //保留本次误差，以供下次计算
    error1_TIM1 = error0_TIM1;

    Motor_1_Drive(output1);
    Motor_2_Drive(output1);
    return  output1;
}

/**************************************
*函数名:  PID_Compute_TIM3
* 注释 :  TIM3
* 用途 :  左前轮PID函数
**************************************/
volatile float output3;
volatile float error0_TIM3, error1_TIM3, error2_TIM3;

float PID_Compute_TIM3(float Setpoint3, float ADC_Buf3)  //Setpoint = Setspeed,ADC_Buf = Speedpa
{
/*    float PIout3 = 0;
    float P_num=1.0,I_num=1.0;

    error0_TIM3 = Setpoint3 - ADC_Buf3;          //take this error     计算偏差

    PIout3 = kp*error0_TIM3*P_num - ki * error1_TIM3*I_num;

    output3 += PIout3;

    if(output3 > outMax) 		                   //limit output range
    {
        output3 = outMax;
    }
    else if(output3 < outMin)
    {
        output3 = outMin;
    }
    else
    {
        output3 = output3;
    }

    error2_TIM3 = error1_TIM3;		            //save this error offered the next one
    error1_TIM3 = error0_TIM3;

    Motor_2_Drive(output3);

    return  output3;*/
    float PIout3 = 0;
    float P_num=1.0,I_num=1.0;

    error0_TIM3 = Setpoint3 - ADC_Buf3;          //take this error     计算偏差

    PIout3 = kp*error0_TIM3*P_num - ki * error1_TIM3*I_num;

    output3 += PIout3;

    if(output3 > outMax) 		                   //limit output range
    {
        output3 = outMax;
    }
    else if(output3 < outMin)
    {
        output3 = outMin;
    }
    else
    {
        output3 = output3;
    }

    error2_TIM3 = error1_TIM3;		            //save this error offered the next one
    error1_TIM3 = error0_TIM3;

//    Motor_2_Drive(output3);

    return  output3;

}


/**************************************
*函数名:  PID_Compute_TIM4
* 注释 :  TIM4
* 用途 :  右后轮PID函数
**************************************/
volatile float output4;
volatile float error0_TIM4, error1_TIM4, error2_TIM4;

float PID_Compute_TIM4(float Setpoint4, float ADC_Buf4)  //Setpoint = Setspeed,ADC_Buf = Speedpa
{
    float PIout4 = 0;
    float P_num=1.0,I_num=1.0;

    error0_TIM4 = Setpoint4 - ADC_Buf4;          //take this error     计算偏差

    PIout4 = kp*error0_TIM4*P_num - ki * error1_TIM4*I_num;

    output4 += PIout4;

    if(output4 > outMax) 		                   //limit output range
    {
        output4 = outMax;
    }
    else if(output4 < outMin)
    {
        output4 = outMin;
    }
    else
    {
        output4 = output4;
    }

    error2_TIM4 = error1_TIM4;		            //save this error offered the next one
    error1_TIM4 = error0_TIM4;

    Motor_3_Drive(output4);

    return  output4;
}
/**************************************
*函数名:  PID_Compute_TIM5
* 注释 :  TIM5
* 用途 :  左后轮PID函数
**************************************/

volatile float output5;
volatile float error0_TIM5, error1_TIM5, error2_TIM5;

float PID_Compute_TIM5(float Setpoint5, float ADC_Buf5)  //Setpoint = Setspeed,ADC_Buf = Speedpa
{
    float PIout5 = 0;
    float P_num=1.0,I_num=1.0;

    error0_TIM5 = Setpoint5 - ADC_Buf5;          //take this error     计算偏差

    PIout5 = kp*error0_TIM5*P_num - ki * error1_TIM5*I_num;

    output5 += PIout5;

    if(output5 > outMax) 		                   //limit output range
    {
        output5 = outMax;
    }
    else if(output5 < outMin)
    {
        output5 = outMin;
    }
    else
    {
        output5 = output5;
    }

    error2_TIM5 = error1_TIM5;		            //save this error offered the next one
    error1_TIM5 = error0_TIM5;

    Motor_4_Drive(output5);

    return  output5;
}

uint8_t Get_TIM1_Speed(void)
{
    int Speed=0;
    Speed=__HAL_TIM_GetCounter(&htim1)-32768;
    __HAL_TIM_SET_COUNTER(&htim1,32768);
    PID_Compute_TIM1(Speed_FR,Speed);
    return Speed;
//	printf("%d\r\n",Speed);
}

uint8_t Get_TIM3_Speed(void)
{
    int Speed=0;
    Speed=__HAL_TIM_GetCounter(&htim3)-32768;
    __HAL_TIM_SET_COUNTER(&htim3,32768);
    PID_Compute_TIM3(Speed_FL,Speed);
    return Speed;
//	printf("%d\r\n",Speed);
}

uint8_t Get_TIM4_Speed(void)
{
    int Speed=0;
    Speed=__HAL_TIM_GetCounter(&htim4)-32768;
    __HAL_TIM_SET_COUNTER(&htim4,32768);
    PID_Compute_TIM4(Speed_BR,Speed);
    return Speed;
//	printf("%d\r\n",Speed);
}

uint8_t Get_TIM5_Speed(void)
{
    int Speed=0;
    Speed=__HAL_TIM_GetCounter(&htim5)-32768;
    __HAL_TIM_SET_COUNTER(&htim5,32768);
    PID_Compute_TIM5(Speed_BL,Speed);
    return Speed;
//	printf("%d\r\n",Speed);
}

//定时器2中断服务程序
void speed_read_TimIcIsr(TIM_HandleTypeDef *htim)
{       Get_TIM1_Speed();
        Get_TIM3_Speed();
        Get_TIM4_Speed();
        Get_TIM5_Speed();
}


void Motor_1_Drive(int Speed)
{
    if(Speed>=0)
    {
        if(Speed>7199)Speed=7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,7199-Speed);
        DIR1_F;
    }
    else
    {
        if(Speed<-7199)Speed=-7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,abs(Speed));
        DIR1_B;
    }
}

void Motor_2_Drive(int Speed)
{
    if(Speed>=0)
    {
        if(Speed>7199)Speed=7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,7199-Speed);
        DIR2_F;
    }
    else
    {
        if(Speed<-7199)Speed=-7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,abs(Speed));
        DIR2_B;
    }
}

void Motor_3_Drive(int Speed)
{
    if(Speed>=0)
    {
        if(Speed>7199)Speed=7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,7199-Speed);
        DIR3_F;
    }
    else
    {
        if(Speed<-7199)Speed=-7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,abs(Speed));
        DIR3_B;
    }
}

void Motor_4_Drive(int Speed)
{
    if(Speed>=0)
    {
        if(Speed>7199)Speed=7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,7199-Speed);
        DIR4_F;
    }
    else
    {
        if(Speed<-7199)Speed=-7199;
        __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,abs(Speed));
        DIR4_B;
    }
}

void TIM_Coder_Start(void)				 //定时器1编码器配置/PA8-A相  PA9-B相
{
    HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
    HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_2);
    HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim5,TIM_CHANNEL_2);

    __HAL_TIM_SET_COUNTER(&htim1,32768);
    __HAL_TIM_SET_COUNTER(&htim3,32768);
    __HAL_TIM_SET_COUNTER(&htim4,32768);
    __HAL_TIM_SET_COUNTER(&htim5,32768);
}

void TIM8_PWM_Start(void)							 //TIM8四通道分别输出PWM1/PWM2/PWM3/PWM4,对应引脚为PC6/PC7/PC8/PC9
{
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_4);
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,0);
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,0);
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,0);
    __HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_4,0);
}
void TIM6_Int_Start()
{
    HAL_TIM_Base_Start_IT(&htim6);
}


