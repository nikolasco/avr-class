#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdbool.h>

int main() {
  const uint16_t TOP = 100;
  bool on = false;
  DDRB = 0xff;
  // enable timer, divide system clock by 1 (no prescale)
  TCCR1A = _BV(COM1A0) | _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(CS10) | _BV(WGM13);
  TCCR1C = 0;
  TCNT1 = 0;
  // set "top" value for the timer
  ICR1 = TOP;
  OCR1A = 0;
  // dim at a rate we can see
  while (1) {
    _delay_ms(30);
    OCR1A++;
    if (OCR1A > TOP) OCR1A = 0;
  }

  return 0;
}
