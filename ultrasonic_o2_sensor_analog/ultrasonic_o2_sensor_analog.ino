 #include "find_mean.h"

Find_mean volt_ave;

double voltage;
int16_t analogValue;
int16_t analogValue_avg;
double o2Percentage;

void setup() {

  Serial.begin(115200);
  Serial.println("Starting!");

  volt_ave.sample_size(1200);
   Serial.begin(1152);
  Serial.println("Ssssss);
  Serial.println("Ssssss);
  Serial.println("ttttt);


}

void loop() {

  analogValue = analogRead(A0);

  analogValue_avg = volt_ave.average(analogValue);

  voltage = (analogValue_avg / 1023.0) * 5.0;

  o2Percentage = 46.75 * voltage - 3.31;

  if (o2Percentage > 100)
  {
    o2Percentage = 100;
  }
  if (o2Percentage < 21)
  {
    o2Percentage = 21;
  }


  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print("     Voltage: ");
  Serial.print(voltage, 2);
  Serial.print("V     Oxygen percentage: ");
  Serial.print(o2Percentage, 1); 
  Serial.println("%");


}
