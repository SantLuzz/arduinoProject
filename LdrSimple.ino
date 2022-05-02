#define pinLDR A0
#define pinLED 2

void setup()
{
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int valorLDR = analogRead(A0);
   Serial.println(valorLDR);
  //apresentar para somente ligar e desligar
  /*if(valorLDR < 85){
    digitalWrite(pinLED, HIGH);
    }else{
      digitalWrite(pinLED, LOW);
   }*/
  //usar para piscar os leds
   while(valorLDR < 85){
        valorLDR = analogRead(A0);
        digitalWrite(pinLED, HIGH);
      delay(300);
      digitalWrite(pinLED, LOW);
        delay(300);
      
    }
}
