#include "msp430x22x4.h"

typedef struct {
	unsigned int sec;
	unsigned int msec;

} realtime_t;

double get_secd(realtime_t t);

realtime_t current_time;
realtime_t start, end;
double work_time = 0.0; //work_time for p1 = 4s

void delay (void)
{
	long i;
	for (i=0; i < 3000000; i++) {
		__no_operation();
		__no_operation();
		__no_operation();
	}
}


int main (void)
{
 WDTCTL = WDTPW + WDTHOLD;
 P1DIR = 0x03;
 P1OUT = 0x00;
 TBCCTL0 = CCIE;
 TBCTL= TASSEL_2 + ID_3 + MC_1;
 TBCCR0 = 125;

 start = current_time;	 
 delay();
 end = current_time;
 
 work_time = get_secd(end) - get_secd(start);
 
 P1OUT = 0x02;

 return 0;
}

double get_secd(realtime_t t){
	return (t.msec/1000.0 + t.sec);
}

#pragma vector=TIMERB0_VECTOR
__interrupt void Timer_B (void)
{
	if (current_time.msec == 999){
		current_time.msec = 0;
		current_time.sec++;
	}
	else{
		current_time.msec++;
	}
}
