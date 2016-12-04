#include "systemc.h"

SC_MODULE(synd)
{
  //Ports
  sc_in <sc_logic> clk;
  sc_in < sc_uint<15> > din;
  sc_out < sc_uint<4> > dout;


  //processus principal
  void syndrome();

  //constructeur
  SC_CTOR(synd)
    {SC_METHOD(syndrome);
    sensitive << clk.pos();
    }

};
