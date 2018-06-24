#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int AOUTpin=0;
const int DOUTpin=6;
const int ledPin=13;

int limit;
int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DOUTpin,INPUT);
  pinMode(ledPin,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.write("Welcome");
  delay(3000); 
  lcd.clear();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(AOUTpin);
  limit=digitalRead(DOUTpin);
  Serial.print("Air quality= ");
  lcd.print("AQ= ");
  //lcd.clear();
  Serial.print(value);
  lcd.print(value);
  Serial.println(" PPM");
  lcd.println("PPM");
  delay(2000); 
  lcd.clear();
  Serial.print("Limit= ");
  lcd.print("Limit= ");
  Serial.println(limit);
  lcd.println(limit);
  delay(2000); 
  lcd.clear();
  if(value>0 && value<80)
  {

    Serial.println("Fresh Air");
    lcd.println("Fresh Air");
    digitalWrite(13, HIGH);   
  delay(2000);             
  digitalWrite(13, LOW);    
  delay(2000);          
    lcd.clear();
    }
    else if(value>80 && value <200)
    {

    Serial.println("Air is poluted");
    lcd.println("Air is poluted");
    //lcd.clear();
    digitalWrite(13, HIGH);   
  delay(2000);              
  digitalWrite(13, LOW);    
  delay(2000);          
      
    }
    else
    {
      Serial.println("Air is very poluted.Leave the place");
      lcd.println("Very poluted");
      //lcd.clear();
      digitalWrite(13, HIGH);   
  delay(2000);             
  digitalWrite(13, LOW);    
  delay(2000);          
      
      }
  
}
