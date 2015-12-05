#include<iostream>
#include<string>

class Card{
private:
	std::string name;
	int kind;
	int remain;
	int max;
public:
	void setting(std::string n, int k, int r);
	std::string getname(){ return name; }
	int getkind() { return kind; }
	int getremain(){ return remain; }
	int spielen(Card c);
	void discard(){ remain -= 1; }
	void restore(){ remain = max; }
};

void Card::setting(std::string n, int k, int r){
	name = n;
	kind = k;
	remain = r;
	max = r;
}

int Card::spielen(Card c){
	//������0 ������1 ��������2 ���ꏟ����4
	switch (kind) {
	case 2: //�������|
		if (c.getkind() == 2){ //���肪�|
			return 2; //������
			break;
		}
		else if (c.getkind() == 1){ //���肪��
			return 4; //����
			break;
		}
		else if (c.getkind() == 0){  //���肪��
			return 0; //����
			break;
		}
		else{
			return 99;
			break;
		}
	case 1: //��������
		if (c.getkind() == 2){ //���肪�|
			return 4; //����
			break;
		}
		else if (c.getkind() == 1){ //���肪��
			return 2; //������
			break;
		}
		else if(c.getkind() == 0){ //���肪��
			return 1; //����
			break;
		}
		else{
			return 99;
			break;
		}
	case 0: //��������
		if (c.getkind() == 2){ //���肪�|
			return 1; //����
			break;
		}
		else if (c.getkind() == 1){ //���肪��
			return 0; //����
			break;
		}
		else if (c.getkind() == 0){ //���肪��
			return 2; //������
			break;
		}
		else{
			return 99;
			break;
		}
	default: //�Ȃ񂩕ʂ̎�
		return 99;
		break;
	}
}




