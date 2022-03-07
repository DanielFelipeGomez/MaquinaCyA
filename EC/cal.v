module cal(output wire out, c_out, input wire a, b, arit, c_in, input wire [1:0] s);
  // Declaración de los cables auxiliares que utilizaré para las 
  // entradas del multiplexor
  wire sum_out_fa, sum_out_cl;
  // Instanciamos la celda lógica
  cl celda_logica (sum_out_cl, a, b, s);
  // Instaciamos el full-adder
  fa full_adder (c_out, sum_out_fa, a, b, c_in);
  // Instanciamos el mux 2_1 donde le pasamos nuestra salida,
  // los cables auxiliares de las salidas del full adder
  // y de la celda lógica y por último nuestra línea de 
  // selleción que nos indica si trabaja fa(1) o cl(0)
  mux2_1 mux2 (out, sum_out_cl, sum_out_fa, arit);
endmodule