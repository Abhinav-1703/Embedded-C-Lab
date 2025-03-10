#include <reg51.h>

sbit switchPin = P2^3; 

void main() {
    unsigned char count = 0;
    unsigned char i, temp;
    
    while (1) {
        temp = P1;  // Read Port 1
        count = 0;

        if (switchPin == 1) {  // If switch is ON, count '1's
            for (i = 0; i < 8; i++) {
                if (temp & (1 << i)) count++;
            }
        } else {  // If switch is OFF, count '0's
            for (i = 0; i < 8; i++) {
                if (!(temp & (1 << i))) count++;
            }
        }
    }
}
