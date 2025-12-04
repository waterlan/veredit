module BUFFER(X, A );
output X;
input  A;

endmodule

module a ( TEST, Q, Z, Z2, T, A, B, X);
input TEST;
output Z;
output Z2;
output T;
output [2:5] X; 
input [15:0] Q;
input  A;
input  B;

endmodule

module b ( Q, Z, Z2, T, A, B, C, D);
output Z;
output Z2;
output T;
output [15:0] Q;
input  A;
input  B;
input  C;
input  D;
endmodule

module c ( W, Z, Z2, T, A, B, C, D,X,Y);
output Z;
output Z2;
output T;
input [7:0] W;
input [2:5] X;
input [2:5] Y;
input  A;
input  B;
input  C;
input  D;
wire f,g,h,i,j,k,l;

 and2x1 inst1 (.Z(f), .A(A), .B(B));
 and2x1 inst2 (.Z(g), .A(f), .B(C));
 and2x1 inst3 (.Z(T), .A(f), .B(g));
 and2x1 inst4 (.Z(Z), .A(D), .B(g));

endmodule

module test ( X, Q, T, Z, Z2, A,B);
output Z;
output [2:5] X;
output [15:0] Q;
output Z2;
output [1:0] T;
input  A;
input  B;

 a inst_a (.TEST(), .Q(Q), .Z(Z), .Z2(Z2), .T(T[1]), .A(A), .B(T[0]), .X(X));
 b Z2_inst (.Q(Q), .Z(Q_0), .Z2(T_0), .T(T[0]), .A(Z), .B(Z2), .C(Q[1]), .D(T[1]));
 c inst_C  (.W({Z2,T[1],T[1:0],Q[3],Q[2:0]}), .X(X[2:5]), .Y(Xx));

endmodule
