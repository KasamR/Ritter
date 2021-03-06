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
	//勝ちは0 負けは1 あいこは2 特殊勝利は4
	switch (kind) {
	case 2: //自分が弓
		if (c.getkind() == 2){ //相手が弓
			return 2; //あいこ
			break;
		}
		else if (c.getkind() == 1){ //相手が盾
			return 4; //負け
			break;
		}
		else if (c.getkind() == 0){  //相手が剣
			return 0; //勝ち
			break;
		}
		else{
			return 99;
			break;
		}
	case 1: //自分が盾
		if (c.getkind() == 2){ //相手が弓
			return 4; //勝ち
			break;
		}
		else if (c.getkind() == 1){ //相手が盾
			return 2; //あいこ
			break;
		}
		else if(c.getkind() == 0){ //相手が剣
			return 1; //負け
			break;
		}
		else{
			return 99;
			break;
		}
	case 0: //自分が剣
		if (c.getkind() == 2){ //相手が弓
			return 1; //負け
			break;
		}
		else if (c.getkind() == 1){ //相手が盾
			return 0; //勝ち
			break;
		}
		else if (c.getkind() == 0){ //相手が剣
			return 2; //あいこ
			break;
		}
		else{
			return 99;
			break;
		}
	default: //なんか別の時
		return 99;
		break;
	}
}




