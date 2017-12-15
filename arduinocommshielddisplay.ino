
#define REC  0
#define CLOCK  1

const int pulsador=A3;

const int led1=6;
const int led2=7;
const int led3=8;

const int disla=A0;
const int dislb=A1;
const int dislc=A2;
const int disld=2;
const int disle=3;
const int dislf=4;
const int dislg=5;
const int dislp=13;

const int mo1A=9;
const int mo1B=10;
const int mo2A=11;
const int mo2B=12;

bool encendido=true;

void setup() {
  // put your setup code here, to run once:

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
  pinMode(disla,OUTPUT);
  pinMode(dislb,OUTPUT);
  pinMode(dislc,OUTPUT);
  pinMode(disld,OUTPUT);
  pinMode(disle,OUTPUT);
  pinMode(dislf,OUTPUT);
  pinMode(dislg,OUTPUT);
  pinMode(dislp,OUTPUT);

  pinMode(mo1A,OUTPUT);
  pinMode(mo1B,OUTPUT);
  pinMode(mo2A,OUTPUT);
  pinMode(mo2B,OUTPUT);
  
  pinMode(REC, INPUT);
  pinMode(CLOCK, INPUT);
  //Serial.begin(9800);
  

}

void loop() {


  
  // put your main code here, to run repeatedly:
   // Serial.print("Recibe");
    String caracter="";
    for (int i=0; i<2; i++) {
    while (digitalRead(CLOCK) == LOW) {
        }
        if (digitalRead(REC) == LOW){
            caracter+="0";
       //     Serial.println("Recibe 0");
            }
        else {
            caracter += "1";
        //    Serial.println("Recibe 1");
            }
        delay(100);
        while (digitalRead(CLOCK) == HIGH)
            {}
    }

   
      if (caracter.equals("00")) {
           derechaMotor(mo1A,mo1B);
           showDisplay(1);
      }
          
      if (caracter.equals("01")){
          izquierdaMotor(mo1A,mo1B); 
           showDisplay(2);
      }
        
      if (caracter.equals("10")){
          paraMotor(mo1A,mo1B); 
           showDisplay(3);
      }
         
      if (caracter.equals("11")) {
          paraMotor(mo1A,mo1B);
          izquierdaMotor(mo1A,mo1B); 
          leds(); 
          showDisplay(4);
      
      }
 
    // statements

    //Serial.println(caracter);
 }

 
void pulsar() {
 
  if (analogRead(pulsador)>650)
    encendido=!encendido;
    digitalWrite(dislp,encendido);
  delay(100);  
}


void delay2(int mili){
  long tiempoactual=millis();  // Anotamos el tiempo actual
  long tiempoAlarma=tiempoactual+mili; // 2 segundos después
  while(millis()<tiempoAlarma) // Mientras no sea el momento de la alarma haz otras cosas
  {
      pulsar();
  }
}


void motores() {
  paraMotor(mo1A,mo1B);
  paraMotor(mo2A,mo2B);
  delay(1000);
  derechaMotor(mo1A,mo1B);
  izquierdaMotor(mo2A,mo2B);
  delay(1000);
  derechaMotor(mo2A,mo2B);
  izquierdaMotor(mo1A,mo1B);
  delay(1000);
  
  paraMotor(mo1A,mo1B);
  paraMotor(mo2A,mo2B);
   
  
}

void paraMotor(int A, int B){
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    return;
  
}


void derechaMotor(int A, int B){
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    return;
  
}

void izquierdaMotor(int A, int B){
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    return;
  
}


void displayA() {
  for (int i=0;i<5;i++) {
    disSeg(LOW,LOW,LOW,LOW,LOW,LOW,HIGH);
    delay2(200);
    disSeg(LOW,LOW,LOW,LOW,LOW,LOW,LOW);
    delay2(200);}
  for (int i=0;i<10;i++) {
    showDisplay(i);
    delay2(500);
  }  
  for (int i=0;i<5;i++) {
    disSeg(LOW,LOW,LOW,LOW,LOW,LOW,HIGH);
    delay2(200);
    disSeg(LOW,LOW,LOW,LOW,LOW,LOW,LOW);
    delay2(200);}
}

void showDisplay(int i) {
   switch ( i )  
      {  
         case 0:  
            disSeg(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW);
            break;  
         case 1:  
            disSeg(LOW,HIGH,HIGH,LOW,LOW,LOW,LOW);
            break;  
         case 2:  
            disSeg(HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH);
            break; 
         case 3:  
            disSeg(HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH);
            break; 
         case 4:  
            disSeg(LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH);
            break; 
         case 5:  
            disSeg(HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH);
            break; 
         case 6:  
            disSeg(HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH);
            break; 
         case 7:  
            disSeg(HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW);
            break; 
         case 8:  
            disSeg(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);
            break; 
         case 9:  
            disSeg(HIGH,HIGH,HIGH,LOW,LOW,HIGH,HIGH);
            break; 
         default:  
           break;
      }  
}

void disSeg(int a,int b,int c, int d, int e, int f, int g) {
  digitalWrite(disla, a);
  digitalWrite(dislb, b);
  digitalWrite(dislc, c);
  digitalWrite(disld, d);
  digitalWrite(disle, e);
  digitalWrite(dislf, f);
  digitalWrite(dislg, g);
  digitalWrite(dislp, LOW);
}
 
   // print(cod.getCaracter(caracter))

   
void leds() {
  for (int i=0;i<4;i++) {
    enciendeLeds(HIGH,LOW,LOW);
    delay2(200);
    enciendeLeds(LOW,HIGH,LOW);
    delay2(200);
    enciendeLeds(LOW,LOW,HIGH);
    delay2(200);
  }

   for (int i=0;i<4;i++) {
     
     enciendeLeds(HIGH,HIGH,HIGH);
     delay2(200);
     enciendeLeds(LOW,LOW,LOW);
     delay2(200);
    }
  return;
}

void enciendeLeds(int a, int b, int c) {
  digitalWrite(led1,a);
  digitalWrite(led2,b);
  digitalWrite(led3,c);
  return;
  
}




