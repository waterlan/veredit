module aa (a, z, in_rst, clk);
input in_rst, clk;
input a;
output z;

  an2x i0 (.A(1'b0), .B(a), .Z(z));

endmodule

module ab (a, z, in_rst, clk);
input in_rst, clk;
input a;
output z;

  an2x i0 (.A(1'b0), .B(a), .Z(z));

endmodule

module cc (a, z, in_reset, in_clock);
input in_clock, in_reset;
input a;
output z;

  an2x i0 (.A(1'b0), .B(a), .Z(z));

endmodule

