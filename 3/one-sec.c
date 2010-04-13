#include <avr/io.h>
#include <inttypes.h>
#include <stdbool.h>

int main() {
  bool on = false;
  // enable timer, divide system clock by 256
  TCCR1A = 0;
  TCCR1B = _BV(CS12);
  TCCR1C = 0;
  TCNT1 = 0;
  while (1) {
    if (TCNT1 > 31250) {
      if (on) {
        // turn it off
        DDRB = 0xff;
        PORTB &= ~_BV(1);
        on = false;
      } else {
        // turn it on
        DDRB = 0xff;
        PORTB |= _BV(1);
        on = true;
      }
    }
  }

  return 0;
}
