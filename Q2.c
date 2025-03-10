#include <reg51.h>

sbit switch_pin = P2^3;  // Define switch at P2.3

void main() {
    unsigned char portValue, count, i;

    P1 = 0x55;  // Load P1 with 0x55 (01010101 in binary)
    P3 = 0x00;  // Clear P3 to display results

    while (1) {
        portValue = 0x55;  // Ensure we're always reading the correct value
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

        P3 = count;  // Display the count on Port 3
    }
}