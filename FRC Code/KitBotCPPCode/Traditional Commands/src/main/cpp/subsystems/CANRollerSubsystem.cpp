// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/RobotController.h>
#include <subsystems/CANRollerSubsystem.h>

using namespace RollerConstants;

// class to run the rollers over CAN
CANRollerSubsystem::CANRollerSubsystem() {
  rollerMotor.ConfigFactoryDefault();
  rollerMotor.ConfigVoltageCompSaturation(ROLLER_MOTOR_VOLTAGE_COMP);
  rollerMotor.EnableVoltageCompensation(true);
}

void CANRollerSubsystem::Periodic() {}

void CANRollerSubsystem::SimulationPeriodic() {}

// enables the roller
void CANRollerSubsystem::EnableRoller() {
  // rollerEnabled = true;
}

// disables the roller
void CANRollerSubsystem::DisableRoller() {
  // rollerEnabled = false;
}

// sets the speed of the roller motor
void CANRollerSubsystem::RunRoller(double forward, double reverse) {
  if (forward <= -0.8) {
    rollerMotor.Set(0);
  } else {
    rollerMotor.Set(forward/2+1); 
  }
}