/* ATM90E36 Energy Monitor Demo Application

   The MIT License (MIT)

  Copyright (c) 2016 whatnick and Ryzee

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <SPI.h>
#include <ATM90E36.h>

void setup() {
  /* Initialize the serial port to host */
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("Start ATM90E36");
  /*Initialise the ATM90E36 + SPI port */
  InitEnergyIC();
  delay(1000);
}



void loop() {
  
  /*Repeatedly fetch some values from the ATM90E36 */
  double voltageA,freq,voltageB,voltageC,currentA,currentB,currentC,power,pf,new_current,new_power;
  int sys0=GetSysStatus0();
  int sys1=GetSysStatus1();
  int en0=GetMeterStatus0();
  int en1=GetMeterStatus1();
  Serial.println("S0:0x"+String(sys0,HEX));
  delay(10);
  Serial.println("S1:0x"+String(sys1,HEX));
  delay(10);
  Serial.println("E0:0x"+String(en0,HEX));
  delay(10);
  Serial.println("E1:0x"+String(en1,HEX));
  voltageA=GetLineVoltageA();
  Serial.println("VA:"+String(voltageA)+"V");
  voltageB=GetLineVoltageB();
  Serial.println("VB:"+String(voltageB)+"V");
  voltageC=GetLineVoltageC();
  Serial.println("VC:"+String(voltageC)+"V");
  delay(10);
  currentA = GetLineCurrentA();
  Serial.println("IA:"+String(currentA)+"A");
  currentB = GetLineCurrentB();
  Serial.println("IB:"+String(currentB)+"A");
  currentC = GetLineCurrentC();
  Serial.println("IC:"+String(currentC)+"A");
  delay(10);
  freq=GetFrequency();
  delay(10);
  Serial.println("f"+String(freq)+"Hz");
  delay(1000);
}
