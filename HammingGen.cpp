#include "HammingGen.h"

void gen::generator()
{
	 sc_uint <11> tmp;
	 sc_uint <15> hamWord;
	 sc_int <1> p1, p2, p3, p4;



	 tmp= (din.read());


	 // Configuration des bits de parités
	 p1 = tmp[0]^tmp[1]^tmp[3]^tmp[4]^tmp[6]^tmp[8]^tmp[10];
	 p2 = tmp[0]^tmp[2]^tmp[3]^tmp[5]^tmp[6]^tmp[9]^tmp[11];
	 p3 = tmp[1]^tmp[2]^tmp[3]^tmp[7]^tmp[8]^tmp[9]^tmp[12];
	 p4 = tmp[4]^tmp[5]^tmp[6]^tmp[7]^tmp[8]^tmp[9]^tmp[13];

	 hamWord = tmp;// recopie du mot à transmetre

	 // mise en place des bits de parités
	 hamWord[11]=p1;
	 hamWord[12]=p2;
	 hamWord[13]=p3;
	 hamWord[14]=p4;

	// Ecriture du mot sur le port de sortie.
	dout.write(hamWord);
}
