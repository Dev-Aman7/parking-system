
#define trigPin1 3
#define echoPin1 2
#define trigPin2 5
#define echoPin2 4
#define trigPin3 7
#define echoPin3 6
#define trigPin4 9
#define echoPin4 8
#define trigPin5 11
#define echoPin5 10
#define trigPin6 15
#define echoPin6 14
#define trigPin7 50
#define echoPin7 52
#define l1 22
#define l2 23
#define l3 24
#define l4 25
#define l5 26
#define l6 27 
long duration, distance, s1,s2,s3,s4,s5,s6;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(trigPin5, OUTPUT);
pinMode(echoPin5, INPUT);
pinMode(trigPin6, OUTPUT);
pinMode(echoPin6, INPUT);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);
pinMode(l6,OUTPUT);

}
void check(int s,int i,int l)
{
  if(s>5)
  {
    Serial.print("free slot  : "); 
    Serial.println(i);
   digitalWrite(l,HIGH);
    
  }
  else
  {
   digitalWrite(l,LOW);
  }
}
void loop() {
SonarSensor(trigPin1, echoPin1);
s1 = distance;
check(s1,1,l1);
SonarSensor(trigPin2, echoPin2);
s2 = distance;
check(s2,2,l2);
SonarSensor(trigPin3, echoPin3);
s3 = distance;
check(s3,3,l3);
SonarSensor(trigPin4, echoPin4);
s4 = distance;
check(s4,4,l4);
SonarSensor(trigPin5, echoPin5);
s5 = distance;
check(s5,5,l5);
SonarSensor(trigPin6, echoPin6);
s6 = distance;
check(s6,6,l6 );
if(s1<5 && s2<5 && s3<5 && s4<5 && s5<5 && s6<5 )
{
  Serial.println("No free slot Available.Go to the next row");

  
}
Serial.println("------------------------------");


//Serial.print(s1);
//Serial.print(" - ");
//Serial.print(s2);
//Serial.print(" - ");
//Serial.print(s3);
//Serial.print(" - ");
//Serial.print(s4);
//Serial.print(" - ");
//Serial.print(s5);
//Serial.print(" - ");
//Serial.println(s6);
delay(1000);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
