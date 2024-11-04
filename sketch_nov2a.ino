int x;
int y;
int pins[5]={4,5,3,6,7};
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  for(int led = 0; led<5;led++){
    pinMode(pins[led],OUTPUT);
  }
}

void  loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  
  if (x != y){
    y=x;
    for(int on =0;on<5;on++){
      if(on<x){
      digitalWrite(pins[on],HIGH);
      }
      else if(on>=x){
        digitalWrite(pins[on],LOW);
      }

    }
  

   
  }
  
  Serial.print("LED(s) on.");
  
}