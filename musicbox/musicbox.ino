#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_OFF 5
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_GS4, NOTE_AS4, NOTE_FS4, NOTE_GS4,NOTE_SILENCE, NOTE_B4, NOTE_AS4, NOTE_FS4, NOTE_GS4, NOTE_SILENCE};
double durations[] = {4,2,2,4,10,4,2,2,6,10};
int melodyLength = 10;

// maybe somewhere in the future we will have one more button...
 #define PIN_BUTTON_MEL_TWO 4
 Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);

// and the second melody
 int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
 double durations2[] = {4, 1, 4, 1};
 int melodyLength2 = 4;

void setup()
{
  Serial.begin(115200);
  buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
  Serial.print("test");
  buzzer.playSound();

  if (buttonOff.wasPressed())
  {
    buzzer.turnSoundOff();
  }

  if (buttonMelodyOne.wasPressed())
  {
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
  }
}
