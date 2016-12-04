#include "systemc.h"

SC_MODULE(correct)
{
  //Ports
  sc_in <sc_logic> clk;
  sc_in < sc_uint<15> > din;
  sc_in < sc_uint<4> > syndIn;
  sc_out < sc_uint<11> > dout;


  //processus principal
  void correction();

  //constructeur
  SC_CTOR(correct)
    {SC_METHOD(correction);
    sensitive << clk.pos();
    }
};
