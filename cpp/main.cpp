#include<iostream>
#include<fstream>
#include<time.h>
#include"rand.h"
#include"Game.h"
#include"agari.h"
#include"Point.h"
#include"util.h"
using namespace std;

double alpha;
int Exp(int &total_play,int &total_reward,int &turn); 
void printtehai(int tehai[KIND]);
int game=0;

int main()
{
  //cout<<"alpha,agari,point,turn,time"<<endl;
  init_genrand((unsigned)time(NULL));
  //init_genrand(0);
  ifstream ifs("result.csv");
  if(ifs.fail()){
    cout<<"error"<<endl;
    exit(1);
  }
  string str;
  while(getline(ifs,str)){
    game++;
  }
  
  int total_play=0,total_reward=0;
  ofstream ofs("result.csv",ios::app);
  while(1){
    //cout<<i<<"game"<<endl;
    int turn=0,agari=0;
    int p=Exp(total_play,total_reward,turn);
    if(p>0){
      agari=1;
    }
    ofs<<game<<","<<agari<<","<<p<<","<<turn<<endl;
	game++;
  }

  //cout<<alpha<<","<<total_agari<<","<<total_point<<","<<total_turn<<","<<time<<endl;
  return 0;
}

int Exp(int &total_play,int &total_reward,int &turn){
  int res=0;
  //cout<<"game:"<<game<<endl;
  Game G(18,game);
  vector<int> t=G.get_tehai();
  //cout<<"dora:"<<numchange(G.get_info_dora())<<endl;

  int tehai[KIND];
  int nokori[KIND];
  memset(tehai,0,sizeof(tehai));
  turn=0;

  for(int i=0;i<KIND;i++)
	nokori[i]=4;

  for(int i=0;i<t.size();i++){
	tehai[t[i]]++;
	nokori[t[i]]--;
  }
	
  for(int n=1;n<=18;n++){
	cout<<n<<endl;
	int tsumo=G.tsumo();
	nokori[tsumo]--;
	tehai[tsumo]++;
	Point P(tehai,G.get_info_dora());
	int p=P.calc_point(tsumo);
	turn++;
		
	//cout<<n<<":tsumo:"<<numchange(tsumo)<<endl;
	for(int i=0;i<KIND;i++)
	  for(int j=0;j<tehai[i];j++)
		cout<<numchange(i)<<" ";
	cout<<endl;

	if(p>0){
	  res+=p;
	  cout<<p<<endl;
	  return res;
	}
	cout<<"next"<<endl;
		
	int play=0,reward=0;
	string s="";
	while(1){
	  cin.clear();
	  //cin.seekg(0);
	  //cout<<"kiru:";
	  cin>>s;
	  bool flag = false;
	  for(int i=0;i<KIND;i++)
		for(int j=0;j<tehai[i];j++)
		  if(numchange(i)==s) flag = true;
	  if(flag==true) break;
	  //if(!cin||haichange(s)>37) continue;
	  //if(tehai[haichange(s)]>0) break;
	}
	tehai[haichange(s)]--;
	total_play+=play;
	total_reward+=reward;
  }
  turn=0;
	
  return res;
}
