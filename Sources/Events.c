/* ###################################################################
**     Filename    : Events.c
**     Project     : bandpass filter
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-10-27, 19:22, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
int16_t x[8];
int16_t y[8];
extern uint16_t output;
int c[]={0,1,2,3,4,5,6,7,8},d[]={0,1,2,3,4,5,6,7,8};
int a[]={109,0,-436,0, 655,0, 437,0,109};
int b[]={114888, 965224,3605114,7814738,10750119,9608653,5449517,1793154};
void TI1_OnInterrupt(void)
{
	byte chan = 8;
	int n;
	uint16_t value;
	AD1_MeasureChan(TRUE, chan);
	AD1_MeasureChan(chan, &value);
	x[d[8]]=value;
	y[c[8]]=(a[0]*x[d[0]]-a[2]*x[d[2]] + a[4]*x[d[4]]-a[6]*x[d[6]]+a[d[8]]*x[d[8]]-(b[0]*y[c[0]] -b[1]*y[c[1]] + b[2]*y[c[2]] -b[3]*y[c[3]] + b[4]*y[c[4]] - b[5]*y[c[5]] +b[6]*y[c[6]] - b[7]*y[c[7]]))/262144;
    output = y[c[8]]>>4;
    for(n=0;n!=9;n++){
    	c[n]++;
    	d[n]++;
    	if(c[n]==9)c[n]=0;
    	if(d[n]==9)d[n]=0;
    }

}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
