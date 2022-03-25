#include <ArduinoJson.h>

int a;
void setup() {
  // Initialize Serial port
  Serial3.begin(9600);
  Serial.begin(115200);
}

void loop() {
  // not used in this example
  a  = random(1, 1000);
  DynamicJsonBuffer  jsonBuffer(200);
  JsonObject& doc = jsonBuffer.createObject();
  doc["num"] = a;
  Serial.println(jsonBuffer.size());
  Serial.println(a);
  doc.printTo(Serial3);
  delay(1000);
}
