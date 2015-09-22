#pragma once

#include<vector>
#include<iostream>
#include<cstring>
using namespace std;


#define KIND 38
class Game{//ゲーム（実験）を管理
	vector<int> Yama; //山
	int dora;//ドラ
	int now_turn;
	int nokori_turn;//残りターン
public:
  Game(int init_nokori_turn);//ランダム
  Game(int init_nokori_turn,int game);
  Game(int init_nokori_turn,int init_dora,vector<int> init_tehai);//配牌指定

	int tsumo(){//ツモる牌を渡して，ターンを進める
		int res=Yama[now_turn];
		now_turn++;
		nokori_turn--;
		return res;
	}
	vector<int> get_tehai(){//手牌を渡して，ターンを進める
		vector<int> res;
		for(int i=0;i<13;i++){
			res.push_back(Yama[i]);
		}
		now_turn+=13;
		return res;
	}

	void print_yama(){
		for(int i=0;i<Yama.size();i++)
			cout<<Yama[i]<<" ";
		cout<<endl;
	}
	int get_info_dora(){return dora;}
};
