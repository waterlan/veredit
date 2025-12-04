module bfx1 (A, Z);
input A;
output Z;

endmodule

module bfx2 (A, Z);
input A;
output Z;

endmodule

module bfx3 (A, Z);
input A;
output Z;

endmodule

module bfx4 (A, Z);
input A;
output Z;

   assign Z = A;
endmodule

module bufx4 (A, Z);
input A;
output Z;

   assign Z = A;
endmodule

module MODULE (END, INPUT, OTHER, NET, .a({a, b, c}), d, e );
input [4:0] END ;
wire  [4:0] END ;
input INPUT ;
output OTHER ;
output [2:1] NET;
output a, b, c;
inout [12:0] d, e;
wire [12:0] d, e;
wire g, h;
wire [9:0] i;

	initial $diesel("../diesel/diesel.cmd");

	initial_cell	ic_0 (.A(1'b0), .Z(notconnected));
	cell_initial	ic_1 (.A(1'b0), .Z(notconnected));

initial_cell
ic_01 (.A(1'b0), .Z(notconnected));
cell_initial
ic_11(.A(1'b0), .Z(notconnected));
initial
$diesel("../diesel/diesel.cmd");

   TIECELL NETS(.Z(1'b1), .X({g,h,i}));
	insta   i0 (.OUTPUT(NET),
	        .DELASSIGN(ASSIGN),
			  .ADDINST(MODULE),
	        .BUFFEROUTPUTS(BUFFER),
			  .INSERTOBSINPUT(times),
			  .z1(c),
			  .z2(p),
			  .INSERTOBSOUTPUT(LISTINST),
			  .INSTANCE(DELETE), .X({g,h,i}), .END(END)
			  );
	

	initial_cell ic_2 (.A(1'b0), .Z(notconnected));
	cell_initial ic_3 (.A(1'b0), .Z(notconnected));

	initial $diesel("../diesel/diesel.cmd");

endmodule


