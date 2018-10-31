int  green=2,yellow=3,red=4, echo=5, trig=6, duration, distance;

int call_distance(){

   digitalWrite(trig, LOW);
   delayMicroseconds(2);
   digitalWrite(trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(trig, LOW);
   duration=pulseIn(echo,HIGH);
   distance=(duration/2)*.0344;
   return distance;
}
void fade(int pin){
  
   for(int f=0; f<=255; f+=30){
    analogWrite(pin, f);
    delay(30);
  }
  for(int f=255; f>0; f-=30){
    analogWrite(pin, f);
    delay(30);
  }
  
}


void setup(){
  
   Serial.begin(9600);
   pinMode(green, OUTPUT);
   pinMode(yellow, OUTPUT);
   pinMode(red, OUTPUT);
   pinMode(echo, INPUT);
   pinMode(trig, OUTPUT);
   
  
}

void loop(){

    call_distance();

    while(distance<=10){
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);

    fade(red);
    call_distance();
   
   }
   while(distance>10&&distance<=100){
     
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    fade(yellow);
    call_distance();
   }
   while(distance>100){
 
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    fade(green);
    call_distance();
    
   }
   delay(100);

  
}
