module buffer (z, a);
output z;
input a;

endmodule

module a_sub (a, b, c, d, e, rst_n, se, si);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;
input rst_n;

  buffer buf_inst0(.z(c), .a(1'b1));
  buffer buf_inst1(.z(d[2]), .a(1'b1));
  buffer buf_inst2(.z(d[1]), .a(1'b1));
  buffer buf_inst3(.z(d[0]), .a(1'b0));
  buffer buf_inst4(.z(e[1]), .a(1'b1));
  buffer buf_inst5(.z(e[0]), .a(1'b0));


endmodule


module a (a, b, c, d, e, rst_n, se);
input [3:0] a;
input b;
output c;
output [2:0] d;
output [1:0] e;
input rst_n;
input se;


 a_sub a_sub_inst ( .a({1'b0, 1'b1}), .b(1'b1), .c(c), .d(d), .e(e), .rst_n(rst_n), .se(se), .si(1'b0));

endmodule



