
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN_1            6
#define PIN_2            4
#define PIN_3            11
#define PIN_4            12
#define PIN_5            13

#define NUMPIXELS      9

Adafruit_NeoPixel light1 = Adafruit_NeoPixel(NUMPIXELS, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel light2 = Adafruit_NeoPixel(NUMPIXELS, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel light3 = Adafruit_NeoPixel(NUMPIXELS, PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel light4 = Adafruit_NeoPixel(NUMPIXELS, PIN_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel light5 = Adafruit_NeoPixel(NUMPIXELS, PIN_5, NEO_GRB + NEO_KHZ800);

int relayPin1 = 10;
int relayPin2 = 7;
int relayPin3 = 8;
int counter = 0;

bool inputControl[3] = {0, 0, 0};

void setup() {
  Serial.begin(115200);
    pinMode(relayPin1, OUTPUT);
    pinMode(relayPin2, OUTPUT);
    pinMode(relayPin3, OUTPUT);
    light1.begin(); 
    light2.begin();
    light3.begin();
    light4.begin();
    light5.begin();

  for (int i = 0; i < NUMPIXELS; i++) {
    light1.setPixelColor(i, light4.Color(0,0,0,0));
    light1.show();
    light2.setPixelColor(i, light4.Color(0,0,0,0));
    light2.show();
    light3.setPixelColor(i, light4.Color(0,0,0,0));
    light3.show();
    light4.setPixelColor(i, light4.Color(0,0,0,0));
    light4.show(); 
    light5.setPixelColor(i, light4.Color(0,0,0,0));
    light5.show(); 
  }       
}

//should be usbmodem 1421
void loop() {
  microphoneLights();
  if (Serial.available()) {
    int input = Serial.read();
    if (input == 255) {
      counter = 0;
    } else {
      inputControl[counter] = input;
      counter++;
    }
      Serial.write(input);
//      for (int i = 0; i < 3; i++) {
//      inputControl[i] = Serial.parseInt();
//      Serial.println(inputControl[0]);
//      Serial.print("Fan Status");
//      Serial.print(i);
//      Serial.println(inputControl[i]);
      }
//    } 
    fanLightControl();

//  }
//  if (!Serial.available()) {
//    Serial.println("Serial unavailable");
//  }
    delay(5);
} 

void fanLightControl() {
    if (inputControl[0]) {
      digitalWrite(relayPin1, HIGH);
      for (int i = 0; i <NUMPIXELS; i++) {
        //for (int j = 0; j < 256; j++) {
        light3.setPixelColor(i, light4.Color(255, 255, 255, 255));
        light3.show();
        //}
//        delay(50);
      }
    }
      else if (!inputControl[0]) {
        digitalWrite(relayPin1, LOW);
        for (int i = 0; i <NUMPIXELS; i++) {
        light3.setPixelColor(i, light4.Color(0,0,0, 0));
        light3.show();
        }
      }
    if (inputControl[1]) {
      digitalWrite(relayPin2, HIGH);
      for (int i = 0; i <NUMPIXELS; i++) {
        //for (int j = 0; j < 256; j++) {
          light4.setPixelColor(i, light4.Color(255, 255, 255, 255));
          light4.show();
        //}
      //delay(50);
      }
     }
     else if (!inputControl[1]) {
        digitalWrite(relayPin2, LOW);
        for (int i = 0; i <NUMPIXELS; i++) {
          light4.setPixelColor(i, light3.Color(0,0,0,0));
          light4.show();
        }
      }
    if (inputControl[2]) {
      digitalWrite(relayPin3, HIGH);
        for (int i = 0; i <NUMPIXELS; i++) {
          //for (int j = 0; j <256; j++) {
          light5.setPixelColor(i, light5.Color(255, 255, 255, 255));
          light5.show();
          //}
        }
        //delay(50);
    }
      else if (!inputControl[2]) {
        digitalWrite(relayPin3, LOW);
        for (int i = 0; i <NUMPIXELS; i++) {
          light5.setPixelColor(i, light5.Color(0,0,0,0));
          light5.show();
        }
      }
}

void microphoneLights() {
      //controlling microphone lights
    //  Serial.println("microphones");
    for(int i=0;i<NUMPIXELS;i++) {
          light1.setPixelColor(i, light1.Color(75, 75, 75, 100)); // Warm white
          light2.setPixelColor(i, light2.Color(75, 75, 75, 100));
          light1.show(); 
          light2.show();
 
      }
      for(int i=0;i<NUMPIXELS;i++){
          light1.setPixelColor(i, light1.Color(0, 0, 0, 25)); // Warm white
          light2.setPixelColor(i, light2.Color(0, 0, 0, 25));
          light1.show(); 
          light2.show();
        }
}

