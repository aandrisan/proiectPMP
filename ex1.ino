/* 
  Super Mario Bros - Overworld theme 
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs                                            
                                              
                                              Robson Couto, 2019
*/

#include "pitches.h"

#define REST      0

#define led0 B0001
#define led1 B0010
#define led2 B0100
#define led3 B1000

int buzzer = 8;
int senz_pin = A1;
int ledPins[] = {
  3,4,5,6 };       // an array of pin numbers to which LEDs are attached
int pinCount = 4;
String categorie= "";

int melody1[] = {

  // We Wish You a Merry Christmas
  
  NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4,
  NOTE_F5,4, NOTE_F5,8, NOTE_G5,8, NOTE_F5,8, NOTE_E5,8,
  NOTE_D5,4, NOTE_D5,4, NOTE_D5,4,
  NOTE_G5,4, NOTE_G5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,4, NOTE_C5,4, NOTE_C5,4,
  NOTE_A5,4, NOTE_A5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8,
  NOTE_F5,4, NOTE_D5,4, NOTE_C5,8, NOTE_C5,8,
  NOTE_D5,4, NOTE_G5,4, NOTE_E5,4,
  NOTE_F5,2, NOTE_C5,4

};

byte LEDs1[]={
  B1010,
  B1000, B1000, B1001, B1000, B1111,
  B1100, B0011, B1111,
  B1001, B0101, B1101, B0001, B0101,
  B1010, B1101, B1101,
  B1111, B0011, B0101, B0010, B1001,
  B0011, B1010, B1001, B1111,
  B1101, B0111, B0010,
  B1000, B1011,
  B1010,
  B1000, B1000, B1001, B1000, B1111,
  B1100, B0011, B1111,
  B1001, B0101, B1101, B0001, B0101,
  B1010, B1101, B1101,
  B1111, B0011, B0101, B0010, B1001,
  B0011, B1010, B1001, B1111,
  B1101, B0111, B0010,
  B1000, B1011
};


int melody2[] = {
  
  NOTE_D4,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_D4,3, NOTE_D4,16, NOTE_D4,16,
  NOTE_D4,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,2,
  NOTE_E4,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_FS4,2,
  NOTE_D5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_B4,3, NOTE_D4,8,
  NOTE_D4,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_D4,3, NOTE_D4,16, NOTE_D4,16,
  NOTE_D4,8, NOTE_B4,8, NOTE_A4,8, NOTE_G4,8, NOTE_E4,3, NOTE_E4,8,
  NOTE_E4,8, NOTE_C5,8, NOTE_B4,8, NOTE_A4,8, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8, NOTE_D5,8,
  NOTE_E5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_G4,2,
  NOTE_B4,8, NOTE_B4,8, NOTE_B4,4, NOTE_B4,8, NOTE_B4,8, NOTE_B4,4,
  NOTE_B4,8, NOTE_D5,8, NOTE_G4,6, NOTE_A4,16, NOTE_B4,2,
  NOTE_C5,8, NOTE_C5,8, NOTE_C5,6, NOTE_C5,16, NOTE_C5,8, NOTE_B4,8, NOTE_B4,8, NOTE_B4,16, NOTE_B4,16,
  NOTE_B4,8, NOTE_A4,8, NOTE_A4,8, NOTE_B4,8, NOTE_A4,4, NOTE_D5,4,
  NOTE_B4,8, NOTE_B4,8, NOTE_B4,4, NOTE_B4,8, NOTE_B4,8, NOTE_B4,4,
  NOTE_B4,8, NOTE_D5,8, NOTE_G4,6, NOTE_A4,16, NOTE_B4,2,
  NOTE_C5,8, NOTE_C5,8, NOTE_C5,6, NOTE_C5,16, NOTE_C5,8, NOTE_B4,8, NOTE_B4,8, NOTE_B4,16, NOTE_B4,16,
  NOTE_D5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_G4,2 };

byte LEDs2[]={
   B0010,   B0100,   B1000,   B0001,   B1111,       B0001,    B0001,
   B0001,   B1000,   B0100,   B0010,   B1111,
   B0010,   B1000,   B0100,   B0001,   B1111,
   B0001,   B0100,   B1000,   B0010,   B1111,       B0010,
   B0010,   B0100,   B1000,   B0001,   B1111,       B0001,    B0001,
   B0001,   B1000,   B0100,   B0010,   B1111,       B0010,
   B0010,   B0100,   B1000,   B0001,   B1001,     B0110,    B1100,       B0011,
   B1010,    B0101,    B1010,     B0101,    B1111,
   B0110,    B0110,    B0110,     B1001,    B1001,      B1001,
   B0010,   B0100,   B1000,   B0001,   B1111,
   B0110,    B0110,    B0110,     B0110,    B0110,      B1001,    B1001,       B1001,      B1001,
   B0010,   B0100,   B1000,   B0001,   B0010,    B1111,
   B0110,    B0110,    B0110,     B1001,    B1001,     B1001,
   B0010,   B0100,   B1000,   B0001,   B1111,
   B0110,    B0110,    B0110,     B0110,    B0110,     B1001,     B1001,       B1001,      B1001,
   B1111,       B1111,       B1100,    B0011,    B1111};


int melody3[] = {

  // Game of Thrones
  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,-4, NOTE_C4,-4,
  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,
  NOTE_D4,-1,
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1,
  NOTE_G4,-4, NOTE_C4,-4,
  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,
  NOTE_D4,-1,
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1,
  NOTE_G4,-4, NOTE_C4,-4,
  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16
};

byte LEDs3[] ={
  B1100, B1010, B1001, B1000, B0100, B0010, B0001, B1111,
  B1100, B1010, B1001, B1000, B0100, B0010, B0001, B1111,
  B1100, B1010, B1001, B1000, B0100, B0010, B0001, B1111,
  B1100, B1010, B1001, B1000, B0100, B0010, B0001, B1111,
  B1010, B0110,
  B1111, B1100, B0011, B1010, B0110, B1001,
  B1111,
  B1000, B0001,
  B0100, B0010, B1000, B0001,
  B1111, B1111, B0110,
  B1000, B0001,
  B1111, B1100, B0011, B1010, B0110, B1001,
  B1111,
  B1000, B0001,
  B0100, B0010, B1000, B0001,
  B1111, B1111, B0110,
  B1000, B0001,
  B1111, B1100, B0011, B1010, B0110, B1001
  
};

int melody4[] = {
  
  // Dart Vader theme (Imperial March) - Star wars   
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, 
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8 
};

byte LEDs4[]={
  B1000, B0100, B0010,
  B0001, B0001,
  B1001, B0110, B1001, B0110, B1111,
  B1001, B0110, B1001, B0110, B1111,
  B1001, B0110, B0011, B1100, B1010, B1010, B1010,
  B0001, B0001,
  B1001, B0110, B1001, B0110, B1111,
  B1001, B0110, B1001, B0110, B1111,
  B1001, B0110, B0011, B1100, B1010, B1010, B1010,
  B1111, B1000, B0100, B0010, B0001,B1111,
  B1010, B0101, B1001, B0110, B1111, B1100, B0011, B1101,
  B1111, B1000, B0100, B0010, B0001,B1111
};

int melody5[] = {

  // Super Mario Bros theme 
  
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8,
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, 
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4,
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4

};

byte LEDs5[] = {
  B1001, B0110, B0000, B1001, B0000, B0110, B0110,
  B1000, B0100, B0010, B000,
  B1101, B1011, B0000, B1110,
  B1001, B0101, B0110, B1001,
  B1010, B1101, B0111, B1111, B1001, B0010,
  B0000, B1101, B1011, B0000, B1110,
  B1101, B1011, B0000, B1110,
  B1001, B0101, B0110, B1001,
  B1010, B1101, B0111, B1111, B1001, B0010,
  B0000, B1101, B1011, B0000, B1110
};

int melody6[] = {
  
  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,
  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4
};

byte LEDs6[] = {
   B1111, B0101, B1010, B1001, B0110, B1111,
   B0010, B0100, B1001, B1000, B0001, B0110,
   B1100, B0011, B1001, B0110,
   B0001, B0010, B0100, B1000, B1111, B1011,
   B1101, B0111, B1011, B1110, B1111,
   B1101, B0111, B1011, B1110, B1111,
   B1100, B0011, B1001, B0110, B0001,
   B0010, B0100, B1001, B1000
};

int melody7[] = {

  
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,

  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2
  
};

byte LEDs7[] = {
  B1100, B0011, B1010, B0101,
  B1111, B0001, B0100, B1111,
  B1001, B1101, B1011, B0100,
  B0010, B1001, B1111,
  B1100, B0011, B1010, B0101,
  B1111, B0001, B0100, B1111,
  B1001, B1101, B1011, B0100,
  B0010, B1001, B1111
  
};

const int melody8[] = {

  // Fur Elise - Ludwig van Beethovem
  NOTE_E5, 16, NOTE_DS5, 16,
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16,
  NOTE_B4, -8, NOTE_E4, 16, NOTE_GS4, 16, NOTE_B4, 16,
  NOTE_C5, 8,  REST, 16, NOTE_E4, 16, NOTE_E5, 16,  NOTE_DS5, 16, 
  NOTE_E5, 16, NOTE_DS5, 16, NOTE_E5, 16, NOTE_B4, 16, NOTE_D5, 16, NOTE_C5, 16,
  NOTE_A4, -8, NOTE_C4, 16, NOTE_E4, 16, NOTE_A4, 16, 
  NOTE_B4, -8, NOTE_E4, 16, NOTE_C5, 16, NOTE_B4, 16, 
  NOTE_A4 , 4
};

byte LEDs8[] = {
  B1111, B1001,
  B1111, B0110, B1000, B0100, B0010, B0001, B1111,
  B0101, B1001, B0111, B0010,
  B1110, B0110, B0011, B0100,
  B0100, B0000, B1111, B1011, B0100,
  B1111, B0110, B1000, B0100, B0010, B0001, B1111,
  B0101, B1001, B0111, B0010,
  B1110, B0110, B0011, B0100,
  B1111
};

int notes1 = sizeof(melody1) / sizeof(melody1[0]) / 2;
int notes2 = sizeof(melody2) / sizeof(melody2[0]) / 2;
int notes3 = sizeof(melody3) / sizeof(melody3[0]) / 2;
int notes4 = sizeof(melody4) / sizeof(melody4[0]) / 2;
int notes5 = sizeof(melody5) / sizeof(melody5[0]) / 2;
int notes6 = sizeof(melody6) / sizeof(melody6[0]) / 2;
int notes7 = sizeof(melody7) / sizeof(melody7[0]) / 2;
int notes8 = sizeof(melody8) / sizeof(melody8[0]) / 2;


int divider = 0, noteDuration = 0;

void setup() {
  
  pinMode(senz_pin, INPUT);
  pinMode(buzzer, OUTPUT);
    for (int i=0;i<pinCount;i++)
  {
    pinMode(ledPins[i],OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  
  Serial1.begin(9600); //for bluetooth communication
}

void loop() {

if(Serial1.available()>0){
  categorie = Serial1.readString();
  }
  
  while (categorie == "1"){
  if ( analogRead( senz_pin) >512 ){
   for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2) {
    int tempo1 = (analogRead(senz_pin) - 500)/2;
    int wholenote1 = (60000 * 4) / tempo1;
    Serial.println(Serial1.available());
    if( analogRead( senz_pin) < 512 || Serial1.available() == 1){
      break;
    }
    // calculates the duration of each note
    divider = melody1[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote1) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote1) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody1[thisNote], noteDuration * 0.9);
    LEDon1(thisNote);
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    LEDoff1(thisNote);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }}

   if ( analogRead( senz_pin) < 512 ){
   for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) {
    int tempo2=(512 - analogRead(senz_pin))/2;
    int wholenote2 = (60000 * 4) / tempo2;
    if( analogRead( senz_pin) > 512 || Serial1.available() == 1){
      break;
    }
    divider = melody2[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote2) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote2) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(buzzer, melody2[thisNote], noteDuration * 0.9);
    LEDon2(thisNote);
    delay(noteDuration);
    LEDoff2(thisNote);

    noTone(buzzer);
  }}

  if (Serial1.available() == 1){
    break;
  }
  
  }
while( categorie == "2"){
  if ( analogRead( senz_pin) > 512 ){
   for (int thisNote = 0; thisNote < notes3 * 2; thisNote = thisNote + 2) {
    int tempo3 = (analogRead(senz_pin)-500)/2;
    int wholenote3 = (60000 * 4) / tempo3;
    if( analogRead( senz_pin) < 512 || Serial1.available() == 1){
      break;
    }
    divider = melody3[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote3) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote3) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody3[thisNote], noteDuration * 0.9);
    LEDon3(thisNote);
    delay(noteDuration);
    LEDoff3(thisNote);
    noTone(buzzer);
  }}

    if ( analogRead( senz_pin) < 512){
   for (int thisNote = 0; thisNote < notes4 * 2; thisNote = thisNote + 2) {
    int tempo4 = (512 - analogRead(senz_pin))/2;
    int wholenote4 = (60000 * 4) / tempo4;
    if( analogRead( senz_pin) > 512 || Serial1.available() == 1){
      break;
    }

    divider = melody4[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote4) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote4) / abs(divider);
      noteDuration *= 1.5; 
    }
    tone(buzzer, melody4[thisNote], noteDuration * 0.9);
    LEDon4(thisNote);
    delay(noteDuration);
    LEDoff4(thisNote);
    noTone(buzzer);
  }}
  if (Serial1.available() == 1){
    break;
  }
  }

  
while(categorie == "3"){
    if ( analogRead( senz_pin) > 512 ){
   for (int thisNote = 0; thisNote < notes5 * 2; thisNote = thisNote + 2) {
    int tempo5 = (analogRead(senz_pin) - 512)/2;
    int wholenote5 = (60000 * 4) / tempo5;
    if( analogRead( senz_pin) < 512 || Serial1.available() == 1){
      break;
    }
    divider = melody5[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote5) / divider;
    } else if (divider < 0) {

      noteDuration = (wholenote5) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(buzzer, melody5[thisNote], noteDuration * 0.9);
    LEDon5(thisNote);
    delay(noteDuration);
    LEDoff5(thisNote);
    noTone(buzzer);
  }}

    if ( analogRead( senz_pin) < 512){
   for (int thisNote = 0; thisNote < notes6 * 2; thisNote = thisNote + 2) {
    int tempo6=(512 - analogRead(senz_pin)) / 2;
    int wholenote6 = (60000 * 4) / tempo6;
    if( analogRead( senz_pin) > 512 || Serial1.available() == 1){
      break;
    }
    divider = melody6[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote6) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote6) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody6[thisNote], noteDuration * 0.9);
    LEDon6(thisNote);
    delay(noteDuration);
    LEDoff6(thisNote);

    noTone(buzzer);
  }}

  if (Serial1.available() == 1){
    break;
  }

}

while( categorie == "4"){
    if ( analogRead( senz_pin) > 512 ){
   for (int thisNote = 0; thisNote < notes7 * 2; thisNote = thisNote + 2) {
    int tempo7=( analogRead(senz_pin) - 500 )/2;
    int wholenote7 = (60000 * 4) / tempo7;
    if( analogRead( senz_pin) < 512 || Serial1.available() == 1){
      break;
    }
    divider = melody7[thisNote + 1];
    if (divider > 0) {
     
      noteDuration = (wholenote7) / divider;
    } else if (divider < 0) {
      
      noteDuration = (wholenote7) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody7[thisNote], noteDuration * 0.9);
    LEDon7(thisNote);
    delay(noteDuration);
    LEDoff7(thisNote);

    noTone(buzzer);
  }}

    if ( analogRead( senz_pin) < 512){
   for (int thisNote = 0; thisNote < notes8 * 2; thisNote = thisNote + 2) {
    int tempo8 = (512 - analogRead(senz_pin))/2;
    int wholenote8 = (60000 * 4) / tempo8;
    if( analogRead( senz_pin) > 512 || Serial1.available() == 1){
      break;
    }
    divider = melody8[thisNote + 1];
    if (divider > 0) {

      noteDuration = (wholenote8) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote8) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody8[thisNote], noteDuration * 0.9);
    LEDon8(thisNote);
    delay(noteDuration);
    LEDoff8(thisNote);

    noTone(buzzer);
  }}

if (Serial1.available() == 1){
    break;
  }
}
  
}

int currentLEDpin=3;
void LEDon2(int thisNote)
{
  if ((LEDs2[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs2[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs2[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs2[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff2(int thisNote)
{
  if ((LEDs2[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs2[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs2[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs2[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon1(int thisNote)
{
  if ((LEDs1[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs1[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs1[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs1[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff1(int thisNote)
{
  if ((LEDs1[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs1[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs1[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs1[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon3(int thisNote)
{
  if ((LEDs3[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs3[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs3[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs3[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff3(int thisNote)
{
  if ((LEDs3[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs3[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs3[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs3[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon4(int thisNote)
{
  if ((LEDs4[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs4[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs4[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs4[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff4(int thisNote)
{
  if ((LEDs4[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs4[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs4[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs4[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon5(int thisNote)
{
  if ((LEDs5[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs5[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs5[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs5[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff5(int thisNote)
{
  if ((LEDs5[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs5[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs5[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs5[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon6(int thisNote)
{
  if ((LEDs6[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs6[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs6[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs6[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff6(int thisNote)
{
  if ((LEDs6[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs6[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs6[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs6[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon7(int thisNote)
{
  if ((LEDs7[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs7[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs7[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs7[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff7(int thisNote)
{
  if ((LEDs7[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs7[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs7[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs7[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}

void LEDon8(int thisNote)
{
  if ((LEDs8[thisNote]&led0)!=0) digitalWrite(ledPins[0],HIGH);
  if ((LEDs8[thisNote]&led1)!=0) digitalWrite(ledPins[1],HIGH);
  if ((LEDs8[thisNote]&led2)!=0) digitalWrite(ledPins[2],HIGH);
  if ((LEDs8[thisNote]&led3)!=0) digitalWrite(ledPins[3],HIGH);
}

void LEDoff8(int thisNote)
{
  if ((LEDs8[thisNote]&led0)!=0) digitalWrite(ledPins[0],LOW);
  if ((LEDs8[thisNote]&led1)!=0) digitalWrite(ledPins[1],LOW);
  if ((LEDs8[thisNote]&led2)!=0) digitalWrite(ledPins[2],LOW);
  if ((LEDs8[thisNote]&led3)!=0) digitalWrite(ledPins[3],LOW);
}
