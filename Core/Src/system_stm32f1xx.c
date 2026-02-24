#define RCC_BASE 0x40021000
#define RCC_CR   (*(volatile unsigned int*)(RCC_BASE + 0x00))
#define RCC_CFGR (*(volatile unsigned int*)(RCC_BASE + 0x04))

void SystemInit(void){
    RCC_CR |= (1 << 16);
    while(!(RCC_CR & (1 << 17)));

    RCC_CFGR |= (7 << 18);
    RCC_CFGR |= (1 << 16);

    RCC_CFGR |= (2 << 0);
}
