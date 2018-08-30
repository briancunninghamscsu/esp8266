/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/


// these indicate that the measurements recieved by this unit are new, to avoid duplicates being sent to the server
// if true, there's a new measurement that needs to be sent to the server. 

int new_air_temp_measurement_flag;
int new_humidity_measurement_flag;
int new_tvoc_measurement_flag;
int new_co2_measurement_flag;
int new_sln_temp_measurement_flag;
int new_tds_measurement_flag;
int new_do_measurement_flag;
int new_orp_measurement_flag;
int new_ph_measurement_flag;
int new_canopy_measurement_flag;
int new_light_height_measurement_flag;
int new_light_measurement_flag;
int new_reservoir_one_status_flag;
int new_reservoir_two_status_flag;
int new_reservoir_three_status_flag;
int new_reservoir_four_status_flag;
int new_reservoir_five_status_flag;
int new_reservoir_six_status_flag;
int new_reservoir_seven_status_flag;
int new_reservoir_eight_status_flag;



// these are the actual values of the newest measurements
int new_air_temp_measurement;
int new_humidity_measurement;
int new_tvoc_measurement;
int new_co2_measurement;
int new_sln_temp_measurement;
int new_tds_measurement;
int new_do_measurement;
int new_orp_measurement;
int new_ph_measurement;
int new_canopy_measurement;
int new_light_height_measurement;
int new_reservoir_one_status;
int new_reservoir_two_status;
int new_reservoir_three_status;
int new_reservoir_four_status;
int new_reservoir_five_status;
int new_reservoir_six_status;
int new_reservoir_seven_status;
int new_reservoir_eight_status;



// for concatenating the data payloud
String string_to_be_sent_to_server;

// other flags
int connection_to_server_success; // if this is low, it tells the server that it had problem connecting to the server, and that some data has been lost




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  // let's wrangle up a data point to send to the server. 
  string_to_be_sent_to_server = "<";
  Serial.println(string_to_be_sent_to_server);



  // is there a new air temperature measurement?
  if (new_air_temp_measurement_flag){
  
  
  
  }

  
}
