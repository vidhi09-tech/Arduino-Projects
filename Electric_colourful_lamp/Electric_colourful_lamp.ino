
int red = 3;
int blue = 4;
int green =5;
int yellow = 6;



const int SENSOR_PIN = 7; //  sensor's SIGNAL pin 

// Variables will change:
int lastState = LOW;      // the previous state from the input pin
int currentState;         // the current reading from the input pin
int red_ledState = HIGH;             
int blue_ledState = LOW; 
int green_ledState = LOW; 
int yellow_ledState = LOW; 

void setup() {
  
  Serial.begin(9600);

  pinMode(SENSOR_PIN, INPUT);
 
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {

  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH){
   
    if(red_ledState == HIGH && blue_ledState ==LOW && green_ledState == LOW && yellow_ledState == LOW){
      
      red_ledState = LOW;
      blue_ledState = HIGH; 
      green_ledState = LOW; 
      yellow_ledState = LOW;
       digitalWrite(red, red_ledState);
      digitalWrite(blue, blue_ledState);
      digitalWrite(yellow, yellow_ledState);
      digitalWrite(green, green_ledState);
    }
    else if(red_ledState == LOW && blue_ledState ==HIGH && green_ledState == LOW && yellow_ledState == LOW){
      red_ledState = LOW;
      blue_ledState = LOW; 
      green_ledState = HIGH; 
      yellow_ledState = LOW;
       digitalWrite(red, red_ledState);
      digitalWrite(blue, blue_ledState);
      digitalWrite(yellow, yellow_ledState);
      digitalWrite(green, green_ledState);
    }
    else if(red_ledState == LOW && blue_ledState ==LOW && green_ledState == HIGH && yellow_ledState == LOW){
      red_ledState = LOW;
      blue_ledState = LOW; 
      green_ledState = LOW; 
      yellow_ledState = HIGH;
       digitalWrite(red, red_ledState);
      digitalWrite(blue, blue_ledState);
      digitalWrite(yellow, yellow_ledState);
      digitalWrite(green, green_ledState);
    }
    else if(red_ledState == LOW && blue_ledState ==LOW && green_ledState == LOW && yellow_ledState == HIGH){
      
      red_ledState = HIGH;
      blue_ledState = LOW; 
      green_ledState = LOW; 
      yellow_ledState = LOW;
      digitalWrite(red, red_ledState);
      digitalWrite(blue, blue_ledState);
      digitalWrite(yellow, yellow_ledState);
      digitalWrite(green, green_ledState);
    }

    
   
  }

  
  lastState = currentState;
}
