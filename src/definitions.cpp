#include "definitions.hpp"

void pidTurn(float set)
{
 armPID.set_set_point(set);
 arm_motor.tarePosition();
//while ((armPID.get_Dterm() > 0.0001) && (armPID.get_error() >= 0.001))

while (abs(armPID.get_error()) >= 0)
{
 arm_motor.move_voltage(armPID.output(arm_motor.getPosition()));
}
arm_motor.move_voltage(0);
}

int calcVoltage(float volts){
  if(volts>1.0){
    volts = 12000;
  } else if(volts<-1.0){
    volts = -12000;
  } else{
    volts *= 12000;
  }

  return((int)volts);
}

void fwbwVoltage(int voltage)
{
  baseLF.moveVoltage(voltage);
  baseLB.moveVoltage(voltage);
  baseRF.moveVoltage(-voltage);
  baseRB.moveVoltage(-voltage);
}
void turnVoltage(int voltage)
{
  baseLF.moveVoltage(voltage);
  baseLB.moveVoltage(voltage);
  baseRF.moveVoltage(voltage);
  baseRB.moveVoltage(voltage);
}
void strafeVoltage(int voltage)
{
  baseLF.moveVoltage(voltage);
  baseLB.moveVoltage(-voltage);
  baseRF.moveVoltage(-voltage);
  baseRB.moveVoltage(voltage);
}
void stopDrive()
{
  baseLF.moveVoltage(0);
  baseLB.moveVoltage(0);
  baseRF.moveVoltage(0);
  baseRB.moveVoltage(0);
}
