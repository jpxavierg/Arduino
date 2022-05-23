#include <VarSpeedServo.h>



//Definição dos Pinos da Plataforma
#define pinServoGarra 10//garra
#define pinServoBase 5 //base
#define pinServoLado1  9//lado1
#define pinServoLado2 3 //lado2

#define LEDPin 13

//Iniciando os Objetos
VarSpeedServo garra;
VarSpeedServo base;
VarSpeedServo lado1;
VarSpeedServo lado2;//servo4;

int i = 0;
//Variaveis Garra
int posGarra = 0; //9
int posGarraInicial = 139;
int posGarraFinal = 100;//90

//Variaveis Base
int posBase = 90;
int posBaseAnt = 90;// base direita - 95 a 0 e esquerda de 95 a 175
int posBaseEsquerda = 5;
int posBaseDireita = 170;

//Variaveis Lado 1

int pos1 = 0;
int pos2 = 0;
int posLado1 = 95;
int posLado1Ant = 170;
int posLado1Min = 95;
int posLado1Max = 170;

int posLado2 = 80;
int posLado2Ant = 100;
int posLado2Min = 80;
int posLado2Max = 100;
int op = 0;



void setup()
{


  // Establishes LEDPin as an output so the LED can be seen
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println("**** Bem Vindos a CODE8734 ****");
  Serial.println("Apresentamos a Garra Robótica controlada pelo Monitor Serial do Arduino");


  garra.attach(pinServoGarra);
  garra.write(posGarraInicial);
  base.attach(pinServoBase); //pos4
  base.write(posBase);
  lado1.attach(pinServoLado1); //pos4
  lado1.write(posLado1);
  lado2.attach(pinServoLado2); //pos4
  lado2.write(posLado2);

}
void movimentoBase() {
  if (posBaseAnt > posBase) {

    for (int i = posBaseAnt; i >= posBase; i -= 2)
    {
      base.write(i);
      // delay(1);
    }
  }
  if (posBaseAnt < posBase) {

    for (int i = posBaseAnt; i <= posBase; i += 2)
    {
      base.write(i);
      // delay(1);
    }
  }

  posBaseAnt = posBase;

}

void movimentoLado1() {
  if (posLado1Ant > posLado1) {

    for (int i = posLado1Ant; i >= posLado1; i -= 10)
    {
      base.write(i);
      //delay(1);
    }
  }
  if (posLado1Ant < posLado1) {

    for (int i = posLado1Ant; i <= posLado1; i += 10)
    {
      base.write(i);
      //delay(1);
    }
  }

  posLado1Ant = posLado1;

}

void movimentoLado2() {
  if (posLado2Ant > posLado2) {

    for (int i = posLado2Ant; i >= posLado2; i -= 10)
    {
      base.write(i);
      // delay(1);
    }
  }
  if (posLado2Ant < posLado2) {

    for (int i = posLado2Ant; i <= posLado2; i += 10)
    {
      base.write(i);
      // delay(1);
    }
  }

  posLado2Ant = posLado2;

}




void loop()
{


  if (Serial.available()) {

    op = Serial.read();
    //Serial.println(op);

    if (op == 51)                                                             // button can be found in Psx.h
    {
      Serial.println("Pressionou a tecla 3.");
      Serial.println("Abrir a Garra !");
      // Serial.println(op);

      garra.write(posGarraFinal);
      op = 0;

    }
    if (op == 49)                                                             // button can be found in Psx.h
    {
      Serial.println("Pressionou a tecla 1.");
      Serial.println("Fechar a Garra !");
      //Serial.println(op);
      garra.write(posGarraInicial);
      op = 0;

    }
    //digitalWrite(LEDPin, HIGH);

    if (op == 52)
    {
      Serial.println("Pressionou a tecla 4.");
      Serial.println("Mover Base para a Esquerda.");
      // Serial.println(op);

      if (posBase > posBaseEsquerda) posBase -= 10;
    }
    if (op == 54)
    {
      Serial.println("Pressionou a tecla 6.");
      Serial.println("Mover Base para a Direita.");
      // Serial.println(op);
      if (posBase < posBaseDireita) posBase += 10;

    }

    base.write(posBase);
    if (op == 56)
    {
      if (posLado2 > posLado2Min) posLado2 -= 10;
      Serial.println("Pressionou a tecla 8.");
      Serial.println("Mover motor 2 para Cima.");
      //Serial.println(op);
    }
    if (op == 50)
    {
      Serial.println("Pressionou a tecla 2.");
      Serial.println("Mover motor 2 para Baixo.");
      // Serial.println(op);
      if (posLado2 < posLado2Max) posLado2 += 10;

    }
    lado2.write(posLado2);
    if (op == 48)
    {
      Serial.println("Pressionou a tecla 0.");
      Serial.println("Mover motor 1 para baixo.");
      //Serial.println(op);
      if (posLado1 > posLado1Min) posLado1 -= 10;
    }
    if (op == 53)
    {
      Serial.println("Pressionou a tecla 5.");
      Serial.println("Mover motor 1 para cima.");
      //Serial.println(op);
      if (posLado1 < posLado1Max) posLado1 += 10;

    }
    lado1.write(posLado1);

  }
}
