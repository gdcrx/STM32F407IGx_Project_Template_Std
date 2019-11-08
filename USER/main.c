#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h" 

void ST_GPIO_Init(void);
	
void ST_SPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	// LED灯接的PE5,PE6引脚
  GPIO_Init(GPIOE, &GPIO_InitStructure);

	// LED灯接的PH9引脚
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOH, &GPIO_InitStructure);
	
}

int main(void)
{
	u32 t=0;
	uart_init(115200);
	delay_init(84);
	
	ST_SPIO_Init();
	GPIO_SetBits(GPIOH,GPIO_Pin_9);
	
  while(1){
    printf("t:%d\r\n",t);
		GPIO_SetBits(GPIOE,GPIO_Pin_5|GPIO_Pin_6);
		delay_ms(1000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5|GPIO_Pin_6);
		delay_ms(1000);
		t++;
	}
}
