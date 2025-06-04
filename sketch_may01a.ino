int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;

// Mode: 0 for Word Mode, 1 for Sentence Mode
int mode = 0; // Start in Word Mode

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  
  // Start Serial communication for USB
  Serial.begin(9600);
}

void loop() {
  a = analogRead(A0); //thumb (10k resistor)
  c = analogRead(A1); //index (10k resistor)
  d = analogRead(A2); //middle (10k resistor)
  b = analogRead(A3); //ring (10k resistor)
  e = analogRead(A4); //little (10k resistor)

  // Debug: Print raw values to Serial Monitor
  Serial.print("Thumb: ");
  Serial.print(a);
  Serial.print(" Index: ");
  Serial.print(c);
  Serial.print(" Middle: ");
  Serial.print(d);
  Serial.print(" Ring: ");
  Serial.print(b);
  Serial.print(" Little: ");
  Serial.println(e);

  // Convert readings to binary (1 for bent, 0 for straight)
  // For all sensors (10k resistors): > 50 is bent (1), < 50 is straight (0)
  int thumbBit = (a > 50) ? 1 : 0;
  int indexBit = (c > 50) ? 1 : 0;
  int middleBit = (d > 50) ? 1 : 0;
  int ringBit = (b > 50) ? 1 : 0;
  int littleBit = (e > 50) ? 1 : 0;

  // Debug: Print binary state
  Serial.print("Binary: ");
  Serial.print(thumbBit);
  Serial.print(indexBit);
  Serial.print(middleBit);
  Serial.print(ringBit);
  Serial.println(littleBit);

  // Calculate the combination (0 to 31)
  int combination = (thumbBit << 4) | (indexBit << 3) | (middleBit << 2) | (ringBit << 1) | littleBit;
  Serial.print("Combination: ");
  Serial.println(combination);

  // Handle the combination based on the current mode
  String output;
  if (combination == 31) { // 11111 - Toggle mode
    mode = (mode == 0) ? 1 : 0; // Switch between Word Mode (0) and Sentence Mode (1)
    output = (mode == 0) ? "Switched to Word Mode" : "Switched to Sentence Mode";
  } else {
    // Map the combination to a word or sentence based on the mode
    if (mode == 0) { // Word Mode
      switch (combination) {
        case 0:  // 00000
          output = "Hello";
          break;
        case 1:  // 00001
          output = "Yes";
          break;
        case 2:  // 00010
          output = "No";
          break;
        case 3:  // 00011
          output = "Please";
          break;
        case 4:  // 00100
          output = "ThankYou";
          break;
        case 5:  // 00101
          output = "Sorry";
          break;
        case 6:  // 00110
          output = "Help";
          break;
        case 7:  // 00111
          output = "Stop";
          break;
        case 8:  // 01000
          output = "Go";
          break;
        case 9:  // 01001
          output = "Come";
          break;
        case 10: // 01010
          output = "Wait";
          break;
        case 11: // 01011
          output = "Now";
          break;
        case 12: // 01100
          output = "Later";
          break;
        case 13: // 01101
          output = "Good";
          break;
        case 14: // 01110
          output = "Bad";
          break;
        case 15: // 01111
          output = "Okay";
          break;
        case 16: // 10000
          output = "Water";
          break;
        case 17: // 10001
          output = "Food";
          break;
        case 18: // 10010
          output = "Phone";
          break;
        case 19: // 10011
          output = "Book";
          break;
        case 20: // 10100
          output = "Pen";
          break;
        case 21: // 10101
          output = "Paper";
          break;
        case 22: // 10110
          output = "Chair";
          break;
        case 23: // 10111
          output = "Table";
          break;
        case 24: // 11000
          output = "Door";
          break;
        case 25: // 11001
          output = "Window";
          break;
        case 26: // 11010
          output = "Light";
          break;
        case 27: // 11011
          output = "Fan";
          break;
        case 28: // 11100
          output = "Up";
          break;
        case 29: // 11101
          output = "Down";
          break;
        case 30: // 11110
          output = "Left";
          break;
        default:
          output = "No word mapped";
          break;
      }
    } else { // Sentence Mode
      switch (combination) {
        case 0:  // 00000
          output = "I need help now";
          break;
        case 1:  // 00001
          output = "Can you come here";
          break;
        case 2:  // 00010
          output = "Please wait for me";
          break;
        case 3:  // 00011
          output = "I am feeling good";
          break;
        case 4:  // 00100
          output = "Thank you so much";
          break;
        case 5:  // 00101
          output = "I am very sorry";
          break;
        case 6:  // 00110
          output = "Can I have water";
          break;
        case 7:  // 00111
          output = "I need some food";
          break;
        case 8:  // 01000
          output = "Please stop now";
          break;
        case 9:  // 01001
          output = "Go to the door";
          break;
        case 10: // 01010
          output = "I will come later";
          break;
        case 11: // 01011
          output = "Is it okay now";
          break;
        case 12: // 01100
          output = "See you later today";
          break;
        case 13: // 01101
          output = "This is very bad";
          break;
        case 14: // 01110
          output = "Turn on the light";
          break;
        case 15: // 01111
          output = "Please open the window";
          break;
        case 16: // 10000
          output = "I need my phone";
          break;
        case 17: // 10001
          output = "Can I have a book";
          break;
        case 18: // 10010
          output = "Give me a pen please";
          break;
        case 19: // 10011
          output = "I need some paper";
          break;
        case 20: // 10100
          output = "Bring me a chair";
          break;
        case 21: // 10101
          output = "Put it on the table";
          break;
        case 22: // 10110
          output = "Close the door now";
          break;
        case 23: // 10111
          output = "Turn on the fan";
          break;
        case 24: // 11000
          output = "Look up there please";
          break;
        case 25: // 11001
          output = "Come down here now";
          break;
        case 26: // 11010
          output = "Turn to the left";
          break;
        case 27: // 11011
          output = "I am going right";
          break;
        case 28: // 11100
          output = "Can you help me";
          break;
        case 29: // 11101
          output = "I am feeling tired";
          break;
        case 30: // 11110
          output = "Please call someone now";
          break;
        default:
          output = "No sentence mapped";
          break;
      }
    }
  }

  // Send the output over Serial (USB)
  Serial.println(output);

  delay(2000); // Delay for readability
}
