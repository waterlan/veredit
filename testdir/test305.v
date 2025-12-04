module a(in_clock, 
        in_reset,
        data_I4);
input  in_clock;
input  in_reset;
output [15:0] data_I4;
wire [15:0] data_I4;
wire  wire_output_data_I0_I4_0;
wire  wire_output_data_I0_I4_1;
wire  wire_output_data_I0_I4_2;
wire  wire_output_data_I0_I4_3;

    assign data_I4[15] = 1'b0 ;
    assign data_I4[14] = 1'b0 ;
    assign data_I4[13] = 1'b0 ;
    assign data_I4[12] = 1'b0 ;
    assign data_I4[11] = 1'b0 ;
    assign data_I4[10] = 1'b0 ;
    assign data_I4[9] = 1'b0 ;
    assign data_I4[8] = 1'b0 ;
    assign data_I4[7] = 1'b0 ;
    assign data_I4[6] = 1'b0 ;
    assign data_I4[5] = 1'b0 ;
    assign data_I4[4] = 1'b0 ;
    assign data_I4[0] = wire_output_data_I0_I4_0 ;
    assign data_I4[1] = wire_output_data_I0_I4_1 ;
    assign data_I4[2] = wire_output_data_I0_I4_2 ;
    assign data_I4[3] = wire_output_data_I0_I4_3 ;
    assign data_IXX[3:0] = "0001" ;
    assign data_IXX[5:4] = 2 ;
	 

    bfx1 i_24(.Z(n_6655), .A(n_2073));
    bfx1 i_22(.Z(n_6652), .A(n_2191));
    bfx4 i_567(.Z(n_22059), .A(n_2067));
    bfx4 i_536(.Z(n_22010), .A(n_6324));
    bfx4 i_535(.Z(n_22009), .A(n_6324));
    bfx4 i_523(.Z(n_21991), .A(n_6323));
    bfx4 i_522(.Z(n_21990), .A(n_6323));
    bfx3 i_517(.Z(n_21982), .A(n_2188));
    bfx4 i_516(.Z(n_21981), .A(n_2188));
    bfx3 i_491(.Z(n_21909), .A(n_2306));
    bfx4 i_490(.Z(n_21908), .A(n_2306));
    bfx1 i_438(.Z(n_21831), .A(n_2311));
    bfx4 i_437(.Z(n_21830), .A(n_2311));
    bfx1 i_432(.Z(n_21822), .A(n_2310));
    bfx4 i_431(.Z(n_21821), .A(n_2310));
endmodule

