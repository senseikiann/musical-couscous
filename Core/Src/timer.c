#define RCC_BASE 0x40021000
#define TIM2_BASE 0x40000000
#define NVIC_ISER0 (*(volatile unsigned int*)0xE000E100)

#define RCC_APB1ENR (*(volatile unsigned int*)(RCC_BASE + 0x1C))
#define TIM2_PSC (*(volatile unsigned int*)(TIM2_BASE + 0x28))
#define TIM2_ARR (*(volatile unsigned int*)(TIM2_BASE + 0x2C))
#define TIM2_DIER (*(volatile unsigned int*)(TIM2_BASE + 0x0C))
#define TIM2_SR (*(volatile unsigned int*)(TIM2_BASE + 0x10))
#define TIM2_CR1 (*(volatile unsigned int*)(TIM2_BASE + 0x00))

void TIM2_IRQHandler(void)
{
    TIM2_SR &= ~(1 << 0);
}

void timer2_init(void)
{
    RCC_APB1ENR |= (1 << 0);

    TIM2_PSC = 7200 - 1;
    TIM2_ARR = 10000 - 1;

    TIM2_DIER |= (1 << 0);

    NVIC_ISER0 |= (1 << 28);

    TIM2_CR1 |= (1 << 0);
}
