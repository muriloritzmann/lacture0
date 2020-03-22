/*
mais detalhes sobre essa função: http://fabianoallex.blogspot.com.br/2015/09/arduino-como-substituir-delay-pelo.html
*/
int time(long timeHigh, long timeLow, long atraso, long mref = 0) {
  long ajuste = mref % (timeHigh + timeLow);
  long resto  = (millis() + timeHigh + timeLow - ajuste - atraso) % (timeHigh + timeLow);
  return (resto < timeHigh ? HIGH : LOW);
}
 
 
void setup(){
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}
 
boolean pisca = false;
 
void loop(){
  int c = Serial.read();
  if (c == 97) { digitalWrite(7, HIGH); pisca = false; } //a -> liga
  if (c == 98) { digitalWrite(7, LOW);  pisca = false; } //b -> desliga
  if (c == 99) { pisca = true;                         } //c -> pisca
 
  if (pisca)   { digitalWrite(7, time(400, 400, 0));   }
}
