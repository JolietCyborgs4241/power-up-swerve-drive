#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Pneumatics : public Subsystem {
  private:
    static constexpr double MAX_PRESSURE = 2.55;

    Compressor* compressor;

    // Claw Pistons (should be actuated together)
    frc::DoubleSolenoid* clawPiston1;
    frc::DoubleSolenoid* clawPiston2;

    frc::DoubleSolenoid* pusherPiston;

    // RIP RAMP BOT Feb 22/2018 -> Mar 17/2018

  public:
    Pneumatics();
    void InitDefaultCommand();

    void Start();

    void OpenClaw();
    void CloseClaw();
    void StopClaw();

    void PushPiston();
    void RetractPiston();
};