/*
 * MFRC522 - Library to use ARDUINO RFID MODULE KIT 13.56 MHZ WITH TAGS SPI W AND R BY COOQROBOT.
 * The library file MFRC522.h has a wealth of useful info. Please read it.
 * The functions are documented in MFRC522.cpp.
 *
 * Based on code Dr.Leong   ( WWW.B2CQSHOP.COM )
 * Created by Miguel Balboa (circuitito.com), Jan, 2012.
 * Rewritten by Søren Thing Andersen (access.thing.dk), fall of 2013 (Translation to English, refactored, comments, anti collision, cascade levels.)
 * 
 * Released into the public domain.
 *
 * This sample shows how to setup a block on a MIFARE Classic PICC to be in "Value Block" mode.
 * In Value Block mode the operations Increment/Decrement/Restore and Transfer can be used.
 * 
 ----------------------------------------------------------------------------- empty_skull 
 
 - Aggiunti pin per arduino Mega
 - Scritto semplice codice per la scrittura e lettura 
 
 - add pin configuration for arduino mega
 - write simple read/write Code for new entry user
 
 http://mac86project.altervista.org/
 
 ----------------------------------------------------------------------------- Nicola Coppola
 * Pin layout should be as follows:
 * Signal     Pin              Pin               Pin
 *            Arduino Uno      Arduino Mega      MFRC522 board
 * ------------------------------------------------------------
 * Reset      9                5                 RST
 * SPI SS     10               53                SDA
 * SPI MOSI   11               52                MOSI
 * SPI MISO   12               51                MISO
 * SPI SCK    13               50                SCK
 *
 * The reader can be found on eBay for around 5 dollars. Search for "mf-rc522" on ebay.com. 
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);        // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

  byte card1UID[] = {0xCD, 0xE8, 0x62, 0xCA};
  byte card2UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card3UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card4UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card5UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card6UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card7UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card8UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card9UID[] = {0x00, 0x00, 0x00, 0x00};
  byte card10UID[] = {0x00, 0x00, 0x00, 0x00};

  byte card1ID[] = {0xE9, 0x5E, 0xFE, 0xE4, 0x90, 0xFC, 0x8D, 0xCD, 0x88, 0x9C, 0xE3, 0x34, 0x09, 0x2B, 0xD8, 0x3B  }; // Card 1
  byte card2ID[] = {0x77, 0x2E, 0x06, 0x9C, 0x1E, 0x5B, 0x47, 0xAD, 0x71, 0x0B, 0x89, 0x5F, 0x1C, 0x18, 0x2B, 0xBF  }; // Card 2
  byte card3ID[] = {0x85, 0xD0, 0xCD, 0xF7, 0x18, 0x8C, 0xB0, 0xE4, 0x70, 0xC2, 0x4C, 0xEF, 0x9A, 0xF5, 0x37, 0x0E  }; // Card 3
  byte card4ID[] = {0x3C, 0x09, 0x7B, 0x39, 0x31, 0x83, 0x72, 0x0D, 0x8D, 0xF0, 0x11, 0x57, 0xCF, 0x62, 0xBC, 0xFA  }; // Card 4
  byte card5ID[] = {0xBC, 0xD1, 0xA9, 0xC3, 0x85, 0xA3, 0x71, 0x96, 0x4C, 0x29, 0x7C, 0xFC, 0x22, 0xDA, 0x1E, 0x46  }; // Card 5
  byte card6ID[] = {0xA8, 0x15, 0xAE, 0xB2, 0xBB, 0x13, 0xB2, 0x2D, 0x8A, 0x09, 0xA8, 0x7D, 0x9D, 0xE4, 0xBE, 0x95  }; // Card 6
  byte card7ID[] = {0x2F, 0x0F, 0xFF, 0xFC, 0x08, 0xAA, 0x2D, 0x0F, 0x66, 0x2B, 0xCB, 0xCE, 0xC1, 0x80, 0x52, 0x89  }; // Card 7
  byte card8ID[] = {0x83, 0x29, 0x33, 0x4F, 0x26, 0x14, 0x3A, 0x03, 0x5D, 0xFC, 0xBB, 0xFC, 0x1C, 0xF9, 0x52, 0xA6  }; // Card 8
  byte card9ID[] = {0x63, 0x3C, 0x6D, 0x4C, 0x58, 0x91, 0x80, 0x14, 0x7F, 0x1C, 0x98, 0x83, 0x5C, 0xC5, 0x0F, 0x90  }; // Card 9
  byte card10ID[] = {0xCE, 0xF0, 0xA0, 0xC9, 0x72, 0x41, 0x14, 0x75, 0xBB, 0xD2, 0x74, 0x89, 0x68, 0x20, 0xB4, 0xF6  }; // Card 10
  
  int check1 = 0;
  int check2 = 0;
  
  int debug = 0; // determines whether to send debug info to UART. 0 = NO, 1 = YES


void setup() {
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();                // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  //Serial.println("Scan a MIFARE Classic PICC to demonstrate Value Blocks.");
  // Prepare key  by setting up private KEY A
  key.keyByte[0] = 0xFA;
  key.keyByte[1] = 0xAD;
  key.keyByte[2] = 0xA1;
  key.keyByte[3] = 0x9B;
  key.keyByte[4] = 0x3C;
  key.keyByte[5] = 0x47;
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
  // Now a card is selected. The UID and SAK is in mfrc522.uid.

  // Dump UID
  if (debug == 1)
  {
    Serial.print("Card UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    } 
  

    Serial.println();
  
    // Dump PICC type
    byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.print("PICC type: ");
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
    if (        piccType != MFRC522::PICC_TYPE_MIFARE_MINI 
      &&        piccType != MFRC522::PICC_TYPE_MIFARE_1K
      &&        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
      //Serial.println("This sample only works with MIFARE Classic cards.");
      return;
    }
  }

  // In this sample we use the second sector (ie block 4-7). the first sector is = 0
  byte sector         = 1;
  // block sector 0-3(sector0) 4-7(sector1) 8-11(sector2)
  byte valueBlockA    = 4;
  byte valueBlockB    = 5;
  //byte valueBlockC    = 6;
  byte trailerBlock   = 7;
  byte status;

  // Authenticate using key A.
  Serial.println("Authenticating using key A...");
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("PCD_Authenticate() failed: ");
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  Serial.println("Authenticated");
  
if(1==0)
  {
    // Writing new value block 4 Use this to save idnetity code onto key
    Serial.println("Writing new value Block 4 : the first of the sector ONE");
    // uncomment to write matching code to key
    byte value1Block[] = {0xE9, 0x5E, 0xFE, 0xE4, 0x90, 0xFC, 0x8D, 0xCD, 0x88, 0x9C, 0xE3, 0x34, 0x09, 0x2B, 0xD8, 0x3B  }; // Card 1
    //byte value1Block[] = {0x77, 0x2E, 0x06, 0x9C, 0x1E, 0x5B, 0x47, 0xAD, 0x71, 0x0B, 0x89, 0x5F, 0x1C, 0x18, 0x2B, 0xBF  }; // Card 2
    //byte value1Block[] = {0x85, 0xD0, 0xCD, 0xF7, 0x18, 0x8C, 0xB0, 0xE4, 0x70, 0xC2, 0x4C, 0xEF, 0x9A, 0xF5, 0x37, 0x0E  }; // Card 3
    //byte value1Block[] = {0x3C, 0x09, 0x7B, 0x39, 0x31, 0x83, 0x72, 0x0D, 0x8D, 0xF0, 0x11, 0x57, 0xCF, 0x62, 0xBC, 0xFA  }; // Card 4
    //byte value1Block[] = {0xBC, 0xD1, 0xA9, 0xC3, 0x85, 0xA3, 0x71, 0x96, 0x4C, 0x29, 0x7C, 0xFC, 0x22, 0xDA, 0x1E, 0x46  }; // Card 5
    //byte value1Block[] = {0xA8, 0x15, 0xAE, 0xB2, 0xBB, 0x13, 0xB2, 0x2D, 0x8A, 0x09, 0xA8, 0x7D, 0x9D, 0xE4, 0xBE, 0x95  }; // Card 6
    //byte value1Block[] = {0x2F, 0x0F, 0xFF, 0xFC, 0x08, 0xAA, 0x2D, 0x0F, 0x66, 0x2B, 0xCB, 0xCE, 0xC1, 0x80, 0x52, 0x89  }; // Card 7
    //byte value1Block[] = {0x83, 0x29, 0x33, 0x4F, 0x26, 0x14, 0x3A, 0x03, 0x5D, 0xFC, 0xBB, 0xFC, 0x1C, 0xF9, 0x52, 0xA6  }; // Card 8
    //byte value1Block[] = {0x63, 0x3C, 0x6D, 0x4C, 0x58, 0x91, 0x80, 0x14, 0x7F, 0x1C, 0x98, 0x83, 0x5C, 0xC5, 0x0F, 0x90  }; // Card 9
    //byte value1Block[] = {0xCE, 0xF0, 0xA0, 0xC9, 0x72, 0x41, 0x14, 0x75, 0xBB, 0xD2, 0x74, 0x89, 0x68, 0x20, 0xB4, 0xF6  }; // Card 10
  
    status = mfrc522.MIFARE_Write(valueBlockA, value1Block, 16);
    if (status != MFRC522::STATUS_OK) {
      Serial.print("MIFARE_Write() failed: ");
      Serial.println(mfrc522.GetStatusCodeName(status));
    }
}

  Serial.println("Checking Card");        
  byte buffer[18];
  byte size = sizeof(buffer);
  // change this: valueBlockA , for read anather block
  status = mfrc522.MIFARE_Read(valueBlockA, buffer, &size);

  if(debug == 1)
  {
    Serial.print("Card ID: ");
    
    for (int i=0; i<18; i++)
    {
      Serial.print(buffer[i]);
      Serial.print(" "); 
    }
    Serial.println();
  }


if (UIDcmp(mfrc522.uid.uidByte, card1UID) == true) check1 = 1;
if (UIDcmp(mfrc522.uid.uidByte, card2UID) == true) check1 = 2;
if (UIDcmp(mfrc522.uid.uidByte, card3UID) == true) check1 = 3;
if (UIDcmp(mfrc522.uid.uidByte, card4UID) == true) check1 = 4;
if (UIDcmp(mfrc522.uid.uidByte, card5UID) == true) check1 = 5;
if (UIDcmp(mfrc522.uid.uidByte, card6UID) == true) check1 = 6;
if (UIDcmp(mfrc522.uid.uidByte, card7UID) == true) check1 = 7;
if (UIDcmp(mfrc522.uid.uidByte, card8UID) == true) check1 = 8;
if (UIDcmp(mfrc522.uid.uidByte, card9UID) == true) check1 = 9;
if (UIDcmp(mfrc522.uid.uidByte, card10UID) == true) check1 = 10;

Serial.print("ID as Card: ");
Serial.println(check1);

if (IDcmp(buffer, card1ID) == true) check2 = 1;
if (IDcmp(buffer, card2ID) == true) check2 = 2;
if (IDcmp(buffer, card3ID) == true) check2 = 3;
if (IDcmp(buffer, card4ID) == true) check2 = 4;
if (IDcmp(buffer, card5ID) == true) check2 = 5;
if (IDcmp(buffer, card6ID) == true) check2 = 6;
if (IDcmp(buffer, card7ID) == true) check2 = 7;
if (IDcmp(buffer, card8ID) == true) check2 = 8;
if (IDcmp(buffer, card9ID) == true) check2 = 9;
if (IDcmp(buffer, card10ID) == true) check2 = 10;

if(check1 == check2)
{
  Serial.print("Confirm as Card: ");
  Serial.println(check2);
}
else
{
  Serial.println("Card Invalid");
}



  // Halt PICC
  mfrc522.PICC_HaltA();

  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();


}

boolean UIDcmp(byte *a, byte *b){
      int n;

      // test each element to be the same. if not, return false
      for (n=0;n<4;n++) if (a[n]!=b[n]) return false;

      //ok, if we have not returned yet, they are equal :)
      return true;
}

boolean IDcmp(byte *a, byte *b){
      int n;

      // test each element to be the same. if not, return false
      for (n=0;n<16;n++) if (a[n]!=b[n]) return false;

      //ok, if we have not returned yet, they are equal :)
      return true;
}






