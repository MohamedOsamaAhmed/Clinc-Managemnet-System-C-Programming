#ifndef _SLOT_H_
#define _SLOT_H_
/*
	Declaring slots as Structure Contine Time and if It reserved or Not 
*/

typedef struct slots
{
	u8 Times [20];
	u32 IsReserved;
}slot;
void ViewValidSlots(void);
void ViewReservedSlots(void);
void DeleteSlot(u32 tempId);
void ReserveSlot(u8 No_of_Slot,u32 Id);
extern slot times[5] ;
#endif