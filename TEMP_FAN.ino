#include <DHT.h> // include library
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int relayPin = 8;
const int DHTPIN = A0;


// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);// Initialize DHT sensor
int relay = 9;

/****/
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
   lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight
  dht.begin();
   pinMode(relay, OUTPUT);
     lcd.init(); 
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("presented by");
  lcd.setCursor(0, 1);
  lcd.print("EJ GROUP 3");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
    
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(t);
    lcd.print("'C");
    lcd.setCursor(0, 1);
    lcd.print("Humi:");
    lcd.print(h);
    lcd.print("%");
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print("Temperature = ");
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.print(" %\t ");
  Serial.println();
    
  if (h >= 35) { // you can change humidity value here - h>=66 to your preffered number
    digitalWrite(relayPin, LOW);
  }
  else {
    digitalWrite(relayPin, HIGH);
  }
  if (t >= 35) {// you can change temperature value here - t>= 30 to your preferred number or change from Celsius to Fahrenheit readings
    digitalWrite(relayPin, LOW);
  }
  else {
    digitalWrite(relayPin, HIGH);
  }
  delay(3000);// 1 second delay between measurements
  
  digitalWrite(relay, HIGH);   // turn the motor on (HIGH is the voltage level)
  delay(5000);                       // wait for a second
  digitalWrite(relay, LOW);    // turn the motor off by making the voltage LOW
  delay(5000);  
}
