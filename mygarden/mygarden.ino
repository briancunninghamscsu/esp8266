/*
  Brian Cunningham & Dylan Kohl
  Senior Design 2018
  
*/


#include <ESP8266WiFi.h>

const char* ssid     = "monkey";
const char* password = "thering17";

const char* host = "192.168.1.12";




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
float new_reservoir_nine_status;


String less_than = "< ";
String greater_than= " >";
String space = " ";

//String date_string;
//String date_time; when the data arrives at the server, the server will timestamp it.


// for concatenating the data payload
String string_to_be_sent_to_server;

// other flags
int connection_to_server_success; // if this is low, it tells the server that it had problem connecting to the server, and that some data has been lost




// the setup function runs once when you press reset or power the board
void setup() {
  
  
  
  // all stuff that initializes the wifi module
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

  
  
  
  


void loop() {
  
  // SENDING A DATA POINT TO THE SERVER
  
  new_batch_of_test_data(); // this generates random data points. edit or remove as needed.

  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  
  // We now create a URI for the request
  // adding the key-value pairs to send to the server
  String url = "/mygarden/api.php?whatiwant=push_data";
  url = url + "&" + "new_air_temp_measurement=" + new_air_temp_measurement;
  url = url + "&" + "new_humidity_measurement=" + new_humidity_measurement;
  url = url + "&" + "new_tvoc_measurement=" + new_tvoc_measurement;
  url = url + "&" + "new_co2_measurement=" + new_co2_measurement;
  url = url + "&" + "new_sln_temp_measurement=" + new_sln_temp_measurement;
  url = url + "&" + "new_tds_measurement=" + new_tds_measurement;
  url = url + "&" + "new_do_measurement=" + new_do_measurement;
  url = url + "&" + "new_orp_measurement=" + new_orp_measurement;
  url = url + "&" + "new_ph_measurement=" + new_ph_measurement;
  url = url + "&" + "new_canopy_measurement=" + new_canopy_measurement;
  url = url + "&" + "new_light_height_measurement=" + new_light_height_measurement;
  url = url + "&" + "new_reservoir_one_status=" + new_reservoir_one_status;
  url = url + "&" + "new_reservoir_two_status=" + new_reservoir_two_status;
  url = url + "&" + "new_reservoir_three_status=" + new_reservoir_three_status;
  url = url + "&" + "new_reservoir_four_status=" + new_reservoir_four_status;
  url = url + "&" + "new_reservoir_five_status=" + new_reservoir_five_status;
  url = url + "&" + "new_reservoir_six_status=" + new_reservoir_six_status;
  url = url + "&" + "new_reservoir_seven_status=" + new_reservoir_seven_status;
  url = url + "&" + "new_reservoir_eight_status=" + new_reservoir_eight_status; 
  url = url + "&" + "new_reservoir_nine_status=" + new_reservoir_nine_status;  

  

  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);

  
 
  
  
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  
  delay(1000);
  
  // PULL USER SETTINGS FROM THE SERVER
  String url = "/mygarden/api.php?whatiwant=pull_settings";
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  String user_settings_for_the_pic = line;
  
  // SEND USER SETTINGS TO THE PIC
 
  // RECIEVE DATA FROM THE PIC
  
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
  new_ph_measurement=random(14);
  new_canopy_measurement=random(100);
  new_light_height_measurement=random(100);
  new_reservoir_one_status=random(2);
  new_reservoir_two_status=random(2);
  new_reservoir_three_status=random(2);
  new_reservoir_four_status=random(2);
  new_reservoir_five_status=random(2);
  new_reservoir_six_status=random(2);
  new_reservoir_seven_status=random(2);
  new_reservoir_eight_status=random(2);
  new_reservoir_nine_status=random(2);

}
