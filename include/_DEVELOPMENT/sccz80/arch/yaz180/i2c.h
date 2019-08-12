
// automatically generated by m4 from headers in proto subdir


#ifndef __I2C_H__
#define __I2C_H__

#include <arch.h>
#include <stdint.h>
#include <stddef.h>

// Defines

#define I2C1_PORT_MSB   __IO_I2C1_PORT_MSB
#define I2C2_PORT_MSB   __IO_I2C2_PORT_MSB


#define I2C_CON_ECHO_BUS_STOPPED    __IO_I2C_CON_ECHO_BUS_STOPPED
#define I2C_CON_ECHO_BUS_RESTART    __IO_I2C_CON_ECHO_BUS_RESTART
#define I2C_CON_ECHO_BUS_ILLEGAL    __IO_I2C_CON_ECHO_BUS_ILLEGAL

#define I2C_IMODE_SET(x)    (x & __IO_I2C_IMODE_MASK)
#define I2C_IMODE_STD       __IO_I2C_IMODE_STD
#define I2C_IMODE_FAST      __IO_I2C_IMODE_FAST
#define I2C_IMODE_FASTP     __IO_I2C_IMODE_FASTP
#define I2C_IMODE_TURBO     __IO_I2C_IMODE_TURBO

// Data Structures


// Functions

// uint8_t i2c_reset( uint8_t device ) __z88dk_fastcall
extern uint8_t __LIB__ i2c_reset(uint8_t device) __smallc __z88dk_fastcall;



// uint8_t i2c_initialise( uint8_t device ) __z88dk_fastcall
extern uint8_t __LIB__ i2c_initialise(uint8_t device) __smallc __z88dk_fastcall;



// uint8_t i2c_interrupt_enable( uint8_t device ) __z88dk_fastcall
extern uint8_t __LIB__ i2c_interrupt_enable(uint8_t device) __smallc __z88dk_fastcall;



// uint8_t i2c_interrupt_disable( uint8_t device ) __z88dk_fastcall
extern uint8_t __LIB__ i2c_interrupt_disable(uint8_t device) __smallc __z88dk_fastcall;



// uint8_t i2c_interrupt_attach( uint8_t device, uint8_t *isr ) __z88dk_callee
extern uint8_t __LIB__ i2c_interrupt_attach(uint8_t device,uint8_t *isr) __smallc;
extern uint8_t __LIB__ i2c_interrupt_attach_callee(uint8_t device,uint8_t *isr) __smallc __z88dk_callee;
#define i2c_interrupt_attach(a,b) i2c_interrupt_attach_callee(a,b)



// uint8_t i2c_write_byte( uint8_t device, uint8_t addr, uint8_t *dp, uint8_t length );
extern void __LIB__ i2c_write_byte(uint8_t device,uint8_t addr,uint8_t *dp,uint8_t length) __smallc;



// uint8_t i2c_read_byte_set( uint8_t device, uint8_t addr, uint8_t length );
extern void __LIB__ i2c_read_byte_set(uint8_t device,uint8_t addr,uint8_t length) __smallc;



// uint8_t i2c_read_byte_get( uint8_t device, uint8_t addr, uint8_t *dp, uint8_t length );
extern void __LIB__ i2c_read_byte_get(uint8_t device,uint8_t addr,uint8_t *dp,uint8_t length) __smallc;



#endif
