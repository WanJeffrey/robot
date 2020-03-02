int count = 0;
void rotaterobot()
{
	motor[motorA] = motor[motorD] = 0;
	resetGyro(S4);
	wait1Msec(50);
	while (fabs(getGyroDegrees(S4)) < 90 )
	{
			motor[motorA] = 25;
			motor[motorD] = -25;
	}
	wait1Msec(50);
	motor[motorA] = motor[motorD] = 50;
}

void squaremove()
{
	for (int x = 0 ; x< count ; x++)
	{
		motor[motorA] = motor[motorD] = 50;
		nMotorEncoder[motorA] = 0;
		while(nMotorEncoder[motorA] < length_rot - (x * offset))
		{}
		rotate();
		while(nMotorEncoder[motorA] < length_rot - (x * offset))
		{}
		rotate();
		while(nMotorEncoder[motorA] < width_rot - ((x+1) * offset))
		{}
		rotate();
		while(nMotorEncoder[motorA] < width_rot - ((x+1) * offset))
		{}
		rotate();
	}
	
}
void return_to_origin(int length, int width)
{
	nMotorEncoder[motorA] = 0;
	
}

task main()
{
	SensorType[S2] = sensorEV3_Touch; // check for sensors in right place, gyro?
	wait1Msec(50);
	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50); 
	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
	int dist_to_wall = 0, count = 0, return_count = 0, offset = 0;
	resetGyro(S4);
	wait1Msec(50);
	nMotorEncoder[motorA] = 0;
	motor[motorA] = motor[motorD] = 50;
	while(sensorValue(S1) < dist_to_wall)
	{}
	float length_rot = nMotorEncoder[motorA];
	int count = length_rot / offset;
	rotate();
	nMotorEncoder[motorA] = 0;
	while(sensorValue(S1) < dist_to_wall)
	{}
	float width_rot = nMotorEncoder[motorA];
	rotate();
	while(sensorValue(S1) < dist_to_wall)
	{}
	rotate();
}
