#include <avr/io.h>
#include <inttypes.h>
#include <stdbool.h>

int main() {
  bool on = false;
  DDRB = 0xff;
  // enable timer, divide system clock by 256
  TCCR1A = 0;
  TCCR1B = _BV(CS12) | _BV(WGM12) | _BV(WGM13);
  TCCR1C = 0;
  TCNT1 = 0;
  // set "top" value for the timer
  ICR1 = 10416;
  while (1) {
    if (TCNT1 > 10415) {
      if (on) {
        // turn it off
        PORTB &= ~_BV(1);
        on = false;
      } else {
        // turn it on
        PORTB |= _BV(1);
        on = true;
      }
    }
  }

  return 0;
}
