#include"agari.h"

vector<int> agari::use(){
	vector<int> V(38,0);
	if(mentsu[0]==KOKUSHI){
		V[1]=V[9]=V[11]=V[19]=V[21]=V[29]=V[31]=V[32]=V[33]=V[34]=V[35]=V[36]=V[37]=1;
		V[atama]++;
		return V;
	}
	else if(mentsu[0]==TITOI){
		for(int i=1;i<8;i++)
			V[mentsu[i]]+=2;
		return V;
	}
	else{
		for(int i=0;i<4;i++){
			if(mentsu[i*2]==ANKO)
				V[mentsu[i*2+1]]+=3;
			else if(mentsu[i*2]==SYUNTSU){
				V[mentsu[i*2+1]]++;
				V[mentsu[i*2+1]+1]++;
				V[mentsu[i*2+1]+2]++;
			}
			else{cout<<"EROOOOOOOOOOOOOOOOOOOOOOOR\n";}
		}
		V[atama]+=2;
		return V;
	}
}