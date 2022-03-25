#include <SPI.h>
#include <SD.h>

const int chipSelect = PA4;
SPIClass SPI_1(1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SD.begin(chipSelect);
  if (!SD.begin(chipSelect)) { 
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  // put your main code here, to run repeatedly:
  String dataString = "abcdefg";
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if(dataFile){
    dataFile.println(dataString);
    dataFile.close();
    Serial.println(dataString);
  }else {
    Serial.println("error opening datalog.txt");
  }

  delay(2000);
}
