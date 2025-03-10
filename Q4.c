#include <reg51.h>

sbit LED = P1^3;  
unsigned int count = 0;

void timer1_delay() {
    TMOD |= 0x10;  
    TH1 = 0xFF;    
    TL1 = 0x1A;    
    TR1 = 1;       
    while (TF1 == 0);  
    TR1 = 0;       
    TF1 = 0;       
}

void timer0_ISR() interrupt 1 {
    count++;

    if (count >= 150) {
        LED = ~LED;  
        timer1_delay();  
        LED = ~LED;  
        timer1_delay();
        count = 0;  
    }
}

void main() {
    TMOD = 0x01;  
    TH0 = 0xFC;   
    TL0 = 0x66;  
    ET0 = 1;  
    EA = 1;   
    TR0 = 1;  

    while (1) {
    }
}