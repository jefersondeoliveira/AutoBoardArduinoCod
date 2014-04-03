const int rodaEsquerda = 9;
const int rodaDireita  = 10;
const int setaEsquerda = 4;
const int farolEsquerdo = 5;
const int setaDireita = 6;
const int farolDireito = 7;
const int buzzer = 11;

 char acao = 'a';

void setup() {
  pinMode(rodaEsquerda, OUTPUT);
  pinMode(rodaDireita, OUTPUT);
  pinMode(setaEsquerda, OUTPUT);
  pinMode(farolEsquerdo, OUTPUT);
  pinMode(setaDireita, OUTPUT);
  pinMode(farolDireito, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  
}

void loop(){
    if (Serial.available() >0) {
        
        acao = Serial.read();
        
        Serial.println(acao);
       
       //CONTROLE BUZZER
        if(acao == 'g'){
          tone(buzzer,1500,100);
 
        }
        
        //CONTROLE FAROL
        if(acao == 'e'){
          digitalWrite(farolEsquerdo, HIGH);
          digitalWrite(farolDireito, HIGH);
        }
        
        if(acao == 'f'){
          digitalWrite(farolEsquerdo, LOW);
          digitalWrite(farolDireito, LOW);
          
        }
        
        //CONTROLE DIREÇÃO  
        if(acao == 'a'){
          digitalWrite(rodaEsquerda, LOW);
          digitalWrite(rodaDireita, LOW);
          digitalWrite(setaEsquerda, LOW);
          digitalWrite(setaDireita, LOW);
        }else
        if(acao == 'b'){
          digitalWrite(rodaEsquerda, HIGH);
          digitalWrite(rodaDireita, HIGH);
          digitalWrite(setaEsquerda, LOW);
          digitalWrite(setaDireita, LOW);
        }else
        if(acao == 'c'){
          digitalWrite(rodaEsquerda, HIGH);
          digitalWrite(rodaDireita, LOW);
          digitalWrite(setaEsquerda, LOW);
          digitalWrite(setaDireita, HIGH);
        }else
        if(acao == 'd'){
          digitalWrite(rodaEsquerda, LOW);
          digitalWrite(rodaDireita, HIGH);
          digitalWrite(setaEsquerda, HIGH);
          digitalWrite(setaDireita, LOW);
        }
        
        
     
    
    }
    
    Serial.flush();

}
