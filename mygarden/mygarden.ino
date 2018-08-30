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
float new_air_temp_measurement;
float new_humidity_measurement;
float new_tvoc_measurement;
float new_co2_measurement;
float new_sln_temp_measurement;
float new_tds_measurement;
float new_do_measurement;
float new_orp_measurement;
float new_ph_measurement;
float new_canopy_measurement;
float new_light_height_measurement;
float new_reservoir_one_status;
float new_reservoir_two_status;
float new_reservoir_three_status;
float new_reservoir_four_status;
float new_reservoir_five_status;
float new_reservoir_six_status;
float new_reservoir_seven_status;
float new_reservoir_eight_status;

String less_than = "< ";
String greater_than= " >";
String space = " ";

//String date_string;
//String date_time; when the data arrives at the server, the server will timestamp it.


// for concatenating the data payloud
String string_to_be_sent_to_server;

// other flags
int connection_to_server_success; // if this is low, it tells the server that it had problem connecting to the server, and that some data has been lost




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  new_air_temp_measurement=-666;
  new_humidity_measurement=-666;
  new_tvoc_measurement=-666;
  new_co2_measurement=-666;
  new_sln_temp_measurement=-666;
  new_tds_measurement=-666;
  new_do_measurement=-666;
  new_orp_measurement=-666;
  new_ph_measurement=-666;
  new_canopy_measurement=-666;
  new_light_height_measurement=-666;
  new_reservoir_one_status=-666;
  new_reservoir_two_status=-666;
  new_reservoir_three_status=-666;
  new_reservoir_four_status=-666;
  new_reservoir_five_status=-666;
  new_reservoir_six_status=-666;
  new_reservoir_seven_status=-666;
  new_reservoir_eight_status=-666;

  
}


void loop() {
  

  // let's wrangle up a data point to send to the server. 
  
  delay(1000);
  new_batch_of_test_data();
  string_to_be_sent_to_server = less_than + new_air_temp_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_humidity_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_tvoc_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_co2_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_sln_temp_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_tds_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_do_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_orp_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_ph_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_canopy_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_light_height_measurement;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_one_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_two_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_three_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_four_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_five_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_six_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_seven_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + space +  new_reservoir_eight_status;
  string_to_be_sent_to_server = string_to_be_sent_to_server + greater_than;  

  Serial.println(string_to_be_sent_to_server);
  Serial.println("tee hee hee");
  
}


void new_batch_of_test_data(){
  new_air_temp_measurement=random(100);
  new_humidity_measurement=random(100);
  new_tvoc_measurement=random(100);
  new_co2_measurement=random(100);
  new_sln_temp_measurement=random(100);
  new_tds_measurement=random(100);
  new_do_measurement=random(100);
  new_orp_measurement=random(100);
  new_ph_measurement=random(100);
  new_canopy_measurement=random(100);
  new_light_height_measurement=random(100);
  new_reservoir_one_status=random(100);
  new_reservoir_two_status=random(100);
  new_reservoir_three_status=random(100);
  new_reservoir_four_status=random(100);
  new_reservoir_five_status=random(100);
  new_reservoir_six_status=random(100);
  new_reservoir_seven_status=random(100);
  new_reservoir_eight_status=random(100);

  

}
