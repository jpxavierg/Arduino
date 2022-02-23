#include <VarSpeedServo.h>

VarSpeedServo garra;//servo1;
VarSpeedServo base;//servo2;
VarSpeedServo lado1;//servo3;
VarSpeedServo lado2;//servo4;


#define pinServo1  6 
#define pinServo2  5 
#define pinServo3  3 
#define pinServo4  9

/* variavel usada no projeto de forma geral */
int i = 0;// Varaiavel para incrementar  de 1 em 1.


void setup() {


portas_servos();
posicao_inicial_servos();



}

void loop() {
 
 sequencia_movimentos();
 
}

void portas_servos(){
  
  garra.attach(pinServo1);
  base.attach(pinServo2);
  lado1.attach(pinServo3);
  lado2.attach(pinServo4);
  }

void posicao_inicial_servos(){  


  //garra.write(38); // 
  //base.write(90); // Posicao inicial
  //lado1.write(60); // 
  lado2.write(180); //posicao inicial

//base.write(0); 
  }
  
/* Aguarda um tempo para a excucao*/
void temporizador(){
   int tempo = 500;
   delay(tempo);
  
  }
/*Velocidade do movimento*/
  void velocidade_movimento(){
    int Vspeed = 26; // Velocidade de movimento 
    delay(Vspeed);    
    }

  void sequencia_movimentos(){
    
    avanca(); 
    temporizador(); 
    recolhe();

    
    
    }
 void base_direita() // A base precisa se mover lentamente
{
  for(i = 93; i <= 180; i += 1)
  { 
    if(i>180)
    {
      i=180;
      break;
    }
    base.write(i); 
    velocidade_movimento();
  } 
}

void base_esquerda() // A base precisa se mover lentamente
{
  for(i=93; i >= 0; i -= 1) // Indo de 93  a 0
  { 
    if(i>93)
    {
      i=93;
      break;
    }
  
    base.write(i); // servo indo para a posicao "i"
    velocidade_movimento();
  } 
}

void recolhe() // Movimenta o lado 2, precisa se mover lentamente
{  
    for(i = 150; i >= 90; i -= 1) // Indo de 120 a 50 graus de 1 em 1
  {       
    if(i<90)
    {
      i=90;
      break;
    } 
    lado2.write(i); // servo indo para a posicao "i"
    velocidade_movimento();
  } 
}


void avanca() // Movimenta o lado 2, precisa se mover lentamente
{
  for(i = 90; i <= 150; i += 1) // Indo de 90 ate 150 graus de 1 em 1
  { 
    if(i>150)
    {
      i=150;
      break;
    }
    lado2.write(i); // servo indo para a posicao "i"
    velocidade_movimento();
  } 
  
}





