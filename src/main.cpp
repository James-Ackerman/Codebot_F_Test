#include "main.h"
//jajaj salu2
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::delay(100);
	pros::lcd::initialize();
	pros::lcd::set_text(1, "INITIALIZE");
	pros::delay(100);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	pros::lcd::set_text(2, "AUTONOMOUS");
}
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 *///.
void opcontrol() {
pros::lcd::set_text(3, "OPCONTROL");
Controller controller;
	while (true)
	{
     driveController.arcade(controller.getAnalog(ControllerAnalog::leftY), -controller.getAnalog(ControllerAnalog::rightX));
		pros::lcd::print(4, "basePos float %f\n", (float) (abs(baseL.getPosition())+abs(baseR.getPosition())/2));
  if (ButtonB.changedToPressed())
  {
    pidTurn(155, 2000_ms, 12000);
  }

	if (ButtonY.changedToPressed())
  {
    pidBase(720, 500_ms, 10000);
  }

	if (ButtonA.changedToPressed())
  {
    pidBaseTurn(-550, 200_ms, 12000);
  }
		pros::delay(20);
	}
}
