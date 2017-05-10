#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <user_interface.h>

const char *ssid = "SSID";
const char *password = "PASSWORD";

int32_t i;
int32_t id = 1;
int32_t packet[101];

IPAddress host(192,168,1,2);
uint16_t port = 8765;

bool tick;
os_timer_t timer;

WiFiUDP udp;

void timer_callback(void *arg) {
  tick = true;
}

void setup() {
  i = 0;
  packet[0] = id;

  Serial.begin(115200);
  delay(10);

  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  tick = false;
  os_timer_setfn(&timer, timer_callback, NULL);
  os_timer_arm(&timer, 10, true);
}

void loop() {

  if(tick)
  {
    tick = false;
    ++i;
    packet[i] = analogRead(A0);
    if (i == 100) {
      i = 0;
      udp.beginPacket(host, port);
      udp.write((uint8_t *)packet, 404);
      udp.endPacket();
    }
  }

  yield();
}
