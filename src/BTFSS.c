#include <stdio.h>
#include "Bytecode.h"
#include "BTFSS.h"

char FSR[0x1000];
int PC;

void btfss(Bytecode *code){
	int mask = 0x01;
	if(code->operand2 == -1||code->operand2 < 0||code->operand2 > 7){
		Throw(ERR_INVALID_OPERAND2);
	}
	if(code->operand3 == F||code->operand3 == W){
		Throw(ERR_INVALID_OPERAND3);
	}
	if(code->operand1 < 0||code->operand2 > 255){
		Throw(ERR_INVALID_OPERAND1);
	}
	
	mask = mask<<code->operand2;
	//printf("%d",(FSR[code->operand1] & mask)>>code->operand2 );
	if((FSR[code->operand1] & mask)>>code->operand2 == 1)
		PC = PC + 0x04;
	else
		PC = PC + 0x02;

}