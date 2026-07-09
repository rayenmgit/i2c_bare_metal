#include<stdint.h>
#define TWCR (*(volatile uint8_t*) (0xb8))
#define TWDR (*(volatile uint8_t*)(0xb9))
#define TWBR (*(volatile uint8_t*)(0xba))
#define TWSR (*(volatile uint8_t*)(0xbb))
void set br()
void start_tran(uint8_t slave_add_w){
    TWCR = (1<<2)|(1<<5)|(1<<7);
    while (!(TWCR & (1<<7)));
    if ((TWSR & 0xF8) != START)start_tran(slave_add_w);
    TWDR = slave_add_w;
    TWCR = (1<<7) | (1<<2);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) != MT_SLA_ACK)ERROR();
    
}
viod tran(uint8_t* data){
    T
}