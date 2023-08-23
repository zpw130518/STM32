
#include "stm32f10x.h"                  // Device header
#include "Delay.h" 
int main (void)
{
//	RCC->APB2ENR = 0x00000010; //打开GPIOC时钟
//	GPIOC->CRH = 0x00300000;//配置GPIOC
//	GPIOC->ODR = 0X00000000;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//配置时钟
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
    while (1)
    {
		GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
		Delay_ms(100);
		GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
		Delay_ms(100);
		
		
    }
}

