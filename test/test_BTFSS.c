#include "unity.h"
#include "CException.h"
#include "Bytecode.h"
#include "BTFSS.h"

void setUp(){}
void tearDown(){}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand1_is_0x256(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 0x256,
					 .operand2 = 0,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand1_is_neg_200(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = -200,
					 .operand2 = 0,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand2_is_8(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = 8,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand2_is_neg20(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = -20,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand2_is_F(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = F,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand2_is_W(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = W,
					 .operand3 = -1,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND2,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand3_is_F(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = 7,
					 .operand3 = F,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND3,operandERR);
	}
}

void test_btfss_should_not_check_bit_and_throw_exception_with_invalid_operand3_is_W(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 123,
					 .operand2 = 7,
					 .operand3 = W,
					 };				 
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND3,operandERR);
	}
}

void test_btfss_should_not_skip_if_there_is_0_is_check_bit_location(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 0x12,
					 .operand2 = 7,
					 .operand3 = -1,
					 .absoluteAddress = 0x22
					 };			

	FSR[code.operand1] = 0x7D; // 0111 1101
	PC = code.absoluteAddress;
	
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0x24,PC);
}

void test_btfss_should_not_skip_if_there_is_1_is_check_bit_location(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 0x12,
					 .operand2 = 5,
					 .operand3 = -1,
					 .absoluteAddress = 0x22
					 };			

	FSR[code.operand1] = 0x7D;
	PC = code.absoluteAddress;
	
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0x26,PC);
}

void test_btfss_should_not_skip_if_there_is_1_is_bit_0_location(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 0x12,
					 .operand2 = 0,
					 .operand3 = -1,
					 .absoluteAddress = 0x36
					 };			

	FSR[code.operand1] = 0x7D;
	PC = code.absoluteAddress;
	
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0x3A,PC);
}

void test_btfss_should_not_skip_if_there_is_0_is_bit_1_location(){
	CEXCEPTION_T operandERR;
	
	Bytecode code = {.instruction = {.mnemonic = BTFSS, .name = "btfss"},
					 .operand1 = 0x12,
					 .operand2 = 1,
					 .operand3 = -1,
					 .absoluteAddress = 0x3A
					 };			

	FSR[code.operand1] = 0x7D;
	PC = code.absoluteAddress;
	
	Try{
		btfss(&code);
	}Catch(operandERR){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND1,operandERR);
	}
	
	TEST_ASSERT_EQUAL(0x3C,PC);
}












