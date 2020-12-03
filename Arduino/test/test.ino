// #include <string.h>

int PIN_READING_VOLTAGE = A0; // select the input pin to read incoming \
                              // voltage to Arduino

int index_button_pressed = 0;
int voltage_value = 0; // Voltage read from buttons
float voltage_value_previous = 0; // Previous voltage read from buttons
int VOLTAGE_RANGES[5] = {161, 197, 563, 722, 923};
int VOLTAGE_READING_TOLERANCE = 10;

String SOUND_TRACK_FILES_PATHS[] = {"a", "b", "c", "d"};

int track_button(int voltage_value) {
  for (int i = 1; i < 5; i ++) {
    if (voltage_value >= VOLTAGE_RANGES[i] and \
        voltage_value < VOLTAGE_RANGES[i+1]) 
    { return i; } 
  }
  Serial.println("Error: voltage read from the circuit is out of range!");
  return 0;
}

void mix_sound_traks(int index_button_pressed) {
/*
TODO:
  - open corresponding sound track files
  - play the files
*/
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_READING_VOLTAGE, INPUT);
  voltage_value_previous = analogRead(PIN_READING_VOLTAGE);
  Serial.println("----Arduino Board Wake Up ----)");
  Serial.println((String)"Initial voltage reading: " + voltage_value_previous);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value from the button circuit
  voltage_value = analogRead(PIN_READING_VOLTAGE);
  if (voltage_value > voltage_value_previous + VOLTAGE_READING_TOLERANCE || \
    voltage_value < voltage_value_previous - VOLTAGE_READING_TOLERANCE) 
  {
    index_button_pressed = track_button(voltage_value);
    Serial.println((String)"You pressed button: " + index_button_pressed + ",");
    Serial.println((String)"    as the voltage read as: " + voltage_value);
    voltage_value_previous = voltage_value;
  }  
}
