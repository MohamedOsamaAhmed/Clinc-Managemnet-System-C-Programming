#include <stdio.h>
#include "Types.h"
#include "Slot.h"


/*
	Initialize slots Time and set all Not Rerseved
*/
slot times[5] = {{"2pm to 2:30pm",0},{"2:30pm to 3pm",0},{"3pm to 3:30pm",0},{"4pm to 4:30pm",0},{"4:30pm to 5pm",0}};

/*
	This viewSlots function View all Slots which are stored by the Admin
*/

void ViewValidSlots(void)
{
	u8 IsValid = 0;
	for(u8 i = 0; i < 5; i++)
	{
		if (times[i].IsReserved == 0)
		{
		    printf("%s and Its Number is : %d\n",times[i].Times,i+1);
			u8 IsValid = 1;
		}		
	}
	if (IsValid == (u8)0)
	{
		printf("\n Oh Sorry There is No Valid Slots!! \n");
	}
}
void ViewReservedSlots(void)
{
	u8 IsFilled = 0;
	for(u8 i = 0; i < 5; i++)
	{
		if (times[i].IsReserved != 0)
		{
		    printf("%s and Its Number is : %d",times[i].Times,i+1);
			printf("for Patient Number: %d \n",times[i].IsReserved);
			IsFilled = 1;
		}		
	}
	if (IsFilled == (u8)0)
	{
		printf("\n Oh Sorry There is No reservations!! \n");
	}
}



/*
	This reserveSlot function reserves a slot depending on its number 
	by set its reserved store the value of the id which reserved it
	
*/

void ReserveSlot(u8 No_of_Slot,u32 Id)
{	
	
   times[No_of_Slot-1].IsReserved = Id;

}

/*
	This delete slot function allow admin to delete any reserved slot 
	with the id who reserved it 
*/
void DeleteSlot(u32 Id)
{
	
	
		for (u8 i = 1; i < 6;i++)
		{
		    if(Id == times[i-1].IsReserved)
		    {
			    times[i-1].IsReserved = 0;
		    }
		}
	
	
}