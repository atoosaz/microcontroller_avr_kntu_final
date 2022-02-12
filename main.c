/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/27/2022
Author  : 
Company : 
Comments: 


Chip type               : ATmega64
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 1024
*******************************************************/

#include <mega64.h>

// Alphanumeric LCD functions
#include <alcd.h>

// Declare your global variables here

// Standard Input/Output functions
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <delay.h>
#include <stdint.h>

//variables
char print[10];
bool admin_pass;
bool user;
bool enter_user;
bool blink=false;
bool admin_request;
int pass;
int temp_user;
int count;
int users[3];
int i;
int KeyboardPort=0;
uint8_t candidate1=0;
uint8_t candidate2=0;
uint8_t candidate3=0;


// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer1 value
TCNT1H=0xBDC >> 8;
TCNT1L=0xBDC & 0xff;
// Place your code here
  if(blink){
        PORTD.0=~PORTD.0;
  }

}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Port E initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRE=(0<<DDE7) | (0<<DDE6) | (0<<DDE5) | (0<<DDE4) | (0<<DDE3) | (0<<DDE2) | (0<<DDE1) | (0<<DDE0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTE=(0<<PORTE7) | (0<<PORTE6) | (0<<PORTE5) | (0<<PORTE4) | (0<<PORTE3) | (0<<PORTE2) | (0<<PORTE1) | (0<<PORTE0);

// Port F initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRF=(0<<DDF7) | (0<<DDF6) | (0<<DDF5) | (0<<DDF4) | (0<<DDF3) | (0<<DDF2) | (0<<DDF1) | (0<<DDF0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTF=(0<<PORTF7) | (0<<PORTF6) | (0<<PORTF5) | (0<<PORTF4) | (0<<PORTF3) | (0<<PORTF2) | (0<<PORTF1) | (0<<PORTF0);

// Port G initialization
// Function: Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRG=(0<<DDG4) | (0<<DDG3) | (0<<DDG2) | (0<<DDG1) | (0<<DDG0);
// State: Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTG=(0<<PORTG4) | (0<<PORTG3) | (0<<PORTG2) | (0<<PORTG1) | (0<<PORTG0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// OC1C output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0.5 s
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<COM1C1) | (0<<COM1C0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x0B;
TCNT1L=0xDC;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
OCR1CH=0x00;
OCR1CL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
TCCR2=(0<<WGM20) | (0<<COM21) | (0<<COM20) | (0<<WGM21) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer/Counter 3 initialization
// Clock source: System Clock
// Clock value: Timer3 Stopped
// Mode: Normal top=0xFFFF
// OC3A output: Disconnected
// OC3B output: Disconnected
// OC3C output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer3 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
// Compare C Match Interrupt: Off
TCCR3A=(0<<COM3A1) | (0<<COM3A0) | (0<<COM3B1) | (0<<COM3B0) | (0<<COM3C1) | (0<<COM3C0) | (0<<WGM31) | (0<<WGM30);
TCCR3B=(0<<ICNC3) | (0<<ICES3) | (0<<WGM33) | (0<<WGM32) | (0<<CS32) | (0<<CS31) | (0<<CS30);
TCNT3H=0x00;
TCNT3L=0x00;
ICR3H=0x00;
ICR3L=0x00;
OCR3AH=0x00;
OCR3AL=0x00;
OCR3BH=0x00;
OCR3BL=0x00;
OCR3CH=0x00;
OCR3CL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
// INT3: Off
// INT4: Off
// INT5: Off
// INT6: Off
// INT7: Off
EICRA=(0<<ISC31) | (0<<ISC30) | (0<<ISC21) | (0<<ISC20) | (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
EICRB=(0<<ISC71) | (0<<ISC70) | (0<<ISC61) | (0<<ISC60) | (0<<ISC51) | (0<<ISC50) | (0<<ISC41) | (0<<ISC40);
EIMSK=(0<<INT7) | (0<<INT6) | (0<<INT5) | (0<<INT4) | (0<<INT3) | (0<<INT2) | (0<<INT1) | (0<<INT0);

// USART0 initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART0 Receiver: On
// USART0 Transmitter: On
// USART0 Mode: Asynchronous
// USART0 Baud Rate: 9600
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL0) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0x33;

// USART1 initialization
// USART1 disabled
UCSR1B=(0<<RXCIE1) | (0<<TXCIE1) | (0<<UDRIE1) | (0<<RXEN1) | (0<<TXEN1) | (0<<UCSZ12) | (0<<RXB81) | (0<<TXB81);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 20
lcd_init(20);

// Global enable interrupts
#asm("sei")

    //start
        //admin password is 1234   
        //-----------------------------------------------------------admin login
        admin_pass=false;
        pass=0;         
        PORTD.0=0;     
        users[0]=101;
        users[1]=102;
        users[2]=103; 
        DDRC=0xf0;
        lcd_puts("Election has not started yet.\r");
         
        while(!admin_pass) {
        
        puts("Enter admin password to start election:\r"); 
        scanf("%d",&pass);
        if(pass==1234){
        
        PORTD.0=1;    
        puts("password is correct. Election begin. \r");   
        admin_pass=true;
        }else{
        puts("wrong password!\r");
        } 
        
        }
        //------------------------------------------------user login    
        admin_request=true;
        while(admin_request){ 
            user=false;
            while(!user){ 
                lcd_clear();
                lcd_puts("Enter your username:\r"); 
                temp_user=0; 
                count=0;
                enter_user=false;
                while(enter_user==false){  
                   
                        PORTC= 0x7f;
                        PORTC.7 = 0;
                        //check row no.1
                        if(!PINC.3){      
                                // 7  
                                KeyboardPort=7;
                                temp_user=temp_user*10+KeyboardPort;
                                delay_ms(600);
                                
                        } 
                        if(!PINC.2){  
                                // 8
                               KeyboardPort=8; 
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600);
                        }   
                        if(!PINC.1){  
                                // 9
                               KeyboardPort=9;
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        }
                        if(!PINC.0){  
                                // void 
                        }  
                        //delay_ms(10);
                        PORTC.7 = 1;
                        PORTC.6 = 0; 
                        //check row no.2
                        if(!PINC.3){      
                                // 4
                               KeyboardPort=4;
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        } 
                        if(!PINC.2){  
                                //5
                               KeyboardPort=5;
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        }   
                        if(!PINC.1){  
                                // 6
                               KeyboardPort=6;
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        }
                        if(!PINC.0){  
                                // void
                        }        
                        //delay_ms(10);
                        PORTC.6 = 1;
                        PORTC.5 = 0; 
                        //check row no.3
                        if(!PINC.3){      
                                // 1
                               KeyboardPort=1; 
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        } 
                        if(!PINC.2){  
                                //2
                               KeyboardPort=2; 
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600);
                        }   
                        if(!PINC.1){  
                                // 3
                               KeyboardPort=3;
                               temp_user=temp_user*10+KeyboardPort; 
                               delay_ms(600); 
                        }
                        if(!PINC.0){  
                                // -
                                
                        }        
                        //delay_ms(10);
                        PORTC.5 = 1;
                        PORTC.4 = 0; 
                        //check row no.4
                        if(!PINC.3){      
                                // void
                        } 
                        if(!PINC.2){  
                                //0
                               KeyboardPort=0; 
                               temp_user=temp_user*10+KeyboardPort;
                               delay_ms(600); 
                        }   
                        if(!PINC.1){  
                                // Enter
                               enter_user=true; 
                               delay_ms(600); 
                        }
                        if(!PINC.0){  
                                // void 
                        }        
                        //delay_ms(10);
                        PORTC.4 = 1;
                    
                } 
                users[0]=101;
                users[1]=102;
                users[2]=103;
                    
                i=0;
                while(i<3){ 

                    if(users[i]==temp_user){
                        lcd_clear();
                        lcd_puts("User is valid:\r");
                        sprintf(print,"%d",temp_user);  
                        lcd_puts(print);   
                        sprintf(print,"User is valid: %d \r",temp_user);
                        puts(print);
                        users[i]=0;                     
                        user=true;
                        count++;   
                    }  
                    i++;
                }     

                if(count==0){
                    lcd_clear();
                    lcd_puts("User is not valid:\r");
                    sprintf(print,"%d",temp_user);  
                    lcd_puts(print);
                    sprintf(print,"User is not valid: %d \r",temp_user);   
                    puts(print); 
                    users[0]=101;
                    users[1]=102;
                    users[2]=103;  
                    delay_ms(1000);
                }    

            }   
            delay_ms(1000);
            lcd_clear();
            blink=true; 
            PORTD.1=1;
            delay_ms(100);
            PORTD.1=0;  
            //-------------------------------------------------------voting
            lcd_puts("You can vote now"); 
            delay_ms(1000);
            lcd_clear();
            lcd_puts("Cand1:1 ,Cand2:2 ,Cand3:3");  
            user=false;
            while(!user){
                count=0;
                enter_user=false;
                while(enter_user==false){  
                    if(!PINF.0){
                         // 1
                               KeyboardPort=1;    
                               lcd_clear();
                               lcd_puts("you chose candidate1 press to confirm");
                               
                    }
                    if(!PINF.1){
                         //2
                               KeyboardPort=2; 
                               lcd_clear();
                               lcd_puts("you chose candidate2 press to confirm");
                               
                    
                    }
                    if(!PINF.2){
                        // 3
                               KeyboardPort=3;
                               lcd_clear();
                               lcd_puts("you chose candidate3 press to confirm");
                               
                    
                    } 
                    if(!PINF.3){
                          // Enter
                               enter_user=true;
                    
                    }
                    
                    
                } 
                i=1;
                while(i<4){ 
                    if(i==KeyboardPort){
                        lcd_clear();
                        lcd_puts("you successfuly voted");
                        sprintf(print,"%d voted %d \r",temp_user,KeyboardPort);  
                        puts(print);
                        user=true;
                        if(KeyboardPort==1){
                            candidate1++; 
                            KeyboardPort=0;
                        }else if(KeyboardPort==2){
                            candidate2++;
                            KeyboardPort=0;
                        } else if(KeyboardPort==3){
                            candidate3++;   
                            KeyboardPort=0;
                        }
                           
                    }   
//                    itoa(candidate1,print);   
//                    puts(print);
//                    puts(" 1 \r");
//                    itoa(candidate2,print);   
//                    puts(print);
//                    puts(" 2 \r");
//                    itoa(candidate3,print);   
//                    puts(print);
//                    puts(" 3 \r");   
                    i++;
                } 
                blink=false ;
                
            } 
            
            PORTD.0=1; 
            PORTD.1=1;
            delay_ms(100);
            PORTD.1=0;
            puts("do you want to continue?[y/n]\r");
            if(getchar()=='n'){
                admin_request=false;
            }
        
        }
        //-------------------------------------------------------showing resaults
        PORTD.0=0;  
        lcd_clear();
        lcd_puts("election finished"); 
        puts("\r election finished. to see resault type 'r': \r");
        if(getchar()=='r'){  
            lcd_clear();
            lcd_puts("c1:"); 
            itoa(candidate1,print);
            puts("\rvotes for candidate 1:");
            lcd_puts(print);
            puts(print);
            puts("\r");
            lcd_puts(" c2:");  
            itoa(candidate2,print);      
            lcd_puts(print); 
            puts("votes for candidate 2:"); 
            puts(print); 
            lcd_puts(" c3:"); 
            puts("\r"); 
            itoa(candidate3,print);
            lcd_puts(print); 
            puts("votes for candidate 3:"); 
            puts(print);
            puts("\r");        
            
        }
        
}
