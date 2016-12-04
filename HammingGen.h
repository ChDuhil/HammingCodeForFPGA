#include "systemc.h"

SC_MODULE(gen)
{
  //Ports
  sc_in <sc_logic> clk;
  sc_in < sc_uint<11> > din;
  sc_out < sc_uint<15> > dout;


  //processus principal
  void generator();

  //constructeur
  SC_CTOR(gen)
    {SC_METHOD(generator);
    sensitive << clk.pos();
    }

};
