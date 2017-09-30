/*
 * glee_boss_task.h
 *
 *  Created on: Sep 29, 2017
 *      Author: blurryface
 */

#ifndef INCLUDE_GLEE_BOSS_TASK_H_
#define INCLUDE_GLEE_BOSS_TASK_H_

#include "esp_common.h"
#include "freertos/FreeRTOS.h"

//-----------------------------------------------------------------------



//-----------------------------------------------------------------------

/*
 *@brief	init glee (boss) task
 *@param	pArg:	this will be passed to glee task (glee_Task) as a argument
 *@return
 *	- glee handler (task handler)
 */
xTaskHandle GLEE_Init(void *pArg);

/*
 *@brief	main glee task
 *@param	pArg:	argument for handler stuff (optional)
 */
void GLEE_Task(void *pArg);

#endif /* INCLUDE_GLEE_BOSS_TASK_H_ */
