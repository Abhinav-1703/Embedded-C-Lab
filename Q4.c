#include <reg51.h>

sbit LED = P1^3;  

void timer1_delay() {
    TMOD |= 0x10;  
    TH1 = 0xFF;    
    TL1 = 0x1A;    
    TR1 = 1;       
    while (TF1 == 0);  
    TR1 = 0;       
    TF1 = 0;       
}

void main() {
    unsigned int count = 0;

    TMOD = 0x05;  
    TR0 = 1;  

    while (1) {
        if (TF0 == 1) {
            TF0 = 0;  
            count++;

            if (count >= 150) {
                LED = ~LED;  
                timer1_delay();  
                LED = ~LED;  
                timer1_delay();
                count = 0;  
            }
        }
    }
}