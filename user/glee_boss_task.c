/*
 * glee_boss_task.c
 *
 *  Created on: Sep 29, 2017
 *      Author: blurryface
 */


#include "../include/glee_boss_task.h"

#include "../include/neorings_light_task.h"
#include "mailbox.h"

xTaskHandle GLEE_Init(void *pArg)
{
	xTaskHandle glee;

	xTaskCreate(GLEE_Task, "GLEE_Task", configMINIMAL_STACK_SIZE, pArg, tskIDLE_PRIORITY, glee);

	return glee;
}

void GLEE_Task(void *pArg)
{
	//task's mailbox
	Task_Mailbox mailbox;

	//init light task
	NeoRings_Init(&mailbox);

	while(1)
	{
//		printf("glee task!\n");

		vTaskDelay(100);
	}
}

