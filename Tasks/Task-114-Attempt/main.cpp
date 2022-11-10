#include "mbed.h"

DigitalOut TRAF_RED1(PC_2,1);
DigitalOut TRAF_YEL1(PC_3,1);
DigitalOut TRAF_GRN1(PC_6,1);
// main() runs in its own thread in the OS
int main()
{
    wait_us(5000000);

    TRAF_GRN1 = 0;
    TRAF_YEL1 = 0;
    TRAF_RED1 = 0;

    while (true) {
        int count = 0;
        while (count < 4) {
            TRAF_RED1 = 1;
            TRAF_GRN1 = 1;
            TRAF_YEL1 = 1;
            wait_us(2000000);
            TRAF_RED1 = 0;
            TRAF_YEL1 = 0;
            TRAF_GRN1 = 0;
            wait_us(2000000);
            count = count + 1;
        }
        
    }
}