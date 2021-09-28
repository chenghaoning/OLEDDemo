#ifndef __KEY2_H__
#define __KEY2_H__


//定义枚举类型
typedef enum
{
	STA1   = (uint8_t)0x01, 
	STA2   = (uint8_t)0x02, 
	STA3   = (uint8_t)0x03, 
	STA4   = (uint8_t)0x04, 
	STA5   = (uint8_t)0x05,
} STA_Machine_Status_t;


//定义结构体类型
typedef struct
{
	STA_Machine_Status_t  ucSTA_Machine_Status;  //状态机状态
	
	void (*Fun_STA1)(void); 
	void (*Fun_STA2)(void);
	void (*Fun_STA3)(void);
	void (*Fun_STA4)(void);
	void (*Fun_STA5)(void);
} STA_Machine_t;

/* extern variables-----------------------------------------------------------*/
//结构体声明
extern STA_Machine_t   STA_Machine;

/* extern function prototypes-------------------------------------------------*/

#endif
/********************************************************
  End Of File
********************************************************/
