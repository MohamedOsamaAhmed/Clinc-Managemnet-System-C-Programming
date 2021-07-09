#ifndef _PATIENT_H_
#define _PATIENT_H_
typedef struct Patient
{
	u32 Id;
	u8 Age;
	u8 Name[50];
	u8 Gender[10];
	struct Patient * NextPatient;
	
}PatientInfo;
void AddPatient(u32 Id,u8 Age,u8 Name[], u8 Gender[]);
u8 EditPatient(u32 Id,u8 Age,u8 Name[],u8 Gender[]);
u8 IsPatientExist(u32 Id);
void ViewPatients(void);
void ViewPatientRecord(void);

#endif