#include<iostream>
#include<fstream>
#include<time.h>
#include"rand.h"
#include"Game.h"
#include"agari.h"
#include"Point.h"
#include"change.h"
using namespace std;

double alpha;
int Exp(int &total_play,int &total_reward,int &turn); 

//FILE *fp;

int main(int argc,char *argv[])
{
  //cout<<"alpha,agari,point,turn,time"<<endl;
  //for(alpha=0.0;alpha<=1;alpha=alpha+0.1){
  clock_t start=clock();
  //alpha = atof(argv[1]);
  init_genrand((unsigned)time(NULL));
  //init_genrand(0);
  /*if ((fp = fopen("result.csv", "w+")) == NULL) {
    printf("file open error!!\n");
    exit(EXIT_FAILURE);	
    }*/
  ifstream ifs("result.csv");
  if(ifs.fail()){
    cout<<"error"<<endl;
    exit(1);
  }
  string str;
  int i=0;
  while(getline(ifs,str)){
    i++;
  }
  
  int total_play=0,total_reward=0;
  ofstream ofs("result.csv",ios::app);
  while(1){
    //cout<<i<<"game"<<endl;
    int turn=0,agari=0;
    int p=Exp(total_play,total_reward,turn);
    if(p>0){
      printf("%d,%d,%d\n",i,p,turn);
      agari=1;
    }
    ofs<<i<<","<<agari<<","<<p<<","<<turn<<endl;
    i++;
  }

  clock_t end=clock();
  double time=(double)(end-start)/CLOCKS_PER_SEC;
  //cout<<alpha<<","<<total_agari<<","<<total_point<<","<<total_turn<<","<<time<<endl;
  //}
  //fclose(fp);
  return 0;
}

int Exp(int &total_play,int &total_reward,int &turn){
	int res=0;

	Game G(18);
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
			cout<<endl;
			return res;
		}

		int play=0,reward=0;
		string s="";
		while(1){
		  //cin.clear();
		  //cin.seekg(0);
		  //cout<<"kiru:";
		  cin>>s;
		  if(!cin||haichange(s)>37) continue;
		  if(tehai[haichange(s)]>0) break;
		}
		tehai[haichange(s)]--;
		total_play+=play;
		total_reward+=reward;
		//cout<<"kiru "<<s<<endl;
	}
	cout<<endl;
	turn=0;
	return res;
}

