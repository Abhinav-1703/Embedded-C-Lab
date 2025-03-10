#include <reg51.h>

sbit switch_pin = P2^3;  // Define switch at P2.3

void main() {
    unsigned char data, count, i;
    
    P1 = 0x55;  // Load P1 with 0x55 (01010101 in binary)
    
    while (1) {
        data = P1;  // Read data from P1
        count = 0;
        
        if (switch_pin == 1) {  // Switch ON -> Count 1s
            for (i = 0; i < 8; i++) {
                if (data & (1 << i)) {
                    count++;
                }
            }
        } else {  // Switch OFF -> Count 0s
            for (i = 0; i < 8; i++) {
                if (!(data & (1 << i))) {
                    count++;
                }
            }
        }
        
        // Store or display count as needed
    }
}