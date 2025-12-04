module aa (a, b);
parameter x = 1;
parameter y = 2;
input a;
output b;
endmodule

module bb (a, b);
parameter x = 1;
parameter y = 2;
input a;
output b;
endmodule



module cc( clk, rst, 
      out_irq
       );
parameter cell_id = 1 ;
input clk;
input rst;
output out_irq;

endmodule

