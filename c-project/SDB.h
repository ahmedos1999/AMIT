#ifndef		SDB_H
#define		SDB_H

#include <stdlib.h>
#include <stdio.h>


/** A Simple DataBase Struct for Students **/

typedef struct SimpleDb
{
	uint32 Student_ID;
	uint32 Student_year;
	uint32 Course1_ID;
	uint32 Course1_grade;
	uint32 Course2_ID;
	uint32 Course2_grade;
	uint32 Course3_ID;
	uint32 Course3_grade;
 
} student;

#define STUDENT_INIT \
{0, 0, 0, 0, 0, 0, 0, 0}

/** Functions' ProtoTypes **/

bool SDB_IsFull ();					/* Checks if the database is full or not. */
uint8 SDB_GetUsedSize();				/* Get how many students in your database have been added. */
bool SDB_AddEntry();					/* When the user chooses to add entry this function asks him for the 
								required data in the database to add one student. */
void SDB_DeletEntry (uint32 id);			/* Delete a student data with a given ID. */
bool SDB_ReadEntry (uint32 id);				/* Prints the data of the user by searching on his data using the given ID. */
void SDB_GetList (uint8 *count, uint32 *list);		/* It gets the number of IDs in the counter and the list  all IDs in the list array,
								that’s you get his base address. */
bool SDB_IsIdExist (uint32 id);				/* Checks if the given ID exists. */
void SDB_APP ();					/* It has a Super-Loop that will run your project until the user chooses to exit;
								 You will ask the user to choose between (0 ~ 7) options. */
void SDB_action (uint8 choice);				/* Takes the user's choice and call the coresponding function for this choice. */


#endif		/* SDB_H */
