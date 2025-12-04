module top (a, b, c, d);
input a;
input b;
output c;
output d;


   module_a inst_1 (.z(c), .a(a));
   module_b inst_2 (.z(d), .a(b));

endmodule

