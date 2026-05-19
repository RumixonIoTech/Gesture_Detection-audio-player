#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

// Condition triggers
bool condition1 = false;
bool condition2 = false;

void setup() {
  // Initialize the native hardware UART at the DFPlayer's 9600 baud rate
  // Pins 1 (TX) and 3 (RX) are used automatically by standard Serial
  Serial.begin(9600);

  // Initialize DFPlayer Mini using Hardware Serial
  while (!myDFPlayer.begin(Serial)) {
    delay(2000);
  }
  
  // Set volume (0 to 30)
  myDFPlayer.volume(20);
}

void loop() {
  // --- Condition 1 ---
  if (condition1) {
    myDFPlayer.playLargeFolder(1, 1); // Plays /mp3/0001.mp3
    condition1 = false;
    delay(5000);
  }
  
  // --- Condition 2 ---
  if (condition2) {
    myDFPlayer.playLargeFolder(1, 2); // Plays /mp3/0002.mp3
    condition2 = false;
    delay(5000);
  }

  delay(100);
}