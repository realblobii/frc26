// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.wpilibj2.command.Command;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants.OperatorConstants;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.*;
import edu.wpi.first.wpilibj.XboxController;

/* You should consider using the more terse Command factories API instead https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands */
public class Launcher extends SubsystemBase {
  /** Creates a new Launcher. */

  XboxController driver = new XboxController(OperatorConstants.kDriverControllerPort);
  VictorSPX motor = new VictorSPX(OperatorConstants.launcherMotor); 

  public Launcher() {
    // Use addRequirements() here to declare subsystem dependencies.
  }
  
  public Command launchBall() {
    return runOnce(
        () -> {
          /* one-time action goes here */
          setLauncherOn();
        });
    }

  public Command launchStop() {
    return runOnce(
        () -> {
          setLauncherOff();
        });
  }

  public Command oopsieLaunch() {
    return runOnce(
      () -> {
        setLauncherReverse();
      }
    );
  }
      public void setLauncherOn() {
    motor.set(ControlMode.PercentOutput, 1);
  }
  
  public void setLauncherReverse() {
    motor.set(ControlMode.PercentOutput, -0.5);
  }
  public void setLauncherOff() {
    motor.set(ControlMode.PercentOutput, 0);
  }

  // Called when the command is initially scheduled.
  // @Override
  // public void initialize() {}

  // // Called every time the scheduler runs while the command is scheduled.
  // @Override
  // public void execute() {}

  // // Called once the command ends or is interrupted.
  // @Override
  // public void end(boolean interrupted) {}

  // // Returns true when the command should end.
  // @Override
  // public boolean isFinished() {
  //   return false;
  // }



}
