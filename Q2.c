#include <reg51.h>

sbit switch_pin = P2^3;  // Define switch at P2.3

unsigned char count_ones(unsigned char data) {
    unsigned char count = 0;
    while (data) {
        count += (data & 1);
        data >>= 1;
    }
    return count;
}

unsigned char count_zeros(unsigned char data) {
    return 8 - count_ones(data);  // Since it's an 8-bit value
}

void main() {
    unsigned char data, result;
    
    P1 = 0x55;  // Load P1 with 0x55 (01010101 in binary)
    
    while (1) {
        data = P1;  // Read data from P1
        
        if (switch_pin == 1) {  // Switch ON
            result = count_ones(data);
        } else {  // Switch OFF
            result = count_zeros(data);
        }
        
        // You can store or display the result as needed
    }
}