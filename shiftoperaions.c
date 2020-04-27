#include <stdio.h>

int main(void){
	int x,y,xr,xl;
	unsigned s,t,sr,sl;
	
	x=-7; 
	y=2;
	xr=x>>y;
	xl=x<<y;
	printf("%08X %08X %08X %08X\n",x,y,xr,xl);
	printf("%d %d %d %d\n",x,y,xr,xl);
	
	s=-7;
	t=2;
	sr=s>>t;
	sl=s<<t;
	printf("%08X %08X %08X %08X\n",s,t,sr,sl);
	printf("%d %d %d %d\n",s,t,sr,sl);
	
	return 0;
}
