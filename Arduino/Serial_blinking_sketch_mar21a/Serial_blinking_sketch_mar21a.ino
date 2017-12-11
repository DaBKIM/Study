const int ledPin=13;
int blinkRate=0;

void setup(){

  // init serial port//init serial port
  Serial.begin(9600);
  // set ledPin by OUTPUT//set ledPin by OUTPUT
  pinMode(ledPin,OUTPUT);
}

int ck=0;

void loop(){

  // Initialize tmp(not to accumulate) 
  int tmp=0; 
 
  while(Serial.available()){
   
   delay(3);
   char ch=Serial.read();
   
   if(isDigit(ch)){

     // char -> int// char -> int
     tmp=tmp*10+(ch-'0');
     // tmp will be initialize
     // So move tmp to ck, so can use ck in blink() safely 
     ck=tmp;
   }
   if(!Serial.available()) {
        Serial.print("delay : ");
        Serial.print(ck);
        Serial.print("ms");
        Serial.print("\n");
    }
  }
  
  blink();
}

//blink the led according to the blinkRate
void blink(){

  // led on
  digitalWrite(ledPin,HIGH);
  // wait for blinkRate time
  delay(ck);
  // led off
  digitalWrite(ledPin,LOW);
  delay(ck);  
}
