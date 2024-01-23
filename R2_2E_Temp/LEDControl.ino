void setup(){
  for(int i=2; i<=16 ; i++){    //各端子の初期化
    pinMode(i, OUTPUT);
    digitalWrite(i , LOW);
  }
  /*
  //割込み処理のRegister制御
  TCCR2A  = 0;           
  TCCR2B  = 0; 
  //TCCRA2_REG：COM2A1 COM2A0  COM2B1  COM2B0  - - WGM21 WGM20
  TCCR2A |= B00000010;          //CTCモード
  //TCCRB2_REG：FOC2A FOC2B - - WGM22 CS22  CS21  CS20
  TCCR2B |= B00000111;           //プリスケーラの設定
  //CS22  CS21  CS22  分周比　　　　速度：1/（16MHz/プリスケ）
  //  0     0    0 停止（カウンタ動作停止）
  //  0     0    1 分周なし
  //  0     1    0 8分周
  //  0     1    1 32分周
  //  1     0    0 64分周
  //  1     0    1 128分周
  //  1     1    0 256分周
  //  1     1    1 1024分周
  OCR2A = 157 - 1;  //オーバーフロー回数235-＞1/（16MHz/1024）*157＝10.048ms
  TIMSK2 |= (1 << OCIE2A);        //割込みEnable
  */
}

/*ISR (TIMER2_COMPA_vect){
  TIMSK2 |= (0 << OCIE2A);
  static int counter = 0;
  counter += 15;
  timer++;
  if(counter>=1000){
    digitalWrite(16, !digitalRead(16));
    counter = 0;
  }
  LEDControl();    
  TIMSK2 |= (1 << OCIE2A);
}
*/
void LEDControl(char wait, char onOff){
  while(wait)
  {
    for(int i=0 ; i<18 ; i++){
        led[i]==HIGH ? (digitalWrite(ports[i], HIGH)) : (digitalWrite(ports[i], LOW));
    }
    delay(10);
    wait--;
  }
}

void LEDControl(int wait){
  while(wait){
    //一周約10mS
    for(int i=0 ; i<setRow ; i++){
      digitalWrite(portRow[i],LOW);
      for(int j=0 ; j<setColomn ; j++){
          leds[i+1][j+1]==HIGH ? (digitalWrite(portColomn[j], HIGH)) : (digitalWrite(portColomn[j], LOW));
      }
      delayMicroseconds(1900);
      for(int j=0 ; j<setRow ; j++){
        digitalWrite(portRow[i],HIGH);
      }
      for(int j=0 ; j<setColomn ; j++){
        digitalWrite(portColomn[j], LOW);
      }
      delayMicroseconds(3);
    }
    wait--;
  }
}
