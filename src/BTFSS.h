#ifndef _BTFSS_H_
#define _BTFSS_H_

#define WREG 0xFE8
#define STATUS 0xFD8

extern char FSR[];

void btfss(Bytecode *code);

#endif