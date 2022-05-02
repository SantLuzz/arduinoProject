#define botaoMin 12
#define botaoMax 13

  int valorLDR;
  int luzMin = 0;
  int luzMax = 1023;
  bool buttonPress = false;


void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(botaoMin, INPUT);
  pinMode(botaoMax, INPUT);
  Serial.begin(9600);
  
  Serial.println("Deseja Realizar a Calibração?");
  Serial.println("Botão verde: S / Botão Vermelho: N");
  while(buttonPress == false){
    if(digitalRead(botaoMin)== true){
      
      Serial.println("Iniciando calibracao...");
      delay(500);
      
      while ((luzMin<1)or(luzMax>1022)){  // pegar minimo e máximo de luz pelos botões
      valorLDR = 1023 - analogRead(A0);
      
        if(digitalRead(botaoMax)==true){
        luzMax = valorLDR;
        Serial.println("Luz Max: " + (String)luzMax);
        delay(80);
        }
    
        if(digitalRead(botaoMin)==true){
        luzMin = valorLDR;
        Serial.println("Luz Min: " + (String)luzMin);
        delay(80);
        }
      }
      buttonPress = true;
      delay(500); // para ver a definição do botao no monitor
    }
    if(digitalRead(botaoMax)==true){
      Serial.println("Luz Min: 0");
        Serial.println("Luz Max: 1023");
      delay(1000);
      buttonPress = true;
    }
    
  }   
 
}


void loop(){
  
  int valorLDR = 1023 - analogRead(A0);
  int escalaLuz = 10*(valorLDR-luzMin)/(luzMax-luzMin);  //conversão do min/max para 0/10
  Serial.println(escalaLuz);
  
  for(int i = 0; i<=escalaLuz+1;i++){
    digitalWrite(i+1,HIGH);
  }
  for(int i = escalaLuz+1;i<=11;i++){
    if(escalaLuz == 0){
      digitalWrite(2,LOW);  
    }
  digitalWrite(i+1,LOW);
  }
  
}
