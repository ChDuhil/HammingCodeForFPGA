#include "Correction.h"

void correct::correction()
{
	 sc_uint <15> tmpIn;
	 sc_uint <4>  s;
	 sc_uint <11> tmpOut;


	 s=(syndIn.read());
	 tmpIn=(din.read());

	 switch(s){
	 case 0:
	 // s = 0000 : Code bon
		tmpOut = tmpIn.range(0,10);
	 	break;

	 case 1 :
	 // s = 0001 : erreur sur P0
		 tmpOut = tmpIn.range(0,10);
		 break;

	 case 2 :
	 // s = 0010 :  erreur sur P1
			tmpOut = tmpIn.range(0,10);
			break;

	 case 3 :
	 // s = 0011 : erreur sur a0
			 tmpOut = tmpIn.range(0,10);
	 	 	 tmpOut[0] = ~tmpIn[0];
			 break;

	 case 4 :
	 // s = 0100 : erreur sur P2
			 tmpOut = tmpIn.range(0,10);
			 break;

	 case 5 :
	 // s = 0101 => erreur sur a1
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[1] = ~tmpIn[1];
			 break;

	 case 6 :
	 // s = 0110 => erreur sur a2
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[2] = ~tmpIn[2];
			 break;

	 case 7 :
	 // s = 0111 => erreur sur a3
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[3] = ~tmpIn[3];
			 break;


	 case 8 :
	 // s = 1000 => erreur sur P3
			 tmpOut = tmpIn.range(0,10);
			 break;

	 case 9 :
	 // s = 1001 => erreur sur a4
	 tmpOut = tmpIn.range(0,10);
			 tmpOut[4] = ~tmpIn[4];
			 break;

	 case 10 :
	 // s = 1010 => erreur sur a5
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[5] = ~tmpIn[5];
			 break;

	 case 11 :
	 // s = 1011 => erreur sur a6
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[6] = ~tmpIn[6];
			 break;


	 case 12 :
	 // s = 1100 => erreur sur a7
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[7] = ~tmpIn[7];
			 break;

	 case 13 :
	 // s = 1101 => erreur sur a8
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[8] = ~tmpIn[8];
			 break;


	 case 14 :
	 // s = 1110 => erreur sur a9
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[9] = ~tmpIn[9];
			 break;


	 case 15 :
	 // s = 1111 => erreur sur a10
			 tmpOut = tmpIn.range(0,10);
			 tmpOut[10] = ~tmpIn[10];
			 break;

	 }

	// Ecriture du mot sur le port de sortie.
	 dout.write(tmpOut);
}
