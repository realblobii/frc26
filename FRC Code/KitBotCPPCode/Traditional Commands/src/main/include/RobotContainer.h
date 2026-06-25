#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandPS4Controller.h>

#include "Constants.h"
#include "subsystems/CANDriveSubsystem.h"
#include "subsystems/CANRollerSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  frc2::CommandPS4Controller driverController{
      OperatorConstants::DRIVER_CONTROLLER_PORT};
  frc2::CommandPS4Controller operatorController{
      OperatorConstants::OPERATOR_CONTROLLER_PORT};

  CANDriveSubsystem driveSubsystem;
  CANRollerSubsystem rollerSubsystem;

  void ConfigureBindings();
};
