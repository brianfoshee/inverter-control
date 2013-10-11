#define analogPin 0
#define switchPin 3
#define ledPin    13

int val = 0;
int status = 0;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(switchPin, LOW);
  readStatus();
}

void loop() {
  if(Serial.available()){
    mode = Serial.parseInt();
    if (mode == 0)
      on();
    else if (mode == 1)
      off();
  }
  delay(1000);
}

void on() {
  Serial.println("Turning On");
  cycle(500);
}

void off() {
  Serial.println("Turning Off");
  cycle(2500);
}

void cycle(int del) {
  digitalWrite(switchPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(del);
  digitalWrite(switchPin, LOW );
  digitalWrite(ledPin, LOW);
  delay(50);
  readStatus();
}

void readStatus() {
  val = analogRead(analogPin);
  if (val < 300)
    status = 0;
  else if (val > 700)
    status = 1;
  Serial.print("Input: ");
  Serial.print(val);
  Serial.print(" status: ");
  Serial.println(status ? "on" : "off");
}
