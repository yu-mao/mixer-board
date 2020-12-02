int voltage_value = 0; // Voltage read from buttons
int PIN_READING_VOLTAGE = A0; // select the input pin to read incoming voltage to Arduino
enum BUTTONS_TO_BE_PRESSED {
  BUTTON_0 = 0,
  BUTTON_1 = 1,
  BUTTON_2 = 2,
  BUTTON_3 = 3
}; // buttons on the bread board
int VOLTAGE_RANGES[5] = {100, 200, 300, 400, 500};
int button_pressed = 0;

int track_button(int voltage_value) {
  for (int i = 0; i < 4; i ++) {
    if (voltage_value >= VOLTAGE_RANGES[i] and voltage_value < VOLTAGE_RANGES[i+1]) {
      printf("Yay! Button %d is pressed down!", i);
      return BUTTONS_TO_BE_PRESSED[i];
     } 
  }
  printf("Error: voltage read from the circuit is out of range!");
  return NULL;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_READING_VOLTAGE, INPUT);
  voltage_value_previous = analogRead(PIN_READING_VOLTAGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value from the button circuit
  voltage_value = analogRead(PIN_READING_VOLTAGE);
  if (voltage_value != voltage_value_previous) {
    button_pressed = track_button(voltage_value);
  }  
}
