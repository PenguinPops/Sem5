/*
#include <avr/io.h>
void PORT_Data_Direction(char port, int linia, int stan)
{
    if (stan)
    {
        switch (port)
        {
        case 'A':
            DDRA |= (1 << linia);
            return;
        case 'B':
            DDRB |= (1 << linia);
            return;
        case 'C':
            DDRC |= (1 << linia);
            return;
        case 'D':
            DDRD |= (1 << linia);
            return;
        }
        return;
    }
    else
    {
        switch (port)
        {
        case 'A':
            DDRA &= ~(1 << linia);
            return;
        case 'B':
            DDRB &= ~(1 << linia);
            return;
        case 'C':
            DDRC &= ~(1 << linia);
            return;
        case 'D':
            DDRD &= ~(1 << linia);
            return;
        }
        return;
    }
}

void Pullup_enable(char port, int linia)
{
    switch (port)
    {
    case 'A':
        if (DDRA & (1 << linia) == 0)
            PORTA |= (1 << linia);
        return;
    case 'B':
        if (DDRB & (1 << linia) == 0)
            PORTB |= (1 << linia);
        return;
    case 'C':
        if (DDRC & (1 << linia) == 0)
            PORTC |= (1 << linia);
        return;
    case 'D':
        if (DDRD & (1 << linia) == 0)
            PORTD |= (1 << linia);
        return;
    }
    return;
}

void OUTPUT_SET(char port, int linia)
{
    switch (port)
    {
    case 'A':
        if (!(DDRA & (1 << linia) == 0))
            PORTA |= (1 << linia);
        return;
    case 'B':
        if (!(DDRB & (1 << linia) == 0))
            PORTB |= (1 << linia);
        return;
    case 'C':
        if (!(DDRC & (1 << linia) == 0))
            PORTC |= (1 << linia);
        return;
    case 'D':
        if (!(DDRD & (1 << linia) == 0))
            PORTD |= (1 << linia);
        return;
    }
    return;
}

void OUTPUT_CLR(char port, int linia)
{
    switch (port)
    {
    case 'A':
        if (!(DDRA & (1 << linia) == 0))
            PORTA &= ~(1 << linia);
        return;
    case 'B':
        if (!(DDRB & (1 << linia) == 0))
            PORTB &= ~(1 << linia);
        return;
    case 'C':
        if (!(DDRC & (1 << linia) == 0))
            PORTC &= ~(1 << linia);
        return;
    case 'D':
        if (!(DDRD & (1 << linia) == 0))
            PORTD &= ~(1 << linia);
        return;
    }
    return;
}

void OUTPUT_TOGGLE(char port, int linia)
{
    switch (port)
    {
    case 'A':
        if (!(DDRA & (1 << linia) == 0))
            PORTA ^= (1 << linia);
        return;
    case 'B':
        if (!(DDRB & (1 << linia) == 0))
            PORTB ^= (1 << linia);
        return;
    case 'C':
        if (!(DDRC & (1 << linia) == 0))
            PORTC ^= (1 << linia);
        return;
    case 'D':
        if (!(DDRD & (1 << linia) == 0))
            PORTD ^= (1 << linia);
        return;
    }
    return;
}

unsigned int SW_odczyt(char port, int linia)
{
    switch (port)
    {
    case 'A':
        return (PINA & (1 << linia)) ? 1 : 0;
    case 'B':
        return (PINB & (1 << linia)) ? 1 : 0;
    case 'C':
        return (PINC & (1 << linia)) ? 1 : 0;
    case 'D':
        return (PIND & (1 << linia)) ? 1 : 0;
    }
    return;
}
*/