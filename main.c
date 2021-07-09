#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "Mode.h"
#include "Patient.h"
#include "Slot.h"

enum AdminSelections
{
	View_Patients,
	Add_Patient,
	Edit_Patient,
	View_Slots,
	Reserve_Slot,
	Cancel_Slot,
	GoBack
};
enum UserSelections
{
	View_Patient_Records,
	View_Reservations
};

void main()
{
	u8 ModeNumber;
	u8 Selector;
	u8 Age;
	u8 No_of_Slot;
	u32 PatientId;
	u8 Name[50];
	u8 Gender[10];
	u8 Exit = 0;

	/*
		This Loop to make the program run untill user Close It
	*/
	while (Exit == 0)
	{
		/*
			CheckMode is a Fucntion check if who use the program is user or admin
			and return 1 if admin and 0 if user 
		*/

		/*
		Ask user to enter mode whether 0 for user or 1 for admin
		*/
		printf("\n Please Enter the Number of Mode You want if \n");
		printf("\n -------------------------------------\n \n");
		printf("	User mode Insert 	0 \n");
		printf("	Admin mode Insert 	1 \n");
		printf("\n -------------------------------------\n \n");
		printf("	Your Selection Is :  ");
		scanf("%d", &ModeNumber);

		/* Validate Entered Mode and Password */
		if (CheckMode((u8)ModeNumber) == (u8)0)
		{
			Exit = 1;
		}
		else
		{
			/*
			This mode for Admin
			*/
		
			if (ModeNumber == 1)
			{

				printf("\n View Patients:-----------------------------------0 \n");
				printf("\n Add  Patient:------------------------------------1 \n");
				printf("\n Edit Patient:------------------------------------2 \n");
				printf("\n View Valid Slots:--------------------------------3 \n");
				printf("\n Reserve A Slot:----------------------------------4 \n");
				printf("\n Cancel A Slot:-----------------------------------5 \n");
				printf("\n Go Back To Mode Choice:--------------------------6 \n");
				printf("Please Enter the number of choice You want:  	");
				scanf("%d", &Selector);

				/*
					Showing All function for Admin to choose one from them.
				*/
				switch (Selector)
				{
				case View_Patients:

					ViewPatients();

					break;

				case Add_Patient:

					printf("Please Enter The ID of Patient:  ");
					scanf("%d", &PatientId);
					printf("Please Enter The Name of Patient:  ");
					scanf(" %s", Name);
					printf("Please Enter The Age of Patient:  ");
					scanf("%d", &Age);
					printf("Please Enter The Gender of Patient:  ");
					scanf("%s", Gender);

					if (IsPatientExist(PatientId))
					{
						printf("\n This ID is Used, Adding Faild \n");
					}
					else
					{
						AddPatient(PatientId, Age, Name, Gender);
						printf("\n the Patient has been added successfully \n");
					}
					break;

				case Edit_Patient:

					printf("Please Enter The ID of Patient:  ");
					scanf("%d", &PatientId);
					printf("Please Enter The New Name of Patient:  ");
					scanf("%s", Name);
					printf("Please Enter The New Age of Patient:  ");
					scanf("%d", &Age);
					printf("Please Enter The New Gender of Patient:  ");
					scanf("%s", Gender);
					if (EditPatient(PatientId, Age, Name, Gender))
					{
						printf("\n The Info Has Been Updated Successfully \n");
					}
					else
					{
						printf("\n This ID Is Not Found \n");
					}
					break;

				case View_Slots:

					ViewReservedSlots();

					break;

				case Reserve_Slot:
					printf("These Are the Avilable Slots \n");
					ViewValidSlots();
					printf("Please Enter the Number of The Slot You want To Reserve \n");
					scanf("%d", &No_of_Slot);
					printf("Please Enter The ID of Patient \n");
					scanf("%d", &PatientId);
					if (IsPatientExist(PatientId))
					{
						ReserveSlot(No_of_Slot, PatientId);
						printf("\n Slot Has Been Reserved successfully  \n");
					}
					else
					{
						printf("\n Invalid Patient ID \n");
					}
					break;

				case Cancel_Slot:

					printf("Please Enter the Patien ID Which You Want to Cancel Its Reservation");
					scanf("%d", &PatientId);
					if (IsPatientExist(PatientId))
					{
						DeleteSlot(PatientId);
						printf("\n Slot Has Been freed successfully  \n");
					}
					else
					{
						printf("\n Invalid Patient ID \n");
					}
					break;

				case GoBack:

					printf("\nIf You want to go back  Enter -----0 \n");
					printf("If You want to Exit  Enter ----------1 \n");
					printf("Your Choice is : ");
					scanf("%d", &Exit);
					printf("\n -------------------------------------\n \n");
					break;

				default:

					Exit = 1;

					break;
				}
			}

			/*
			This Mode for User
		*/
			else if (ModeNumber == 0)

			{

				u32 Selector;
				printf("\n -------------------------------------\n \n");
				printf("	View Records :--------0 \n");
				printf("	View reservations :---1 \n");
				printf("	Please Enter the number of choice You want :");

				scanf("%d", &Selector);
				printf("\n -------------------------------------\n \n");
				switch (Selector)
				{
				case View_Patient_Records:
					ViewPatientRecord();
					break;

				case View_Reservations:
					ViewReservedSlots();
					break;

				default:

					Exit = 1;

					break;
				}
			}
			/*
			This last case if user enter any value else
		*/
			else
			{
				printf("\n -------------------------------------\n \n");
				printf("The Selection you Entered is Not Valid \n");
			}
		}
		/*
			Asking The User if he want to continue or close the program
		*/
		printf("\n If You want to go back  Enter ---0 \n");
		printf("\n If You want to Exit  Enter ------1 \n");
		printf("Your Choice is : ");
		scanf("%d",&Exit);
		printf("\n -------------------------------------\n \n");
	}
}
