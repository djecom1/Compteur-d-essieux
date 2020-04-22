#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);
extern uint8_t BigNumbers[];
extern uint8_t SmallFont[];

const int  buttonPin = 5;    // the pin that the Up pushbutton is attached to
const int  buttonPin1 = 6;    // the pin that the Down pushbutton is attached to

// Variables will change:

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState5 = 0;         // current state of the button
int buttonState6 = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


void setup() {
  Serial.begin(9600);

  myOLED.begin();
//  myOLED.setFont(BigNumbers);
//  myOLED.setFont(SmallFont);

  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop() {

  // read the pushbutton up input pin:
  buttonState5 = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState5 != lastButtonState) {

    // if the state has changed, increment the counter
    if (buttonState5 == HIGH)
    {      buttonPushCounter++;
      Serial.println(buttonPushCounter);
      myOLED.setFont(BigNumbers);
      myOLED.printNumI(buttonPushCounter,CENTER,24);
      myOLED.update();
      //myOLED.clrScr();
    }
    delay(100);
    
    if (buttonPushCounter != 0)
    {
      Serial.println("CANTON OCCUPE");
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      myOLED.setFont(SmallFont);
      myOLED.print("CANTON OCCUPE",CENTER,0);
      myOLED.update();
      myOLED.clrScr();
    } else {
      Serial.println("CANTON LIBRE");
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      myOLED.setFont(SmallFont);
      myOLED.print("CANTON LIBRE",CENTER,0);
      myOLED.update();
      myOLED.clrScr();
    }
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState5;

  // read the pushbutton down input pin:
  buttonState6 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState6 != lastButtonState) {
    
    // if the state has changed, decrement the counter
    if (buttonState6 == HIGH)
    {
      buttonPushCounter -= 1;
      Serial.println(buttonPushCounter);
      myOLED.setFont(BigNumbers);
      myOLED.printNumI(buttonPushCounter,CENTER,24);
      myOLED.update();
      //myOLED.clrScr();
    }
    delay(100);

    if (buttonPushCounter != 0)
    {
      Serial.println("CANTON OCCUPE");
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      myOLED.setFont(SmallFont);
      myOLED.print("CANTON OCCUPE",CENTER,0);
      myOLED.update();
      myOLED.clrScr();
    } else {
      Serial.println("CANTON LIBRE");
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      myOLED.setFont(SmallFont);
      myOLED.print("CANTON LIBRE",CENTER,0);
      myOLED.update();
      myOLED.clrScr();
    }
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState6;
}
