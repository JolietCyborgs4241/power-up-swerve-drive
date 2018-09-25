#include "OI.h"
#include "Commands/ClawControl.h"
#include "Commands/EjectCube.h"
#include "Commands/ElevatorPosControl.h"
<<<<<<< HEAD
#include "Commands/IncreasePos.h"
#include "Commands/DeployRamp.h"
OI::OI() {
	// Process operator interface input here.
	pi = 3.14159;

	driverJoystickLeft = new Joystick(0); //Ps4
	driverJoystickRight = new Joystick(1); //Xbox

	//Xbox
	a = new JoystickButton(driverJoystickRight, 1);
	b = new JoystickButton(driverJoystickRight, 2);
	xb = new JoystickButton(driverJoystickRight, 3);
	y = new JoystickButton(driverJoystickRight, 4);
	lb = new JoystickButton(driverJoystickRight, 5);
	rb = new JoystickButton(driverJoystickRight, 6);
	back = new JoystickButton(driverJoystickRight, 7);
	start = new JoystickButton(driverJoystickRight, 8);
	//^Xbox^

	//PS4
	sq = new JoystickButton(driverJoystickLeft, 1);
	xp = new JoystickButton(driverJoystickLeft, 2);
	circle = new JoystickButton(driverJoystickLeft, 3);
	tri = new JoystickButton(driverJoystickLeft, 4);
	l1 = new JoystickButton(driverJoystickLeft, 5);
	r1 = new JoystickButton(driverJoystickLeft, 6);
	l2 = new JoystickButton(driverJoystickLeft, 7);
	r2 = new JoystickButton(driverJoystickLeft, 8);
	shr = new JoystickButton(driverJoystickLeft, 9);
	opt = new JoystickButton(driverJoystickLeft, 10);
	l3 = new JoystickButton(driverJoystickLeft, 11);
	r3 = new JoystickButton(driverJoystickLeft, 12);
	ps = new JoystickButton(driverJoystickLeft, 13);
	pad = new JoystickButton(driverJoystickLeft, 14);
	//^PS4^


	//xbox
	a->WhenPressed(new ResetPigeonYaw);



	//l1->WhenPressed(new PositionArm);

	//ps4
	xp->ToggleWhenPressed(new ClawControl);
	sq->ToggleWhenPressed(new RampEndUp);
	ps->ToggleWhenPressed(new DeployRamp);
	//tri->WhenPressed(new ElevatorPosControl(Robot::cycleElevator->ElevatorCycleNum));

}

Joystick* OI::getDriverJoystickLeft() {
	return driverJoystickLeft;
}
Joystick* OI::getDriverJoystickRight() {
	return driverJoystickRight;
}

bool OI::getL1() {
	return driverJoystickRight->GetRawButton(5);
}

double OI::getJoystickMagnitude() {
	if(driverJoystickRight->GetMagnitude() < .1) {
		return 0;
	} else {
		if (driverJoystickRight->GetY() < 0) {
			return -driverJoystickRight->GetMagnitude();
		} else {
			return driverJoystickRight->GetMagnitude();
		}
	}
}

double OI::getJoystickZ() {
	return adjustJoystick(driverJoystickRight->GetRawAxis(4));
}

double OI::getJoystickX() {
	return adjustJoystick(driverJoystickRight->GetX());
}

double OI::getJoystickY() {
	return adjustJoystick(driverJoystickRight->GetY());
}

double OI::getPS4Joy() {
	return adjustJoystick(driverJoystickLeft->GetY());
=======
#include "Commands/IntakeActuate.h"
#include "Commands/PusherPiston.h"
#include "Commands/ResetPigeonYaw.h"
#include "Commands/SetElevatorPosition.h"
#include "Commands/ToggleElevatorPosControl.h"
#include "Commands/ToggleFieldCentric.h"
#include "Commands/ToggleLimitSwitch.h"
#include "Commands/TogglePrecisionDrive.h"
#include "Commands/ToggleTwistPID.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Subsystems/DriveTrain.h"

OI::OI() {
    // Process operator interface input here.
    xBoxControl = new Joystick(0);
    xBoxDrive = new Joystick(1);

    // Xbox
    DriveA = new JoystickButton(xBoxDrive, 1);
    DriveB = new JoystickButton(xBoxDrive, 2);
    DriveX = new JoystickButton(xBoxDrive, 3);
    DriveY = new JoystickButton(xBoxDrive, 4);
    DriveLB = new JoystickButton(xBoxDrive, 5);
    DriveRB = new JoystickButton(xBoxDrive, 6);
    DriveBack = new JoystickButton(xBoxDrive, 7);
    DriveStart = new JoystickButton(xBoxDrive, 8);
    DriveLeftStick = new JoystickButton(xBoxControl, 9);
    DriveRightStick = new JoystickButton(xBoxControl, 10);
    //^Xbox^

    ControlA = new JoystickButton(xBoxControl, 1);
    ControlB = new JoystickButton(xBoxControl, 2);
    ControlX = new JoystickButton(xBoxControl, 3);
    ControlY = new JoystickButton(xBoxControl, 4);
    ControlLB = new JoystickButton(xBoxControl, 5);
    ControlRB = new JoystickButton(xBoxControl, 6);
    ControlBack = new JoystickButton(xBoxControl, 7);
    ControlStart = new JoystickButton(xBoxControl, 8);
    ControlLeftStick = new JoystickButton(xBoxControl, 9);
    ControlRightStick = new JoystickButton(xBoxControl, 10);
    // Used For controlling main subsystems excluding drive

    // XboxDrive
    DriveA->WhenPressed(new ResetPigeonYaw(90));
    DriveB->WhenPressed(new ToggleFieldCentric);
    DriveX->WhenPressed(new TogglePrecisionDrive);

    /* Eh, no gyro assist today
    DriveY->WhenPressed(new ToggleTwistPID);
    if (xBoxDrive->GetPOV() != -1) {
        Robot::gyroAssist = true;
        Robot::gyroAssistPID->SetSetpoint(xBoxDrive->GetPOV());
    }
    */

    /* No elevator pos control
    ControlA->WhenPressed(new ElevatorPosControl(0));
    ControlLB->WhenPressed(new ElevatorPosControl(3));
    ControlRB->WhenPressed(new ElevatorPosControl(4));

    ControlY->WhenPressed(new ToggleElevatorPosControl);

    ControlBack->WhenPressed(new SetElevatorPosition);
    */

    ControlStart->WhenPressed(new ToggleLimitSwitch);

    ControlX->ToggleWhenPressed(new ClawControl);
    ControlB->ToggleWhenPressed(new PusherPiston);
    ControlA->WhenPressed(new EjectCube);
}

Joystick* OI::getControlJoystick() {
    return xBoxControl;
}
Joystick* OI::getDriveJoystick() {
    return xBoxDrive;
}

bool OI::getLB() {
    return xBoxDrive->GetRawButton(5);
}

double OI::getJoystickMagnitude() {
    if (xBoxDrive->GetMagnitude() < .1) {
        return 0;
    } else {
        if (xBoxDrive->GetY() < 0) {
            return -xBoxDrive->GetMagnitude();
        } else {
            return xBoxDrive->GetMagnitude();
        }
    }
}

double OI::getDriveRightX() {
    return adjustJoystick(xBoxDrive->GetRawAxis(4));
}

double OI::getDriveLeftX() {
    return adjustJoystick(xBoxDrive->GetX());
}

double OI::getDriveLeftY() {
    return adjustJoystick(xBoxDrive->GetY());
}

double OI::getControlJoy() {
    return adjustJoystick(xBoxControl->GetY());
>>>>>>> 2049c4a3761c73539323a05bf768cbdc00da8cff
}

double OI::adjustJoystick(double value) {
    // cube output
    double adjV = pow(value, 3);

    // add deadzone
    if (fabs(adjV) < 0.05) {
        return 0;
    } else {
        return adjV;
    }
}
