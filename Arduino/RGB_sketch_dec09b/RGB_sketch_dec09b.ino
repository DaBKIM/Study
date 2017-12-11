
void setup() { //  RGB LED
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

int store[3]={};

void loop() {

  // Initialize tmp
  int tmp=0; 
  int i=0;
    
  while(Serial.available()){

    char ch=Serial.read();

    Serial.println(ch);

    // store RGB number
    if(isDigit(ch)){
      tmp=tmp*10+(ch-'0');
    }
    // just store RGB num
    else if(ch==','){
      store[i]=tmp;
      tmp=0;
      i++;
    }
    // If not ',' or digit, break the loop 
    else{
      store[i]=tmp;
      tmp=0;
      break;
    }

  }

  //Debug
  //Serial.println(store[0]);
  //Serial.println(store[1]);
  //Serial.println(store[2]);
  delay(100);

  // LED in various color
  analogWrite(11,store[0]);
  analogWrite(10,store[1]);
  analogWrite(9,store[2]);
  
}
