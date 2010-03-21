#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>

int main() {
  DDRB = 0xff; // Data Direction Register B
  DDRC = 0x0; // Data Direction Register C
  DDRD = 0xff; // Data Direction Register D

  PORTB = 0x0;
  PORTC = _BV(5);
  PORTD = 0x0;

  while (1) { // loop forever

    if (bit_is_set(PINC, PC5)) {
      PORTB |= _BV(1); // turn LED on
    } else {
      PORTB &= ~_BV(1); // turn LED off
    }
  }

  return 0;
}
