#ifndef AI_H
#define AI_H
class ai
{
private:
	int handCard[20] = { 0 };
	int ifLandlord = 0;                       //�Ƿ�Ϊ��������Ϊ1����Ϊ0

public:
	void order();
	int getLL();

	int* getHand();
	void setLL(int a);
	void setCard(int* a);
	void setLLcard(int* a);
	void chuCard();

};




#endif
