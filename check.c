#include <stdio.h>
#include <math.h>

void set(int num, int basic,int change_num){
	int result;
	result=basic|change_num;
	printf("%d번 문제: ",num);
	printf("변경전: %08X , 선택적-세트:  %08X , 결과: %08X\n\n",basic,change_num,result);
}
void complement(int num, int basic, int change_num){
	int result;
	result= basic ^ change_num;
	printf("%d번 문제: ",num);
	printf("변경전: %08X , 선택적-보수: %08X , 결과: %08X\n\n",basic,change_num,result);
}
void mask(int num, int basic, int change_num){
	int result=basic;
	result &= change_num;
	printf("%d번 문제: ",num);
	printf("변경전: %08X , 마스크: %08X , 결과: %08X\n\n",basic,change_num,result);
}
void insert(int num, int basic, int change_spot, int change_num){
	int result=basic;
	result &= change_spot;
	result |= change_num;
	printf("%d번 문제: ",num);
	printf("변경전: %08X , 마스크: %08X , 삽입: %08X , 결과: %08X\n\n",basic,change_spot,change_num,result);
}
int main(void){
	//65    a3a2a1a0   선택적-세트
	set(1,65,15); 
	
	//-127  a7a6a5a4a3 선택적-보수화
	complement(2,-127,248);
	
	//-1024  a28a27a26   선택적-보수화
	complement(3,-1024,469762048);
	
	//512  a31a30a29a28a27a26   선택적-보수화
	complement(4,512,4227858432);
	
	//-5  a31a30a29a28a27a26   매스크(mask) 
	mask(5,-5,67108863);
	
	//-17  a23a22a21a20   매스크(mask) 
	mask(6,-17,4279238655);
	
	//1023   a8a5a3a0   매스크(mask) 
	mask(7,1023,4294966998);
	
	//int형 값 129의  비트들 a3a2a1 대신에 101을 삽입하여 변수 z에 저장하는 코드를 작성하고 출력결과를 적으시오.
	insert(8, 129, 241 ,10);
	
	//int형 값 -20의  비트들 a31a30a29a28a27a26 대신에 111101을 삽입하여 변수 z에 저장하는 코드를 작성하고 출력결과를 적으시오.
	insert(9, -20, 67108863,4093640704);
	
	//int형 값 23의  비트들 a16a13a10a8 대신에 1111을 삽입하여 변수 z에 저장하는 코드를 작성하고 출력결과를 적으시오.
	insert(10, 23, 4294957823,75008);
	return 0;
	};

