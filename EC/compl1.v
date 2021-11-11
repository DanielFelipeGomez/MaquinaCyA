module compl1(output wire [3:0] Sal, input wire [3:0] Ent, input wire cpl);
  assign Sal = (cpl == 1) ? (~Ent) : Ent;
endmodule
