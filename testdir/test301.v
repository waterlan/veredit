
module a (a, z);
input a ;
output z ;

endmodule

module b (a, z);
input a ;
output z ;

endmodule

module c (a, z);
input [1:0] a;
output [1:0] z;


  a i1 (.z(z[0]), .a(a[0]));

endmodule

