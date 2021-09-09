/*
 * functions.c
 *
 *  Created on: Sep 7, 2021
 *      Author: AhmedAlaa
 */
#include <stdio.h>
#include "functions.h"

FLAG ask_for_engine_state(ENGINE_STATE *state){
	/* User Interface */
	printf("Please, Choose just one option [a - b - c]\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	printf("Enter the character of choice: ");

	// Ask for user's choice
	char choice;
	scanf("%c", &choice);

	/* States flow */
	if ((choice == 'a') || (choice == 'A'))
	{
		*state = ON;
		return SUCCEED;
	}
	else if ((choice == 'b') || (choice == 'B'))
	{
		*state = OFF;
		return SUCCEED;
	}
	else if ((choice == 'c') || (choice == 'C'))
	{
		*state = -1;
		return EXIT;
	}
	else
	{
		*state = -1;
		return FAILED;
	}
}


FLAG repeat_until_succeed_or_exit(ENGINE_STATE *state)
{
	ERROR404();
	FLAG stage = FAILED;
	char choice;

	// Ask for user's choice
	do
	{
		printf("Enter again the character of choice: ");
		scanf("%c", &choice);

		/* States flow */
		if ((choice == 'a') || (choice == 'A'))
		{
			*state = ON;
			stage = SUCCEED;
		}
		else if ((choice == 'b') || (choice == 'B'))
		{
			*state = OFF;
			stage = SUCCEED;
		}
		else if ((choice == 'c') || (choice == 'C'))
		{
			*state = -1;
			stage = EXIT;
		}
		else
		{
			*state = -1;
			stage = FAILED;
		}

	} while(stage == FAILED);


	return stage;
}
