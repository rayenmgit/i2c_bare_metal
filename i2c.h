#ifndef I2C_H
#define I2C_H

#include<stdint.h>
#define TWCR (*(volatile uint8_t*) (0xb8))
#define TWDR (*(volatile uint8_t*)(0xb9))
#define TWBR (*(volatile uint8_t*)(0xba))
#define TWSR (*(volatile uint8_t*)(0xbb))
#define MT_SLA_ACK  0x18
#define MT_DATA_ACK 0x28
#define START       0x08
#define F_CPU 16000000UL
#define SCL_CLOCK 400000UL
void set_br();
void start_tran();
void tran_byte();
void ERROR();
void tran_word();

#endif