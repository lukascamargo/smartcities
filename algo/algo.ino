#include "round_class.h"
turno r1;

#include "timer_class.h"
timer d;  

int delayCount = 0; 
int led = 10;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
long startTime = 1000;
unsigned long time = 0;



//

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  

  bool passouCarro = false;

  if((d.getDelay() % 10) == 0){
    passouCarro = true;
  }

  //Se passou carro, vamos adicionar ao count do r1
  if(passouCarro){
    r1.addCarro();
    
    //FAZER O LED PISCAR INDICANDO QUE PASSOU CARRO
    analogWrite(led, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    analogWrite(led, LOW);
  }
  
  
  

  time = d.addDelay(time);
  delay(1);
  time++;

  if(!d.validity()){
    d.clearDelay();  
    //r1.setState('fechado');

    Serial.println(r1.getState());

    if(r1.getState() == "fechado"){
      //STEP F1 - verifica se passou menos que 1 carro... se sim, não importa o count, vai se manter fechado
      if(r1.getCarros() < 1) {
        r1.setState("fechado");
        Serial.println("STEP F1");
      }   

      
      //STEP F2 - verifica se passou mais que 5 carros... se sim, vai abrir no proximo round
      if(r1.getCarros() >= 5) {
        r1.setState("aberto");
        Serial.println("STEP F2");
      }

      //STEP F3 - verifica se teve apenas entre 1 e 4 carros.. se sim, adiciona no count e mantém fechado
      if(r1.getCarros() > 1 && r1.getCarros() < 5) {
        r1.addCount();
        Serial.println("STEP F3");
      }

      //STEP F4 - verifica se teve mais que 3 counts... se sim, vai abrir no próximo round 
      if(r1.getCount() > 3){
        r1.setState("aberto");
        Serial.println("STEP F4");
      }
      
    } else if(r1.getState() == "aberto"){
      //STEP A1 - verifica se passou menos que 5 carros nesse round... se sim, fecha no proximo round
      if(r1.getCarros() < 5){
        r1.setState("fechado");
        Serial.println("STEP A1");
      }

      //STEP A2 - verifica se passou mais ou igual a 5 carros... se sim, mantém aberto e adiciona count
      if(r1.getCarros() >= 5){
        r1.addCount();
        Serial.println("STEP A2");
      }

      //STEP A3 - verifica se teve mais que 3 counts... se sim, vai fechar no próximo round
      if(r1.getCount() > 3) {
        r1.setState("fechado");
        Serial.println("STEP A3"); 
       }

    }

    
  }
  
  
}
