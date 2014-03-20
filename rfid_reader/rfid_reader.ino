
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
byte Read_UUID [8];
int i = 0;
byte card1[8] = {
  0xCD, 0xE8, 0x62, 0xCA, 0x00, 0x00, 0x00, 0x00};

void setup() {
  Serial.begin(57600);	// Initialize serial communications with the PC
  SPI.begin();		// Init SPI bus
  mfrc522.PCD_Init();	// Init MFRC522 card
  Serial.println("Online and ready to scan");
}

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
    // Halt PICC
  mfrc522.PICC_HaltA();

  Serial.println("Card Present and Selected");

  // Dump UID
  Serial.print("Card UID:");
  for (i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  
  Serial.println();

  for (i=0; i < mfrc522.uid.size; i++) 
  {
    Read_UUID[i] = mfrc522.uid.uidByte[i];
  }

  if(Read_UUID[0] == card1[0] && Read_UUID[1] == card1[1] && Read_UUID[2] == card1[2] && Read_UUID[3] == card1[3] && Read_UUID[4] == card1[4] && Read_UUID[5] == card1[5] && Read_UUID[6] == card1[6] && Read_UUID[7] == card1[7]) Serial.println("Authenticated - Card 1");
  
  else Serial.println("Not Authenticated");
  
  for(i=0; i<8; i++)
  {
    Read_UUID[i] = 0;
  }

  for(i=0; i<8; i++)
  {
    Serial.print(Read_UUID[i], HEX);
    Serial.print(" ");
  }

  Serial.println();
  Serial.println();




}


