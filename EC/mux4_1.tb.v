`timescale 1 ns / 10 ps 

module mux4_1_tb;

reg test_a, test_b, test_c, test_d;
reg [1:0] test_s;
wire test_out;

mux4_1 mux(test_out, test_a, test_b, test_c, test_d, test_s);


initial
begin
  $monitor("tiempo=%0d a=%b b=%b c=%b d=%b s=%b out=%b", $time, test_a, test_b, test_c, test_d, test_s, test_out);
  $dumpfile("mux4_1_tb.vcd");
  $dumpvars;

  //vector de test 0
  test_a = 1'b0;
  test_b = 1'b1;
  test_c = 1'b1;
  test_d = 1'b1;
  test_s = 2'b00;
  #20;

  //vector de test 1
  test_a = 1'b0;
  test_b = 1'b1;
  test_c = 1'b0;
  test_d = 1'b0;
  test_s = 2'b01;
  #20;

  //vector de test 2
  test_a = 1'b0;
  test_b = 1'b0;
  test_c = 1'b0;
  test_d = 1'b1;
  test_s = 2'b11;
  #20;

  $finish;

end
endmodule