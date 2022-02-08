/*
 * UART_Config.h
 *
 * Created: 17-03-20 14:59:50
 *  Author: Caro et Fred
 */ 

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

extern void uart_config(void);
extern char uart_receive(void);
extern void uart_send(char);
extern void uart_send_string(char *);

#endif