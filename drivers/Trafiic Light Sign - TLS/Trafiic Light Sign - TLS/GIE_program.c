
/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_State.h"

/* GIE.h*/
#include "GIE_register.h"
#include "GIE_private.h"
#include "GIE_config.h"
#include "GIE_interface.h"

void GIE_Enable(void)
{
	SET_BIT(GIE_SREG, I);
}

void GIE_Disable(void)
{
	CLR_BIT(GIE_SREG, I);
}