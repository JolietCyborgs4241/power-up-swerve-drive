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

<<<<<<< HEAD
	// Pistons to hold the ramp
	DoubleSolenoid* holdRampPiston1;
	//DoubleSolenoid* holdRampPiston2;
=======
    // RIP RAMP BOT Feb 22/2018 -> Mar 17/2018
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff

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