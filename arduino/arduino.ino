#include <SoftwareSerial.h>
#include <OneWire.h>
#define HM10_TXD 8
#define HM10_RXD 7
#define BT_RX HM10_TXD
#define BT_TX HM10_RXD
#define OW_PIN 5
#define INPUT_SIZE 20

char inputBuffer[INPUT_SIZE+1];
SoftwareSerial HM10(BT_RX,BT_TX);
OneWire ds(OW_PIN);

void setup() {  
  Serial.begin(9600); //to serial monitor
  HM10.begin(9600); //arduino <-> hm10
  Serial.println("\r\nHM10 + thermo");
}


char temperaturebuf[7];
String lastTemperature;

void loop() {
  bool noti = false;
  if(HM10.available() > 0) {
      int len = HM10.available();
      Serial.print("received ");
      Serial.print(len);
      Serial.println(" bytes");
      Serial.print("value : ");
      byte size = HM10.readBytes(inputBuffer, INPUT_SIZE);
      inputBuffer[len] = 0;
      Serial.println(inputBuffer);
      noti = true;
  }

  String t = getTemperature();
  if(t != lastTemperature) {
    noti = true;
  }
  if(noti) {
    Serial.println("temperature is " + t);
    t.toCharArray(temperaturebuf, sizeof(temperaturebuf));
    HM10.write(temperaturebuf, sizeof(temperaturebuf));
    lastTemperature = t;
  }

  if(Serial.available() > 0) {
    HM10.write(Serial.read());
  }
}

String getTemperature() {
    byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;

  ds.reset_search();
  if ( !ds.search(addr)) {
      Serial.print("No more addresses.\n");
      ds.reset_search();
      return String("ERR");
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end

  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.

  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
  }

  LowByte = data[0];
  HighByte = data[1];
  TReading = (HighByte << 8) + LowByte;
  SignBit = TReading & 0x8000;  // test most sig bit
  if (SignBit) // negative
  {
    TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }
  Tc_100 = (6 * TReading) + TReading / 4;    // multiply by (100 * 0.0625) or 6.25

  Whole = Tc_100 / 100;  // separate off the whole and fractional portions
  Fract = Tc_100 % 100;

//  double temp = Tc_100 / 100;
  if(SignBit) {
    Whole= Whole * -1;
  }
  
//  Serial.println("temperature get");
//  Serial.print(Whole);
//  Serial.print(".");
//  Serial.print(Fract);
//  Serial.print("\n");
  return String(Whole) + "." + (Fract < 10 ? "0" : "") + String(Fract);
}

