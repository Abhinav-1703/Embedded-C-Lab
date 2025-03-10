#include <reg51.h>

sbit switch_pin = P2^3;  // Define switch at P2.3

void main() {
    unsigned char portValue;  
    unsigned char count;  
    unsigned char i;  

    P1 = 0x55;  // Load P1 with 0x55 (01010101 in binary)

    while (1) {
        portValue = P1;  // Read data from P1
        count = 0;

        if (switch_pin == 1) {  // Switch ON -> Count 1s
            for (i = 0; i < 8; i++) {
                if (portValue & (1 << i)) {
                    count++;
                }
            }
        } else {  // Switch OFF -> Count 0s
            for (i = 0; i < 8; i++) {
                if (!(portValue & (1 << i))) {
                    count++;
                }
            }
        }

        P1 = count;  // Output the count value to Port 1
    }
}