
#pragma once

#include<cstring>
#include"util.h"
#include"Game.h"

class agari{
	int last_kind;
	int atama;
	vector<int> mentsu;
public:
  agari(int init_atama,int init_last_kind,vector<int> m)//:atama(atama),last_kind(last_kind)
  {
    atama=init_atama;
    last_kind=init_last_kind;
    mentsu=m;
  }
	void print(){
		cout<<"atama is "<<atama<<endl;
		for(int i=0;i<mentsu.size();i++)
			cout<<mentsu[i]<<" ";
		cout<<endl;
	};
	vector<int> use();

	int calc(int dora);
    int hansuu(int dora);

	bool daisusi();
	bool honitsu();
	bool honroutou();
	bool ikkitukan();
	bool ipeko();
	bool pinhu();
	bool ryuiso();
	bool sanankou();
	bool sansyokudoukou();
	bool sansyokudouzyun();
	bool suanko();
	bool syousangen();
	bool syoususi();
	bool tanyao();
	bool tinitsu();
	bool tinroutou();
	bool titoi_honitsu();
	bool titoi_honroutou();
	bool titoi_tanyao();
	bool titoi_tinitsu();
	bool toitoi();
	bool tuiso();
	bool tyanta();
	bool tyuren();
	bool yakuhai();
	bool zyuntyan();
	bool ryanpeko();
	bool daisangen();
	bool ton();
	bool hatsu();
	bool haku();
	bool tyun();
	bool titoi_tuiso();
	int count_dora(int dora);

};
