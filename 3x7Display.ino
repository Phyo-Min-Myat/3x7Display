#define dg0 2
#define dg1 15
#define dg2 32
#define a 33
#define b 25
#define c 26
#define d 27 
#define e 14
#define f 12
#define g 13

int digit0 = 0;
int digit1 = 0;
int digit2 = 0;


const int dgPin[3] = {dg0,dg1,dg2};
const int segs[7] = {a, b, c, d, e, f, g};
const byte numbers[10] = { 0b0111111,
                           0b0000110,
                           0b1011011,
                           0b1001111,
                           0b1100110,
                           0b1101101,
                           0b1111101,
                           0b0000111,
                           0b1111111,
                           0b1101111};
void setup() {
  for(int i=0;i<7;i++){
    pinMode(segs[i],OUTPUT);
  }
  for(int i=0;i<3;i++){
    pinMode(dgPin[i],OUTPUT);
  }
}

void loop() {
  Display(567);
}

void Display(int Number){
  digit2 = 0;
  while(Number > 99){
    Number -= 100;
    digit2 += 1;
  }
  digit1 = 0;
  while(Number > 9){
    Number -= 10;
    digit1 += 1;
  }
  digit0 = Number;
  
  lightDigit0(numbers[digit0]);
  delayMicroseconds(1000);
  lightDigit1(numbers[digit1]);
  delayMicroseconds(1000);
  lightDigit2(numbers[digit2]);
  delayMicroseconds(1000);
}

void lightDigit0(byte number){
  digitalWrite(dgPin[2],LOW);
  digitalWrite(dgPin[0],HIGH);
  digitalWrite(dgPin[1],HIGH);
  lightSegments(number);
  delayMicroseconds(2000);
}

void lightDigit1(byte number){
  digitalWrite(dgPin[2],HIGH);
  digitalWrite(dgPin[0],LOW);
  digitalWrite(dgPin[1],HIGH);
  lightSegments(number);
  delayMicroseconds(2000);
}

void lightDigit2(byte number){
  digitalWrite(dgPin[2],HIGH);
  digitalWrite(dgPin[0],HIGH);
  digitalWrite(dgPin[1],LOW);
  lightSegments(number);
  delayMicroseconds(2000);
}

void lightSegments(byte number){
  for (int i = 0; i < 7; i++){
    int Bit = bitRead(number, i);
    digitalWrite(segs[i], Bit);
  }
}
