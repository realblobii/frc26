// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/AutoCommand.h"
#include "commands/DriveCommand.h"
#include "commands/RollerCommand.h"
#include <subsystems/CANRollerSubsystem.h>

RobotContainer::RobotContainer() 
    : driverController(OperatorConstants::DRIVER_CONTROLLER_PORT),
      operatorController(OperatorConstants::OPERATOR_CONTROLLER_PORT),
      driveSubsystem(),
      rollerSubsystem() {
  // Initialize all of your commands and subsystems here

  // Use frc2::JoystickButton for button bindings
//  frc2::JoystickButton(&operatorController, frc::PS4Controller::Button::kCross) // X button to enable roller
//      .OnTrue(frc2::RunCommand([this] { rollerSubsystem.EnableRoller(); }, {&rollerSubsystem}));

//  frc2::JoystickButton(&operatorController, frc::PS4Controller::Button::kCircle) // Circle button to disable roller
//      .OnTrue(frc2::RunCommand([this] { rollerSubsystem.DisableRoller(); }, {&rollerSubsystem}));

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Set the default command for the drivetrain to use the DriveCommand to drive
  // the robot with the left Y and right X axes of the gamepad
  driveSubsystem.SetDefaultCommand(DriveCommand(
      &driveSubsystem, [this] { return -driverController.GetLeftY(); },
      [this] { return -driverController.GetRightX(); }));

  rollerSubsystem.SetDefaultCommand(RollerCommand(
      &rollerSubsystem,
      [this] { return driverController.GetL2Axis(); },
      [this] { return 0; }));

  // operatorController.Circle().WhileTrue(new RollerCommand(&rollerSubsystem, [this] { return 0.3; }, [this] { return 1.0; }));
//  operatorController.Circle().OnFalse(new RollerCommand(&rollerSubsystem, [this] { return 0.3; }, [this] { return 1.0; }));

  // Set the default command for the roller to be analog control mapped to the
  // trigger axes of the 2nd gamepad
//  rollerSubsystem.SetDefaultCommand(RollerCommand(
//      &rollerSubsystem,
//      [this] { return operatorController.GetR2Axis(); },
//      [this] { return operatorController.GetL2Axis(); }));

  // While the Square button of the 2nd gamepad is held, run the roller at a fixed
  // speed
//  frc2::JoystickButton(&operatorController, frc::PS4Controller::Button::kSquare)
//      .WhileTrue(RollerCommand(
//          &rollerSubsystem,
//          [this] { return RollerConstants::ROLLER_MOTOR_EJECT_SPEED; },
//          [this] { return 0; })
//          .WithName("Fixed speed"));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  return AutoCommand(&driveSubsystem).ToPtr();
}
