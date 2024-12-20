#define LED 2

void dot() {
  digitalWrite(LED, HIGH);
  delay(200); // Durasi titik
  digitalWrite(LED, LOW);
  delay(200);
}

void dash() {
  digitalWrite(LED, HIGH);
  delay(600); // Durasi garis
  digitalWrite(LED, LOW);
  delay(200);
}

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // SOS: ... --- ...
  dot(); dot(); dot(); // S
  delay(400);
  dash(); dash(); dash(); // O
  delay(400);
  dot(); dot(); dot(); // S
  delay(1000); // Jeda sebelum ulangi
}
