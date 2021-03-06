#include "OI.h"
#include "Commands/ClawControl.h"
#include "Commands/EjectCube.h"
#include "Commands/ElevatorPosControl.h"
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
