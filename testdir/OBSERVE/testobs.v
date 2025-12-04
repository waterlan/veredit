module dft_obs_ctrl_comb(Q, D, CP, HOLD);
output Q;
input  D;
input  CP;
input  HOLD;

  mx21x2pdv U1MUX ( .Z(Q), .D0(D), .D1(n1), .S0(HOLD) );
  df1qpdv   U2FF  ( .Q(n1), .D(Q), .CP(CP));

endmodule


module dft_obs_ctrl_ff(Q, D, CP, HOLD);
output Q;
input  D;
input  CP;
input  HOLD;

  mx21x2pdv U1MUX ( .Z(n1), .D0(D), .D1(Q), .S0(HOLD) );
  df1qpdv   U2FF  ( .Q(Q), .D(n1), .CP(CP) );

endmodule

module a_sub (a, b, c, d, e);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;

endmodule


module a (a, b, c, d, e);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;


 a_sub a_sub_inst ( .a(a), .b(b), .c(c), .d(d), .e(e));

endmodule



