#include "systemc.h"
#include "testbenchreg.h"
#include "reg.h"
#include "Correction.h"
#include "syndrome.h"
#include "HammingGen.h"



int sc_main(int argc, char *argv[])
{

  sc_signal <sc_logic> clk;
  sc_signal < sc_uint<11> > in, out;
  sc_signal < sc_uint<15> > hamOut, regOut;
  sc_signal < sc_uint<4> > syndOut;
 

  gen HammingGen("HammingGen");
  shift reg("reg");
  synd Syndrome("Syndrome");
  correct Correction("Correction");

  HammingGen.clk(clk);
  HammingGen.din(in);
  HammingGen.dout(hamOut);

  reg.clk(clk);
  reg.din(hamOut);
  reg.dout(regOut);

  Syndrome.clk(clk);
  Syndrome.din(regOut);
  Syndrome.dout(syndOut);

 Correction.clk(clk);
 Correction.din(hamOut);
 Correction.syndIn(syndOut);
 Correction.dout(out);


  testbenchreg test("test");
  test.clk(clk);
  test.din(in);
  test.dout(out);

  sc_start();
  return 0;
 

}



