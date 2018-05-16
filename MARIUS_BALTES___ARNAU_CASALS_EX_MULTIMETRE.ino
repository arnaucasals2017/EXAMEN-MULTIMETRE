/******************************************************************
**                                                               **
**                       EXAMEN MULTIMETRE                       **      
**                                                               **
**                                                               ** 
**  BALTES MARIUS & ARNAU CASALS             DATA:  14/05/2018   **            
*******************************************************************/
//**************************** INCLUDE ****************************
 int   Pin_de_medicion = 0; 
  int   R1 = 10000; 
  long  lectura; 
  float Tension_de_trabajo = 5.0; 
  float Voltatge_R2; 
  float Resistencia; 

  void setup()
{
  Serial.begin(9600);
  Serial.println("Mesura de resistencia:");
  Serial.println();
}

  void loop()
{

  lectura=0;
  for(int i=0;i<5;i++){
    lectura+=analogRead(Pin_de_medicion);
  }
  lectura=trunc(lectura/5);
  
  
  Voltatge_R2=(Tension_de_trabajo/1023.0)*lectura;
  
  
  Serial.print("Voltatge en R1: ");
  Serial.print(Voltatge_R2,2);
  Serial.println(" Volts");
  
  
  Resistencia=R1*Voltatge_R2/(Tension_de_trabajo-Voltatge_R2);
  Serial.print("La resistencia es ");
  Serial.print(Resistencia,2);
  Serial.println(" Ohm.");
  Serial.println();
  delay(1000);
}
