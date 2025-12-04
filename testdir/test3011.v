module BUFFER(X, A );
output X;
input  A;

endmodule

module a_sub (  Q, D, DBUS);
output Q;
input  D;
output [4:1] DBUS;

endmodule

module a ( TEST, Q, Z, Z2, T, A, B, X, II);
input TEST;
output Z;
output Z2;
output T;
output [2:5] X; 
input [15:0] Q;
input  A, B;
input  II;
     a_sub a_i0 (.Q(Q));
     a_sub a_i1 (.Q(Q));
 and2x1 inst1 (.Z(f), .A(A), .B(B));
endmodule

module b ( Q, Z, Z2, T, A, B, C, D, II);
output Z;
output Z2;
output T;
output [15:0] Q;
input  A;
input  B;
input  C;
input  D;
input  II;
endmodule

module c ( W, Z, Z2, T, A, B, C, D,X,Y,II);
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
input  II;
wire f,g,h,i,j,k,l;

 and2x1 inst1 (.Z(f), .A(A), .B(B));
 and2x1 inst2 (.Z(g), .A(f), .B(C));
 and2x1 inst3 (.Z(T), .A(f), .B(g));
 and2x1 inst4 (.Z(Z), .A(D), .B(g));
     a_sub c_i0 (.Q(Q));
     a_sub c_i1 (.Q(Q));

endmodule

module test ( X, Q, T, Z, Z2, A,B, II, \III );
output Z;
output [2:5] X;
output [15:0] Q;
output Z2;
output [1:0] T;
input  A;
input  B;
input  II;
input  \III ;
wire \AA ;
tri  \TT ;
tri0 \T0 ;
tri1 T1;
trior TOR;
triand TAND;
wor Wor;
wand WANDJE;

  assign \AA  = \TT ;
 

 a inst_a (.TEST(), .Q(Q), .Z(Z), .Z2(Z2), .T(T[1]), .A(A), .B(T[0]), .X(X), .II(II));
 b Z2_inst (.Q(Q), .Z(Q_0), .Z2(T_0), .T(T[0]), .A(Z), .B(Z2), .C(Q[1]), .D(T[1]), .II(II));
 c inst_C  (.W({Z2,T[1],T[1:0],Q[3],Q[2:0]}), .X(X[2:5]), .Y(Xx), .II(II), .III(\III ));

endmodule
