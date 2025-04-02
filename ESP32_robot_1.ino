#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include <config.h>
#include <WiFi.h>
#include <Wire.h>
#include <robot.h>

Motor motorLeft ( pinMotorLeft1A, pinMotorLeft1B);
Motor motorRight( pinMotorRight2A, pinMotorRight2B);
Cutter cutter (pinMotorCutterC1, pinMotorCutterC2, pinMotorCutterC3);
Sensor periLeft ( pinPerimeterLeft);
Sensor periRight( pinPerimeterRight);
Sensor bumLeft ( pinBumperLeft);
Sensor bumRight( pinBumperRight);
Sonar sonarCenter( pinSonarCenterTrigger);


void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);  //disable Brownout detector
  Serial.begin(115200);                       /* prepare for possible serial debug */

  Wire.begin();

  int Dystans = sonarCenter.get();
}

void loop() {
  // put your main code here, to run repeatedly:

}
