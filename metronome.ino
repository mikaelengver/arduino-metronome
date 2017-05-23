#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Declaring and setting Initial bpm.
int bpm = 144;

void setup() {
  pinMode(10,INPUT);
  pinMode(13,INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Metronome");
}

void loop() {
  oneBeat(9,6,1);
  oneBeat(8,9,2);
  oneBeat(7,8,3);
  oneBeat(6,7,4);
}

void oneBeat(int pinOn, int pinOff, int beat) {
  digitalWrite(pinOn, HIGH);
  digitalWrite(pinOff, LOW);
  updateLcdBeat(beat);
  delayOneBeat();
  checkButtons();
  updateBpm();
}

void updateLcdBeat(int beat) {
  lcd.setCursor(12, 1);
  for (int i=4; i >= 1; i--)
  {
    if (beat == i)
    {
      lcd.print(beat);
    }
    else {
      lcd.print(" ");
    }
  }
}

void delayOneBeat() {
  delay(60000/bpm);
}

void checkButtons() {
  int increaseBeatState = digitalRead(10);
  int decreaseBeatState = digitalRead(13);

  if (increaseBeatState == HIGH) {
    bpm += 2;
  }

  if (decreaseBeatState == HIGH) {
    bpm -= 2;
  }
}

void updateBpm() {
  lcd.setCursor(0, 1);
  lcd.print(bpm);
  lcd.print(" bpm  ");
}
