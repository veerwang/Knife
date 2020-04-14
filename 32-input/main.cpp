/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020年04月14日 
 *       Revision:  1 
 *       Compiler:  gcc
 *
 *         Author:  kevin.wang 
 *   Organization:  
 *
 * =====================================================================================
 */

#include 	<cstdlib>
#include 	<cstdio>
#include 	<iostream>

#include 	<unistd.h>
#include	<fcntl.h>
#include 	<linux/input.h>  
#include 	<string.h>
 

void read_event(int fd,input_event& event, int &x,int &y) {
	memset(&event,0,sizeof(event));
	read(fd,&event,sizeof(event));
	if ( event.type == EV_ABS ) {
		if ( event.code == ABS_X )
			x = event.value;
		if ( event.code == ABS_Y )
			y = event.value;
	}
}

int main(int argc, const char *argv[]) {
	std::cout << "input event programe" << std::endl;
	int fd = -1;
	struct input_event event; 
	char *tmp;

	fd = open("/dev/input/event2",O_RDWR|O_NONBLOCK);
	if ( fd == -1 ) {
		perror("open file fail");
		return EXIT_SUCCESS;
	}

	int x = 0; int y = 0;
	while(1) {
		read_event(fd,event,x,y);
		if ( x != 0 && y != 0 ) {
			printf("x=%x,y=%x\n",x,y);
			x = 0;y = 0;
		}
		else  // 如果都是0,那就跳过 break
			continue;
	}

	/*
	while(1) {
		memset(&event,0,sizeof(event));
		read(fd,&event,sizeof(event));

		switch (event.type) {  
			case EV_KEY:  
				if (event.code > BTN_MISC) {  
					printf("Button %d %s",  
							event.code & 0xff,  
							event.value ? "press" : "release");  
				} else {  
					printf("Key %d (0x%x) %s",  
							event.code & 0xff,  
							event.code & 0xff,  
							event.value ? "press" : "release");  
				}  
				break;  
			case EV_REL:  
				switch (event.code) {  
					case REL_X:      tmp = "X";       break;  
					case REL_Y:      tmp = "Y";       break;  
					case REL_HWHEEL: tmp = "HWHEEL";  break;  
					case REL_DIAL:   tmp = "DIAL";    break;  
					case REL_WHEEL:  tmp = "WHEEL";   break;  
					case REL_MISC:   tmp = "MISC";    break;  
					default:         tmp = "UNKNOWN"; break;  
				}  
				printf("Relative %s %d", tmp, event.value);  
				break;  
			case EV_ABS:  
				switch (event.code) {  
					case ABS_X:        tmp = "X";        break;  
					case ABS_Y:        tmp = "Y";        break;  
					case ABS_Z:        tmp = "Z";        break;  
					case ABS_RX:       tmp = "RX";       break;  
					case ABS_RY:       tmp = "RY";       break;  
					case ABS_RZ:       tmp = "RZ";       break;  
					case ABS_THROTTLE: tmp = "THROTTLE"; break;  
					case ABS_RUDDER:   tmp = "RUDDER";   break;  
					case ABS_WHEEL:    tmp = "WHEEL";    break;  
					case ABS_GAS:      tmp = "GAS";      break;  
					case ABS_BRAKE:    tmp = "BRAKE";    break;  
					case ABS_HAT0X:    tmp = "HAT0X";    break;  
					case ABS_HAT0Y:    tmp = "HAT0Y";    break;  
					case ABS_HAT1X:    tmp = "HAT1X";    break;  
					case ABS_HAT1Y:    tmp = "HAT1Y";    break;  
					case ABS_HAT2X:    tmp = "HAT2X";    break;  
					case ABS_HAT2Y:    tmp = "HAT2Y";    break;  
					case ABS_HAT3X:    tmp = "HAT3X";    break;  
					case ABS_HAT3Y:    tmp = "HAT3Y";    break;  
					case ABS_PRESSURE: tmp = "PRESSURE"; break;  
					case ABS_DISTANCE: tmp = "DISTANCE"; break;  
					case ABS_TILT_X:   tmp = "TILT_X";   break;  
					case ABS_TILT_Y:   tmp = "TILT_Y";   break;  
					case ABS_MISC:     tmp = "MISC";     break;  
					default:           tmp = "UNKNOWN";  break;  
				}  
				printf("Absolute %s %d\n", tmp, event.value);  
				break;  
			case EV_MSC: printf("Misc"); break;  
			case EV_LED: printf("Led");  break;  
			case EV_SND: printf("Snd");  break;  
			case EV_REP: printf("Rep");  break;  
			case EV_FF:  printf("FF");   break;  
				     break;  
		}
	}
	*/

	close(fd);
	return EXIT_SUCCESS;
}
