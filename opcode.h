#ifndef OPCODE_H
#define OPCODE_H

#define OP_I_TYPE_1 0b0010011
#define OP_I_TYPE_2 0b0000011
#define OP_I_TYPE_3 0b1100111
#define OP_I_TYPE_4 0b1110011
#define OP_R_TYPE 0b0110011
#define OP_S_TYPE 0b0100011
#define OP_B_TYPE 0b1100011
#define OP_J_TYPE 0b1101111
#define OP_U_TYPE_1 0b0110111
#define OP_U_TYPE_2 0b0010111

#include "opcodes/i_type_1.h"
#include "opcodes/i_type_2.h"
#include "opcodes/i_type_3.h"
#include "opcodes/i_type_4.h"
#include "opcodes/r_type.h"
#include "opcodes/s_type.h"
#include "opcodes/b_type.h"
#include "opcodes/j_type.h"
#include "opcodes/u_type_1.h"
#include "opcodes/u_type_2.h"

#endif // OPCODE_H