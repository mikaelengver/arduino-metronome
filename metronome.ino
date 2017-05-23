#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int bpm = 144;

void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  pinMode(13,INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Metronome");
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

void delayOneBeat() {
  delay(60000/bpm);
}

void updateBpm() {
  lcd.setCursor(0, 1);
  lcd.print(bpm);
  lcd.print(" bpm  ");
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

void oneBeat(int pinOn, int pinOff, int beat) {
  digitalWrite(pinOn, HIGH);
  digitalWrite(pinOff, LOW);
  updateLcdBeat(beat);
  delayOneBeat();
  checkButtons();
  updateBpm();
}

void loop() {
  oneBeat(9,6,1);
  oneBeat(8,9,2);
  oneBeat(7,8,3);
  oneBeat(6,7,4);
}
