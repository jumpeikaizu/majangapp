#include"Point.h"

void Point::nuki_mentsu(int num,int k,vector<int> mentsu,vector<agari> &V,int last_kind,int atama){
	if(num==4){
		V.push_back(agari(atama,last_kind,mentsu)); //面倒になったので上がった牌についてはノーカンにしよう　のちに修正
		return;
	}

	for(int i=k;i<=37;i++){
		if(tehai[i]==0) continue;
		if(tehai[i]>=3){
			tehai[i]-=3;
			mentsu[num*2]=ANKO;
			mentsu[num*2+1]=i;
			nuki_mentsu(num+1,i,mentsu,V,last_kind,atama);
			mentsu[num*2]=-1;
			mentsu[num*2+1]=-1;
			tehai[i]+=3;
		}
		if(i%10>=1 && i%10<=7 && i<30){
			if(tehai[i]>=1 && tehai[i+1]>=1 && tehai[i+2]>=1){
				tehai[i]--;tehai[i+1]--;tehai[i+2]--;
				mentsu[num*2]=SYUNTSU;
				mentsu[num*2+1]=i;
				nuki_mentsu(num+1,i,mentsu,V,last_kind,atama);
				tehai[i]++;tehai[i+1]++;tehai[i+2]++;
				mentsu[num*2]=-1;
				mentsu[num*2+1]=-1;

			}
		}
		if(tehai[i]>=1) return;
	}
}

void Point::kokushi(int k,vector<int> mentsu,vector<agari> &V){
	for(int i=0;i<KIND;i++){
		if((i/10==3 && i!=30) || i%10 == 1 || i%10 ==9){
			if(i==k) continue;
			if(tehai[i]==0) return;
		}
	}
	mentsu[0]=KOKUSHI;
	V.push_back(agari(k,1,mentsu));
	mentsu[0]=-1;
}

void Point::titoi(int num,int k,vector<int> mentsu,vector<agari> &V){
	if(num==7){
		mentsu[0]=TITOI;
		V.push_back(agari(mentsu[1],mentsu[1],mentsu));
		return;
	}
	for(int i=k;i<KIND;i++){
		if(tehai[i]>=2){
			mentsu[num+1]=i;
			tehai[i]-=2;
			num++;
			titoi(num,i+1,mentsu,V);
			num--;
			tehai[i]+=2;
			mentsu[num+1]=-1;
		}
	}
}

int Point::calc_point(int last_kind){
	vector<int> mentsu(8,-1);
	vector<agari> V;

	for(int i=0;i<KIND;i++){
		if(tehai[i]>=2){
			tehai[i]-=2;
			nuki_mentsu(0,0,mentsu,V,last_kind,i);
			tehai[i]+=2;
		}
	}

	for(int i=0;i<KIND;i++){
		if(tehai[i]==2 && (i%10==1 || i%10==9 ||i>=31)){
			kokushi(i,mentsu,V);
		}
	}

	titoi(0,0,mentsu,V);

	int res=0;
	for(int i=0;i<V.size();i++)
		res=max(res,V[i].calc(dora));

	return res;

}

