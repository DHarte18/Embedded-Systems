#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{
    printf("\nTASK-112\n");

    //getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);                   // £= ASCII of 163, *= ASCII of 42, " "= ASCII of 32, %= ASCII of 37

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);

    //scanf
    printf("\n\nTo set the delay (in ms), type in an integer number and press return\n");       // When delay= 500 LEDs flash once evry 0.5s
    int delay_ms;                                                                               // When delay= 500a LEDs flash every 0.5s
    int parsed = scanf("%d", &delay_ms);                                                        // When delay= a500 as soon as a is pressed, none integer detected and code asks to be restarted
    
    printf("You entered %d correct integer values. The value was %dms\n", parsed, delay_ms);

    // Stop
    while (parsed > 0) {
        wait_us(delay_ms * 1000);
        led1 = 1;
        led2 = 1;
        led3 = 1;
        wait_us(delay_ms * 1000);
        led1 = 0;
        led2 = 0;
        led3 = 0;        
    } 

    printf("Invalid - please restart and try again\n");
    while(1);    
}