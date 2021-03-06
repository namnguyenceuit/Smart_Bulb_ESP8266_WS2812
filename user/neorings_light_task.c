/*
 * neorings_light_task.c
 *
 *  Created on: Sep 29, 2017
 *      Author: blurryface
 */

#include "../include/neorings_light_task.h"
#include "esp8266_arduino_ws2812.h"



xTaskHandle NeoRings_Init(void *pArg)
{
	xTaskHandle neorings;

	xTaskCreate(NeoRings_Task, "NeoRings_Task", configMINIMAL_STACK_SIZE*2, pArg, tskIDLE_PRIORITY, neorings);

	return neorings;
}

void NeoRings_Task(void *pArg)
{
	WS2812_Init(12, 4, NEO_GRB + NEO_KHZ800);
	WS2812_Begin();
	int i = 0;
	int j = 0;
	Task_Mailbox* mailbox;
	mailbox = (Task_Mailbox*) pArg;
	mailbox->neorings[0] = 255, 	//Brightness
	//mailbox->neorings[1] = 0,		//White
	mailbox->neorings[1] = 255,		//Blue
	mailbox->neorings[2] = 255,		//Green
	mailbox->neorings[3] = 255,		//Red
		//analyze light data
		//light: red green blue white brightness
	WS2812_SetBrightness(mailbox->neorings[0]);
	for(i=0; i<12; i++)
	{
		// Moderately bright green color.
		WS2812_SetPixelColor(i, mailbox->neorings[3], mailbox->neorings[2], mailbox->neorings[1], 0);
		//WS2812_SetPixelColor(i, light[3], light[2], light[1], 0);
		WS2812_Show();
	}
}
/*
void NeoRings_Task(void *pArg)
{
	//task's mailbox
	Task_Mailbox* mailbox;
	//light data
	Task_Mailbox_NeoRings oldLightData[4];

	//get the task's mailbox
	mailbox = (Task_Mailbox*)pArg;

	//init ws2812
	WS2812_Init(12, 4, NEO_GRB + NEO_KHZ800);
	WS2812_Begin();

	//light up first
	mailbox->neorings[0] = 15, 	//Brightness
	//mailbox->neorings[1] = 0,		//White
	mailbox->neorings[1] = 179,		//Blue
	mailbox->neorings[2] = 52,		//Green
	mailbox->neorings[3] = 255,		//Red
	//mailbox->neorings[5] = 0;		//fix

	//255 52 179

	NeoRings_UpdateLight(mailbox->neorings);
	NeoRings_CopyLight(oldLightData, mailbox->neorings);

	while(1)
	{
		if(NeoRings_Light_isDiff(oldLightData, mailbox->neorings))
		{
			NeoRings_UpdateLight(mailbox->neorings);

//			oldLightData = mailbox->neorings;
			NeoRings_CopyLight(oldLightData, mailbox->neorings);
		}

		vTaskDelay(10);
	}
}

void NeoRings_CopyLight(Task_Mailbox_NeoRings* light1, Task_Mailbox_NeoRings* light2)
{
	int i = 0;
	for(i = 0; i < 6; i++)
		light1[i] = light2[i];
}

bool NeoRings_Light_isDiff(Task_Mailbox_NeoRings* light1, Task_Mailbox_NeoRings* light2)
{
	int i = 0;
	for(i = 0; i < 6; i++)
		if(light1[i] != light2[i])
			return true;

	return false;
} */
/*
void NeoRings_UpdateLight(Task_Mailbox_NeoRings* light)
{

	//for loop
	int i = 0;
	int j = 0;
	Task_Mailbox* mailbox;
	mailbox = (Task_Mailbox*) pArg;
	mailbox->neorings[0] = 255, 	//Brightness
	//mailbox->neorings[1] = 0,		//White
	mailbox->neorings[1] = 0,		//Blue
	mailbox->neorings[2] = 255,		//Green
	mailbox->neorings[3] = 0,		//Red
	//analyze light data
	//light: red green blue white brightness
	WS2812_SetBrightness(mailbox->neorings[0]);
	for(i=0; i<12; i++)
	{
		// Moderately bright green color.
		WS2812_SetPixelColor(i, mailbox->neorings[3], mailbox->neorings[2], mailbox->neorings[1], 0);
		//WS2812_SetPixelColor(i, light[3], light[2], light[1], 0);
		WS2812_Show();
	}
	// This sends the updated pixel color to the hardware.

} */
