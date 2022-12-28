#define pinSensorA A0
#define pinSensorD 8

void setup() {
  pinMode(pinSensorD, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //MANIPULAR DIRETAMENTE NO MODULO
  Serial.print("Digital:");
  
  if (digitalRead(pinSensorD)) {
     Serial.print("SEM UMIDADE ");
     
  } else {
     Serial.print("COM UMIDADE ");
  }

  Serial.print("  Analogico:");
  Serial.print(analogRead(pinSensorA)); 
  Serial.print("  ");

  Serial.print("  Atuador:");
  if (analogRead(pinSensorA) > 700) {
     Serial.println("TERRA SECA");
     digitalWrite(11, HIGH);
     digitalWrite(12, LOW);
  } else {
    Serial.println("TERRA OK");
     digitalWrite(11, LOW);
     digitalWrite(12, HIGH);
  }
}
