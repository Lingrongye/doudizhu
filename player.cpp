#include"function.h"
#include"player.h"

using namespace std;

//return����ֵ
int player::getLL() { return ifLandlord; }
//return��������
int* player::getHand() { return handCard; }
//�β�aΪint���ͣ�������ҵ���ֵ
void player::setLL(int a) { ifLandlord = a; }

//�����������������
void player::order() {
	int min;
	int temp;
	for (int j = 0; j < 20; j++) {
		min = 100;
		temp = 0;
		for (int i = j; i < 20; i++) {
			if (handCard[i] < min) {
				min = handCard[i];
				temp = i;
			}
		}
		swap(handCard[j], handCard[temp]);
	}
}

//�β�a���������ͣ������Ƹ�ֵ
void player::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}

//�β�a���������ͣ������Ƽ��ϵ�����
void player::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}



//�״γ��Ƶĺ���
void player::chuCardFirst() {
	//����Ҫ������Ƶ���ŵ����飬��0��β
	int x[20] = { 0 };   
	//����Ҫ������Ƶ���ֵ�����飬��0��β
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;
	
	cout << endl<<"�ֵ����ȳ���"<<endl;
	

	//��ѭ����Ϊ��ʵ�������������Ƶ���ź��ж��ܷ������ܴ��������ѭ�����������ظ�ѭ��
	do {
		cout << "��������Ҫ����Ƶ����" << endl;
		
		for (i = 0; i < 20; i++) {
			x[i] = 0;
		}
		for (i = 0; i < 20; i++) {
			y[i] = 0;
		}
        j = 0;
		do {
			cin >> x[j];

			//�����ֹӦ�õ�һ�γ��Ƶ��˲�����
			if (x[0] == 0) {
				cout << endl << "�����Բ�������" << endl;
				continue;
			}
			
			if (x[j] == 0) {
				break;
			}			

			j++;
		} while (1);
 
		

		//handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0		
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  
			Temp++;
		}
		i = 0;
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}

	} while (rightFirst(y) == 0);



	
		//��������ƽ����ݴ�
		for (int i = 0; i < 20; i++) {
			temp[i] = y[i];
		}

		//��������ƺ�����Ƹ�ֵΪ0
		i = 0;
		while (x[i] != 0) {
			handCard[Temp + x[i] - 1] = 0;
			i++;
		}
		order();
		tempchu = 0;
		cout << "����� ";


		//����
		i = 0;
		while (y[i] != 0) {
			cout << y[i] << " ";
			i++;
		}
		cout << endl;

		//����
		cout << "��������Ϊ��";
		for (int i = 0; i < 20; i++)
		{
			cout << getHand()[i] << " ";
		}
		cout << endl;



}


//������Ƶĺ���
void player::chuCard() {
	//����Ҫ������Ƶ���ŵ����飬��0��β
	int x[20] = { 0 };
	//����Ҫ������Ƶ���ֵ�����飬��0��β
	int y[20] = { 0 };

	int j = 0;
	int i = 0;
	int Temp = 0;

	//flagΪ�Ƿ񲻳���Ϊ1�ǳ��ƣ�Ϊ0�ǲ���
	int flag = 1;

	//��ѭ����Ϊ��ʵ�������������Ƶ���ź��ж��ܷ������ܴ��������ѭ�����������ظ�ѭ��
	do {
		cout << endl;
		cout << "��������Ҫ����Ƶ����" << endl;
		
		for ( i = 0; i < 20; i++) {
			x[i] = 0;
		}

		j = 0;
		do {			
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);

		//�ֳ��������������
		if (x[0] == 0) {
			flag = 0;
			break;
		}


		//handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0
		
		Temp = 0;
		while (handCard[Temp] == 0) {			 			 
			Temp++;
		}

		i = 0;
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}


	} while (right(y, temp, tempFunction) == 0);



	if (flag == 1) {
        //�ı��ݴ�ֵ
		for (int i = 0; i < 20; i++) {
			temp[i] = y[i];                                        
		}

        //��������ƺ�����Ƹ�ֵΪ0
		i = 0;
		while (x[i] != 0) {
			handCard[Temp + x[i] - 1] = 0;                            
			i++;
		}
		
		//��������
		order();                                                   

		//����
		i = 0;
		cout << "�����;";
		while (y[i] != 0) {
			cout << y[i] << " ";
			i++;
		}
		tempchu = 0;
		cout << endl;

		//����
		cout << "��������Ϊ��";
		for (int i = 0; i < 20; i++)
		{
			cout << getHand()[i] << " ";
		}
		cout << endl;

	}


	//�����tempchu��ô��⣬��ʼֵΪ2������chuFirst����������tempchu=0��tempchu=0������chucard��������������������tempchu=0��
	//tempchu=0������chucard����������������tempchu+1��ֵΪ1����Ϊtempchu=1����һ���Ե���chucard�����������һ�ε���chucard�������Բ�����tempchu+1��
	//tempchu=2�������chufirst����������
	else {
		tempchu ++;
		cout << "����" << endl;
	}
}
