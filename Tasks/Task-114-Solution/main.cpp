#include "mbed.h"

//All Led ON when the code starts
DigitalOut redLED(PC_2,1);                      //PC2/ADC1IN12/PWM1_3N
DigitalOut yellowLED(PC_3,1);                   //PC3/A2/ADC1IN13/SPI2_MOSI
DigitalOut greenLED(PC_6,1);                    //PC6/UART6_TX/PWM3_1


int main()
{
    //1s pause to show all LEDs are working
    wait_us(1000000);  

    //Reset
    yellowLED = 0;
    greenLED = 0;

    while (true) {
        //Red
        redLED = 1;
        wait_us(2000000);

        //Red+Yellow
        redLED = 1;
        yellowLED = 1;
        wait_us(2000000);    

        //Green
        redLED = 0;
        yellowLED = 0;
        greenLED = 1;
        wait_us(2000000);

        //Flash the yellow
        greenLED = 0;
        int count = 0;
        while (count < 4) {
            yellowLED = 1;
            wait_us(250000);
            yellowLED = 0;
            wait_us(250000);   
            count = count + 1;     
        }

        //The whole routine now repeats

    }
}

