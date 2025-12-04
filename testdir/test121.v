module core(clk, mtl_clk, hold_inputs, hold_outputs, clk_testshell, ssi, sso, si, so, se,
            sx, sy, sz);
input  clk;
input  mtl_clk;
input  hold_inputs;
input  hold_outputs;
input  clk_testshell;
input  [1:0] ssi;
output [1:0] sso;
input  [1:0] si;
output [1:0] so;
input [3:0] sx;
output [3:0] sy;
output sz;
input  se;
wire [1:0] ssi;
wire [1:0] sso;
wire [1:0] si;
wire [1:0] so;
wire [3:0] sx;
wire [3:0] sy;

    ip_top_b1_scan_2 x1(.clk(clk), .mtl_clk(mtl_clk),
	.he(hold_outputs), .si({si, ssi[1]}),
        .so({inscan_net_16, inscan_net_8, inscan_net_12}), .se(se));

    xxx x3(.so({so, sso[1]}), .sx({sx[3:1], ssx[0]}), .s(sx_3),
	        .sy({sy[3:1], ssy[0]}), .sz(sz));

    ip_top_b1_scan_1 x2(.clk(clk), .mtl_clk(mtl_clk),
	.he(hold_outputs), .si({inscan_net_16, inscan_net_8,
        inscan_net_12}), .so({inscan_net_17, inscan_net_9, inscan_net_13}),
        .se(se));

    core_df_wrapper_0 antiskewInst_0(.data_in(inscan_net_5),
        .data_out(sso[0]), .clock(clk_testshell));
    core_df_wrapper_0 antiskewInst_1(.data_in(inscan_net_13),
        .data_out(sso[1]), .clock(clk));
    core_df_wrapper_0 antiskewInst_2(.data_in(inscan_net_9),
        .data_out(so[0]), .clock(clk));
    core_df_wrapper_0 antiskewInst_3(.data_in(inscan_net_17),
        .data_out(so[1]), .clock(mtl_clk));

endmodule




