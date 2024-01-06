#include "STD.h"
#include "SDB.h"

extern student st_db[];
uint32 num = 0;
uint32 inx ;
int32 i = 0, j = 0;
int32 history[5] = {111, 111, 111, 111, 111};


/**
 * SDB_IsFull - Checks if the database is full or not.
 *
 * Return : if the DataBase is full return (true), else return (false).
 **/
bool SDB_IsFull (void)
{
	if (num == 10)
		return (true);
	else
		return (false);
}


/**
 * SDB_GetUsedSize - get how many students in the database that have been added.
 *
 * Return: Return the number of students in the database.
 **/
uint8 SDB_GetUsedSize(void)
{
	uint8 len = num;
	return (len);
}


/**
 * SDB_AddEntry - Adds a New Student Data to the DataBase.
 *
 * Retrun : True / 1 for Successfull Entery , False / 0 for Error in Entery.
 **/
bool SDB_AddEntry(void)
{

	if (SDB_IsFull() == true)
	{
		return (false);
	}
	if (history[0] != 111)
	{
		inx = history[--j];
	}
	printf("\nEnter Student Data : Slot No.%d\n", inx + 1);

	printf("\nEnter Student ID : ");
	scanf("%d", &st_db[inx].Student_ID);

	printf("\nEnter Student Year : ");
	scanf("%d", &st_db[inx].Student_year);

	printf("\nEnter Course 1 ID : ");
	scanf("%d", &st_db[inx].Course1_ID);

	printf("\nEnter Course 1 Grade : ");
	scanf("%d", &st_db[inx].Course1_grade);

	printf("\nEnter Course 2 ID : ");
	scanf("%d", &st_db[inx].Course2_ID);

	printf("\nEnter Course 2 Grade : ");
	scanf("%d", &st_db[inx].Course2_grade);

	printf("\nEnter Course 3 ID : ");
	scanf("%d", &st_db[inx].Course3_ID);

	printf("\nEnter Course 3 Grade : ");
	scanf("%d", &st_db[inx].Course3_grade);
	while (getchar() != '\n')
	{
		continue;
	}

	if (num < 10)
		num++;
	if (history[j] != 111)
		history[j] = 111;
	if (history[0] == 111)
		inx = num;

	return (true);
}


/**
 * SDB_DeletEntry - Deletes Student Data with a Given ID
 * @id: The ID of the Student to Delete his Data
 *
 **/
void SDB_DeletEntry(uint32 id)
{
	for (i = 0; i < num; i++)
	{
		if (st_db[i].Student_ID == id)
		{
			st_db[i].Student_ID = 0;
			st_db[i].Student_year = 0;
			st_db[i].Course1_ID = 0;
			st_db[i].Course1_grade = 0;
			st_db[i].Course2_ID = 0;
			st_db[i].Course2_grade = 0;
			st_db[i].Course3_ID = 0;
			st_db[i].Course3_grade = 0;
			break;
		}
	}
	history[j++] = i;
	num--;
}


/**
 * SDB_ReadEntry - Reads Student Data with a Given ID
 * @id: the ID of the student to show his Data
 * Return: True / 1 if the ID exists, Flase / 0 if it doesn't exist
 **/
bool SDB_ReadEntry(uint32 id)
{
	for (i = 0; i < num; i++)
	{
		if (st_db[i].Student_ID == id)
		{
			printf("\nStuden Data in Slot No.%d\n", i);
			printf("\nStudent ID    : %d", st_db[i].Student_ID);
			printf("\nStudent Year  : %d", st_db[i].Student_year);
			printf("\nCourse1 ID    : %d", st_db[i].Course1_ID);
			printf("\nCourse1 Grade : %d", st_db[i].Course1_grade);
			printf("\nCourse2 ID    : %d", st_db[i].Course2_ID);
			printf("\nCourse2 Grade : %d", st_db[i].Course2_grade);
			printf("\nCourse3 ID    : %d", st_db[i].Course3_ID);
			printf("\nCourse3 Grade : %d", st_db[i].Course3_grade);

			return (true);
		}
	}
	if (i == num)
		return (false);
}


/**
 * SDB_GetList -
 *
 *
 **/
void SDB_GetList(uint8 * count, uint32 * list)
{
}


/**
 * SDB_IsIdExist -  Checks if the given ID exists
 * @id: the ID of the student to be checked
 * Return: True / 1 if the ID exists, Flase / 0 if it doesn't exist
 **/
bool SDB_IsIdExist(uint32 id)
{
	for (i = 0; i < num; i++)
	{
		if (st_db[i].Student_ID == id)
		{
			printf("\nSlot No.%d\n", i);
			return (true);
		}
	}
	if (i == num)
		return (false);
}
