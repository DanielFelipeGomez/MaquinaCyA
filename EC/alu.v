module alu(output wire [3:0] R, output wire zero, carry, sign, input wire [3:0] A, B, input wire [1:0] ALUOp, input wire arit);
  // Declaración de los cables intermedios para conectar
  // todos los módulos
  wire [3:0] OP1, OP2, aux_compl1, cout;
  wire op1_A, op2_B, cpl, cin;

  // Instanciamos los mux y su complemento a 1
  mux2_4 mux_Alu01 (OP1, 4'b0000, A, op1_A);
  mux2_4 mux_Alu02 (aux_compl1, A, B, op2_B);
  compl1 compl1_Alu (OP2, aux_compl1, cpl);
  
  // Instaciamos todos las celdas aritmético-lógicas
  cal cal0 (R[0], cout[0], OP1[0], OP2[0], arit, cin, ALUOp);
  cal cal1 (R[1], cout[1], OP1[1], OP2[1], arit, cout[0], ALUOp);
  cal cal2 (R[2], cout[2], OP1[2], OP2[2], arit, cout[1], ALUOp);
  cal cal3 (R[3], cout[3], OP1[3], OP2[3], arit, cout[2], ALUOp);

  // funciones obtenidas de la simplificación por Karnaugh 
  // de la tabla de la verdad
  assign op1_A = ~arit | ~ALUOp[1];
  assign op2_B = ~arit | ALUOp[0] | ~ALUOp[1];
  // Modificacion
  assign cpl = arit & ALUOp[0];
  // assign cpl = arit & ALUOp[0] | arit & ALUOp[1];
  assign cin = ALUOp[0] | ALUOp[1];

  // Salidas especiales
  // El bit más significativo correesponde con el signo 1(Neg) 0(Pos)
  assign sign = R[3];
  // El último carry coincide con el carry final
  assign carry = cout[3];
  //assign zero = (~R[0])&(~R[1])&(~R[2])&(~R[3]);
  // mod
    wire and1_aux, and2_aux;
    and and1(and1_aux, ~R[0],~R[1]);
    and and2(and2_aux, ~R[2],~R[3]);
    and and3(zero, and1_aux, and2_aux);
endmodule