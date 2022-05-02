#define pinLDR A0
#define led1 2
#define led2 3
#define led3 4
#define led4 5
#define led5 6
#define led6 7
#define led7 8
#define led8 9
#define led9 10
#define led10 11

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int valorLDR = analogRead(A0);
  Serial.println(valorLDR);
  
  while(valorLDR < 85){
    valorLDR = analogRead(A0);
    for(int i = 2; i<=11; i++){
       digitalWrite(i, HIGH);
      delay(80);
      digitalWrite(i, LOW);
    }
    
  }
}
