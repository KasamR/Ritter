#include<iostream>
#include<string>
#include"card.h"
using namespace std;
string names[] = { "Bow", "Shield", "Sword" };
int cards[3] = { 1, 1, 5 };
int player[2] = { 0 };
bool draw = false;
Card mycard[3];
Card yourcard[3];

void Spielen(int b, Card c, Card d);

int main(){
	for (int i = 0; i < 3; i++){
		//名前を入れる 種類を入れる 残り数を入れる
		mycard[i].setting(names[i], 2-i, cards[i]);
		yourcard[i].setting(names[i], 2-i, cards[i]);
	}
	string my, you;
	int mn, yn;
	bool loop = true;

	while (player[0] < 5 && player[1] < 5){
		if (draw) {
			for (int i = 0; i < 3; i++){
				mycard[i].restore();
				yourcard[i].restore();
			}
		}
		cout << "Your STARS: ";
		for (int i = 0; i < player[0]; i++) cout << "☆"; cout << endl;
		cout << "Enemy's STARS: ";
		for (int i = 0; i < player[1]; i++) cout << "☆"; cout << endl;

		cout << endl << "What is your card?" << endl;
		for (int i = 0; i < 3; i++) cout << mycard[i].getname() << ": " << mycard[i].getremain() << " ";
		cout << endl;
		while (loop){
			cin >> my;
			for (int i = 0; i < 3; i++){
				if (my == names[i]) loop = false;
				if (i == 2 && loop) cout << "miss!" << endl;
			}
		}
		loop = true;
		cout << "What is enemy's card?" << endl;
		for (int i = 0; i < 3; i++) cout << yourcard[i].getname() << ": " << yourcard[i].getremain() << " ";
		cout << endl;
		while (loop){
			cin >> you;
			for (int i = 0; i < 3; i++){
				if (you == names[i]) loop = false;
				if (i == 2 && loop) cout << "miss!" << endl;
			}
		}
		loop = true;
		for (int i = 0; i < 3; i++){
			if (mycard[i].getname() == my) mn = i;
			if (yourcard[i].getname() == you) yn = i;
		}
		cout << "SPIELEN!!" << endl;
		int battle = mycard[mn].spielen(yourcard[yn]);
		Spielen(battle, mycard[mn], yourcard[yn]);
		if (battle == 2) draw = false, mycard[mn].discard(), yourcard[yn].discard();
		else draw = true;
		cout << endl;
	}
}

void Spielen(int b, Card c, Card d){
	//勝ちは0 負けは1 あいこは2 特殊勝利は4
	switch (b){
	case 0:
		cout << "You WIN!!" << endl;
		player[0] += 1;
		break;
	case 1:
		cout << "You LOSE!!" << endl;
		player[1] += 1;
		break;
	case 2:
		cout << "DRAW!!" << endl;
		break;
	case 4:
		if (c.getkind() == 2){ //自分が弓だったら
			cout << "Shame on you!!" << endl;
			player[1] += 3;
		}
		else if (c.getkind() == 1){ //自分が盾だったら
			cout << "You WIN!!" << endl;
			player[0] += 3;
		}
		else{
			cout << "Error!!" << endl;
		}
		break;
	default:
		cout << "Error!!" << endl;
		break;
	}
}

/*	
//#include<afxmaskededit.h> //マスクに関する奴
std::pair<std::string, int> h("sord", 3);
std::map<std::string, int> m;
std::vector<std::vector<std::string>> v;
m["sord"] = 3;
m["bow"] = 1;
m["shield"] = 1;
std::cout << m["sord"] << std::endl;
*/