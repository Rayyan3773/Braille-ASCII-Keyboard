#include "stm32f446xx.h"
#include <string.h>

// ---------------- UART INIT ----------------
void uart_init()
{
    RCC->APB2ENR |= (1<<2);   // GPIOA
    RCC->APB1ENR |= (1<<17);  // USART2

    // PA2 -> TX (AF push-pull)
    GPIOA->CRL &= ~(0xF << 8);
    GPIOA->CRL |=  (0xB << 8);

    // PA3 -> RX (input floating)
    GPIOA->CRL &= ~(0xF << 12);
    GPIOA->CRL |=  (0x4 << 12);

    USART2->BRR = 0x1D4C; // 72MHz → 9600 baud
    USART2->CR1 |= (1<<13) | (1<<3) | (1<<2); // UE, TE, RE
}

// ---------------- UART PRINT ----------------
void uart_print(char *str)
{
    while(*str)
    {
        while(!(USART2->SR & (1<<7)));
        USART2->DR = *str++;
    }
}

// ---------------- DELAY ----------------
void delay(volatile uint32_t t)
{
    while(t--);
}

// ---------------- GPIO INIT ----------------
void gpio_init()
{
    RCC->APB2ENR |= (1<<2); // GPIOA clock

    // PA0–PA6 input floating
    GPIOA->CRL = 0x44444444;
}

// ---------------- READ PIN ----------------
int read_pin(int pin)
{
    return (GPIOA->IDR & (1 << pin)) ? 1 : 0;
}


void play_audio(char *file)
{
    uart_print(" -> ");
    uart_print(file);
    uart_print("\r\n");
}


void process_input()
{
    int i = read_pin(0);
    int j = read_pin(1);
    int k = read_pin(2);
    int l = read_pin(3);
    int m = read_pin(4);
    int n = read_pin(5);
    int o = read_pin(6); // mode switch

    // -------- LETTER MODE --------
    if(o == 0)
    {
        if(i && !j && !k && !l && !m && !n){ uart_print("A"); play_audio("A.wav"); }
        else if(i && j && !k && !l && !m && !n){ uart_print("B"); play_audio("B.wav"); }
        else if(i && !j && !k && l && !m && !n){ uart_print("C"); play_audio("C.wav"); }
        else if(i && !j && !k && l && m && !n){ uart_print("D"); play_audio("D.wav"); }
        else if(i && !j && !k && !l && m && !n){ uart_print("E"); play_audio("E.wav"); }
        else if(i && j && !k && l && !m && !n){ uart_print("F"); play_audio("F.wav"); }
        else if(i && j && !k && l && m && !n){ uart_print("G"); play_audio("G.wav"); }
        else if(i && j && !k && !l && m && !n){ uart_print("H"); play_audio("H.wav"); }
        else if(!i && j && !k && l && !m && !n){ uart_print("I"); play_audio("I.wav"); }
        else if(!i && j && !k && l && m && !n){ uart_print("J"); play_audio("J.wav"); }
        else if(i && !j && k && !l && !m && !n){ uart_print("K"); play_audio("K.wav"); }
        else if(i && j && k && !l && !m && !n){ uart_print("L"); play_audio("L.wav"); }
        else if(i && !j && k && l && !m && !n){ uart_print("M"); play_audio("M.wav"); }
        else if(i && !j && k && l && m && !n){ uart_print("N"); play_audio("N.wav"); }
        else if(i && !j && k && !l && m && !n){ uart_print("O"); play_audio("O.wav"); }
        else if(i && j && k && l && !m && !n){ uart_print("P"); play_audio("P.wav"); }
        else if(i && j && k && l && m && !n){ uart_print("Q"); play_audio("Q.wav"); }
        else if(i && j && k && !l && m && !n){ uart_print("R"); play_audio("R.wav"); }
        else if(!i && j && k && l && !m && !n){ uart_print("S"); play_audio("S.wav"); }
        else if(!i && j && k && l && m && !n){ uart_print("T"); play_audio("T.wav"); }
        else if(i && !j && k && !l && !m && n){ uart_print("U"); play_audio("U.wav"); }
        else if(i && j && k && !l && !m && n){ uart_print("V"); play_audio("V.wav"); }
        else if(!i && j && !k && l && m && n){ uart_print("W"); play_audio("W.wav"); }
        else if(i && !j && k && l && !m && n){ uart_print("X"); play_audio("X.wav"); }
        else if(i && !j && k && l && m && n){ uart_print("Y"); play_audio("Y.wav"); }
        else if(i && !j && k && !l && m && n){ uart_print("Z"); play_audio("Z.wav"); }


        else if(!i && !j && !k && l && !m && !n){ uart_print(" "); play_audio("space.wav"); }
        else if(!i && !j && k && !l && !m && !n){ uart_print("\r\n"); play_audio("enter.wav"); }
    }

    // -------- NUMBER MODE --------
    else
    {
        if(!i && j && !k && l && m && !n){ uart_print("0"); play_audio("0.wav"); }
        else if(i && !j && !k && !l && !m && !n){ uart_print("1"); play_audio("1.wav"); }
        else if(i && j && !k && !l && !m && !n){ uart_print("2"); play_audio("2.wav"); }
        else if(i && !j && !k && l && !m && !n){ uart_print("3"); play_audio("3.wav"); }
        else if(i && !j && !k && l && m && !n){ uart_print("4"); play_audio("4.wav"); }
        else if(i && !j && !k && !l && m && !n){ uart_print("5"); play_audio("5.wav"); }
        else if(i && j && !k && l && !m && !n){ uart_print("6"); play_audio("6.wav"); }
        else if(i && j && !k && l && m && !n){ uart_print("7"); play_audio("7.wav"); }
        else if(i && j && !k && !l && m && !n){ uart_print("8"); play_audio("8.wav"); }
        else if(!i && j && !k && l && !m && !n){ uart_print("9"); play_audio("9.wav"); }
    }
}


int main(void)
{
    uart_init();
    gpio_init();

    uart_print("System Ready\r\n");

    while(1)
    {
        process_input();
        delay(300000);
    }
}
