#include <VarSpeedServo.h>
#include <Psx.h>


//Definição dos Pinos Controle Psx
#define dataPin 12
#define cmndPin 11
#define attPin 10
#define clockPin 13

//Definição dos Pinos da Plataforma
#define pinServoGarra 6 //garra
#define pinServoBase 5 //base
#define pinServoLado1 3 //lado1
#define pinServoLado2 2 //lado2

#define LEDPin 13

//Iniciando os Objetos
VarSpeedServo garra;
VarSpeedServo base;
VarSpeedServo lado1;
VarSpeedServo lado2;//servo4;

//Iniciando os Objetos
Psx Psx;                                                  // Initializes the library

unsigned int data = 0;
int Vspeed = 100;
int i = 0;
//Variaveis Garra
int posGarra = 38;
int posGarraInicial = 38;
int posGarraFinal = 5;

//Variaveis Base
int posBase = 83;
int posBaseAnt = 95;// base direita - 95 a 0 e esquerda de 95 a 175
int posBaseEsquerda = 10;
int posBaseDireita = 170;

//Variaveis Lado 1

int pos1 = 0;
int pos2 = 0;
int posLado1 = 90;
int posLado1Ant = 180;
int posLado1Min = 90;
int posLado1Max = 180;

int posLado2 = 90;
int posLado2Ant = 120;
int posLado2Min = 90;
int posLado2Max = 120;


int valorPotBase;
int valorAngBase;

void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);

  pinMode(LEDPin, OUTPUT);                                // Establishes LEDPin as an output so the LED can be seen
  Serial.begin(9600);


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

    for (int i = posBaseAnt; i >= posBase; i-=3)
    {
      base.write(i);
     // delay(1);
    }
  }
  if (posBaseAnt < posBase) {

    for (int i = posBaseAnt; i <= posBase; i+=3)
    {
      base.write(i);
     }
  }

  posBaseAnt = posBase;

}

void movimentoLado1() {
  if (posLado1Ant > posLado1) {

    for (int i = posLado1Ant; i >= posLado1; i-=3)
    {
      base.write(i);
      //delay(1);
    }
  }
  if (posLado1Ant < posLado1) {

    for (int i = posLado1Ant; i <= posLado1; i+=3)
    {
      base.write(i);
      //delay(1);
    }
  }

  posLado1Ant = posLado1;

}

void movimentoLado2() {
  if (posLado2Ant > posLado2) {

    for (int i = posLado2Ant; i >= posLado2; i-=3)
    {
      base.write(i);
     // delay(1);
    }
  }
  if (posLado2Ant < posLado2) {

    for (int i = posLado2Ant; i <= posLado2; i+= 3)
    {
      base.write(i);
     // delay(1);
    }
  }

  posLado2Ant = posLado2;

}




void loop()
{
  data = Psx.read();


  Serial.println(data);
  if (data & psxR1)                                                             // button can be found in Psx.h
  {
    Serial.println("Pressionou (abre Garra)");
    if (posGarra = posGarraInicial) {
      garra.write(posGarraFinal);

    }
    digitalWrite(LEDPin, HIGH);                           // If button is pressed, turn on the LED
  }
  if (data & psxL1)                                                             // button can be found in Psx.h
  {
    Serial.println("Pressionou (Fecha Garra)");
    if (posGarra = posGarraFinal) {
      garra.write(posGarraInicial);

    }

    digitalWrite(LEDPin, HIGH);                           // If button is pressed, turn on the LED
  }

  if (data & psxLeft)
  {
    if (posBase > posBaseEsquerda) posBase --;
  }
  if (data & psxRight)
  {
    if (posBase < posBaseDireita) posBase++;

  }
  base.write(posBase);

  if (data & psxTri)
  {
    if (posLado1 > posLado1Min) posLado1 --;
  }
  if (data & psxX)
  {
    if (posLado1 < posLado1Max) posLado1 ++;

  }
  lado1.write(posLado1);

  if (data & psxSqu)
  {
    if (posLado2 > posLado2Min) posLado2 --;
  }
  if (data & psxO)
  {
    if (posLado2 < posLado2Max) posLado2 ++;

  }
  lado2.write(posLado2);


}
