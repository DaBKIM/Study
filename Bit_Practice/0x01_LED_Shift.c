#include <avr/io.h>
#include <util/delay.h>


int main(void){
    
    unsigned LED = 0x01; // 0000 0001
    
    PORTA = LED;
    DDRA = 0xFF; // 1111 1111, OUTPUT
    
    // Loop
    while (1){
        
        do{
            LED = LED << 1; // Shift 1 bit
            PORTA = LED;
            _delay_ms(1000);
            
        } while(LED != 0x80); // Until 1000 0000
        
        do{
            LED = LED >> 1; // Shift 1 bit contrary
            PORTA = LED;
            _delay_ms(1000);
            
        } while(LED != 0x01); // Until 0000 0001
    }
}
