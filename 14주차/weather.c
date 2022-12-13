#include <SPI.h>
#include <WiFiNINA.h>

//기상청서버
const int httpPort = 80;
const char* host = "www.kma.go.kr";

//-----------------------------------------------
const char* ssid = "****"; // WIFI ID
const char* password = "****"; //WIFI PASSWORD
const String url = "wid/queryDFSRSS.jsp?zone=5011059000"; // 지역별 xml주소작성(rss)
//-----------------------------------------------

WiFiClient client;

// 지역 정보
String Temp = ""; // 온도
String Humi = ""; // 습도
String WfEn = ""; // 날씨(영어)
String WfKor = ""; // 날씨(한글)

int red = 0;
int green = 1;
int blue = 2;

void setup() {
  Serial.begin(9600);       
  //시리얼 통신(9600) 오픈
  if (WiFi.status() == WL_NO_MODULE) {     //와이파이 모듈 체크
    Serial.println("Communication with WiFi module failed!");  //모듈체크,  오류메세지 출력
    while (true);
  }

  // 와이파이 연결시도(연결이 되어 있지 않을때만 실행)
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    // wait 5 seconds for connection:
    delay(5000);
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
  weatherData();
}

void loop() {

  Serial.print(WfEn);
  Serial.println("(" + WfKor + ")");
  Display.print(WfEn);
   val = digitalRead(inputPin);         // 센서 신호값을 읽어와서 val에 저장
    
  if (val == HIGH) {                   // 센서 신호값이 HIGH면(인체 감지가 되면)    
    weatherToLED()     // LED ON
    if (pirState == LOW){                         
      Serial.println("Welcome!");    // 시리얼 모니터 출력
      pirState = HIGH;
    } 
  } 
  else {                    // 센서 신호값이 LOW면(인체감지가 없으면)
    // LED OFF
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);       
  if (pirState == HIGH){                
      Serial.println("Good Bye~");   // 시리얼 모니터 출력
      pirState = LOW;
    }
  }

}

void weatherData(){
  Serial.print("Weather get..");
  if(client.connect(host, httpPort)){
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" + 
    "Connection: close\r\n\r\n");
    delay(50);
  }else{Serial.print("."); return;}
  while(client.connected()){
    String line = client.readStringUntil('\n');
    if(line == "\r"){
      Serial.print(".");
      break;
    }
  }

  String matchString = "";
  while(client.available()){
    Serial.print(".");
    String line = client.readStringUntil('\e');
     //온도
    int temp = line.indexOf("</temp>");
      if(temp>0){       
        String tmp_str = "<temp>";
        String wt_temp = line.substring(line.indexOf(tmp_str)+tmp_str.length(),temp);
        Temp = wt_temp;
      }else{return;}
    //습도
    int reh = line.indexOf("</reh>");
      if(reh>0){
        String tmp_str = "<reh>";
        String wt_humi = line.substring(line.indexOf(tmp_str)+tmp_str.length(),reh);
        Humi = wt_humi;
      }else{return;}
    //날씨 영어
    int wfEn = line.indexOf("</wfEn>");
    if(wfEn>0){
      String tmp_str = "<wfEn>";
      String wt_wfEn = line.substring(line.indexOf(tmp_str)+tmp_str.length(),wfEn);
      WfEn = wt_wfEn;  
    }else{return;}
    //날씨 한글
    int wfKor = line.indexOf("</wfKor>");
    if(wfKor>0){
      String tmp_str = "<wfKor>";
      String wt_wfKor = line.substring(line.indexOf(tmp_str)+tmp_str.length(),wfKor);
      WfKor = wt_wfKor;
    }else{return;}
  }
  Serial.println("Completed");
  delay(1000);
}

void connectWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  // 와이파이 연결
  WiFi.begin(ssid, password);
  Serial.print("WIFI Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Display.setTextAlignment(PA_CENTER); // 매트릭스 센터 출력
    Display.print("Loading..."); // Loading... 출력
    Serial.print(".");
  }
  Serial.println("Completed");
}

void weatherToLED(){
  switch(WfEn){
  // 맑음
  case "Clear": 
    // 초록색
    digitalWrite(green, HIGH);
    break;

  // 흐림
  case "Mostly Cloudy": 
    // 보라색
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
  case "Cloudy":
    break;

  // 비
  case "Rain":
  case "Rain/Snow":
  case "Shower":
  case "Raindrop/Snow Drifting":
    // 파란색
    digitalWrite(blue, HIGH);
    break;

  // 눈
  case "Snow":
  case "Snow Drifting":
    // 하늘색
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    break;

  // 초록색
  default: 
    digitalWrite(green, HIGH);
    break;
  }
}
