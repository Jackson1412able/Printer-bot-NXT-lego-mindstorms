#pragma config(Sensor,S1,touch,sensorTouch)
#pragma config(Sensor,S3,color,sensorCOLORFULL)
#pragma config(Motor,motorA,verticalmotor,tmotorNXT,PIDControl,encoder)
#pragma config(Motor,motorB,horizontalmotor,tmotorNXT,PIDControl,encoder)
#pragma config(Motor,motorC,penmotor,tmotorNXT,PIDControl,encoder)

//*!!Code automatically generated by 'ROBOTC' configuration wizard!!*//

void LiftPen()	//Rotate the pen motor to lift the pen
{
	motor[motorC] = 10;
	wait1Msec(900);
	motor[motorC] = 0;
}

void ResetHorizontal()	//Rotate the horizontal motor to bring the horizontal module to the left
{
	while(SensorValue(touch) == 0)
	{
		motor[motorB] = -40;
	}
	motor[motorB] = 0;

	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = 20;
	motor[motorB] = 20;
	while(nMotorRunState[motorB] != runStateIdle)
	{
	}
	motor[motorB] = 0;
}

void ResetVertical()	//Rotate the vertical motor until paper is inserted and detected
{
	while(SensorValue(color) != WHITECOLOR)
	{
		motor[motorA] = 20;
	}
	motor[motorA] = 0;
	//PlaySoundFile("Note 3.rso");
	//nVolume = 2;
	//wait1Msec(500);
	wait1Msec(3000);
	while(SensorValue(color) == WHITECOLOR)
	{
		motor[motorA] = -40;
	}
	motor[motorA] = 0;

	nMotorEncoder[motorA] = 0;
	nMotorEncoderTarget[motorA] = 30;
	motor[motorA] = 40;
	wait1Msec(3000);
	motor[motorA] = 0;
}

void Horizontal(int duration)	//Rotate the horizontal motor to move the horizontal module horizontally
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = duration;
	if(duration > 0)
	{
		motor[motorB] = 40;
	}
	else if (duration < 0)
	{
		motor[motorB] = -40;
	}
	while(nMotorRunState[motorB] != runStateIdle)
	{
	}
	motor[motorB] = 0;
	wait1Msec(200);
}

void Vertical(int duration)	//Rotate the vertical motor to move the paper vertically
{
	nMotorEncoder[motorA] = 0;
	nMotorEncoderTarget[motorA] = duration;
	if(duration > 0)
	{
		motor[motorA] = 40;
	}
	else if (duration < 0)
	{
		motor[motorA] = -40;
	}
	while(nMotorRunState[motorA] != runStateIdle)
	{
	}
	motor[motorA] = 0;
	wait1Msec(200);
}

void LowerPen()	//Rotate the pen motor so the tip of the pen is in contact with the paper
{
	motor[motorC] = -20;
	wait1Msec(380);
	//motor[motorC] = 0;
	motor[motorC] = 20;
	wait1Msec(30);
	motor[motorC] = 0;
}

void Eject()	//Rotate the vertical motor to move the paper out
{
	LiftPen();
	while(SensorValue(color) == WHITECOLOR)
	{
		motor[motorA] = -100;
	}
	wait1Msec(1000);
	motor[motorA] = 0;
}

int duration1 = 0;
task Horizontal2()	//Rotate the horizontal motor to move the horizontal module horizontally for asynchronous task
{
	nMotorEncoder[motorB] = 0;
	nMotorEncoderTarget[motorB] = duration1;
	if(duration1 > 0)
	{
		motor[motorB] = 40;
	}
	else if (duration1 < 0)
	{
		motor[motorB] = -40;
	}
	while(nMotorRunState[motorB] != runStateIdle)
	{
	}
	motor[motorB] = 0;
	wait1Msec(200);
}

int duration2 = 0;
task Vertical2()	//Rotate the vertical motor to move the paper vertically for asynchronous task
{
	nMotorEncoder[motorA] = 0;
	nMotorEncoderTarget[motorA] = duration2;
	if(duration2 > 0)
	{
		motor[motorA] = 40;
	}
	else if (duration2 < 0)
	{
		motor[motorA] = -40;
	}
	while(nMotorRunState[motorA] != runStateIdle)
	{
	}
	motor[motorA] = 0;
	wait1Msec(200);
}

task main()
{
	LiftPen();
	ResetHorizontal();
	ResetVertical();
	Horizontal(100);
	Vertical(-100);
	LowerPen();
	Horizontal(1000);
	Vertical(1000);
	Horizontal(-400);
	Vertical(-200);
	Horizontal(200);
	Vertical(-600);
	Horizontal(-600);
	Vertical(600);
	Horizontal(200);
	Vertical(200);
	Horizontal(-400);
	Vertical(-1000);
	LiftPen();
	Horizontal(400);
	Vertical(400);
	LowerPen();
	Horizontal(200);
	Vertical(200);
	Horizontal(-200);
	Vertical(-200);
	LiftPen();
	ResetHorizontal();
	Horizontal(100);
	Vertical(900);
	LowerPen();
	Vertical(-250);

	duration1 = 250;
	duration2 = 250;
	StartTask(Horizontal2);
	StartTask(Vertical2);
	wait1Msec(2000);

	Vertical(-250);
	LiftPen();
	Horizontal(125);
	LowerPen();

	StartTask(Horizontal2);
	StartTask(Vertical2);
	wait1Msec(2000);
	

	LiftPen();
	Horizontal(-250);
	LowerPen();

	duration2 = -250;
	StartTask(Horizontal2);
	StartTask(Vertical2);
	wait1Msec(2000);

	LiftPen();
	Horizontal(125);
	LowerPen();

	Horizontal(250);
	Horizontal(-125);
	Vertical(250);
	LiftPen();
	ResetHorizontal();
	Horizontal(200);
	Vertical(50);
	LowerPen();
	Horizontal(300);
	Vertical(100);
	Horizontal(-300);
	Vertical(100);
	Horizontal(300);
	LiftPen();
	Horizontal(100);
	LowerPen();
	Horizontal(20);
	Vertical(-20);
	Horizontal(-20);
	Vertical(20);
	LiftPen();
	Horizontal(100);
	LowerPen();
	Horizontal(300);
	Vertical(-200);
	Horizontal(-300);
	Vertical(200);

	Eject();
}
