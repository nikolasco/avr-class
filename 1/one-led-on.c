#include <avr/io.h>
#include <inttypes.h>

int main() {
  DDRB = 0xff; // Data Direction Register B
  PORTB |= _BV(1); // Port B

  return 0;
}
