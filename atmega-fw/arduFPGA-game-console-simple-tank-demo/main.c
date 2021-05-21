/*
 * Main file for arduFPGA designs.
 * 
 * Copyright (C) 2020  Iulian Gheorghiu (morgoth@devboard.tech)
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

//#define USE_SERVO_SCAN
#define SERVO_SENSOR_STEP		8

//#define SHOW_3D_TRIANGLE

#define WHEELS_MAX_SPEED		400

#define REMOTE_UP_KEY			1
#define REMOTE_DN_KEY			2
#define REMOTE_LEFT_KEY			4
#define REMOTE_RIGHT_KEY		8
#define REMOTE_1_KEY			16
#define REMOTE_2_KEY			32
#define REMOTE_3_KEY			64
#define REMOTE_4_KEY			128
#define REMOTE_5_KEY			256
#define REMOTE_6_KEY			512

#include <avr/io.h>
#include <string.h>
#include "def.h"
#include "sys.h"
#include "kbd.h"
#include "driver/spi.h"
#include "driver/twi_s.h"
#include "driver/uart.h"
#include "shield/freenove_ThreeWeeled.h"
#include "gfx/draw.h"
#include "gfx/3d.h"
#include "delay.h"
#include DISPLAY_DRIVER_FILE

spi_t spi;
twi_t twi;
freeNove_ThreeWeled_t *freeNoveInst;

timer_t uartTimeout_timer;
timer_t wheelsPoolStop_timer;
uint8_t uartRxBuf[6];
uint8_t uartRxCnt = 0;
uint16_t uartRxCommand = 0;
uint16_t uartRxCommandBack = 0;

#ifndef SSD1306_USE_NO_BUF
uint8_t screen_buf[1024];
#else /* SSD1306_USE_NO_BUF */
uint8_t screen_buf[1];
#endif /* SSD1306_USE_NO_BUF */

_3d_points_i Points_i;

dir_e direction = LEFT;
int16_t position = 90;

void service() {
	timer_service();
}

int main(void)
{
	asm("sei");
	
	void (*vect_set_service)(uint16_t) = (void *)BOOT_VECTOR_SET_SERVICE_VECT;
	vect_set_service((uint16_t)service);
	
	uartTimeout_timer.value = 2;
	wheelsPoolStop_timer.value = 200;
	timer_enable(&wheelsPoolStop_timer, true);

	spi.spcr = &SPCR;
	spi.spsr = &SPSR;
	spi.spdr = &SPDR;
	spi_init(&spi);
	
	DISPLAY_FUNC_INIT(&spi, screen_buf);

	/*twi.twbr = &TWBR;
	twi.twcr = &TWCR;
	twi.twsr = &TWSR;
	twi.twdr = &TWDR;
	twi.twar = &TWAR;*/
	twi.ctrla = &(*(uint8_t *)0xb8);
	twi.ctrlb = &(*(uint8_t *)0xb9);
	twi.ctrlc = &(*(uint8_t *)0xba);
	twi.status = &(*(uint8_t *)0xbb);
	twi.baud = &(*(uint8_t *)0xbc);
	twi.data = &(*(uint8_t *)0xbd);
	twi_init(&twi, 100000);
	
	freeNoveInst = freeNove_ThreeWeled_init(&twi);
	freeNoveInst->servoMin[0] = 700;
	freeNoveInst->servoMax[0] = 1200;
	freeNoveInst->servoMin[1] = 700;
	freeNoveInst->servoMax[1] = 1500;
	freeNoveInst->servoMin[2] = 700;
	freeNoveInst->servoMax[2] = 1500;
	freeNoveInst->servoMin[3] = 700;
	freeNoveInst->servoMax[3] = 1500;

	uart_init(57600);
	
	kbd_init();

#ifdef SHOW_3D_TRIANGLE
	int32_t x[3];
	int32_t y[3];
	int32_t z[3];
	int32_t depth[3];
	int32_t scaleFactor[3];

    Points_i.x = x;
    Points_i.y = y;
    Points_i.z = z;
    Points_i.depth = depth;
    Points_i.scaleFactor = scaleFactor;

    Points_i.x[0] = -70;
    Points_i.y[0] = -70;
    Points_i.z[0] = -70;
    Points_i.x[1] = 70;
    Points_i.y[1] = -70;
    Points_i.z[1] = -70;
    Points_i.x[2] = 0;
    Points_i.y[2] = 70;
    Points_i.z[2] = -70;
    Points_i.length = 3;// Three points to be processed.
    Points_i.focalLength = 100;
	Points_i.depthScale = 1;
	
	int16_t angle_x = 0;
	int16_t angle_y = 0;
	int16_t angle_z = 0;

	lib_3ds_draw_triangle_i(&spi, NULL, screen_buf, &Points_i, 64, 32, angle_x, angle_y, angle_z, Clr32White);
	DISPLAY_FUNC_REFRESH(&spi, screen_buf);
#endif
	
	//draw_line(inst, box, buf, (int16_t)screenPoints[0].x + X_offset, (int16_t)screenPoints[0].y + Y_offset, (int16_t)screenPoints[1].x + X_offset, (int16_t)screenPoints[1].y + Y_offset, 1, Color);

    /* Replace with your application code */
    while (1) {
		/*kbd_idle();
		if(kbd_changed()) {
			uint8_t kbd_state = kbd_get();
			if(kbd_state & KBD_U_KEY) {
				if(angle_y > 0)
					angle_x--;
			} else if(kbd_state & KBD_D_KEY) {
				if(angle_y < 360)
					angle_x++;
			} else if(kbd_state & KBD_L_KEY) {
				if(angle_x > 0)
					angle_x--;
			} else if(kbd_state & KBD_R_KEY) {
				if(angle_x < 360)
					angle_x++;
			} else if(kbd_state & KBD_A_KEY) {
				if(angle_x > 0)
					angle_z--;
			} else if(kbd_state & KBD_B_KEY) {
				if(angle_x < 360)
					angle_z++;
			}
			DISPLAY_FUNC_CLEAR(&spi, screen_buf, Clr32Black);
			lib_3ds_draw_triangle_i(&spi, NULL, screen_buf, &Points_i, 64, 32, angle_x, angle_y, angle_z, Clr32White);
			DISPLAY_FUNC_REFRESH(&spi, screen_buf);
		}*/
		//delay_ms(30);
#ifdef SHOW_3D_TRIANGLE
		if(angle_y < 360)
			angle_y++;
		else
			angle_y = 0;
		DISPLAY_FUNC_CLEAR(&spi, screen_buf, Clr32Black);
		lib_3ds_draw_triangle_i(&spi, NULL, screen_buf, &Points_i, 64, 32, angle_x, angle_y, angle_z, Clr32White);
		DISPLAY_FUNC_REFRESH(&spi, screen_buf);
#endif
#ifdef USE_SERVO_SCAN
		if(direction == LEFT) {
			position-=SERVO_SENSOR_STEP;
			if(position < SERVO_SENSOR_STEP ) {
				direction = RIGHT;
				position = 0;
			}
		} else {
			position+=SERVO_SENSOR_STEP;
			if(position > 179 - SERVO_SENSOR_STEP) {
				direction = LEFT;
				position = 179;
			}
		}
		freeNove_ThreeWeled_servo(freeNoveInst, 0, position);
#endif
		uint8_t c;
		if(uart_get_c_nb(&c)) {
			if(uartRxCnt < sizeof(uartRxBuf)) {
				uartRxBuf[uartRxCnt++] = c;
			}
			timer_enable(&uartTimeout_timer, true);
		}
		if(timer_tik(&uartTimeout_timer)) {
			timer_enable(&uartTimeout_timer, false);
			if(uartRxCnt == 6 && uartRxBuf[0] == 0xFF && uartRxBuf[1] == 0x55 && (uartRxBuf[2] == (uint8_t)(255 - uartRxBuf[3])) && (uartRxBuf[4] == (uint8_t)(255 - uartRxBuf[5]))) {
				uartRxCommand = (uartRxBuf[4] << 8) | uartRxBuf[2];
			}
			memset(uartRxBuf, 0, sizeof(uartRxBuf));
			uartRxCnt = 0;

			if(uartRxCommand & REMOTE_UP_KEY) {
				freeNove_ThreeWeled_dir(freeNoveInst, 0, true);
				freeNove_ThreeWeled_dir(freeNoveInst, 1, true);
				freeNove_ThreeWeled_pwm(freeNoveInst, 0, WHEELS_MAX_SPEED);
				freeNove_ThreeWeled_pwm(freeNoveInst, 1, WHEELS_MAX_SPEED);
			}
			else if(uartRxCommand & REMOTE_DN_KEY) {
				freeNove_ThreeWeled_dir(freeNoveInst, 0, false);
				freeNove_ThreeWeled_dir(freeNoveInst, 1, false);
				freeNove_ThreeWeled_pwm(freeNoveInst, 0, WHEELS_MAX_SPEED);
				freeNove_ThreeWeled_pwm(freeNoveInst, 1, WHEELS_MAX_SPEED);
			}
			else if(uartRxCommand & REMOTE_LEFT_KEY) {
				freeNove_ThreeWeled_dir(freeNoveInst, 0, false);
				freeNove_ThreeWeled_dir(freeNoveInst, 1, true);
				freeNove_ThreeWeled_pwm(freeNoveInst, 0, WHEELS_MAX_SPEED);
				freeNove_ThreeWeled_pwm(freeNoveInst, 1, WHEELS_MAX_SPEED);
			}
			else if(uartRxCommand & REMOTE_RIGHT_KEY) {
				freeNove_ThreeWeled_dir(freeNoveInst, 0, true);
				freeNove_ThreeWeled_dir(freeNoveInst, 1, false);
				freeNove_ThreeWeled_pwm(freeNoveInst, 0, WHEELS_MAX_SPEED);
				freeNove_ThreeWeled_pwm(freeNoveInst, 1, WHEELS_MAX_SPEED);
			}
			if(uartRxCommand & REMOTE_6_KEY) {
				position-=SERVO_SENSOR_STEP;
				if(position < SERVO_SENSOR_STEP ) {
					direction = RIGHT;
					position = 0;
				}
				freeNove_ThreeWeled_servo(freeNoveInst, 0, position);
			}
			if(uartRxCommand & REMOTE_5_KEY) {
				position+=SERVO_SENSOR_STEP;
				if(position > 179 - SERVO_SENSOR_STEP) {
					direction = LEFT;
					position = 179;
				}
				freeNove_ThreeWeled_servo(freeNoveInst, 0, position);
			}
		}
		if(timer_tik(&wheelsPoolStop_timer) && (uartRxCommand & (REMOTE_UP_KEY || REMOTE_DN_KEY || REMOTE_LEFT_KEY || REMOTE_RIGHT_KEY)) == 0) {
			freeNove_ThreeWeled_pwm(freeNoveInst, 0, 0);
			freeNove_ThreeWeled_pwm(freeNoveInst, 1, 0);
		}
		/*if(uartRxCommand != uartRxCommandBack) {
			if((uartRxCommand & REMOTE_UP_KEY) != (uartRxCommandBack & REMOTE_UP_KEY)) {
			}
			if((uartRxCommand & REMOTE_DN_KEY) != (uartRxCommandBack & REMOTE_DN_KEY)) {
			}
			if((uartRxCommand & REMOTE_LEFT_KEY) != (uartRxCommandBack & REMOTE_LEFT_KEY)) {
			}
			if((uartRxCommand & REMOTE_RIGHT_KEY) != (uartRxCommandBack & REMOTE_RIGHT_KEY)) {
			}
			uartRxCommandBack = uartRxCommand;
		}*/
    }
}

