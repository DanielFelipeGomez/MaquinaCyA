module cl(output wire out, input wire a, b, input wire [1:0] s);

  wire aux_and, aux_or, aux_xor, aux_not; 
  //Puertas Lógicas
  and and1 (aux_and, a, b);
  or or1  (aux_or, a, b);
  xor xor1 (aux_xor, a, b);
  not not1 (aux_not, a);
  //Instanciamos el mux4_1 al modulo de la celda logica
  mux4_1 mux1 (out, aux_and, aux_or, aux_xor, aux_not, s);

  
endmodule
