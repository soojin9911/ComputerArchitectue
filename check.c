#include <stdio.h>
#include <math.h>

void set(int num, int basic,int change_num){
	int result;
	result=basic|change_num;
	printf("%d�� ����: ",num);
	printf("������: %08X , ������-��Ʈ:  %08X , ���: %08X\n\n",basic,change_num,result);
}
void complement(int num, int basic, int change_num){
	int result;
	result= basic ^ change_num;
	printf("%d�� ����: ",num);
	printf("������: %08X , ������-����: %08X , ���: %08X\n\n",basic,change_num,result);
}
void mask(int num, int basic, int change_num){
	int result=basic;
	result &= change_num;
	printf("%d�� ����: ",num);
	printf("������: %08X , ����ũ: %08X , ���: %08X\n\n",basic,change_num,result);
}
void insert(int num, int basic, int change_spot, int change_num){
	int result=basic;
	result &= change_spot;
	result |= change_num;
	printf("%d�� ����: ",num);
	printf("������: %08X , ����ũ: %08X , ����: %08X , ���: %08X\n\n",basic,change_spot,change_num,result);
}
int main(void){
	//65    a3a2a1a0   ������-��Ʈ
	set(1,65,15); 
	
	//-127  a7a6a5a4a3 ������-����ȭ
	complement(2,-127,248);
	
	//-1024  a28a27a26   ������-����ȭ
	complement(3,-1024,469762048);
	
	//512  a31a30a29a28a27a26   ������-����ȭ
	complement(4,512,4227858432);
	
	//-5  a31a30a29a28a27a26   �Ž�ũ(mask) 
	mask(5,-5,67108863);
	
	//-17  a23a22a21a20   �Ž�ũ(mask) 
	mask(6,-17,4279238655);
	
	//1023   a8a5a3a0   �Ž�ũ(mask) 
	mask(7,1023,4294966998);
	
	//int�� �� 129��  ��Ʈ�� a3a2a1 ��ſ� 101�� �����Ͽ� ���� z�� �����ϴ� �ڵ带 �ۼ��ϰ� ��°���� �����ÿ�.
	insert(8, 129, 241 ,10);
	
	//int�� �� -20��  ��Ʈ�� a31a30a29a28a27a26 ��ſ� 111101�� �����Ͽ� ���� z�� �����ϴ� �ڵ带 �ۼ��ϰ� ��°���� �����ÿ�.
	insert(9, -20, 67108863,4093640704);
	
	//int�� �� 23��  ��Ʈ�� a16a13a10a8 ��ſ� 1111�� �����Ͽ� ���� z�� �����ϴ� �ڵ带 �ۼ��ϰ� ��°���� �����ÿ�.
	insert(10, 23, 4294957823,75008);
	return 0;
	};

