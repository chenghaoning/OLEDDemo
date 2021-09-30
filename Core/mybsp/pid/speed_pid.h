#ifndef TEXT_CAR_DRIVER_H
#define TEXT_CAR_DRIVER_H


extern int Num;
extern int Speed_FL;
extern int Speed_FR;
extern int Speed_BL;
extern int Speed_BR;

#define DIR1_F HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,SET)
#define DIR1_B HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,RESET)

#define DIR2_F HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,SET)
#define DIR2_B HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,RESET)

#define DIR3_F HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,SET)
#define DIR3_B HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,RESET)

#define DIR4_F HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,SET)
#define DIR4_B HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,RESET)


void TIM_Coder_Start(void);						 //定时器1编码器配置/PA8-A相  PA9-B相
void TIM8_PWM_Start(void);							 //TIM8四通道分别输出PWM1/PWM2/PWM3/PWM4,对应引脚为PC6/PC7/PC8/PC9
void TIM6_Int_Start(void );


//定时器1编码器配置/PA8-A相  PA9-B相，In1-C0  In2-C6，OUT1-电机+  OUT2-电机-
//定时器3编码器配置/PA6-A相  PA7-B相，In1-C1  In2-C7，OUT1-电机+  OUT2-电机-
//定时器4编码器配置/PB6-A相  PB7-B相，In1-C2  In2-C8，OUT1-电机+  OUT2-电机-
//定时器5编码器配置/PA0-A相  PA1-B相，In1-C3  In2-C9，OUT1-电机+  OUT2-电机-

void Motor_1_Drive(int Speed);
void Motor_2_Drive(int Speed);
void Motor_3_Drive(int Speed);
void Motor_4_Drive(int Speed);

float PID_Compute_TIM1(float Setpoint1, float ADC_Buf1);
float PID_Compute_TIM3(float Setpoint3, float ADC_Buf3);
float PID_Compute_TIM4(float Setpoint4, float ADC_Buf4);
float PID_Compute_TIM5(float Setpoint5, float ADC_Buf5);

uint8_t Get_TIM1_Speed(void);
uint8_t Get_TIM3_Speed(void);
uint8_t Get_TIM4_Speed(void);
uint8_t Get_TIM5_Speed(void);

void speed_read_TimIcIsr(TIM_HandleTypeDef *htim);
#endif
