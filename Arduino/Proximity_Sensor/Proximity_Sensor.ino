int prox = A2;
void setup() {
  // put your setup code here, to run once:
 pinMode(prox, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(prox));

}
