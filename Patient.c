#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "Patient.h"
#include "Slot.h"

PatientInfo *CurrentPatientInfo = Null;

void AddPatient(u32 Id, u8 Age, u8 Name[], u8 Gender[])
{
	PatientInfo *temp = malloc(sizeof(PatientInfo));
	temp->Id = Id;
	temp->Age = Age;
	for (u8 i = 0; i < 50; i++)
	{
		if (Name[i] != '\0')
		{
			temp->Name[i] = Name[i];
		}
		else
		{
			break;
		}
	}
	for (u8 i = 0; i < 10; i++)
	{
		
		temp->Gender[i] = Gender[i];
		
	}
	temp->NextPatient = CurrentPatientInfo;
	CurrentPatientInfo = temp;
}

u8 IsPatientExist(u32 Id)
{
	/*
		isExist To ensure that this patient is not added before
	*/
	u8 IsExist = 0;
	if (CurrentPatientInfo != NULL)
	{
		PatientInfo *ptr = CurrentPatientInfo;
		if (ptr->Id == Id)
		{
			IsExist = 1;
		}

		while (ptr->NextPatient != Null)
		{
			if (ptr->Id == Id)
			{
				IsExist = 1;
				break;
			}
			ptr = ptr->NextPatient;
		}
	}
	return IsExist;
}

u8 EditPatient(u32 Id, u8 Age, u8 Name[], u8 Gender[])
{
	u8 IsComplete = 0;
	PatientInfo *ptr = CurrentPatientInfo;
	if (ptr->Id == Id)
	{
		ptr->Id = Id;
		ptr->Age = Age;
		for (u8 i = 0; i < 50; i++)
		{
			if (Name[i] != '\0')
			{
				ptr->Name[i] = Name[i];
			}
			else
			{
				break;
			}
		}
		for (u8 i = 0; i < 10; i++)
		{

			ptr->Gender[i] = Gender[i];
		
		}
		IsComplete = 1;
	}

	while (ptr->NextPatient != Null)
	{
		if (ptr->Id == Id)
		{
			ptr->Id = Id;
			ptr->Age = Age;
			for (u8 i = 0; i < 50; i++)
			{
				if (Name[i] != '\0')
				{
					ptr->Name[i] = Name[i];
				}
				else
				{
					break;
				}
			}
			for (u8 i = 0; i < 10; i++)
			{
			
				ptr->Gender[i] = Gender[i];
	
			}
			IsComplete = 1;
			break;
		}
		ptr = ptr->NextPatient;
	}

	return IsComplete;
}

/*
	This viewPatient function  View all patient which are stored by the Admin
*/
void ViewPatients(void)
{

	PatientInfo *temp = CurrentPatientInfo;
	if (temp == Null)
	{
		printf("There is No patients \n");
	}
	else

		while (temp != Null)
		{
			printf("	Patient ID is : %d", temp->Id);
			printf("\n 	Patient Name is %s", temp->Name);
			printf("\n 	Patient Age is : %d", temp->Age);
			printf("\n 	Patient gender is : %s \n", temp->Gender);
			printf("\n ------------------------------ \n");
			temp = temp->NextPatient;
		}
}

/*
	This viewPatientRecord function View all Slots which are stored by this User
	through its ID
*/
void ViewPatientRecord(void)
{
	u32 tempID;
	u8 IsFilled = 0;
	printf("\n -------------------------------------\n \n");
	printf("Please Enter the ID Which You Want to get Its Reservation :  ");
	scanf("%d", &tempID);
	printf("Your Reservations are :   \n");
	for (u8 i = 0; i < 5; i++)
	{
		if (times[i].IsReserved == tempID)
		{
			printf("   ");
			printf("%s", times[i].Times);
			printf("\n");
			IsFilled = 1;
		}
	}
	if (IsFilled == 0)
	{
		printf("\n Oh Sorry You Have Not Reserve Yet!! \n");
	}

	printf("\n -------------------------------------\n \n");
}
