#include <Adafruit_NeoPixel.h>
#include <LRemote.h>
LRemoteSlider slider;
int soundSensor = 8;
int buttonSensor = 2;
int buttonSensor2 = 1;
int i;
int button = 0;
int count = 0;
int setting =0;
int setting2 =0;
int setting3 =0;
int setting4 =0;
LRemoteButton flash_button;
LRemoteButton home_button;
LRemoteButton fourcolor_button;
LRemoteButton light_button;
LRemoteButton interchange_button;
LRemoteSlider slider1;  
LRemoteSlider slider2;  
LRemoteSlider slider3;  
LRemoteSlider slider4;  
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(90,9,NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  pinMode (soundSensor,INPUT);
  pinMode (buttonSensor,INPUT);
  pinMode (buttonSensor2,INPUT);
  pixels.begin();
  pixels.setBrightness(20);  
  LRemote.setName("Clemmy's LinkIt 7697");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);
  home_button.setText("隨音樂閃");
  home_button.setPos(0, 0);
  home_button.setSize(1, 1);
  home_button.setColor(RC_BLUE);
  flash_button.setText("隨機流星");
  flash_button.setPos(0, 1);
  flash_button.setSize(1, 1);
  flash_button.setColor(RC_PINK);
  slider1.setPos(1, 1);   //slider1的滑桿位置設定在(0, 7)的位置
  slider1.setSize(2, 1);   //slider1的滑桿大小設為3*1
  slider1.setText("時間間距-流星");   //slider1的滑桿名稱顯示為速度值
  slider1.setValueRange(1, 15, 15);   //slider1的滑桿範圍為0到255初始值為0
  slider1.setColor(RC_ORANGE);   //slider1的滑桿顏色設為橘色
  fourcolor_button.setText("四色變換");
  fourcolor_button.setPos(0, 2);
  fourcolor_button.setSize(1, 1);
  fourcolor_button.setColor(RC_YELLOW);
  slider2.setPos(1, 2);   
  slider2.setSize(2, 1);   
  slider2.setText("時間間距-4色");   
  slider2.setValueRange(2, 3, 2);   
  slider2.setColor(RC_YELLOW);   
  light_button.setText("藍天流星");
  light_button.setPos(0, 3);
  light_button.setSize(1, 1);
  light_button.setColor(RC_GREY);
  slider3.setPos(1, 3);   
  slider3.setSize(2, 1);   
  slider3.setText("時間間距-藍天流星");   
  slider3.setValueRange(1, 2, 2);   
  slider3.setColor(RC_BLUE);
  interchange_button.setText("白色交錯");
  interchange_button.setPos(0, 4);
  interchange_button.setSize(1, 1);
  interchange_button.setColor(RC_GREEN);
  slider4.setPos(1, 4);   
  slider4.setSize(2, 1);   
  slider4.setText("時間間距-白色交錯");   
  slider4.setValueRange(1, 2, 2);   
  slider4.setColor(RC_GREEN);
  LRemote.addControl(slider1);  
  LRemote.addControl(slider2);   
  LRemote.addControl(slider3);   
  LRemote.addControl(slider4);  
  LRemote.addControl(home_button);  
  LRemote.addControl(flash_button);
  LRemote.addControl(fourcolor_button);
  LRemote.addControl(light_button);
  LRemote.addControl(interchange_button);
  LRemote.begin();
}


void loop() {
   if(!LRemote.connected()) {
    Serial.println("waiting for connection");
    delay(1000);
  }
  LRemote.process();
  if(interchange_button.isValueChanged()){
  if(interchange_button.getValue()==1){
    button = 4;
  }
  }
  if(light_button.isValueChanged()){
  if(light_button.getValue()==1){
    button = 3;
  }
  }
  if(fourcolor_button.isValueChanged()){
  if(fourcolor_button.getValue()==1){
    button = 2;
  }
  }
  if(flash_button.isValueChanged()){
  if(flash_button.getValue()==1){
    button = 1;
  }
  }
  if(home_button.isValueChanged()){
  if(home_button.getValue()==1){
    button = 0;
  }
  }
  
  if(slider1.isValueChanged()){
    setting=1;
    if(button == 1){
      chase(slider1.getValue()); // Red
    }        
  }else{
    if(button == 1){
      if(setting==1){
        chase(slider1.getValue()); // Red        
      }else{
        chase(15); // Red   
      }

    }    
  }
  if(slider2.isValueChanged()){
    if(button == 2){
      setting2=1;
      changecolor(slider2.getValue()); // Red
    }        
  }else{
    if(button == 2){
      if(setting2==1){      
        changecolor(slider2.getValue()); // Red  
      }else{
        changecolor(2); // Red  
      }      

    }    
  }
   if(slider3.isValueChanged()){
    if(button == 3){
      setting3=1;
      bluechase(slider3.getValue()); // Red
    }        
  }else{
    if(button == 3){
      if(setting3==1){      
         bluechase(slider3.getValue()); // Red
      }else{
         bluechase(2); // Red
      }      

    }    
  }
  if(slider4.isValueChanged()){
    if(button == 4){
      setting4=1;
      inter_change(slider4.getValue()); // Red
    }        
  }else{
    if(button == 4){
      if(setting4==1){      
         inter_change(slider4.getValue()); // Red
      }else{
         inter_change(2); // Red
      }      

    }    
  }
  // put your main code here, to run repeatedly:‵
  int statusSensor = digitalRead (soundSensor);
  
  if (statusSensor == 1 && button == 0)
  {
   // pixels.setBrightness(30);
  for (i = 0; i <= 178; i++) {
    if(i%2!=0){
    pixels.setPixelColor(i,pixels.Color(255,255,255));      
    }else{
     pixels.setPixelColor(i,pixels.Color(12,0,0));     
    }
  }
  pixels.show();
  }
  else if (statusSensor == 0 && button == 0)
  {
   // pixels.setBrightness(5);
     for (i = 0; i <= 178; i++) {
      if(i%2!=0){
        pixels.setPixelColor(i,pixels.Color(255,0,0));
        }else{
        pixels.setPixelColor(i,pixels.Color(15,0,0));  
        }
      
  }
  pixels.show();
  }
}

static void chase(int time) {      
  int color1 =random(0,256);
  int color2 =random(0,256);
  int color3 =random(0,256);
  if(button ==1){
  for(uint16_t i=0; i<pixels.numPixels()+8; i++) {    
      pixels.setPixelColor(i  , pixels.Color(color1,color2,color3)); // Draw new pixel        
      pixels.setPixelColor(i-8, pixels.Color(0,0,10)); // Erase pixel a few steps back
      pixels.show();
      delay(time);
  } 
  }
}
static void changecolor(int time) {      
  count = count+1;
  int color1 =random(240,256);
  if(button ==2){
  for(uint16_t i=0; i<pixels.numPixels(); i++) {    
      if(count==1){
         pixels.setPixelColor(i  , pixels.Color(0,color1,color1)); // Draw new pixel     
      }else if(count==2){
         pixels.setPixelColor(i  , pixels.Color(0,0,color1));
      }else if(count==3){
        pixels.setPixelColor(i  , pixels.Color(color1,0,0));
      }else if(count==4){
        pixels.setPixelColor(i  , pixels.Color(0,color1,0));
      }
             
  } 

  pixels.show();     

  delay(time*1000);
  }  
  if(count==4){
    count=0;    
  }
}

static void bluechase(int time) {      
  if(button ==3){
  for(uint16_t i=0; i<pixels.numPixels()+1; i++) {    
    
      pixels.setPixelColor(i  , pixels.Color(255,255,255)); // Draw new pixel        
      pixels.setPixelColor(i-1  , pixels.Color(0,0,50)); // Draw new pixel        
      pixels.show();
      if(time==2){
        delay(20);
      }else{
        delay(1);
      }
      
  } 
  }
}
static void inter_change(int time){
  if(button ==4){
  for(uint16_t i=0; i<pixels.numPixels(); i++) {    
    if(i%2==0){
      pixels.setPixelColor(i  , pixels.Color(255,255,255)); // Draw new pixel              
      pixels.show();      
    }else if(i%2!=0){
      pixels.setPixelColor(i  , pixels.Color(0,0,0)); // Draw new pixel              
      pixels.show();      
    } 
  }
  delay(time*250);
    for(uint16_t i=0; i<pixels.numPixels(); i++) {    
    if(i%2!=0){
      pixels.setPixelColor(i  , pixels.Color(0,0,0)); // Draw new pixel              
      pixels.show();      
    }else if(i%2==0){
      pixels.setPixelColor(i  , pixels.Color(0,0,0)); // Draw new pixel              
      pixels.show();      
    } 
  }
   delay(time*250);
   for(uint16_t i=0; i<pixels.numPixels(); i++) {    
    if(i%2==0){
      pixels.setPixelColor(i  , pixels.Color(0,0,0)); // Draw new pixel              
      pixels.show();      
    }else if(i%2!=0){
      pixels.setPixelColor(i  , pixels.Color(255,255,255)); // Draw new pixel              
      pixels.show();      
    } 
  }
   delay(time*250);
  
  
  }  
}

