
#include "reg.h"

void shift::shifter()
{
	 sc_uint <15> tmp;

	 tmp[5] = ~tmp[5]; // def dsur bit N°5

	  tmp= (din.read());

	dout.write(tmp);
}

