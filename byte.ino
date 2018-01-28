#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#define DHTTYPE DHT11
#define DHTPIN D1


const char* ssid = "honor";

const char* password = "1233211234";
DHT dht(DHTPIN, DHTTYPE, 11);
float humidity, temp_c;
WiFiClient client;

unsigned long myChannelNumber = 412954;  // change your ThingSpeak channel number

const char * myWriteAPIKey = "TBXM65KE68N0OYML";   // change your API key

void setup() {

  
  Serial.begin(115200);
  dht.begin();
  delay(10);
  Serial.println();
  Serial.println();

  Serial.print("Connecting to ");

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

  //   Start the server

  //server.begin();

  Serial.println("Server started");

  //&nbsp;

  ThingSpeak.begin(client);

}

void loop() {
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temp_c = dht.readTemperature();
            // Read temperature as Fahrenheit (isFahrenheit = true)
           // float f = dht.readTemperature(true);
            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temp_c)) {
              Serial.println("Failed to read from DHT sensor!");
              strcpy(celsiusTemp,"Failed");
              strcpy(fahrenheitTemp, "Failed");
              strcpy(humidityTemp, "Failed");         
            }
            else{
              // Computes temperature values in Celsius + Fahrenheit and Humidity
              //float hic = dht.computeHeatIndex(t, h, false);       
              //dtostrf(hic, 6, 2, celsiusTemp);             
              //float hif = dht.computeHeatIndex(f, h);
              //dtostrf(hif, 6, 2, fahrenheitTemp);         
              //dtostrf(h, 6, 2, humidityTemp);
              // You can delete the following Serial.print's, it's just for debugging purposes
              Serial.print("Humidity: ");
              Serial.print(humidity);
              Serial.print(" %\t Temperature: ");
              Serial.print(temp_c);
              //Serial.print(" *C ");
             // Serial.print(f);
              //Serial.print(" *F\t Heat index: ");
              //Serial.print(hic);
              //Serial.print(" *C ");
              //Serial.print(hif);
              //Serial.print(" *F");
              Serial.print("Humidity: ");
              Serial.print(humidity);
              Serial.print(" %\t Temperature: ");
              Serial.print(temp_c);
              //Serial.print(" *C ");
              //w4Serial.print(f);
              //Serial.print(" *F\t Heat index: ");
              //Serial.print(hic);
              //Serial.print(" *C ");
              //Serial.print(hif);
              //Serial.println(" *F");

  ThingSpeak.writeField(myChannelNumber, 1, temp_c, myWriteAPIKey);

  ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
  delay(100);
}
