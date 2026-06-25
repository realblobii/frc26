// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import com.ctre.phoenix.motorcontrol.can.WPI_VictorSPX;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import edu.wpi.first.util.sendable.SendableRegistry;
// import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import frc.robot.Constants.OperatorConstants;

public class DriveTrain extends SubsystemBase {
  /** Creates a new DriveTrain. */

  public final WPI_VictorSPX m_leftLeader = new WPI_VictorSPX(OperatorConstants.leftMotorLead);
  public final WPI_VictorSPX m_rightLeader = new WPI_VictorSPX(OperatorConstants.rightMotorLead);
  private final WPI_VictorSPX m_leftFollower = new WPI_VictorSPX(OperatorConstants.leftMotorFollow);
  private final WPI_VictorSPX m_rightFollower = new WPI_VictorSPX(OperatorConstants.rightMotorFollow);
  // public final XboxController m_Controller = new XboxController(OperatorConstants.kDriverControllerPort);
  public final DifferentialDrive m_robotDrive = new DifferentialDrive(m_leftLeader, m_rightLeader);
  

  public DriveTrain() {
    m_leftFollower.follow(m_leftLeader);
    m_rightFollower.follow(m_rightLeader);
    SendableRegistry.addChild(m_robotDrive, m_leftLeader);
    SendableRegistry.addChild(m_robotDrive, m_rightLeader);

    //m_rightLeader.setInverted(true);
    // m_leftLeader.setInverted(true);
  }

  public void tankDrive(double leftSpeed, double rightSpeed) {
    //Operate in tank drive with a separate joystick controlling each side
    //Each side has a trim value multiplier to adujst speeds
    m_robotDrive.tankDrive(leftSpeed*OperatorConstants.kLeftTrim, rightSpeed*OperatorConstants.kRightTrim);
  }

}
