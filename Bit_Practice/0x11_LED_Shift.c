#include <avr/io.h>
#include <util/delay.h>

int main(void){
    
    unsigned LED = 0x01; // 0000 0001
    
    DDRA = 0xff; // 1111 1111, OUTPUT
    PORTA = 0X01;
    
    // Loop
    while (1){
        
        Led = Led << 1; // Shift 1 bit
        
        // If 0000 1000 or 1000 1000 -> make the pattern
        if (PORTA == 0x08 || PORTA == 0x88){
            
            LED = 0x11; // 0001 0001
        }
        
        _delay_ms(1000);
        PORTA = LED;
    }
}
