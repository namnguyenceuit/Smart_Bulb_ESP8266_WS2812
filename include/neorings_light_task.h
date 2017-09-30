/*
 * neorings_light_task.h
 *
 *  Created on: Sep 29, 2017
 *      Author: blurryface
 */

#ifndef INCLUDE_NEORINGS_LIGHT_TASK_H_
#define INCLUDE_NEORINGS_LIGHT_TASK_H_

#include "esp_common.h"
#include "freertos/FreeRTOS.h"

#include "mailbox.h"

/*
 *@brief	init neorings (light) task
 *@param	pArg:	this will be passed to neorings task (neorings_Task) as a argument
 *@return
 *	- neorings handler (task handler)
 */
xTaskHandle NeoRings_Init(void *pArg);

/*
 *@brief	main neorings task
 *@param	pArg:	argument for handler stuff (optional)
 */
void NeoRings_Task(void *pArg);

/*
 * @brief	copy light
 * @param	light1:		destination of copy
 * @param	light2:		source of copy
 */
void NeoRings_CopyLight(Task_Mailbox_NeoRings* light1, Task_Mailbox_NeoRings* light2);

/*
 * @brief	compare two light
 * @param	light1:		light to compare
 * @param	light2:		light to compare
 * @return	true if two light is different
 */
bool NeoRings_Light_isDiff(Task_Mailbox_NeoRings* light1,
		Task_Mailbox_NeoRings* light2);

/*
 * @brief	update light
 * @param	light to update (array of 6 element)
 * 			- exp: [red, green, blue, white, brightness]
 */
void NeoRings_UpdateLight(Task_Mailbox_NeoRings* light);

#endif /* INCLUDE_NEORINGS_LIGHT_TASK_H_ */
