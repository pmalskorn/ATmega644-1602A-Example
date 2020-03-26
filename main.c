#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "LCD_1602A.h"

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
	
	
	while (1)
	{
		//LCD_1602A_print_prog_string(&lcd, PSTR("Hallo !!!"));
		
		LCD_1602A_set_courser(&lcd,1,1);
		LCD_1602A_print_int(&lcd, 0);
		_delay_ms(1000);
		LCD_1602A_set_courser(&lcd,0,1);
		LCD_1602A_print_int(&lcd, 1);
		_delay_ms(1000);
		LCD_1602A_set_courser(&lcd,1,5);
		LCD_1602A_print_int(&lcd, 12);
		_delay_ms(1000);
		LCD_1602A_set_courser(&lcd,0,5);
		LCD_1602A_print_int(&lcd, 155);
		_delay_ms(1000);
		LCD_1602A_set_courser(&lcd,1,10);
		LCD_1602A_print_char(&lcd, 0x52);
		_delay_ms(1000);
		LCD_1602A_set_courser(&lcd,0,10);
		LCD_1602A_print_char(&lcd, 0x52);
		_delay_ms(1000);
		LCD_1602A_clear(&lcd);
		_delay_ms(1000);
	}
	
	
}

