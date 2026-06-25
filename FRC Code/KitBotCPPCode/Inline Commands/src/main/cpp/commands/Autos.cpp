// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>

#include "subsystems/CANDriveSubsystem.h"

// Example autonomous commands which drives forward for 1 second.

frc2::CommandPtr autos::ExampleAuto(CANDriveSubsystem *driveSubsystem) {
  return frc2::cmd::Sequence(
      driveSubsystem
          ->ArcadeDrive(
              driveSubsystem, []() { return 0.5; }, []() { return 0.0; })
          .WithTimeout(1.0_s),
      driveSubsystem->ArcadeDrive(
          driveSubsystem, []() { return 0.0; }, []() { return 0.0; }));
}
