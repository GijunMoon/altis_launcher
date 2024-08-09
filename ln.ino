//OUT 1
int ENA = 13;
int IN1 = 12;
int IN2 = 11;

//SWITCH
int SW1 = 2; //업, 주황색
int SW2 = 3; //다운, 초록색

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void Launcher_UP(){
  Serial.println("up");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255); //최대속도
}

void Launcher_DOWN(){
  Serial.println("down");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255); //최대속도
}

void Launcher_STOP(){
  Serial.println("stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); //최대속도
}

void loop() {
  if(digitalRead(SW1) == LOW){ //호이스트 업
    Launcher_UP();
  }
  else if(digitalRead(SW2) == HIGH){
    Launcher_STOP();
  }

  if(digitalRead(SW2) == LOW){//호이스트 다운
    Launcher_DOWN();
  }
  else if(digitalRead(SW1) == HIGH){
    Launcher_STOP();
  }

}
