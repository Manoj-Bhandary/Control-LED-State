
#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#include
< Universal Telegram Bot.b>
#include <ArduinoJson.h>
const char* ssid = "ECE_CF_283"; Const char *password = "0123456789";
#define BOTtoken
"689524492: AAHxTdWRDQq_5 NTON DK9ePg RUqEFrL_AFqk"
#define CHAT-ID "-4195079497"
#ifdef ESP8266
X509 List Cert (TELEGRAM_CERTIFICATE_ROOT);
#endif
WifiClientosecure client; Universal Telegram Bot bot (BOT toker, client);
int botRequest Delay = 1000; unsigned long last Time BotRan;
const int ledPin = 2;
bool ledstate = LOW;
void handle New Messages (int numNew Messages) {
Serial.printh ("handle New Messages");
Serial.printh (otring (rum NewMessages);
for (int i=0; i<num New Messages; i++) {
String chot_id=string(bot.messages[i].chat_id);
if (chat_id!=CHAT-10)
e(chat_id, "Unauthorized user", ""); bot. sendMessage(chat_id,
Continue;
}
String text = bot. messages[i].text;
printin (text);"
astring from-name = bot.messages[i].from_name;
if (text == "/led_on"){
bot, send Message (chat_id, "LED state sel to ON", "");
leddtate = LOW;
digitalWrite (ledPin, LedState); }
"f (text == "/led_off"){
bot. sendMessage (chat_id, "LED state set to DFF", "");
LedState = cow;
digitalWrite(ledpin, led State);
}
if (text == "/state"){
if (digitalRead (ledPin)) {
bot. Send Message (Chat-id, "LED & ON", "");
5
else {
bot, send Message (chat-id, "LED & OFF", "");
}
}
}
}
void setup()
Serial. begin (115200);
#ifdef ESP8266
Config Time Co,D, "pool.ntp.org");
Client. set Trust Anchors (&cent);
#endif
DinMode (ledPin, OUTPUT);
digitalWrite (ledPin, led State);
WiFi.module (WIFI_STA);
Wifi. begin (ssid, password);
#ifdef ESP32
Client. Set CACest (TELEGRAM_CERTIFICATE_ROOT);
#endif
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println("Connecting } to WiFi..");
Serial.println(WiFi.localIP());
bot. send Message (CHAT_ID, "Bot started.", "");
}
void loop(){
if (millis() > Last Time BotRan + botRequestDelay) {
int num NewMessages = bot. get updates (bot.last_message-received
+1);
while(num New Messages) {
Serial.println("got response');
handle New Messages (neum NewMessages);
purn New Messages = bot. git Updates (bot. last-message-received + 1);
}
Last TimeBot Ran = millis();
}
}