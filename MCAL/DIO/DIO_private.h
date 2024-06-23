

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_




/* DATA DIRCTION REGISTERS */
//#define DDRA           (*(volatile u8*)0x3A)
#define DDRB           (*(volatile u8*)0x24)
#define DDRC           (*(volatile u8*)0x27)
#define DDRD           (*(volatile u8*)0x2A)

/* OUTPUT REGISTERS */
//#define PORTA          (*(volatile u8*)0x3B)
#define PORTB          (*(volatile u8*)0x25)
#define PORTC          (*(volatile u8*)0x28)
#define PORTD          (*(volatile u8*)0x2B)

/* INPUT REGISTERS */
//#define PINA           (*(volatile u8*)0x39)
#define PINB           (*(volatile u8*)0x23)
#define PINC           (*(volatile u8*)0x26)
#define PIND           (*(volatile u8*)0x29)


#endif
