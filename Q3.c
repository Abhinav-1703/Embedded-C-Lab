#include <reg51.h>

sbit SW = P1^7;
sbit PWM = P1^2;
sbit SQ_WAVE = P2^3;

void timer0_ISR() interrupt 1 {
    TH0 = 0xF8;  // Reload for 2 KHz (500 µs)
    TL0 = 0x30;
    PWM = ~PWM;  // Toggle for PWM
}

void timer1_ISR() interrupt 3 {
    TH1 = 0xFD;  // Reload for 5 KHz (200 µs)
    TL1 = 0xA0;
    SQ_WAVE = ~SQ_WAVE;
}

void main() {
    TMOD = 0x11;  // Timer 0 & 1 in Mode 1 (16-bit)
    ET0 = 1;  // Enable Timer 0 interrupt
    ET1 = 1;  // Enable Timer 1 interrupt
    EA = 1;   // Enable global interrupts
    
    while (1) {
        if (SW == 0) {  // Generate PWM at P1.2
            TR0 = 1;
            TR1 = 0;
        } else {  // Generate square wave at P2.3
            TR0 = 0;
            TR1 = 1;
        }
    }
}
