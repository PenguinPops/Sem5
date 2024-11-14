// #include <avr/io.h>
// #include <util/delay.h>
// #include <string.h>

// #define F_CPU 1000000L
// #define LCD_DDR DDRB
// #define LCD_PORT PORTB
// #define LCD_RS 2
// #define LCD_EN 3
// #define LCD_DB4 4
// #define LCD_DB5 5
// #define LCD_DB6 6
// #define LCD_DB7 7

// void wypisz(uint8_t b) {
// 	LCD_PORT |= _BV(LCD_EN); // wlaczenie linii enable
// 	LCD_PORT = (b & 0xF0)|(LCD_PORT & 0x0F); // wyslanie 4 starszych bitow
// 	LCD_PORT &= ~(_BV(LCD_EN)); // potwierdzenie wyslania danych, opadniecie ENABLE
// 	asm volatile("nop"); // odczekanie 1 cyklu
// 	LCD_PORT |= _BV(LCD_EN);
// 	LCD_PORT = ((b & 0x0F)<<4)|(LCD_PORT & 0x0F); // wyslanie 4 mlodszych bitów
// 	LCD_PORT &= ~(_BV(LCD_EN));
// 	_delay_us(50);
// }
// void LCD_clear() {
// 	LCD_PORT &= ~(_BV(LCD_RS));
// 	wypisz(0x01);
// 	LCD_PORT |= _BV(LCD_RS);
// 	_delay_ms(60);
// }
// void inicjalizacjaLCD()
// {
//     LCD_DDR = (0xf0) | (_BV(LCD_RS)) | (_BV(LCD_EN));
//     _delay_ms(50);    // Opóźnienie po starcie
//     LCD_PORT &= ~(_BV(LCD_RS));   // RS = 0 dla komend

//     wypisz(0x33);    // Tryb 4-bitowy, dwa razy
//     _delay_ms(5);
//     wypisz(0x32);
//     _delay_ms(5);

//     wypisz(0x28);    // Ustawienie trybu 4-bitowego
//     wypisz(0x0C);    // Wyświetlacz włączony, kursor wyłączony
//     wypisz(0x06);    // Auto inkrementacja kursora
//     LCD_clear();      // Wyczyść ekran

//     LCD_PORT |= _BV(LCD_RS);    // RS = 1 dla danych
// }
// void ustawKursor(unsigned char w, unsigned char h){
// 	LCD_PORT &=~(_BV(LCD_RS));
// 	wypisz((w*0x40+h) | 0x80);
// 	LCD_PORT |= _BV(LCD_RS);
// 	_delay_ms(5);
// }
// void napisz(char *tekst, int8_t dlugosc){
// 	int8_t i=0;
// 	ustawKursor(0, 5);
// 	while(i<dlugosc){
// 		if(i==16) {
// 		ustawKursor(1,0);
// 		}
// 	wypisz(tekst[i]);
// 	i++;
// 	}
// }

// int main(void) {
// 	char tekst[]={'H', 'e', 'l', 'l','o',' ','W','o','r','l','d'};
// 	inicjalizacjaLCD();
// 	napisz(tekst,11);
// 	while(1){}
// }