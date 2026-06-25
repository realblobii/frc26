// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Constants.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

class CANDriveSubsystem : public frc2::SubsystemBase {
 public:
  CANDriveSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

  frc2::CommandPtr ArcadeDrive(CANDriveSubsystem *driveSubsystem,
                               std::function<double()> xSpeed,
                               std::function<double()> zRotation);

 private:
  rev::spark::SparkMax leftLeader;
  rev::spark::SparkMax leftFollower;
  rev::spark::SparkMax rightLeader;
  rev::spark::SparkMax rightFollower;

  frc::DifferentialDrive drive{leftLeader, rightLeader};
};
