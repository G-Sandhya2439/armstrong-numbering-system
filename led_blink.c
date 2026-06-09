#define RCC 0x40023800
#define AHB1 0x30
#define RCC_AHB1 *(int*)(RCC+AHB1)
#define GPIOB 0x40020400 
#define GPIOC 0x40020800 
#define GPIOMODER_OFF 0x00
#define GPIOC_MODER *(int*)(GPIOC+GPIOMODER_OFF)
	#define GPIOB_MODER *(int*)(GPIOB+GPIOMODER_OFF)
#define GPIOPUPDR_OFF 0x0C
#define GPIOC_PUPDR *(int*)(GPIOC+GPIOPUPDR_OFF)
#define GPIOIDR_OFF 0x10
#define GPIOC_IDR *(int *)(GPIOC+GPIOIDR_OFF)
#define GPIOODR_OFF 0x14
#define GPIOB_ODR *(int*)(GPIOB+0x14)

void delay(int a){
	int i;
	for(i=1;i<1660*a;i++);
}
int main(void)
{
	RCC_AHB1 |=(0x01<<1);
	RCC_AHB1 |=(0x01<<2);
	
	GPIOB_MODER&=(~(0x01<<26));
	GPIOB_MODER&=(~(0x01<<24));
	GPIOB_MODER|=(0x01<<26);
	GPIOB_MODER|=(0x01<<24);
	
	GPIOB_MODER&=(~(0x01<<28));
	GPIOB_MODER|=(0x01<<28);
	
	GPIOB_ODR&=(~(0x01<<13));
	GPIOC_PUPDR|=(0x01<<20);
	GPIOC_PUPDR|=(0x01<<18);
	GPIOC_PUPDR|=(0x01<<16);
	
	GPIOB_ODR|=(0x01<<13);
	GPIOB_ODR|=(0x01<<14);
	while(1){
		if((GPIOC_IDR&(0x01<<10))==0){
		GPIOB_ODR&=~(0x01<<13);
		delay(1000);
		GPIOB_ODR|=(0x01<<13);
		delay(1000);
		}
		if((GPIOC_IDR &(0x01<<9))==0){
		GPIOB_ODR&=~(0x01<<14);
		delay(1000);
		GPIOB_ODR|=(0x01<<14);
		delay(1000);
		}
		if((GPIOC_IDR&(0x01<<8)) == 0){
			
		GPIOB_ODR|=(0x01<<12);
		delay(1000);
			GPIOB_ODR&=~(0x01<<12);
		delay(1000);
		}
	}
}
			
			
		
		
		
		
	
	
	
	
	
	
	
	

