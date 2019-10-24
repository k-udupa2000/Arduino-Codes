/*
  Author: Shubhayu Das
  Description:  This is some basic code to test out a 3 bit multiplier made using 4-bit full adders and 'and' gates
*/

int a2 = 8, a1 = 7, a0 = 6;
int b2 = 5, b1 = 4, b0 = 3;

int num1 = 4, num2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(b2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b0, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 1; i < 8; i++)
    for(int j = 0; j < 8; j++){
      binaryInput(1, i);
      binaryInput(2, j);
      delay(3000);
  }
}

void binaryInput(int mode, int number){
  if(mode == 1){
    digitalWrite(a2, (number/4)%2);
    digitalWrite(a1, (number/2)%2);
    digitalWrite(a0, number%2);
  }

  else if(mode == 2){
    digitalWrite(b2, (number/4)%2);
    digitalWrite(b1, (number/2)%2);
    digitalWrite(b0, number%2);
  }
}
