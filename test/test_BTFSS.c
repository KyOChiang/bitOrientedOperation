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












