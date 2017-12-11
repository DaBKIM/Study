int totalCnt = 0;
int SW = 2; // switch
int pinC = 3; // CLK
int pinD = 4; // DATA

void setup() {

  Serial.begin(115200);
  pinMode(SW,INPUT);
  pinMode(pinC,INPUT);
  pinMode(pinD,INPUT);
  digitalWrite(SW,HIGH);
  pinMode(9,OUTPUT); // LED
}

int cnt = 0;

void loop() {

  // If switch is LOW, it's not work
  if(digitalRead(SW)==LOW){
    totalCnt = 0;
  }

  cnt = getValue();

  if(cnt != 0){
    
    totalCnt += cnt;
    // Limit maximum and minimum value
    int mapped = map(totalCnt,0,1023,3,255);
    Serial.println(mapped);

    // Control brightness of LED
    analogWrite(9,mapped);
  }
  
}

int oldC = LOW;
int oldD = LOW;

// check the rotate
int getValue(){
  int val = 0;
  int C = digitalRead(pinC);
  int D = digitalRead(pinD);

  // Rotate direction is changed
  // CLK change LOW and HIGH regularly
  // DATA means direction
  if(C != oldC || D != oldD){
    if(oldC == LOW && C == HIGH){
      if(oldD == HIGH) val = 1;
      else val = -1;
    }
  }

  oldC = C;
  oldD = D;

  return val;
}

