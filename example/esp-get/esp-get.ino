#include <ArduinoJson.h>
#include <SoftwareSerial.h>

SoftwareSerial ser(12, 14);

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  ser.begin(9600);
}

void loop() {
  // not used in this example
  DynamicJsonBuffer jsonBuffer(200);
  JsonObject& obj = jsonBuffer.parseObject(ser);

  if(obj.success()){
    int num = obj["num"];
    Serial.println(num);
    delay(1000);
  } else{
    Serial.println("Data read error");
    delay(10);
  }
}
