const int buzzer = 8;
#define RED_PIN 3
#define GREEN_PIN 5
int sensor = 6;
int detected;
void setup() {
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  detected = digitalRead(sensor);
  if (detected == 0){
    Serial.println("Flame detected");
    analogWrite(RED_PIN, HIGH);
    delay(1000);
    digitalWrite(buzzer, HIGH);
  }
  else{
    Serial.println("No flame detected");
    analogWrite(GREEN_PIN, HIGH);
    delay(1000);
      digitalWrite(buzzer, LOW);
  }

}
