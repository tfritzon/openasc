/*! \file front_panel/usart.h
 *  \brief USART routines
 *  \ingroup front_panel_group
 *  \author Mikael Larsmark, SM2WMV
 *  \date 2010-01-25
 *  \code #include "front_panel/usart.h" \endcode
 */
//    Copyright (C) 2008  Mikael Larsmark, SM2WMV
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include "../global.h"

#ifndef _USART_H_
#define _USART_H_

unsigned char poll_usart0_receive (void);
void usart0_init (unsigned int baudrate);
void usart0_transmit (char data);
unsigned char usart0_receive (void);
unsigned char usart0_receive_loopback (void);
unsigned char poll_usart0_receive (void);
unsigned char usart0_sendstring (char *data,unsigned char length);

unsigned char poll_usart1_receive (void);
void usart1_init(unsigned int baudrate, unsigned char stopbits);
unsigned char usart1_transmit (unsigned char data);
unsigned char usart1_receive (void);
unsigned char usart1_receive_loopback (void);
unsigned char poll_usart1_receive (void);
unsigned char usart1_sendstring (char *data,unsigned char length);

unsigned char poll_usart3_receive (void);
void usart3_init (unsigned int baudrate, unsigned char stopbits);
unsigned char usart3_transmit (unsigned char data);
unsigned char usart3_receive (void);
unsigned char usart3_receive_loopback (void);
unsigned char poll_usart3_receive (void);
unsigned char usart3_sendstring (char *data,unsigned char length);

#endif

