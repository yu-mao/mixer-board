#include <Console.h>

int voltage_value = 0; // Voltage read from buttons
float voltage_value_previous = 0; // Previous voltage read from buttons
int PIN_READING_VOLTAGE = A0; // select the input pin to read incoming voltage to Arduino
// enum BUTTONS_TO_BE_PRESSED {
//   BUTTON_0 = 0,
//   BUTTON_1 = 1,
//   BUTTON_2 = 2,
//   BUTTON_3 = 3
// }; // buttons on the bread board
int VOLTAGE_RANGES[5] = {161, 197, 563, 722, 923};
int index_button_pressed = 0;

int track_button(int voltage_value) {
  for (int i = 1; i < 5; i ++) {
    if (voltage_value >= VOLTAGE_RANGES[i] and \
        voltage_value < VOLTAGE_RANGES[i+1]) 
    {
      return i;
    } 
  }
  Serial.println("Error: voltage read from the circuit is out of range!");
  return 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_READING_VOLTAGE, INPUT);
  voltage_value_previous = analogRead(PIN_READING_VOLTAGE);
  Serial.println("----I'm ready to kick-off ----)");
  Serial.println(voltage_value_previous);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value from the button circuit
  voltage_value = analogRead(PIN_READING_VOLTAGE);
  if (voltage_value > voltage_value_previous + 100 || \
    voltage_value < voltage_value_previous - 100) 
  {
    index_button_pressed = track_button(voltage_value);
    Serial.println("A button is pressed ;)");
    Serial.println(voltage_value);
    Serial.println(index_button_pressed);
    voltage_value_previous = voltage_value;
  }  
}
