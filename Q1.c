#include <reg51.h>

sbit led = P1^5;

void timer0_delay() {
    TMOD = 0x01;  // Timer 0, Mode 1 (16-bit)
    TH0 = 0x3C;   // Load high byte for 50ms delay
    TL0 = 0xB0;   // Load low byte
    TR0 = 1;      // Start timer
    while (TF0 == 0); // Wait for overflow
    TR0 = 0;      // Stop timer
    TF0 = 0;      // Clear overflow flag
}

void main() {
    while (1) {
        led = ~led;  // Toggle P1.5
        timer0_delay();
       }  
    }
