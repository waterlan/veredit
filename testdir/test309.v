module a ( clk, rst, in_start,
      in_wr_data_I0, in_wr_valid_I0, in_rd_accept_I0,
      in_aaaa_cs_I0, in_aaaa_we_n_I0, in_aaaa_addr_I0, in_aaaa_type_I0,
      in_aaaa_wdata_I0, in_aaaa_wmask_I0, in_bbbb_sel_I1, in_bbbb_addr_I1,
      in_bbbb_write_I1, in_bbbb_trans_I1,
      in_bbbb_wdata_I1, out_wr_accept_I0, out_rd_data_I0,
      out_rd_valid_I0, out_aaaa_rdata_I0, out_aaaa_run_I0,
      out_bbbb_rdata_I1, out_bbbb_resp_I1, out_irq );
input [0:0] in_wr_data_I0;
input [31:0] in_aaaa_addr_I0;
input [1:0] in_aaaa_type_I0;
input [31:0] in_aaaa_wdata_I0, in_bbbb_addr_I1;
input [3:0] in_aaaa_wmask_I0;
input [1:0] in_bbbb_trans_I1;
input [31:0] in_bbbb_wdata_I1;
output [0:0] out_rd_data_I0;
output [31:0] out_aaaa_rdata_I0;
output [31:0] out_bbbb_rdata_I1;
output [1:0] out_bbbb_resp_I1;
input clk, rst, in_start, in_wr_valid_I0, 
   in_rd_accept_I0, in_aaaa_cs_I0, in_aaaa_we_n_I0, in_bbbb_sel_I1, 
   in_bbbb_write_I1;
output out_wr_accept_I0, out_rd_valid_I0, out_aaaa_run_I0, 
   out_irq;
wire n43, n44, UNCONNECTED_1, UNCONNECTED_2, 
   UNCONNECTED_3, UNCONNECTED_4, UNCONNECTED_5, 
   UNCONNECTED_6, UNCONNECTED_7, UNCONNECTED_8, 
   UNCONNECTED_9, UNCONNECTED_10, UNCONNECTED_11, 
   UNCONNECTED_12, UNCONNECTED_13, UNCONNECTED_14, 
   UNCONNECTED_15, UNCONNECTED_16, UNCONNECTED_17, 
   UNCONNECTED_18, UNCONNECTED_19, UNCONNECTED_20, 
   UNCONNECTED_21, UNCONNECTED_22, UNCONNECTED_23, 
   UNCONNECTED_24, UNCONNECTED_25, UNCONNECTED_26, 
   UNCONNECTED_27, UNCONNECTED_28, UNCONNECTED_29, 
   UNCONNECTED_30, UNCONNECTED_31, UNCONNECTED_32, 
   UNCONNECTED_33, UNCONNECTED_34, UNCONNECTED_35, 
   UNCONNECTED_36, UNCONNECTED_37, UNCONNECTED_38, 
   UNCONNECTED_39, UNCONNECTED_40, UNCONNECTED_41, 
   UNCONNECTED_42, UNCONNECTED_43,
   UNCONNECTED_45, UNCONNECTED_46;

wire [31:0] in_aaaa_wdata_I0, in_bbbb_addr_I1;
wire [3:0] in_aaaa_wmask_I0;
wire [1:0] in_bbbb_trans_I1;

   b i0_b ( .clk(clk), .rst(n44),
      .in_start(in_start),
      .in_wr_data_I0(n43), .in_wr_valid_I0(in_wr_valid_I0),
      .in_rd_accept_I0(in_rd_accept_I0), .in_aaaa_cs_I0(in_aaaa_cs_I0),
      .in_aaaa_we_n_I0(in_aaaa_we_n_I0), .in_aaaa_addr_I0({ UNCONNECTED_1,
      UNCONNECTED_2, UNCONNECTED_3, UNCONNECTED_4,
      UNCONNECTED_5, UNCONNECTED_6, UNCONNECTED_7,
      UNCONNECTED_8, UNCONNECTED_9, UNCONNECTED_10,
      UNCONNECTED_11, UNCONNECTED_12, in_aaaa_addr_I0[19:2],
      UNCONNECTED_13, UNCONNECTED_14 }), .in_aaaa_type_I0({ UNCONNECTED_15,
      UNCONNECTED_16 }), .in_aaaa_wdata_I0(in_aaaa_wdata_I0),
      .in_aaaa_wmask_I0(in_aaaa_wmask_I0), .in_bbbb_sel_I1(in_bbbb_sel_I1),
      .in_bbbb_addr_I1({ UNCONNECTED_17, UNCONNECTED_18,
      UNCONNECTED_19, UNCONNECTED_20,
      UNCONNECTED_21, UNCONNECTED_22,
      UNCONNECTED_23, UNCONNECTED_24,
      UNCONNECTED_25, UNCONNECTED_26,
      UNCONNECTED_27, UNCONNECTED_28,
      UNCONNECTED_29, UNCONNECTED_30,
      UNCONNECTED_31, UNCONNECTED_32,
      UNCONNECTED_33, UNCONNECTED_34,
      UNCONNECTED_35, UNCONNECTED_36,
      UNCONNECTED_37, UNCONNECTED_38,
      UNCONNECTED_39, UNCONNECTED_40,
      UNCONNECTED_41, UNCONNECTED_42,
      UNCONNECTED_43, in_bbbb_addr_I1[4:0] }), .in_bbbb_write_I1(in_bbbb_write_I1),
      .in_bbbb_trans_I1(in_bbbb_trans_I1),
      .in_bbbb_wdata_I1(in_bbbb_wdata_I1), .out_wr_accept_I0(out_wr_accept_I0),
      .out_rd_data_I0(out_rd_data_I0[0]), .out_rd_valid_I0(out_rd_valid_I0),
      .out_aaaa_rdata_I0(out_aaaa_rdata_I0), .out_aaaa_run_I0(out_aaaa_run_I0),
      .out_bbbb_rdata_I1(out_bbbb_rdata_I1),
      .out_bbbb_resp_I1({ UNCONNECTED_45, UNCONNECTED_46 }),
      .out_irq(out_irq));
   bfax1 U4 ( .Z(n43), .A(in_wr_data_I0[0]));
   bfax1 U5 ( .Z(n44), .A(rst));
   bfx1 out_bbbb_resp_I1_1_inst ( .Z(out_bbbb_resp_I1[1]), .A(tolx1_tienet));
   bfx1 out_bbbb_resp_I1_0_inst ( .Z(out_bbbb_resp_I1[0]), .A(tolx1_tienet));
   tolx1 tolx1_inst ( .TL(tolx1_tienet));
endmodule

