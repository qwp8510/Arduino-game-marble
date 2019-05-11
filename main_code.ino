#include<Servo.h>                         

Servo myservo;                                                                                                                                                                                                         
int big =2;  //ST                            
int push = 3; //SH
int data = 4; //DT

int touch = A0; //ttp223 
int relight = 9; //button of changing light                                                                            
int restart = 8; // turn the score to zero

//for score displace
int bigscore = 6; //ST for score display
int pushscore = 7; //SH for score display
int datascore = 5; // DT for score display

long randomNumber;
int val ; //digitalRead ttp224
int tipval; //digitalRead ttp224 bonus pin
int score ; //game score


//for debounce
static unsigned long lastDebounceTime;                                                                                       
#define DEBOUNCE_DELAY 200

//for led transform
byte led3_a[8] = {1,0,1,0,0,0,1,0};
byte led3_b[8] = {0,1,0,0,1,0,1,0};
byte led3_c[8] = {1,0,1,0,0,1,0,0};
byte led3_d[8] = {0,0,1,0,1,0,1,0};
byte led2_a[8] = {0,1,0,0,0,0,1,0};
byte led2_b[8] = {1,0,0,0,0,0,1,0};
byte led2_c[8] = {0,0,1,0,0,1,0,0};
byte led2_d[8] = {0,0,1,0,1,0,0,0};
byte led2_e[8] = {1,0,0,0,0,1,0,0};
byte led1_a[8] = {0,0,0,1,0,0,0,0};
//for score display                                               
byte zero[8] = { 0,0,1,1,1,1,1,1};
byte one[8] = {0,0,0,0,0,1,1,0};
byte two[8] ={0,1,0,1,1,0,1,1};
byte three[8] = {0,1,0,0,1,1,1,1};
byte four[8] = {0,1,1,0,0,1,1,0};
byte five[8] = {0,1,1,0,1,1,0,1};
byte six[8] = {0,1,1,1,1,1,0,1};
byte seven[8] = {0,0,0,0,0,1,1,1};
byte eight[8] = {0,1,1,1,1,1,1,1};
byte nine[8] = {0,1,1,0,0,1,1,1};

void setup(){
  //74hc595
  pinMode(big,OUTPUT);
  pinMode(push,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(bigscore,OUTPUT);
  pinMode(pushscore,OUTPUT);
  pinMode(datascore,OUTPUT);
  //
  pinMode(touch,INPUT);
  pinMode(restart,INPUT);
  pinMode(relight,INPUT);
  myservo.attach(11);
  Serial.begin(9600);
}
//first 74hc595 working function for led&ttp223 transform
void putsh(int number){
  digitalWrite(push,LOW);
  digitalWrite(data,number);
  digitalWrite(push,HIGH); 
}
//second 74hc595 working function,for score display
void putsh_score(int number){
  digitalWrite(pushscore,LOW);
  digitalWrite(datascore,number);
  digitalWrite(pushscore,HIGH); 
}

/*I'll set amount of function for different led transform.
   SO we can set variety of order by random number*/
void led_transform_3_a(){  
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led3_a[i]);
    }
      digitalWrite(big,HIGH);
  }
  
void led_transform_3_b(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led3_b[i]);
    }
      digitalWrite(big,HIGH);     
  }
  
void led_transform_3_c(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led3_c[i]);
    }
      digitalWrite(big,HIGH);     
  }
  
void led_transform_3_d(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led3_d[i]);
    }
      digitalWrite(big,HIGH);    
}

void led_transform_2_a(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led2_a[i]);
    }
      digitalWrite(big,HIGH);   
}
  
void led_transform_2_b(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led2_b[i]);
    }
      digitalWrite(big,HIGH);        
  }
  
void led_transform_2_c(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led2_c[i]);
    }
      digitalWrite(big,HIGH);         
  }
  
void led_transform_2_d(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led2_d[i]);
    }
      digitalWrite(big,HIGH);     
  }
  
void led_transform_2_e(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led2_e[i]);
    }
      digitalWrite(big,HIGH);    
}

void led_transform_1_a(){
    digitalWrite(big,LOW);
      for(int i=0;i<8;i++){
        putsh(led1_a[i]);
    }
      digitalWrite(big,HIGH); 
}

//for debounce
void updateLed(){
  unsigned long currentTime = millis();
  if((currentTime - lastDebounceTime) > DEBOUNCE_DELAY){
    lastDebounceTime = currentTime;  
  }
}
 
int k;

void loop() {
  val = analogRead(touch);
  int Restart = digitalRead(restart);  //turn the score to zero 
  int Relight = digitalRead(relight);  //changing led order
  // I like to put a servo make the game more fun.and Increase diffuculties to take led_transform_1.
  myservo.write(180);
  delay(500);
  myservo.write(-180);
  delay(500);
  Serial.println(k);
  if(Relight==1){
     updateLed();
     long randomNumber = random(500);
     k = randomNumber%10 + 1 ;     
  } 
    if(k==1){
      led_transform_3_a();
    }
    if(k==2){
      led_transform_3_b();
    }
    if(k==3){
      led_transform_3_c();
    }
    if(k==4){
      led_transform_3_d();
    }
    if(k==5){
      led_transform_2_a();
    }
    if(k==6){
      led_transform_2_b();
    }
    if(k==7){
      led_transform_2_c();
    }
    if(k==8){
      led_transform_2_d();
    }
    if(k==9){
      led_transform_2_e();
    }
    if(k==10){
      led_transform_1_a();
    }
  if(val>>5){
    if(k==1 or k==2 or k==3 or k==4)
    {
      score+=1;
      //Serial.println(score);
      delay(1000);
    }
    if(k==5 or k==6 or k==7 or k==8 or k==9){
      score+=2;
      //Serial.println(score);
      delay(1000);
  }
    if(k==10){
      score+=5;  
      //Serial.println(score);
      delay(1000);
    }
  }
  
  if(Restart==1){
    score=0;
  }

  //score display
  if(score == 0){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(zero[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 1){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(one[i]);
     }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 2){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(two[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 3){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(three[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 4){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(four[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 5){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(five[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 6){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(six[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 7){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(seven[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 8){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(eight[i]);
    }
      digitalWrite(bigscore,HIGH);
    }
    if(score == 9){     
      digitalWrite(bigscore,LOW);
      for(int i=0;i<8;i++){
        putsh_score(nine[i]);
    }
      digitalWrite(bigscore,HIGH);
    }  
}
