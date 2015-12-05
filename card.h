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
	//Ÿ‚¿‚Í0 •‰‚¯‚Í1 ‚ ‚¢‚±‚Í2 “ÁêŸ—˜‚Í4
	switch (kind) {
	case 2: //©•ª‚ª‹|
		if (c.getkind() == 2){ //‘Šè‚ª‹|
			return 2; //‚ ‚¢‚±
			break;
		}
		else if (c.getkind() == 1){ //‘Šè‚ª‚
			return 4; //•‰‚¯
			break;
		}
		else if (c.getkind() == 0){  //‘Šè‚ªŒ•
			return 0; //Ÿ‚¿
			break;
		}
		else{
			return 99;
			break;
		}
	case 1: //©•ª‚ª‚
		if (c.getkind() == 2){ //‘Šè‚ª‹|
			return 4; //Ÿ‚¿
			break;
		}
		else if (c.getkind() == 1){ //‘Šè‚ª‚
			return 2; //‚ ‚¢‚±
			break;
		}
		else if(c.getkind() == 0){ //‘Šè‚ªŒ•
			return 1; //•‰‚¯
			break;
		}
		else{
			return 99;
			break;
		}
	case 0: //©•ª‚ªŒ•
		if (c.getkind() == 2){ //‘Šè‚ª‹|
			return 1; //•‰‚¯
			break;
		}
		else if (c.getkind() == 1){ //‘Šè‚ª‚
			return 0; //Ÿ‚¿
			break;
		}
		else if (c.getkind() == 0){ //‘Šè‚ªŒ•
			return 2; //‚ ‚¢‚±
			break;
		}
		else{
			return 99;
			break;
		}
	default: //‚È‚ñ‚©•Ê‚Ì
		return 99;
		break;
	}
}




