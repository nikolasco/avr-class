#include <avr/io.h>
#include <inttypes.h>
#include <stdbool.h>

int main() {
  bool on = false;
  DDRB = 0xff;
  // enable timer, divide system clock by 256
  TCCR1A = _BV(COM1A0);
  TCCR1B = _BV(CS12) | _BV(WGM12) | _BV(WGM13);
  TCCR1C = 0;
  TCNT1 = 0;
  // set "top" value for the timer
  ICR1 = 10416;
  // set the value that the timer will be compared with
  OCR1A = 0;
  while (1) {
    // look ma, no code!
  }

  return 0;
}
