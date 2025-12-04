module buffer(Z, A );
output Z;
input  A;

endmodule


module a_sub (a, b, c, d, e);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;

endmodule


module b_sub (a, b, c, d, e, f);
input [3:0] a;
input b;
input c;
input [2:0] d;
input [1:0] e;
output [1:0] f;

endmodule


module a (a, b, c, d, e, f);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;
output [1:0] f;
wire [2:0] d;
wire [1:0] e;


 a_sub a_sub_inst ( .a(a), .b(b), .c(c), .d(d), .e(e));
 b_sub b_sub_inst ( .a(a), .b(b), .c(c), .d(d), .e(e), .f(f));

endmodule



