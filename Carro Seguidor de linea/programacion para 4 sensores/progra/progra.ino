const int sensor1= 7;
const int sensor2= 6;
const int sensor3= 8;
const int sensor4= 9;

const int motor1= 2;//izquierdo
const int motor2= 3;//izquierdo
const int motor3= 5;//derecho
const int motor4= 4;//derecho

int s1;
int s2;
int s3;
int s4;

int A=0;

void setup(){
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
}

void loop(){
  
  s1=digitalRead(sensor1);
  s2=digitalRead(sensor2);
  s3=digitalRead(sensor3);
  s4=digitalRead(sensor4);
  
//----------------------up------------------------  
if(s3==0 && s1==1 && s2==1 && s4==0 || s3==1 && s1==1 && s2==1 && s4==1 )
{
  Serial.println("up");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);

}

//----------------------derecha------------------------

if(s3==0 && s1==0 && s2==1 && s4==0 || s3==0 && s1==0 && s2==1 && s4==1 )
{
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,0);
A=0;
}

if(s3==0 && s1==1 && s2==1 && s4==1 || s3==0 && s1==0 && s2==1 && s4==1 ) //Giro de 90°
{
 
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
A=0;
 
 }
 
if(s3==0 && s1==0 && s2==0 && s4==1 )
{
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
A=0;
}

//----------------------izquierda------------------------

if(s3==0 && s1==1 && s2==0 && s4==0 || s3==1 && s1==1 && s2==0 && s4==0)
{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0;
}

if(s3==1 && s1==1 && s2==1 && s4==0 || s3==1 && s1==1 && s2==0 && s4==0 )//Giro de 90°

{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,1); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0; 
}

if(s3==1 && s1==0 && s2==0 && s4==0 )
{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,1); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0;
}




if(s3==0 && s1==0 && s2==0 && s4==0 )
{ delay(50);
  Serial.println("0000");
 digitalWrite(motor1,0); 
 digitalWrite(motor2,1); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
delay(100);
A++;
}
if( A==4){
Serial.println("stop");
 digitalWrite(motor1,0); 
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,0);
}
}
