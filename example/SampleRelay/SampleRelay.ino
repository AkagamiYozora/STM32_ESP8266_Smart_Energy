void setup() {
  // put your setup code here, to run once:
  pinMode(PB8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PB8, HIGH);
  delay(5000);
  digitalWrite(PB8, LOW);
  delay(5000);
}
