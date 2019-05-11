//you can use this easy code to test if your circuit of led&ttp223 work 

int big =2;  //ST                            
int push = 3; //SH
int data = 4; //DT

int touch = A0; //ttp223 
int relight = 9; //button of changing light                                                                            
int restart = 8; // turn the score to zero

long randomNumber;
int val ; //digitalRead ttp224
int score = 0; //game score
 // random number
//for debiunce
static unsigned long lastDebounceTime;                                                                                       
#define DEBOUNCE_DELAY 200
void setup() {
  // put your setup code here, to run once:
  
  pinMode(big,OUTPUT);
  pinMode(push,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(touch,INPUT);
  pinMode(relight,INPUT);
  Serial.begin(9600);
}
void putsh(int number){
  digitalWrite(push,LOW);
  digitalWrite(data,number);
  digitalWrite(push,HIGH);
  
}
void updateLed(){
  unsigned long currentTime = millis();
  if((currentTime - lastDebounceTime) > DEBOUNCE_DELAY){
    lastDebounceTime = currentTime;

  }
}
int k ;
void loop() {
  val = analogRead(touch);
  int Relight = digitalRead(relight);
  Serial.println(k);
  if(Relight==1){
    k+=1;
  }
  delay(1000);
  if(k>>1){
   digitalWrite(big,LOW);
    putsh(0);
    putsh(0);
    putsh(1);
    putsh(1);
    putsh(0);
    putsh(1);
    putsh(0);
    putsh(0);
    digitalWrite(big,HIGH);  
    
  
  }
  if(val>>4){
    score+=1;
  Serial.println(score);
  delay(1000);
  }
}
