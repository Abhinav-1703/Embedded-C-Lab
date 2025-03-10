#include <reg51.h>

sbit LED = P1^3;

void timer0_ISR() interrupt 1 {
    static unsigned int count = 0;
    count++;
    
    if (count >= 150) {
        LED = ~LED;  // Toggle LED
        count = 0;    // Reset counter
    }
}

void timer1_delay() {
    TMOD |= 0x10;  // Timer 1 in Mode 1 (16-bit)
    TH1 = 0xFF;    // Load for 20µs delay
    TL1 = 0xEC;
    TR1 = 1;       // Start Timer 1
    while (TF1 == 0);  // Wait
    TR1 = 0;       // Stop Timer
    TF1 = 0;       // Clear flag
}

void main() {
    TMOD = 0x01;  // Timer 0 in Mode 1 (Counter)
    ET0 = 1;  // Enable Timer 0 interrupt
    EA = 1;   // Enable global interrupts
    TR0 = 1;  // Start Timer 0

    while (1) {
        timer1_delay();
    }
}
