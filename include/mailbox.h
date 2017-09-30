/*
 * mailbox.h
 *
 *  Created on: Sep 29, 2017
 *      Author: blurryface
 */

#ifndef INCLUDE_MAILBOX_H_
#define INCLUDE_MAILBOX_H_

#include "esp_common.h"

//-----------------------------------------------------------------------

/*
 * @brief	each task mail box data type
 */
typedef uint16_t Task_Mailbox_Sneaky;
typedef uint16_t Task_Mailbox_GLEE;
typedef uint8_t Task_Mailbox_NeoRings;

/*
 * @brief	task's mailbox
 */
typedef struct TASK_MAILBOX
{
	Task_Mailbox_Sneaky sneaky;				/*!< sneaky mailbox */
	Task_Mailbox_GLEE glee;					/*!< glee mailbox */
	//TODO	improve this shitty communication style
	Task_Mailbox_NeoRings neorings[5];			/*!< neorings mailbox */
} Task_Mailbox;

//-----------------------------------------------------------------------



#endif /* INCLUDE_MAILBOX_H_ */
