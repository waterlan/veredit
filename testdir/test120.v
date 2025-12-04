`uselib file=/p/lib/corelib/1.3/tools/verilog/corelib.v
`timescale 1ns / 10ps

`include "fifo_all.v"

module clkbuf ( clkin, clkout );
input clkin ;
output clkout ;

   INV inv1 (.A(clkin), .Z(clk_tmp1));
   INV inv2 (.A(clk_tmp1), .Z(clk_tmp2));
   INV inv3 (.A(clk_tmp2), .Z(clk_tmp3));
   INV inv4 (.A(clk_tmp3), .Z(clkout));

endmodule


module MACRO_MT1( clk, aap, banaan, appel,mmmm, ui );
input clk;
input aap;
output [2:0] banaan;
inout ui;
assign a = b;
assign c = d;
output [2:0] appel, mmmm;
wire [2:0] banaan, appel, boot;

endmodule


module MACRO_MT2( clk, aap, banaan, appel );
input clk;
input aap;
output [2:0] banaan;
output  appel;
wire [2:0] weg, banaan, huis;
assign a = b;
wire tak, appel, boot;
wire b = 1;
wire [2:0] a = "111";
wire e, f ;


assign c = b;
assign d = b;


  cella a_inst (.clk(clk), .aap(aap), .appel(appel), .banaan(banaan), .\a ());
  cellb b_inst (.clk(clk), .aap(aap), .appel(appel), .banaan(banaan));
  celld d_inst (.clk(clk), .aap(aap), .appel(appel), .banaan(banaan));

  defparam a_inst.i0_inst.mem_inst.preloadMem = "mem0.init";
  defparam a_inst.i1_inst.mem_inst.preloadMem = "mem1.init";

endmodule

