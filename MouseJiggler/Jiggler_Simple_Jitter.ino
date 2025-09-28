#include <Mouse.h>

void setup() {
  Mouse.begin();
}

void loop() {
  Mouse.move(2, 0);
  delay(50);
  Mouse.move(-2, 0);
  delay(30000);
}
