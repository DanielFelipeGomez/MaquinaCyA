module cal(output wire out, c_out, input wire a, b, arit, c_in, input wire [1:0] s);
  wire sum_out_fa, sum_out_cl;
  cl celda_logica (sum_out_cl, a, b, s);
  fa full_adder (c_out, sum_out_fa, a, b, c_in);
  mux2_1 mux2 (out, sum_out_fa, sum_out_cl, arit);
endmodule