char data = 0;           //Variable for storing received data
#include "DHT.h"
#define DHTTYPE DHT11

#define DHTPIN 11
DHT dht(DHTPIN, DHTTYPE);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt = 1000;
void setup() 
{
    Serial.begin(9600);  //Sets the data rate in bits per second (baud) for serial data transmission
    pinMode(13, OUTPUT); //Sets digital pin 13 as output pin green led
    pinMode(12, OUTPUT); //Sets digital pin 12 as output pin red led
    dht.begin();
}

void loop()
{
  humidity=dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);
    if(Serial.available() > 0)       // Send data only when you receive data:
    {
        data = Serial.read();        //Read the incoming data and store it into variable data
        Serial.print(data);          //Print Value inside data in Serial monitor
        Serial.print("\n");          //New line 
        if(data == '1')    {          //Checks whether value of data is equal to 1 
          Serial.print("Humidity: ");
          Serial.println(humidity);
          Serial.print("%");
          Serial.print("Temprature in Centigrade ");
          Serial.print(tempC);
          Serial.println("C");
          Serial.print("Temprature in Farhanite ");
          Serial.print(tempF);
          Serial.println("F");
          delay(dt);
            digitalWrite(13, HIGH);  //If value is 1 then green LED turns ON
            digitalWrite(12, LOW);}  //If value is 0 then red LED turns OFF
        else if(data == '0'){         //Checks whether value of data is equal to 0
            digitalWrite(13, LOW);   //If value is 0 then green LED turns OFF
            digitalWrite(12, HIGH);}  //If value is 1 then red LED turns ON
    
    }                            
}
