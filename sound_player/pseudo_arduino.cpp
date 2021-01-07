// pseudo code for Arduino component

// translate the voltages read from the circuit component
// to the corresponding button presses 

// command the computer component
// to play the corresponding sound track(s)
// by translated button presses

// =====================

bool detect_voltage_changes() {
	return false; // if no voltage changes
	return true; // if voltage changes
}

int translate_button_press() {
	return index_pressed_button;
}


// function that implement the sound playing action
void play_sound(index_pressed_button) {
	sound_player.play_sound(index_pressed_button)

}

void setup() {
	// read initial voltage from the circuit component
	voltage_initial = ...
	sound_files_path = ...
	sound_player = SoundPlayer(sound_files_path)
}

void loop() {
	// if the detected voltage is changed
	if detect_voltage_changes():
		// translate to button presses
		index_pressed_button = translate_button_press();
		// command the computer component to play the sounds
		play_sound(index_pressed_button);
}

