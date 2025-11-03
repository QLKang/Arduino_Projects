//#include <SoftwareSerial.h>

// C++ code
//

int ledPin = 13;
int buttonPin = 3;

int ledState = LOW;          // LED 当前状态
int lastButtonState = 0;     // 上一次按钮状态
int stableState = LOW;       // 去抖后确认下的稳定状态

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // 去抖延时（ms）

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);  // 外部下拉
  digitalWrite(ledPin, ledState);
}

void loop() {
  
  int reading = digitalRead(buttonPin); // 读取原始状态
  // int buttonState = digitalRead(buttonPin);
  
  // 如果状态变化了（抖或真变化），更新计时起点
  if (reading != lastButtonState){
    lastDebounceTime = millis();
  }
  
  // 若超过去抖时间，认为状态稳定
  if ((millis() - lastDebounceTime) > debounceDelay){
    // 如果稳定状态和当前读到的稳定值不同，说明状态真正改变
    if (reading != stableState){
    	stableState = reading;
      
      // 对外部下拉，按下=HIGH -> 检测上升沿
      if (stableState == HIGH) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
      }
    }
  }
  
  lastButtonState = reading;    // 更新上一次状态
}











