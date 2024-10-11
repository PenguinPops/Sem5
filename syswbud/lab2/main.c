/*
#define F_CPU 1000000
#include <util/delay.h>
#include <avr/io.h>
void PORT_Data_Direction(char port, int linia, int stan);
void Pullup_enable(char port, int linia);
void OUTPUT_SET(char port, int linia);
void OUTPUT_CLR(char port, int linia);
void OUTPUT_TOGGLE(char port, int linia);

unsigned int SW_odczyt(char port, int linia);

int main()
{
    PORT_Data_Direction('A', 0, 1);
    PORT_Data_Direction('A', 1, 0);
    PORT_Data_Direction('A', 2, 0);
    PORT_Data_Direction('A', 3, 0);
    Pullup_enable('A', 1);
    Pullup_enable('A', 2);
    Pullup_enable('A', 3);
    OUTPUT_CLR('A', 0);
    _delay_ms(1000);
    OUTPUT_SET('A', 0);
    int a;
    while (1)
    {
        a = SW_odczyt('A', 1);
        if (!a)
            OUTPUT_CLR('A', 0);
        a = SW_odczyt('A', 2);
        if (!a)
            OUTPUT_SET('A', 0);
        a = SW_odczyt('A', 3);
        if (!a)
        {
            OUTPUT_TOGGLE('A', 0);
            _delay_ms(500);
        }
        // if(SW_odczyt('A', 1)) OUTPUT_CLR('A', 0);
        //_delay_ms(20);
        // if(SW_odczyt('A', 2)) OUTPUT_SET('A', 0);
        //_delay_ms(20);
        // if(SW_odczyt('A', 3)) OUTPUT_TOGGLE('A', 0);
        _delay_ms(100);
    }
    return 0;
}
*/