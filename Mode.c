#include <stdio.h>
#include "Types.h"
#include "Mode.h"
u8 CheckMode(u8 ModeNumber)
{
	/*
		Declearing varibles
	*/
	u8 isPassed = 0;
	u8 no_of_trails = 3;
	u32 password;
	/*
		If mode is 1-> admin ask user to enter the password and he have 3 times of trying then the program will close 
	*/
	if (ModeNumber == 1)
	{
		do
		{
			printf("Please Enter Your Password : ");
			scanf("%d", &password);
			if (password == 1234)
			{
				isPassed = (u8)1;
				break;
			}
			else
			{
				printf("You have Entered a wrong Password please try again \n");
				no_of_trails--;
				printf("Remind Number of trails is %d \n", no_of_trails);
				printf("\n");
			}
		} while (no_of_trails > (u8)0);

		if (no_of_trails == (u8)0)
		{

			printf("You have Entered Password Error many times so the program has been stopped");
			isPassed = (u8)0;
		}
	}
	else if (ModeNumber == (u8)0)
	{
		isPassed = (u8)1;
	}

	return isPassed;
}