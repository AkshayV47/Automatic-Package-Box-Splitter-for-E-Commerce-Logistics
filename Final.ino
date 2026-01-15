#define BLYNK_TEMPLATE_ID "TMPL3yCBTN7b9"
#define BLYNK_TEMPLATE_NAME "Smart Door Security Alert System"
#define BLYNK_AUTH_TOKEN "KlHwvRFBmZ0p1vlP-1H7eb6ytVCMFFtz"

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <BlynkSimpleEsp8266.h>    
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define SS_PIN 2    //D4
#define RST_PIN 0   //D3
  
#define Buzzer D2  
#define Servo_pin D8

Servo myServo;

MFRC522 mfrc522(SS_PIN, RST_PIN); 

bool locked;

const char* ssid = "Jeevanth";
const char* password ="Jeev@2006";

// const char* ssid = "OPPOReno8T5G";
// const char* password ="OPPO8T5G";

void setup() {

  SPI.begin();         // Initiate  SPI bus
  mfrc522.PCD_Init();  // Initiate MFRC522
  mfrc522.PCD_DumpVersionToSerial();
  myServo.attach(Servo_pin);
  locked = false;
  pinMode(Buzzer, OUTPUT);
  pinMode(A0, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  Serial.begin(9600);  // Initiate a serial communication
}
BLYNK_WRITE(V4) {
  int switchState = param.asInt(); // 1 = ON, 0 = OFF
  if (switchState == 1){
    myServo.write(180);
    Blynk.virtualWrite(V2, "Door is Open");
    analogWrite(LED_BUILTIN, 500);
  }
  else if (switchState == 0){
    myServo.write(0);
    Blynk.virtualWrite(V2, "Door is Close");  
    analogWrite(LED_BUILTIN, 0); 
  }
}
void loop() {
  Blynk.run();
  const int Ldr = analogRead(A0);
  Serial.println(Ldr);
  delay(1000);
  if(Ldr < 100){
    Blynk.virtualWrite(V3, "Person Passed In");
    Serial.println("Person Passed In"); 
    myServo.write(0);
    delay(1000);
    Serial.println("Door Closed");
    Blynk.virtualWrite(V2, "Door Closed");
  }
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println();
  Serial.print(" UID tag :");
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();

  if (content.substring(1) == "83 21 69 14")  
  {
    Blynk.virtualWrite(V0, "Person-1");       // V0 - Status of Name
    Serial.println("Name : Person-1");
    Blynk.virtualWrite(V1, "Granted");
    Serial.println("Grante");
    Blynk.virtualWrite(V2, "Door Opened");
    Serial.println("Door Opened");
    myServo.write(180);
    delay(100);
    if(Ldr < 100){
      Blynk.virtualWrite(V3, "Person Passed In");
      Serial.println("Person Passed In"); 
      myServo.write(0);
      delay(1000);
      Serial.println("Door Closed");
      Blynk.virtualWrite(V2, "Door Closed");
    }
    digitalWrite(Buzzer,LOW);
    Blynk.virtualWrite(V3, "-----------");
  } 
  else if(content.substring(1) == "B3 30 6F 21"){
    Blynk.virtualWrite(V0, "Person-2");       // V0 - Status of Name
    Serial.println("Name : Person-2");
    Blynk.virtualWrite(V1, "Granted");
    Serial.println("Grante");
    Blynk.virtualWrite(V2, "Door Opened");
    Serial.println("Door Opened");
    myServo.write(180);
    delay(100);
    digitalWrite(Buzzer,LOW);
    Blynk.virtualWrite(V3, "-----------");
  }
  else if (content.substring(1) != "B3 30 6F 21" && content.substring(1) != "83 21 69 14"){
    Blynk.virtualWrite(V0, "Unauthorized");       // V0 - Status of Name
    Serial.println("Unauthorized");
    Blynk.virtualWrite(V1, "Not Granted");
    Serial.println("Not Grante");
    Blynk.virtualWrite(V2, "Door Not Opened");
    Serial.println("Door Not Opened");
    Blynk.virtualWrite(V3, "Unauthorized Person Passed In");
    Serial.println("Unauthorized Person Passed In"); 
    myServo.write(0);
    digitalWrite(Buzzer,HIGH);
    delay(1000);
  }

  delay(1000);
}