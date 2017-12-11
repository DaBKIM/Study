void setup() {
  
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  // analog don't have to set the pin
}

void loop() {

  // 'analogRead()' can return 0 to 1023
  int val = analogRead(A0);
  // Set the minimum number as 3
  // Set the maximum number as 255
  // So that LED will not be turn off
  int mapped = (val,0,1023,3,255);

  analogWrite(3,mapped);

}
