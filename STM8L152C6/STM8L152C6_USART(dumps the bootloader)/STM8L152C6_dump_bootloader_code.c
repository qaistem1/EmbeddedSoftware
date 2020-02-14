// Source: http://www.colecovision.eu
// Modified by: Qais Temeiza

#include <stdint.h>
#include <stdio.h>

#define PC_DDR	(*(volatile uint8_t *)0x500c)
#define PC_CR1	(*(volatile uint8_t *)0x500d)

#define CLK_DIVR	(*(volatile uint8_t *)0x50c0)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c3)

#define USART1_SR	(*(volatile uint8_t *)0x5230)
#define USART1_DR	(*(volatile uint8_t *)0x5231)
#define USART1_BRR1	(*(volatile uint8_t *)0x5232)
#define USART1_BRR2	(*(volatile uint8_t *)0x5233)
#define USART1_CR2	(*(volatile uint8_t *)0x5235)
#define USART1_CR3	(*(volatile uint8_t *)0x5236)

#define USART_CR2_TEN (1 << 3)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)





int putchar(int c)
{
	
	while(!(USART1_SR & USART_SR_TXE ));

	USART1_DR = c;

	return USART1_DR;

}

void main(void)
{
	unsigned long i = 0;
	
    unsigned char *Addr;
	CLK_DIVR = 0x00; // Set the frequency to 16 MHz
	CLK_PCKENR1 = 0xFF; // Enable peripherals

	PC_DDR = 0x08; // Put TX line on
	PC_CR1 = 0x08;

	USART1_CR2 = USART_CR2_TEN; // Allow TX and RX
	USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	USART1_BRR2 = 0x03; USART1_BRR1 = 0x68; // 9600 baud

	//int count = 0;

	for(Addr=(unsigned char *)0x006000;Addr<=(unsigned char *)0x007F00;Addr++)
	{
		printf("%02X",*Addr);
	}

    printf("\n \n \n \n \n \n \n \n");
    printf("Dumping is Done ! Dumping is Done !");
    printf("\n \n \n \n \n \n \n \n");


}