#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "LCD_1602A.h"


#define PrintChar
//#define PrintInteger
//#define PrintProgString
//#define SetCoursor


int main(void)
{
	
	lcd_t lcd;
	lcd.Controll_ddr = &DDRC;
	lcd.Controll_pin = &PINC;
	lcd.Controll_port = &PORTC;
	lcd.RS = 0b00000001;
	lcd.RW = 0b00000010;
	lcd.E  = 0b01000000;
	
	lcd.DB_ddr = &DDRD;
	lcd.DB_pin = &PIND;
	lcd.DB_port = &PORTD;
	lcd.data_pins = 0b11111111;
	
	LCD_1602A_init(&lcd);
	
	const char* progstring = PSTR("Hello World!");
	
	while (1)
	{
		#ifdef PrintChar
			
			for(uint8_t i = 0; i < 255; i++){
				if(i % 16 == 0){
					LCD_1602A_clear(&lcd);
				}
				LCD_1602A_print_char(&lcd, i);
				_delay_ms(200);
			}
		
		#endif
		
		
		#ifdef PrintInteger
		
			LCD_1602A_print_int(&lcd, 5);
			_delay_ms(500);
			LCD_1602A_clear(&lcd);
			LCD_1602A_print_int(&lcd, 15);
			_delay_ms(500);
			LCD_1602A_clear(&lcd);
			LCD_1602A_print_int(&lcd, 155);
			_delay_ms(500);
			LCD_1602A_clear(&lcd);
		
		#endif
		
			
		#ifdef PrintProgString
		
			LCD_1602A_print_prog_string(&lcd, progstring);
			
		#endif
		
		
		#ifdef SetCoursor
		
			LCD_1602A_set_courser(&lcd, 1, 2);
			LCD_1602A_print_prog_string(&lcd, progstring);
			_delay_ms(500);
			LCD_1602A_set_courser(&lcd, 0, 2);
			LCD_1602A_print_prog_string(&lcd, progstring);
			_delay_ms(500);
			LCD_1602A_set_courser(&lcd, 1, 0);
			LCD_1602A_print_char(&lcd, 123);
			LCD_1602A_set_courser(&lcd, 0, 0);
			LCD_1602A_print_char(&lcd, 123);
			LCD_1602A_set_courser(&lcd, 1, 15);
			LCD_1602A_print_char(&lcd, 125);
			LCD_1602A_set_courser(&lcd, 0, 15);
			LCD_1602A_print_char(&lcd, 125);
			_delay_ms(500);			
			
		#endif
			
		_delay_ms(1000);
		LCD_1602A_clear(&lcd);
		_delay_ms(1000);
	}
	
	
}

