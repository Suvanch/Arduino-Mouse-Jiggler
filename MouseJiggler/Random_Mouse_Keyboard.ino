#include <Keyboard.h>
#include <Mouse.h>

// Configuration
const int jitterDist = 5;       // Distance to move side-to-side 
const int loopDelay  = 5000;    // Wait 5 seconds between cycles

void setup() {
  Mouse.begin(); [cite: 5]
  Keyboard.begin(); [cite: 266]
  randomSeed(analogRead(0));    // Randomize the internal timer
}

void loop() {
  // 1. Move Side-to-Side (Jiggle) 
  // Moves right, then immediately back to the left to maintain position
  Mouse.move(jitterDist, 0); [cite: 5]
  delay(100);
  Mouse.move(-jitterDist, 0); [cite: 5]
  delay(500);

  // 2. Perform a single Left Click
  // This helps keep applications focused without dragging items [cite: 19]
  Mouse.click(MOUSE_LEFT);
  delay(500);

  // 3. Type a random string
  // Uses a 6ms delay per character to look more natural [cite: 209, 249]
  typeRandomChars(8); 

  // 4. Long delay before repeating
  delay(loopDelay);
}

void typeRandomChars(int len) {
  const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  for (int i = 0; i < len; i++) {
    char c = charset[random(0, sizeof(charset) - 1)];
    Keyboard.write(c); [cite: 209]
    delay(10); // Short delay to mimic fast typing [cite: 249]
  }
}
