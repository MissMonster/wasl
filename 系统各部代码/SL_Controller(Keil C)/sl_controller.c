/*									
*		P0.0-P0.3	:	·���źſ���
*		P0.4-P0.7	:	�����źŷ���
*		P1.0-P1.3	:	�ɱ������ն˷��͵���һ��·�Ƶ��ź�
*		P1.4-P1.7	:	����һ���ն˷��͵��������ն˵��ź�
*		P2.0-P2.3	:	�Ƿ��Զ�ģʽ
*		P2.4-P2.7	:	��Web��ȡ�Ŀ����ź�
*
*		Create by skyfffire@outlook.com in 2017-6-1
*/

#include "tools.h"

#define COUNT 30
#define TIME 50

unsigned char litTime[4] = {0, 0, 0, 0};

void main()
{
	int i = 0;
	unsigned char isAuto = 0;
	unsigned char isLine = 0;
	unsigned char isHeadLit = 0;
			   
    P1 = 0XFF;

	while (1)
	{
		// �����ĸ�·��
		for (i = X_MIN; i <= 3; i++)
		{
			// ��ȡ����ͨѶ�˷������Զ������ź�
			isAuto = getInfo(2, i);

			// �Զ�ģʽ�жϣ���ʱΪ�ֶ�ģʽ
			if (!isAuto)
			{
				opreation(0, i, getInfo(2, i + 4));
			}
			else
			{	 
				// ����źż�⣬��ʾǰ��·�Ʒ������ź�
				if ((!getInfo(1, i + 4) || !getInfo(1, i))
				&& !isHeadLit)
				{	
					if (!litTime[i])
					{
						lits[i] = ZHAN_KONG;
						isLit[i] = 1;
					}
				   	litTime[i] = COUNT;
				}

				// �����źż�⣬�˴���ʾ���ⱻ�赲
				if (!getInfo(0, i + 4))
				{
					// ��������Χ�ĵ�����COUNT��λ��TIME 

					// ����յ
					if (i - 2 <= -1) 
					{
						isLine = 1;
						isHeadLit = 1;
						opreation(1, 8 + (i - 2), 0);
					}
					else
					{	 
						if (!litTime[i - 2])
						{
							lits[i - 2] = ZHAN_KONG;
							isLit[i - 2] = 1;
						}
						litTime[i - 2] = COUNT;
					}

					// ��һյ
					if (i - 1 <= -1)
					{
						isLine = 1;
						isHeadLit = 1;
						opreation(1, 8 + (i - 1), 0);
					} 
					else
					{	
						if (!litTime[i - 1])
						{
							lits[i - 1] = ZHAN_KONG;
							isLit[i - 1] = 1;
						}
						litTime[i - 1] = COUNT;
					}

					// ��������յ����
					if (!litTime[i])
					{
						lits[i] = ZHAN_KONG;
						isLit[i] = 1;
					}
					litTime[i] = COUNT;

					// ��һյ�Ĵ����ж��Ƿ���Ҫ���ͨѶ
					if (i + 1 >= 4)
					{
						isLine = 1;
						opreation(1, (i + 1) % 4, 0);
					}
					else
					{	
						if (!litTime[i + 1])
						{
							lits[i + 1] = ZHAN_KONG;
							isLit[i + 1] = 1;
						}

						litTime[i + 1] = COUNT;
					}

					// ��һյ����һյ�Ĵ����ж��Ƿ���Ҫ���ͨѶ
					if (i + 2 >= 4)
					{
						isLine = 1;

						opreation(1, (i + 2) % 4, 0);
					}
					else
					{	
						if (!litTime[i + 2])
						{
							lits[i + 2] = ZHAN_KONG;
							isLit[i + 2] = 1;
						}

						litTime[i + 2] = COUNT;
					}
				}
	
				// �����������жϣ�����֣�litTime[i] == 255��Ҳ������������
				if (litTime[i]) 
				{
					litTime[i] -= 1;

					if (!litTime[i]) 
					{
						lits[i] = 0;
						isLit[i] = 0;
					}
				}
	
				opreation(0, i, litTime[i] == 0);
			}
		}  

		delay(TIME); 

		if (isLine) 
		{
			P1 = 0XFF;

			isLine = 0;
			isHeadLit = 0;
		}
	} 
}