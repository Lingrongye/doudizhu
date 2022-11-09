#include"function.h"
#include"player.h"
using namespace std;
int player::getLL() { return ifLandlord; }
int* player::getHand() { return handCard; }
void player::setLL(int a) { ifLandlord = a; }

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

void player::setCard(int* a)
{
	int j = 0;
	for (int i = 0; i < 17; i++) {
		handCard[i] = a[i];
	}

}


void player::setLLcard(int* a) {
	for (int i = 0; i < 3; i++) {
		handCard[i] = a[i];
	}
}

void player::chuCardFirst() {
	int x[20] = { 0 };    //Ҫ������Ƶ���ţ���0��β
	int y[20] = { 0 };
	int j = 0;

	int i = 0;
	int Temp = 0;

	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		for (int i = 0; i < 20; i++) {
			y[i] = 0;
		}

		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);


		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  //handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}

	} while (rightFirst(y) == 0);

	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];
	}

	i = 0;
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;
		i++;
	}
	order();

	cout << "����� ";
	//����
	i = 0;
	
	while (y[i] != 0) {
		cout << y[i] << " ";
		i++;
	}
	cout << endl;


}

void player::chuCard() {
	int x[20] = { 0 };    //Ҫ������Ƶ����
	int y[20] = { 0 };    //Ҫ�������
	int j = 0;
	int i = 0;
	int Temp = 0;


	do {
		j = 0;
		for (int i = 0; i < 20; i++) {
			x[i] = 0;
		}
		do {
			cin >> x[j];
			if (x[j] == 0) {
				break;
			}
			j++;
		} while (1);


		i = 0;
		Temp = 0;
		while (handCard[Temp] == 0) {			 			  //handCard�������±�ΪTemp��Ԫ�ؿ�ʼ��Ϊ0
			Temp++;
		}
		while (x[i] != 0) {
			y[i] = handCard[Temp + x[i] - 1];
			i++;
		}


	} while (right(y, temp, tempFunction) == 0);


	for (int i = 0; i < 20; i++) {
		temp[i] = y[i];                                        //�ı��ݴ�ֵ
	}
	while (x[i] != 0) {
		handCard[Temp + x[i] - 1] = 0;                            //��������ƺ�����Ƹ�ֵΪ0
		i++;
	}
	order();                                                   //��������

	//����
	while (y[i] != 0) {
		cout << "�����" << y[i] << " ";
	}
	cout << endl;
}
