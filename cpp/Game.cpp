#include"Game.h"
#include<algorithm>
#include<fstream>
#include<sstream>
#include<string>
#include"rand.h"

Game::Game(int init_nokori_turn){
    nokori_turn=init_nokori_turn;
	now_turn=0;
	Yama.clear();
	for(int k=0;k<KIND;k++){
		if(k%10==0) continue;
		for(int n=0;n<4;n++){
			Yama.push_back(k);
		}
	}

	//srand(0);
	random_shuffle(Yama.begin(),Yama.end());

	dora=Yama[Yama.size()-1];

}

Game::Game(int init_nokori_turn,int game){
  nokori_turn=init_nokori_turn;
  now_turn=0;
  Yama.clear();
  ifstream ifs("yama.txt");
  string yama;
  for(int i=0;i<game;i++){
	getline(ifs,yama);
  }
  stringstream ss(yama);
  string hai;
  while(getline(ss,hai,' ')){
	Yama.push_back(stoi(hai));
  }
}


Game::Game(int init_nokori_turn,int init_dora,vector<int> init_tehai){
	nokori_turn=init_nokori_turn;
	dora=init_dora;
	now_turn=0;
	Yama.clear();

	int nokori[KIND];

	for(int i=0;i<KIND;i++)
		nokori[i]=4;

	for(int i=0;i<init_tehai.size();i++)
		nokori[init_tehai[i]]--;

	vector<int> work;//混ぜたい

	for(int k=0;k<KIND;k++){
		if(k%10==0) continue;
		for(int n=0;n<nokori[k];n++){
			work.push_back(k);
		}
	}
	random_shuffle(work.begin(),work.end(),r_gen);

	for(int i=0;i<init_tehai.size();i++)
		Yama.push_back(init_tehai[i]);

	for(int i=0;i<work.size();i++)
		Yama.push_back(work[i]);

}
