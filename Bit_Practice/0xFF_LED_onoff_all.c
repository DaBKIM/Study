#include <avr/io.h>

int main(void){
    
    unsigned char LED = 0xFF; // 1111 1111
    
    PORTA = 0xFF;
    DDRA = 0xFF; // OUTPUT
    
    while (1)
    {
        LED = ~LED; // 1111 1111 -> 0000 0000
        PORTA = LED;
    }
}
