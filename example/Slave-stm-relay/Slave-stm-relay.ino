void setup() {
  // put your setup code here, to run once:
  pinMode(PA3, INPUT);
  pinMode(PC13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool a = digitalRead(PA3);
  digitalWrite(PC13, a);
}
