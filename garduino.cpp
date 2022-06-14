// C++ code
//
/*

  Modify this code to be compatible with analog

  Moisture sensor detection (edge detection)

  The circuit:
    pushbutton attached to pin 2 from +5V
    10K resistor attached to pin 2 from ground
    LED attached from pin 13 to ground (or use the


  Assembly:
    3 pins to 5V
    Connect everything yo ground and combine pins/connections if necessary.

*/

const int GREEN_LED_1 = 8; // Positive Leads
const int GREEN_LED_2 = 6;
const int RED_LED_1 = 7;
const int RED_LED_2 = 5;
const int RELAY_1 = 11;
const int RELAY_2 = 12;
const int SENSOR_1 = A0;
const int SENSOR_2 = A1;
const int BUTTON_1 = 2;
const int BUTTON_2 = 3;

int buttonState_1 = 0;
int lastButtonState_1 = 0;
int buttonState_2 = 0;
int lastButtonState_2 = 0;
unsigned long time_now_1 = 0; // Time since measurement of sensor 1
unsigned long time_now_2 = 0; // Time since measurement of sensor 2
//int period = 10000; // used for testing
int period = 3600000; // period set to every hour

void setup()
{
  Serial.begin(9600);
  pinMode(GREEN_LED_1, OUTPUT);
  pinMode(GREEN_LED_2, OUTPUT);
  pinMode(RED_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);// Repeat for more sensors and buttons
}

void loop()
{
  // #### Create a timestamp ####
  unsigned long currentMillis = millis();

  // ###### SENSOR 1 CODE ######

  // Check the buttonState, do a measurement and reset the time_now_2 variable
  // read the pushbutton input pin
  buttonState_1 = digitalRead(BUTTON_1);
  if (lastButtonState_1 != buttonState_1) {
    if (buttonState_1 == HIGH) {
      // reset time_now
      time_now_1 = currentMillis;
      // sensor code here
      // Open the relay and have a small delay
      digitalWrite(RELAY_1, HIGH);
      delay(2500);
      // Read from the moisture sensor
      int sensorValue_1 = analogRead(SENSOR_1);
      delay(1000);
      Serial.print("Sensor 1: ");
      Serial.println(sensorValue_1);
      // Turn on the LED if the moisture is high
      if (sensorValue_1 >= 450) {
        digitalWrite(RED_LED_1, HIGH);
        digitalWrite(GREEN_LED_1, LOW);
      }
      else if (sensorValue_1 < 450) {
        digitalWrite(GREEN_LED_1, HIGH);
        digitalWrite(RED_LED_1, LOW);
      }

    }
    // delay a little bit to avoid debouncing
    delay(500); // Wait for 0.1 second(s)
    digitalWrite(RELAY_1, LOW);
    // save the current state as the last state, for
    // the next time through the loop
    lastButtonState_1 = buttonState_1;
  }

  // Check the time_now_1 and do a measurement of sensor_1 after an hour

  if ((currentMillis - time_now_1) >= period) {
    // Sensor code goes here
    // Open the relay and have a small delay
    digitalWrite(RELAY_1, HIGH);
    delay(2500);
    // Read from the moisure sensor
    int sensorValue_1 = analogRead(SENSOR_1);
    delay(1000);
    Serial.print("Sensor 1: ");
    Serial.println(sensorValue_1);
    // Turn on the LED if the moisture is high
    if (sensorValue_1 >= 450) {
      digitalWrite(RED_LED_1, HIGH);
      digitalWrite(GREEN_LED_1, LOW);
    }
    else if (sensorValue_1 < 450) {
      digitalWrite(GREEN_LED_1, HIGH);
      digitalWrite(RED_LED_1, LOW);
    }


    // turn off the relay
    digitalWrite(RELAY_1, LOW);
    delay(500); // Wait for 0.2 second(s)
    // Use the snapshot to set track time until next event
    time_now_1 = currentMillis;
  }

  // ###### SECOND SENSOR CODE ######


  // Check the buttonState, do a measurement and reset the time_now_2 variable
  // read the pushbutton input pin
  buttonState_2 = digitalRead(BUTTON_2);
  if (lastButtonState_2 != buttonState_2) {
    if (buttonState_2 == HIGH) {
      // reset time_now
      time_now_2 = currentMillis;
      // sensor code here
      // Open the relay and have a small delay
      digitalWrite(RELAY_2, HIGH);
      delay(2500);
      // Read from the moisture sensor
      int sensorValue_2 = analogRead(SENSOR_2);
      delay(1000);
      Serial.print("Sensor 2: ");
      Serial.println(sensorValue_2);
      // Turn on the LED if the moisture is high
      if (sensorValue_2 >= 450) {
        digitalWrite(RED_LED_2, HIGH);
        digitalWrite(GREEN_LED_2, LOW);
      }
      else if (sensorValue_2 < 450) {
        digitalWrite(GREEN_LED_2, HIGH);
        digitalWrite(RED_LED_2, LOW);
      }

    }
    // delay a little bit to avoid debouncing
    delay(500); // Wait for 0.1 second(s)
    digitalWrite(RELAY_2, LOW);
    // save the current state as the last state, for
    // the next time through the loop
    lastButtonState_2 = buttonState_2;
  }

  // Check the time_now_2 and do a measurement of sensor_2 after an hour

  if ((currentMillis - time_now_2) >= period) {
    // Sensor code goes here
    // Open the relay and have a small delay
    digitalWrite(RELAY_2, HIGH);
    delay(2500);
    // Read from the moisure sensor
    int sensorValue_2 = analogRead(SENSOR_2);
    delay(1000);
    Serial.print("Sensor 2: ");
    Serial.println(sensorValue_2);
    // Turn on the LED if the moisture is high
    if (sensorValue_2 >= 450) {
      digitalWrite(RED_LED_2, HIGH);
      digitalWrite(GREEN_LED_2, LOW);
    }
    else if (sensorValue_2 < 450) {
      digitalWrite(GREEN_LED_2, HIGH);
      digitalWrite(RED_LED_2, LOW);
    }

  // turn off the relay
  digitalWrite(RELAY_2, LOW);
  delay(500); // Wait for 0.2 second(s)
  // Use the snapshot to set track time until next event
  time_now_2 = currentMillis;
  }
  // End of the loop
}