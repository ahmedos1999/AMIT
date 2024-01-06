#include "STD.h"
#include "SDB.h"

static uint8 choice = 0;
static uint8 EXIT = 0;

/**
 * SDB_action - Calls the Coresponding Function for the User's Choice.
 * @choice: The User Input, Represents the function No..
 * 
 **/ 

void SDB_action(uint8 choice)
{
	uint32 id = 0;

	switch (choice)
	{
		case 0:
		{
			EXIT = 1;
			printf("\nExiting Program...\n\t\tThank You For Using The Program\n");
			break;
		}
		case 1:
		{
			static uint32 size = 0;
			bool check = false;


			if (size < 3)
			{
				printf("\n***At Least 3 Students' Data will be Entered ***\n");	
				while ((size = SDB_GetUsedSize()) < 3)
				{
					check = SDB_AddEntry();
				}
			}
			else
				check = SDB_AddEntry();
			if (check == true)
				printf("\tData Added Successfully.\n");
			else
				printf("\tCouldn't Add Data.\n");
			break;
		}
		case 2:
		{
			printf("\nThe Number of Students in The DataBase : %d\n", SDB_GetUsedSize());
			break;
		}
		case 3:
		{
			printf("\nEnter the Student's ID to get his Data : ");
			scanf("%d", &id);
			while (getchar() != '\n');
			SDB_ReadEntry(id);
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			printf("\nEnter The ID to be Searched :");
			scanf(" %d",&id);
			while (getchar() != '\n');
			if (SDB_IsIdExist(id))
				printf("\tID Found : %d\n",id);
			else
				printf("\t**ID Not Found.**\n");
			break;
		}
		case 6:
		{
			printf("\nEnter the student's ID to Delete his Data : ");
			scanf("%d", &id);

			while (getchar() != '\n');
			SDB_DeletEntry(id);
			break;
		}
		case 7:
		{

			if (SDB_IsFull () == true)
				printf("\tDataBase is Full.\n");
			else
				printf("\tDataBase isn't Full, Can Add more Data.\n");
			break;
		}
	}
}



/**
 * SDB_APP - The Super Loop to Run the Program with 8 Choices (0 ~ 7)
 * 	I-Add Entry :					1
 * 	II-Used Data Size :				2
 * 	III-Read a specific Student's Data :		3
 * 	IV-A List of All Students' IDs :		4
 * 	V -Check a Specific ID :			5
 * 	VI-Delete a Student Data :			6
 * 	VII-Check if DataBase is Full:			7
 * 	VIII-Exit Program :				0
 *
 **/

void SDB_APP (void)
{

	printf("\n\t\t*** Welcome to Students DataBase ***\n\n");
	while (EXIT == 0)
	{
		printf("\nEnter Your Choice (0 ~ 7)\n");
		printf("\nI    - Add Entry : 				1");
		printf("\nII   - Used Data Size : 			2");
		printf("\nIII  - Read a specific Student's Data : 	3");
		printf("\nIV   - A List of All Students' IDs : 		4");
		printf("\nV    - Check a Specific ID : 			5");
		printf("\nVI   - Delete a Student Data :\t		6");
		printf("\nVII  - Check if DataBase is Full : 		7");
		printf("\nVIII - Exit Program :\t			0\n");

		scanf("%d", &choice);
		while (getchar() != '\n')
			continue;
		/* if ((choice != 0) ||(choice != 1) ||(choice != 2) ||(choice != 3)\
			||(choice != 4) ||(choice != 5) ||(choice != 6) ||(choice != 7)) */
		if (choice < 0 || choice > 7)
			printf("\n*** Enter a Valid Choice. ***\n");
		SDB_action(choice);
	}
}
