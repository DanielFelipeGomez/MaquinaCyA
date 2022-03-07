module compl1(output wire [3:0] Sal, input wire [3:0] Ent, input wire cpl);
  // Si la líena cpl(línea de selección) se pone a 1
  // se complementa a 1, que basicamenet es la entrada negada
  // si por el contrario es 0, se devuleve la entrada sin más 
  assign Sal = (cpl == 1) ? (~Ent) : Ent;
endmodule
