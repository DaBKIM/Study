#include <avr/io.h>
#include <util/delay.h>


int main(void){
    
    unsigned LED = 0x01; // 0000 0001
    
    PORTA = LED;
    DDRA = 0xFF;  // OUTPUT
    
    // Loop
    while (1){
        
        do{
            LED = LED << 2; // Shift 2 bit
            PORTA = LED;
            _delay_ms(1000);
            
        }while (LED != 0x40) // Until 0100 0000
        
        LED = 0x80; // Last bit
        PORTA = LED;
        _delay_ms(1000);
            
        do{
            LED = LED >> 2; // Shift 2 bit contrary
            PORTA = LED;
            _delay_ms(1000);
            
        } while(LED != 0x02) // Until 0000 0010
            
        LED = 0x01; // First bit
        PORTA = LED;
        _delay_ms(1000);
        
    }
}
