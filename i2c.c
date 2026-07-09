#include<stdint.h>
#include"i2c.h"
void set_br(){
    TWSR &= ~((1 << 0) | (1 << 1));
    TWBR = (uint8_t)((F_CPU - 16 * SCL_CLOCK) / (2 * SCL_CLOCK));
}
void start_tran(uint8_t slave_add_w){
    TWCR = (1<<2)|(1<<5)|(1<<7);
    while (!(TWCR & (1<<7)));
    if ((TWSR & 0xF8) != START)start_tran(slave_add_w);
    TWDR = slave_add_w;
    TWCR = (1<<7) | (1<<2);
    while (!(TWCR & (1<<7)));
    if ((TWSR & 0xF8) != MT_SLA_ACK)ERROR();
}
void tran_byte(char data,uint8_t slave_add_w){
    TWDR = (uint8_t)data;
    
    TWCR = (1<<7) | (1<<2);
    while (!(TWCR & (1<<7)));
    if ((TWSR & 0xF8) != MT_DATA_ACK)ERROR();
   
}
void ERROR(){while(;;);}
void tran_word(char* word,uint8_t slave_add_w){
    uint8_t i =0;
    start_tran(slave_add_w);
    while(word[i] != '\0'){
        tran_byte(word[i],slave_add_w);
        i++;
    }
    TWCR = (1<<7)|(1<<2)|(1<<4);
}
