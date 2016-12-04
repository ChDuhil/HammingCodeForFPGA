#include "syndrome.h"

void synd::syndrome()
{
	 sc_uint <15> tmp;
	 sc_uint <4> s;



	 tmp= (din.read());


	 // Configuration des bits de parités
	 s[0] = tmp[0]^tmp[1]^tmp[3]^tmp[4]^tmp[6]^tmp[8]^tmp[10]^tmp[11];
	 s[1] = tmp[0]^tmp[2]^tmp[3]^tmp[5]^tmp[6]^tmp[9]^tmp[10]^tmp[12];
	 s[2] = tmp[1]^tmp[2]^tmp[3]^tmp[7]^tmp[8]^tmp[9]^tmp[10]^tmp[13];
	 s[3] = tmp[4]^tmp[5]^tmp[6]^tmp[7]^tmp[8]^tmp[9]^tmp[10]^tmp[14];



	// Ecriture du mot sur le port de sortie.
	dout.write(s);
}
