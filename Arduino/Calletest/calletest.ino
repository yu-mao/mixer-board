// #include <string.h>

int PIN_READING_VOLTAGE = A0;  //This selects A0 as the pin to read

int button_pressed[4] = {1, 2, 3, 4};  //This creates an array to call for what button is pressed
int voltage_value = 0; //This sets an initial value for the integer which is later 
//used to read the voltage on the pin
int voltage_value_previous = 0;
  //float voltage_value_previous = 0;
int VOLTAGE_RANGES[5] = {161, 197, 563, 722, 923}; //This are the ranges for each button
//int VOLTAGE_READING_TOLERANCE = 10;

//  sound_player = SoundPlayer(sound_files_path) ;//This is a function to play the sound
                        //on the PC

//}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_READING_VOLTAGE, INPUT);
  Serial.println("...Arduino waking up...");
  voltage_value = 0;  //Does this have to be both in setup and beforehand?
  //sound_files_path[4] = (Path1 Path2 Path3 Path4);
  //sound_player = SoundPlayer(sound_files_path);
}

void loop() {
  int voltage_value = analogRead(PIN_READING_VOLTAGE);

  if (voltage_value != voltage_value_previous) {
    if (voltage_value < VOLTAGE_RANGES[0]) {
      Serial.println("Out of range");
    }
    else if (voltage_value > VOLTAGE_RANGES[4]) {
      Serial.println("Out of range");
    }
    else if (voltage_value >= VOLTAGE_RANGES[0] && voltage_value< VOLTAGE_RANGES[1]) {
      //play_sound(1) //What integer should we call play_sond with?
    Serial.println("Button 1");
    }
    else if (voltage_value >= VOLTAGE_RANGES[1] && voltage_value< VOLTAGE_RANGES[2]) {
      //play_sound(2)
    Serial.println("Button 2");
    }
    else if (voltage_value >= VOLTAGE_RANGES[2] && voltage_value< VOLTAGE_RANGES[3]) {
      //play_sound(3)
    Serial.println("Button 3");
    }
    else if (voltage_value >= VOLTAGE_RANGES[3] && voltage_value< VOLTAGE_RANGES[4]) {
      //play_sound(4)
    Serial.println("Button 4");
    }
    voltage_value_previous = voltage_value;
  }
}
