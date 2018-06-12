const int sensor1= 7;
const int sensor2= 6;
const int sensor3= 8;
const int sensor4= 9;
const int sensor5= 10;
const int sensor6= 11;


const int motor1= 2;//izquierdo
const int motor2= 3;//izquierdo
const int motor3= 4;//derecho
const int motor4= 5;//derecho

int s1;
int s2;
int s3;
int s4;
int s5;
int s6;

int A=0;

void setup(){
  Serial.begin(9600);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);
  pinMode(sensor6,INPUT);
  
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
  s5=digitalRead(sensor5);
  s6=digitalRead(sensor6);
  
//----------------------up-----------------------------  
if(s5==0 && s3==0 && s1==1 && s2==1 && s4==0 && s6==0|| s5==1 && s3==1 && s1==1 && s2==1 && s4==1 && s6==1 || s5==0 && s3==1 && s1==1 && s2==1 && s4==1 && s6==0 )
{
  Serial.println("up");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);

}

//----------------------derecha------------------------

if(s5==0 && s3==0 && s1==0 && s2==1 && s4==0 && s6==0 || s5==0 && s3==0 && s1==0 && s2==1 && s4==1 && s6==1||s5==0 && s3==0 && s1==0 && s2==0 && s4==0 && s6==1  )
{
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,0);
A=0;
}

if(s5==0 && s3==0 && s1==1 && s2==1 && s4==1 && s6==0 ||s5==0 && s3==0 && s1==0 && s2==1 && s4==1 && s6==0|| s5==0 && s3==0 && s1==1 && s2==1 && s4==1 && s6==1 || s5==0 && s3==0 && s1==0 && s2==1 && s4==1 && s6==1 ) //Giro de 90° a la derecha
{
 
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
A=0;
 

 }
 
 


if(s5==0 && s3==0 && s1==0 && s2==0 && s4==1 && s6==0 || s5==0 && s3==0 && s1==0 && s2==0 && s4==1 && s6==1  )
{
  Serial.println("derecha");
 digitalWrite(motor1,1);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
A=0;
}

//----------------------izquierda------------------------

if(s5==1 && s3==0 && s1==0 && s2==0 && s4==0 && s6==0 || s5==0 && s3==0 && s1==1 && s2==0 && s4==0 && s6==0 || s5==1 && s3==1 && s1==1 && s2==0 && s4==0 && s6==0)
{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,0); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0;
}

if(s5==0 && s3==1 && s1==1 && s2==1 && s4==0 && s6==0 || s5==0 && s3==1 && s1==1 && s2==0 && s4==0 && s6==0 || s5==1 && s3==1 && s1==1 && s2==1 && s4==0 && s6==0 || s5==1 && s3==1 && s1==1 && s2==0 && s4==0 && s6==0)//Giro de 90° a la izquierda

{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,1); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0; 
}

if(s5==0 && s3==1 && s1==0 && s2==0 && s4==0 && s6==0 || s5==1 && s3==1 && s1==0 && s2==0 && s4==0 && s6==0 )
{
  Serial.println("izquierda");
 digitalWrite(motor1,0);
 digitalWrite(motor2,1); 
 digitalWrite(motor3,1);
 digitalWrite(motor4,0);
A=0;
}



//----------------------Condicion para evaluar el stop-------------------
if(s5==0 && s3==0 && s1==0 && s2==0 && s4==0 && s6==0 )
{ delay(50);
  Serial.println("0000");
 digitalWrite(motor1,0); 
 digitalWrite(motor2,1); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,1);
delay(100);
A++;
}
//----------------------stop---------------------------------------------
if( A==4){
Serial.println("stop");
 digitalWrite(motor1,0); 
 digitalWrite(motor2,0); 
 digitalWrite(motor3,0);
 digitalWrite(motor4,0);
}
}
