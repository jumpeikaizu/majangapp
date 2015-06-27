#include"agari.h"

//とりあえずトンバの親を考えてる
int agari::count_dora(int dora){
	int res=0;
	if(atama==dora)
		res+=2;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO){
			if(mentsu[i*2+1]==dora)
				res+=3;
		}
		if(mentsu[i*2]==SYUNTSU){
			if(mentsu[i*2+1]==dora||
				mentsu[i*2+1]==dora-1 ||
				mentsu[i*2+1]==dora-2)
				res++;
		}
	}
	return res;
}

bool agari::pinhu(){
	if(atama==31 || atama>=35)
		return false;

	bool ryanmen=false;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]!=SYUNTSU)
			return false;
		int first=mentsu[i*2+1];
		if((first==last_kind && first%10<7)||
			(first+2==last_kind && first%10>=2)){
			ryanmen=true;
		}
	}
	return ryanmen?true:false;	
}

bool agari::tanyao(){
	if(atama>=30 || atama%10==1 || atama%10 ==9)
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO){
			if(mentsu[i*2+1]>=30 || mentsu[2*i+1]%10==1 || mentsu[2*i+1]%10==9)
				return false;
		}
		else if(mentsu[i*2]==SYUNTSU){
			if(mentsu[i*2+1]%10==1 || mentsu[i*2+1]%10==7)
				return false;
		}
		else{cout<<"Error tanyao\n"; return false;}
	}
	return true;
}

bool agari::ipeko(){
	int work[38];
	memset(work,0,sizeof(work));
	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=SYUNTSU)
			continue;
		work[mentsu[2*i+1]]++;
		if(work[mentsu[2*i+1]]>=2)
			return true;
	}
	return false;
}
//トンバの親を考えてます
bool agari::ton(){
	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO && mentsu[i*2+1]==31)
			return true;
	}
	return false;
}

bool agari::haku(){
		for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO && mentsu[i*2+1]==35)
			return true;
	}
	return false;
}

bool agari::hatsu(){
		for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO && mentsu[i*2+1]==36)
			return true;
	}
	return false;
}

bool agari::tyun(){
		for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO && mentsu[i*2+1]==37)
			return true;
	}
	return false;
}

//ジュンチャンとは複合しないことは判定していない
bool agari::tyanta(){
	if(atama/10!=3 && atama%10!=1 && atama%10!=9)
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO){
			if(mentsu[i*2+1]/10!=3 && mentsu[i*2+1]%10!=1 && mentsu[i*2+1]%10!=9)
				return false;
		}
		else if(mentsu[i*2]==SYUNTSU){
			if(mentsu[i*2+1]%10!=1 && mentsu[i*2+1]%10!=7)
				return false;
		}else{cout<<"Error tyanta\n"; return false;
		}
	}
	return true;
}

//ちんろうとうのとき呼ばないで！ 絶対意味がないけど一応つくった
bool agari::honroutou(){
	if(atama<30 && !(atama%10==1 || atama%10==9))
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=ANKO)
			return false;
		if(mentsu[2*i+1]<30 && !(mentsu[2*i+1]%10==1 || mentsu[2*i+1]%10==9))
			return false;
	}
	return true;
}

bool agari::sansyokudouzyun(){
	bool work[30];
	memset(work,false,sizeof(work));

	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=SYUNTSU)
			continue;
		work[mentsu[2*i+1]]=true;
	}

	for(int i=1;i<10;i++){
		if(work[i]&&work[i+10]&&work[i+20])
			return true;
	}
	return false;
}

//無きはない　必ずあんこ
bool agari::sansyokudoukou(){
	bool work[30];
	memset(work,false,sizeof(work));
	for(int i=0;i<4;i++){
		if(mentsu[i*2]!=ANKO || mentsu[i*2+1]>=30)
			continue;
		work[mentsu[i*2+1]]=true;
	}
	for(int i=1;i<10;i++){
		if(work[i]&&work[i+10]&&work[i+20])
			return true;
	}
	return false;
}

bool agari::ikkitukan(){
	bool work[9];
	memset(work,false,sizeof(work));
	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=SYUNTSU)
			continue;
		if(mentsu[2*i+1]%10==1)
			work[mentsu[2*i+1]/10*3]=true;
		else if(mentsu[2*i+1]%10==4)
			work[mentsu[2*i+1]/10*3+1]=true;
		else if(mentsu[2*i+1]%10==7)
			work[mentsu[2*i+1]/10*3+2]=true;
	}
	if((work[0]&&work[1]&&work[2])||(work[3]&&work[4]&&work[5])||(work[6]&&work[7]&&work[8]))
		return true;
	return false;
}

//必ずスーアンコになるけど、まあ一応
bool agari::toitoi(){
	for(int i=0;i<4;i++){
		if(mentsu[i*2]==SYUNTSU)
			return false;
	}
	return true;
}

bool agari::sanankou(){
	int num=0;
	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO)
			num++;
	}
	if(num==3)
		return true;
	return false;
}

bool agari::syousangen(){
	bool ok[3];
	memset(ok,false,sizeof(ok));

	if(atama<=34){
		return false;
	}
	ok[atama-35]=true;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]!=ANKO || mentsu[i*2+1]<=34)
			continue;
		ok[mentsu[i*2+1]-35]=true;
	}
	if(ok[0]&&ok[1]&&ok[2])
		return true;
	return false;
}

bool agari::titoi_tanyao(){
	for(int i=1;i<8;i++){
		if(mentsu[i]>=30 || mentsu[i]%10==1 || mentsu[i]%10==9)
			return false;
	}
	return true;
}

bool agari::titoi_honitsu(){
	int work=mentsu[1]/10;

	for(int i=1;i<8;i++){
		if(work==3)
			work=mentsu[i]/10;
		else{
			if(mentsu[i]/10!=3 && work!=mentsu[i]/10)
				return false;
		}
	}
	return true;
}

bool agari::titoi_honroutou(){
	for(int i=1;i<8;i++){
		if(mentsu[i]<30 && !(mentsu[i]%10==1 || mentsu[i]%10==9))
			return false;
	}
	return true;
}

bool agari::titoi_tinitsu(){
	int work;
	work=mentsu[1]/10;
	if(work==3)
		return false;
	for(int i=2;i<8;i++){
		if(work!=mentsu[i]/10)
			return false;
	}
	return true;
}

bool agari::titoi_tuiso(){
	for(int i=1;i<8;i++){
		if(mentsu[i]/10!=3)
			return false;
	}
	return true;
}

bool agari::ryanpeko(){
	int work[30];
	memset(work,0,sizeof(work));

	for(int i=0;i<4;i++){
		if(mentsu[i*2]!=SYUNTSU)
			return false;
		work[mentsu[i*2+1]]++;
	}

	int num=0;
	for(int i=0;i<30;i++){
		if(work[i]==1)
			return false;
		if(work[i]==2)
			num++;
		if(work[i]==4)
			return true;
	}
	if(num==2)
		return true;
	return false;
}

bool agari::zyuntyan(){
	if(atama>30 || !(atama%10==1 || atama%10==9))
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO){
			if(mentsu[i*2+1]>30 || !(mentsu[2*i+1]%10==1 || mentsu[2*i+1]%10==9))
				return false;
		}
		else if(mentsu[i*2]==SYUNTSU){
			if(!(mentsu[i*2+1]%10==1 || mentsu[2*i+1]%10==7))
				return false;
		}
	}
	return true;
}

//清一色のときに呼ばないで！
bool agari::honitsu(){
	int work= atama/10;

	for(int i=0;i<4;i++){
		if(work==3)
			work= mentsu[i*2+1]/10;
		else{
			if( mentsu[i*2+1]/10!=3 && work!= mentsu[i*2+1]/10)
				return false;
		}
	}
	if(work==3)
		return false;//つーいーそー？

	return true;
}

bool agari::tinitsu(){
	int work=atama/10;
	if(work==3)
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[i*2+1]/10!=work)
			return false;
	}
	return true;
}

bool agari::suanko(){
	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=ANKO)
			return false;
	}
	return true;
}

bool agari::daisangen(){
	bool work[3];
	memset(work,false,sizeof(work));

	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=ANKO)
			continue;
		if(mentsu[i*2+1]==35)
			work[0]=true;
		else if(mentsu[i*2+1]==36)
			work[1]=true;
		else if(mentsu[i*2+1]==37)
			work[2]=true;
	}
	if(work[0]&&work[1]&&work[2])
		return true;
	return false;
}

bool agari::tuiso(){
	if(atama<30)
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[2*i+1]<30)
			return false;
	}
	return true;
}

bool agari::syoususi(){
	bool work[4];
	memset(work,false,sizeof(work));

	if(!(atama>=31 && atama<=34))
		return false;
	work[atama-31]=true;

	for(int i=0;i<4;i++){
		if(mentsu[i*2+1]>=31 && mentsu[i*2+1]<=34){
			work[mentsu[2*i+1]-31]=true;
		}
	}

	if(work[0]&&work[1]&&work[2]&&work[3])
		return true;
	return false;
}

bool agari::daisusi(){
	bool work[4];
	memset(work,false,sizeof(work));

	for(int i=0;i<4;i++){
		if(!(mentsu[2*i+1]>=31 && mentsu[2*i+1]<=34))
			return false;
	}
	return true;
}

bool agari::ryuiso(){
	if(!(atama==22 || atama==23 || 
		 atama==24 || atama==26 || 
		 atama==28 || atama==36))
		 return false;

	for(int i=0;i<4;i++){
		if(mentsu[2*i]==SYUNTSU){
			if(mentsu[2*i+1]!=22)
				return false;
		}
		else if(!(mentsu[2*i+1]==22 || mentsu[2*i+1]==23 ||
			 	  mentsu[2*i+1]==24 || mentsu[2*i+1]==26 ||
				  mentsu[2*i+1]==28 || mentsu[2*i+1]==36))
				  return false;
	}
	return true;
}

bool agari::tyuren(){
	int work[10];
	int s=atama/10;
	if(s==3)
		return false;

	memset(work,0,sizeof(work));
	work[atama%10]+=2;
	for(int i=0;i<4;i++){
		if(mentsu[2*i+1]/10!=s)
			return false;
		if(mentsu[2*i]==ANKO)
			work[mentsu[2*i+1]%10]+=3;
		else if(mentsu[2*i]==SYUNTSU){
			work[mentsu[2*i+1]%10  ]++;
			work[mentsu[2*i+1]%10+1]++;
			work[mentsu[2*i+1]%10+2]++;
		}
	}
	if(!(work[1]>=3 && work[9]>=3))
		return false;
	for(int i=2;i<9;i++)
		if(work[i]<1)
			return false;
	return true;
}

bool agari::tinroutou(){
	if(atama>30 || !(atama%10==1 || atama%10 ==9))
		return false;

	for(int i=0;i<4;i++){
		if(mentsu[2*i]!=ANKO)
			return false;
		if(mentsu[2*i+1]>30 || !(mentsu[2*i+1]%10==1 || mentsu[2*i+1]%10==9))
			return false;
	}
	return true;
}

