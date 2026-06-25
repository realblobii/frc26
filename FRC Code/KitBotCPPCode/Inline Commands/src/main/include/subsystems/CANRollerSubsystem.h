// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <Constants.h>
#include <frc/RobotController.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>

class CANRollerSubsystem : public frc2::SubsystemBase {
 public:
  CANRollerSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

  frc2::CommandPtr RunRoller(CANRollerSubsystem *rollerSubsystem,
                             std::function<double()> forward,
                             std::function<double()> reverse);

 private:
  rev::spark::SparkMax rollerMotor;
};