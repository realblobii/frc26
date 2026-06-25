// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>

#include "commands/Autos.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Set the default command for the drivetrain to use the DriveCommand to drive
  // the robot with the left Y and right X axes of the gamepad
  driveSubsystem.SetDefaultCommand(driveSubsystem.ArcadeDrive(
      &driveSubsystem, [this] { return -driverController.GetLeftY(); },
      [this] { return -driverController.GetRightX(); }));

  // Set the default command for the roller to be analog control mapped to the
  // trigger axes of the 2nd gamepad
  rollerSubsystem.SetDefaultCommand(rollerSubsystem.RunRoller(
      &rollerSubsystem,
      [this] { return operatorController.GetRightTriggerAxis(); },
      [this] { return operatorController.GetLeftTriggerAxis(); }));

  // While the A button of the 2nd gamepad is held, run the roller at a fixed
  // speed
  operatorController.A().WhileTrue(rollerSubsystem.RunRoller(
      &rollerSubsystem, [this] { return RollerConstants::ROLLER_EJECT_SPEED; },
      [this] { return 0; }));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&driveSubsystem);
}
