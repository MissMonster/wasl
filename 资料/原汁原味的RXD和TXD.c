#include <string.h>
#include "tools.h"

/*#define INBUF_LEN 7   					// ��ȡ���ݳ���
unsigned char inbuf1[INBUF_LEN];			// ��ȡ�ַ���
unsigned char checksum, count3, count=0;
bit           read_flag=0;*/

void init_serialcomm(void)
{
	TMOD=0x20;		// ���ö�ʱ��1Ϊģʽ2
	TH1=0xfd;		// װ��ֵ�趨������
	TL1=0xfd;
	TR1=1;			// ������ʱ��
	SM0=0;			// ����ͨ��ģʽ����
	SM1=1;
}

//�򴮿ڷ���һ���ַ�
void send_char_com(char ch)
{
    SBUF = ch;
    while(TI == 0);
    TI = 0;
    delay(10);
}

//�򴮿ڷ���һ���ַ�����strlenΪ���ַ�������
/*void send_string_com(char *str,int strlen)
{
    int k=0;

	for (k = 0; k <= strlen - 2; k++) {
        send_char_com(str[k]);
	}
}*/


//���ڽ����жϺ���
/*void serial () interrupt 4 using 3
{
    if (RI)
    {
        unsigned char ch1;
        RI = 0;

        ch1 = SBUF;
        inbuf1[count++] = ch1;
        if(count == INBUF_LEN)
        {
        	read_flag = 1;  	// ������ڽ��յ����ݴﵽINBUF_LEN������У��û��
			count = 0;      	// ����λȡ����־
        }
    }
}*/

void delay_1s()     //1s
{
    unsigned int i;
    for(i=0;i<45000;i++)
    {
    }
}

void delay_1us()     //1us
{
    unsigned int i;
    for(i=0;i<45;i++)
    {
    }
}

void main()
{
    init_serialcomm(); 			// ��ʼ������
	delay_1s();
	send_char_com(112);			// �򴮿ڷ�������
}