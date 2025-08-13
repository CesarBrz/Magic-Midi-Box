#include <arduino.h>
#include <BLEMidi.h> // midi bluetooth

void BLEconnected();
void disconnected();//funcoes do modulo midi ble
void onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity, uint16_t timestamp);
void onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity, uint16_t timestamp);
void onControlChange(uint8_t channel, uint8_t controller, uint8_t value, uint16_t timestamp);

//Arrays que armazenam os pinos lógicos em que os botões estão conectados ao ESP32
byte Btns1[8] = {0,5,18,19,21,3,22,23};
byte Btns2[8] = {0,32,15,2,0,4,16,17};
byte Btns3[8] = {0,13,12,14,27,26,25,33};

//Arrays de flags dos botões (ativado ou desativado)
byte FlagsBtns1[8] = {0,0,0,0,0,0,0,0};
byte FlagsBtns2[8] = {0,0,0,0,0,0,0,0};
byte FlagsBtns3[8] = {0,0,0,0,0,0,0,0};

void setup() {
Serial.begin(19200);
BLEMidiServer.begin("Midi Magic Box v1");

//setando input linha por linha de botões
pinMode(Btns1[1], INPUT_PULLUP);
pinMode(Btns1[2], INPUT_PULLUP);
pinMode(Btns1[3], INPUT_PULLUP);
pinMode(Btns1[4], INPUT_PULLUP);
pinMode(Btns1[5], INPUT_PULLUP);
pinMode(Btns1[6], INPUT_PULLUP);
pinMode(Btns1[7], INPUT_PULLUP);

pinMode(Btns2[1], INPUT_PULLUP);
pinMode(Btns2[2], INPUT_PULLUP);
pinMode(Btns2[3], INPUT_PULLUP);
pinMode(Btns2[4], INPUT_PULLUP);
pinMode(Btns2[5], INPUT_PULLUP);
pinMode(Btns2[6], INPUT_PULLUP);
pinMode(Btns2[7], INPUT_PULLUP);

pinMode(Btns3[1], INPUT_PULLUP);
pinMode(Btns3[2], INPUT_PULLUP);
pinMode(Btns3[3], INPUT_PULLUP);
pinMode(Btns3[4], INPUT_PULLUP);
pinMode(Btns3[5], INPUT_PULLUP);
pinMode(Btns3[6], INPUT_PULLUP);
pinMode(Btns3[7], INPUT_PULLUP);

}

void loop() 
{
 
  //valor obtido por experimentação
  int delayComando = 5000;

  //Canal de envio das Notas
  byte CanalEnvio = 15;
  
  //Offset de notas enviadas
  byte Offset = 0;

  for (int a = 1; a<=7; a++)
  {
   
    //Handler para botões da primeira linha
    if (digitalRead(Btns1[a]) == LOW && FlagsBtns1[a] == 0)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns1[a] = 1;
      BLEMidiServer.noteOn(CanalEnvio, (a+Offset) , 127);
      //Serial.println ("Ativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }
    if (digitalRead(Btns1[a]) == HIGH && FlagsBtns1[a] == 1)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns1[a] = 0;
      BLEMidiServer.noteOff(CanalEnvio, (a+Offset) , 0);
      //Serial.println ("Desativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }

     //Handler para botões da segunda linha
    if (digitalRead(Btns2[a]) == LOW && FlagsBtns2[a] == 0)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns2[a] = 1;
      BLEMidiServer.noteOn(CanalEnvio, (7+a+Offset) , 127);
      //Serial.println ("Ativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }
    if (digitalRead(Btns2[a]) == HIGH && FlagsBtns2[a] == 1)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns2[a] = 0;
      BLEMidiServer.noteOff(CanalEnvio, (7+a+Offset) , 0);
      //Serial.println ("Desativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }

     //Handler para botões da terceira linha
    if (digitalRead(Btns3[a]) == LOW && FlagsBtns3[a] == 0)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns3[a] = 1;
      BLEMidiServer.noteOn(CanalEnvio, (14+a+Offset) , 127);
      //Serial.println ("Ativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }
    if (digitalRead(Btns3[a]) == HIGH && FlagsBtns3[a] == 1)
    {//Chama funcao para executar funcao do botao e ativa a flag sinalizando ativacao
      FlagsBtns3[a] = 0;
      BLEMidiServer.noteOff(CanalEnvio, (14+a+Offset) , 0);
      //Serial.println ("Desativou");
      //pausa o processamento o suficiente para que o sinal estabilize (caso contrário gera falso positivo/negativo)
      delayMicroseconds(delayComando);
    }
    
  }


}
