#include<Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();     //  Setup the wire library for I2C communication
  Serial.begin(9600);

  while(!Serial)
    Serial.println("Scanner for all I2C devices.");
}

void loop() {
  // put your main code here, to run repeatedly:
  byte response, address;

  int numberOfDevices = 0;

  for(address = 0; address < 127; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if(error == 0){
      Serial.print("Device successfully found at address: 0x");
      if(address < 16)
        Serial.println(0);
      else
        Serial.println(address, HEX); 

      numberOfDevices++;
    }

    else if(error == 4){
       Serial.print("Some error occurred on address: 0x");
      if(address < 16)
        Serial.println(0);
      else
        Serial.println(address, HEX); 
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("Scan completed. Next scan after 5 seconds\n");
 
  delay(5000);           // wait 5 seconds for next scan
}
