#include <>
#include <>

#define BL PIOB_PER_P20
#define SW1 PIOB_PER_P24
#define SW2 PIOB_PER_P25
#define BUZ PIOB_PER_P19

#define BIT_SET(x) PIOB_SODR=x //nowa wartośc rejestru to stara zsumowana z x
#define BIT_CLR(x) PIOB_CODR=x //PIOB_CODR | x

//PROCEDURA OBSŁUGI PRZERWANIA ISR
void TIMER0_COMP_vect()
{
TC0_SR; // na początku pusty odczyt rejestru statusu - kasowanie flagi przerwania CPCS

//zmiana stanu LCD_BL
PIOB_ODSR ^= BL;
}

void SW_pushed() {
int a = PIOB_ISR;
if(a & (1<<24)) {
TC0_RC = 31250;
}
if(a & (1<<25)) {
TC0_RC = 12500;
}
}


void zad2(){

PIOB_PER = BL | BUZ; // Pin Enable Register - załączenie pinu P20
PIOB_OER = BL | BUZ; // Output Enable Register - ustawienie Pinu20 w tryb wyjściowy OSR - sprawdzanie stanu ODR - disable
PIOB_PUDR = BL | BUZ; // Pull Up Disable Register - PUER, PUSR - wyłączenie rezystora podciągającego
PIOB_CODR = BL | BUZ; // wył. podświetlenie, jawne wyłączenie
PIOB_OWER = BL;

PIT_MR = 999999 | 1 << 24 ; // wartość (1mil bo 3mil/s) | włączenie za pomocą PITEN

while(1){

if((PIT_PIIR & (1<<23)) && (PIT_PIIR & (1<<20))){ // PIIR nie resetuje, PIVR resetuje, sprawdzamy
// int a=PIT_PIIR>>20;
// if (a>=9){
PIOB_ODSR ^= BL;
PIT_PIVR; // reset poprzez odczyt
}
}

}

void zad3() {
ctl_global_interrupts_disable();         //globalne wyłączenie przerwań

PMC_PCER = PMC_PCER_TC0;                 // załączenie zegara do wybranych peryferiów
PMC_PCER = PMC_PCER_PIOB;

PIOB_PER = BL | BUZ;                     // Pin Enable Register - załączenie pinu P20
PIOB_OER = BL | BUZ;                     // Output Enable Register - ustawienie Pinu20 w tryb wyjściowy OSR - sprawdzanie stanu ODR - disable
PIOB_ODR = SW1 | SW2;                    // Output Disable Register - wyłączenie wyjścia
PIOB_PUDR = SW1 | SW2;                   // Pull Up Disable Register - PUER, PUSR - wyłączenie rezystora podciągającego
PIOB_PUDR = BL | BUZ;                    // Pull Up Disable Register - PUER, PUSR - wyłączenie rezystora podciągającego
PIOB_CODR = BL | BUZ;                    // wył. podświetlenie, jawne wyłączenie
PIOB_OWER = BL;                          // Output Write Enable Register - zezwolenie na zapis do rejestru ODSR


TC0_CCR = TC0_CCR_CLKDIS;                // disable clock
TC0_IDR = 0xFF;                          // disable all interrupts
TC0_SR;                                  // reset t0
TC0_CMR = TC0_CMR_CPCTRG | (1 << 2);     // tryb RC oraz clock 5
TC0_RC = 62499;                          // ustawienie wartości RC
TC0_CCR = TC0_CCR_SWTRG | TC0_CCR_CLKEN; // załączenie zegara | reset licznika


ctl_set_isr(12,1,CTL_ISR_TRIGGER_FIXED,TIMER0_COMP_vect,0); // przerwanie
ctl_set_isr(3,1,CTL_ISR_TRIGGER_FIXED,SW_pushed,0);
TC0_IER = (1<<4); // przerwanie od RC
PIOB_IER = (1<<25)|(1<<24);
ctl_unmask_isr(12); // unmask - zezwala na przerwania
ctl_unmask_isr(3);

ctl_global_interrupts_enable(); //sei ale dla sam7

while(1);
}













void zad1()
{
ctl_global_interrupts_disable(); //globalne wyłączenie przerwań

PMC_PCER = PMC_PCER_TC0; // załączenie zegara do wybranych peryferiów

PIOB_PER = BL | BUZ; // Pin Enable Register - załączenie pinu P20
PIOB_OER = BL | BUZ; // Output Enable Register - ustawienie Pinu20 w tryb wyjściowy OSR - sprawdzanie stanu ODR - disable
PIOB_PUDR = BL | BUZ; // Pull Up Disable Register - PUER, PUSR - wyłączenie rezystora podciągającego
PIOB_CODR = BL | BUZ; // wył. podświetlenie, jawne wyłączenie
PIOB_OWER = BL;


TC0_CCR = TC0_CCR_CLKDIS; // disable clock
TC0_IDR = 0xFF;
TC0_SR; // reset t0
TC0_CMR = TC0_CMR_CPCTRG | (1 << 2);// tryb RC oraz clock 5
TC0_RC = 62499; //ustawienie wartości RC
TC0_CCR = TC0_CCR_SWTRG | TC0_CCR_CLKEN; // załączenie zegara | reset licznika


ctl_set_isr(12,1,CTL_ISR_TRIGGER_FIXED,TIMER0_COMP_vect,0); // przerwanie
TC0_IER = (1<<4); // przerwanie od RC
ctl_unmask_isr(12); // unmask - zezwala na przerwania

ctl_global_interrupts_enable(); //sei ale dla sam7

while(1);
}




int main(void)
{

zad3();

}
