#include "pitches.h"
const int buttonPin1 = 9;  
const int buttonPin2 = 11;
const int buttonPin3 = 7;
int buttonState1 = 0; 
int buttonState2 = 0;
int buttonState3 = 0;
const int buzzerPin = 2;   
static int led = A1;
static int dog = A3;
static int ped = A5;
int nightsMelody[] = {
 233,233,277,311,277,311,349,311,277,233
 };

int nightsDurations[] = {
  8,8,8,3,8,8,8,8,8,2
};
int maskMelody[] = {
NOTE_D6,NOTE_F6,NOTE_A6,NOTE_F6,NOTE_G6,NOTE_A6,NOTE_G6,
NOTE_F6,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_A5,NOTE_D6
};
int beatsPerMinute = 45;
int maskDurations[] = {
  4,8,8,8,2,8,8,8,4,8,8,8,2
};
int replayMelody[] = {
  NOTE_E4, NOTE_CS4,NOTE_B3,NOTE_A3,NOTE_B3,NOTE_CS4,NOTE_B3,NOTE_A3,NOTE_E4,NOTE_CS4
  
};
int replayDurations[] = {
  4,4,8,8,8,6,8,4,4,4
};
void setup() {
  // put your setup code here, to run once:

  pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
      pinMode(buttonPin3, INPUT);
   pinMode(led,OUTPUT);
      pinMode(dog,OUTPUT);
         pinMode(ped,OUTPUT);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  // put your main code here, to run repeatedly:
  if (buttonState1 == HIGH) {
   digitalWrite(led,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(led,LOW);    // turn the LED off by making the voltage LOW
  delay(0);
   playNights();
      
   }
   
   if (buttonState2 == HIGH) {
       digitalWrite(dog,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(dog,LOW);    // turn the LED off by making the voltage LOW
  delay(0);
     playMask();
 
   }
   if (buttonState3 == HIGH) {
   digitalWrite(ped,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(ped,LOW);    // turn the LED off by making the voltage LOW
  delay(0);
    playReplay();
   
   }
}
void playNights(){
  // iterate over the notes of the melody:
  int len = sizeof(nightsMelody)/sizeof(nightsMelody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / nightsDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, nightsMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}

void playMask(){
  // iterate over the notes of the melody:
  int len = sizeof(maskMelody)/sizeof(maskMelody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / maskDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, maskMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}

void playReplay(){
  // iterate over the notes of the melody:
  int len = sizeof(replayMelody)/sizeof(replayMelody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / replayDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, replayMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}
