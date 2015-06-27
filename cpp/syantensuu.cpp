#include "syantensuu.h"

//コンストラクタ
Syanten::Syanten(){
	fuurosuu=0;

	//作業用
	int key;
	int pattern1_m;
	int pattern1_t;
	int pattern2_m;
	int pattern2_t;
	int index=1,indexloop=0;
	vector<int> tmp;

	//シャンテンファイル読み込み
	ifstream ifs("./syanten.dat");
	string str;
	if(ifs.fail()) {
		exit(0);
	}

	while(getline(ifs, str)) {
		sscanf(str.data(),"%d %d %d %d %d", &key,&pattern1_m,&pattern1_t,&pattern2_m,&pattern2_t);
		tmp.push_back(pattern1_m);
		tmp.push_back(pattern1_t);
		tmp.push_back(pattern2_m);
		tmp.push_back(pattern2_t);
		map_[key] = tmp;
		tmp.clear();
	}
}

//中身クリア
void Syanten::clear()
{
	for(int i=0;i<38;i++){
		tehai[i]=0;
	}
	tehai[38]=-1;
	fuurosuu=0;
}

//手牌セット
void Syanten::set_tehai(int t[])
{
	for(int i=0;i<38;i++){
		tehai[i]=t[i];
	}
	tehai[38]=-1;
}

//エラーチェック
bool Syanten::error_check()
{
	int tmp=0;
	for(int i=0;i<38;i++){
		tmp+=tehai[i];
	}
	if(tmp%3!=1||tmp>=14||tmp<1) return true;
	return false;
}

//国士シャンテン
int Syanten::KokusiSyanten()
{
	int kokusi_toitu=0,syanten_kokusi=13,i;             
	//老頭牌
	for(i=1;i<30;i++){        
		if(i%10==1||i%10==9||i%20==1||i%20==9){	   
			if(tehai[i])
				syanten_kokusi--;
			if(tehai[i] >=2 && kokusi_toitu==0)
				kokusi_toitu=1;	
		}
	}             
	//字牌
	for(i=31;i<38;i++){      
		if(tehai[i]){	        
			syanten_kokusi--;
			if(tehai[i] >=2 && kokusi_toitu==0)
				kokusi_toitu=1;			            
		}
	}             
	//頭
	syanten_kokusi-= kokusi_toitu;             
	return syanten_kokusi;
}

//チートイシャンテン
int Syanten::TiitoiSyanten()
{
	int i=1,toitu=0,syurui=0,syanten_tiitoi;
	//トイツ数を数える
	for(;i<=37;i++){ 
		for(;!tehai[i];i++);
		if(i>=38) continue;
		syurui++;
		if(tehai[i] >=2)
		toitu++;
	}
	syanten_tiitoi=6-toitu;
	//４枚持ちを考慮
	if(syurui<7)
		syanten_tiitoi+= 7-syurui;
	return syanten_tiitoi;
}

//通常手シャンテン
int Syanten::NormalSyanten()
{
	int result=99;
	int tmpresult=0;
	for(int i=1;i<38;i++)
	{
		//頭抜き出し
		if(2 <= tehai[i])
		{            
			tehai[i] -= 2;
			tmpresult=checkNormalSyanten()-1;
			if(tmpresult < result){
				result=tmpresult;
			}
			tehai[i] += 2;
		}
	}
    //フーロなしなら
	
	if(fuurosuu == 0){
        tmpresult=checkNormalSyanten();   //頭無しと仮定して計算
		if(tmpresult < result){
			result=tmpresult;
		}
	}


	return result;
}

//Checkシャンテン
int Syanten::checkNormalSyanten()
{
	int key=0;
	int pt1m=0,pt1t=0;
	int pt2m=0,pt2t=0;
	int pt=0,ptm=0,ptt=0;
	vector<int> tmp;

	for(int j=0;j<3;j++){
		key=0;
		for(int i=1+j*10,offset=100000000;i<=9+j*10;i++,offset/=10){
			key+=tehai[i]*offset;
		}

		tmp=map_[key];

		pt1m=tmp[0];
		pt1t=tmp[1];

		pt2m=tmp[2];
		pt2t=tmp[3];

		if(pt1m*2+pt1t>=pt2m*2+pt2t){
			ptm+=pt1m;
			ptt+=pt1t;
		}
		else{
			ptm+=pt2m;
			ptt+=pt2t;
		}
	}

	for(int i=31;i<=37;i++){
		if(tehai[i]>=3){
			ptm++;
		}
		else if(tehai[i]>=2){
			ptt++;
		}
	}
	if(ptm+ptt>4){
		while(ptm+ptt>4) ptt--;
	}
	
	return 8-ptm*2-ptt;
}


//孤立牌
void Syanten::NotKoritu ()
{
	int work[38];//作業用
	int i=0,p=0;
	//配列初期化
	memset(work,0,sizeof(work));
	memset(not_koritu,0,sizeof(not_koritu));
	//計算
	for(;i<=37;i++){ 
		for(;!tehai[i];i++);if(i>=38) continue;
		//数牌
		if(i<30){
			if(i%10==1) work[i]=work[i+1]=work[i+2]=1;
			else if(i%10==2) work[i]=work[i+1]=work[i+2]=work[i-1]=1;
			else if(i%10>=3 &&i%10<=7) work[i]=work[i-1]=work[i+1]=work[i-2]=work[i+2] =1;
			else if(i%10==8) work[i]=work[i+1]=work[i-2]=work[i-1]=1;
			else if(i%10==9) work[i]=work[i-1]=work[i-2]=1;             
		}
		//字牌
		else if(i>30) work[i]=1;
	}
	//結果を格納
	for(i=0;i<=37;i++){ 
		for(;!work[i];i++);if(i>=38) continue;
		if(tehai[i]<4){
		  not_koritu[p++]=i;
		}
	}
}

/*
* 通常手の有効牌
*/ 
bool Syanten::NormalYuukou (vector<int>  NormalYuukou[])
{
	if(error_check()) return false;

	int p_koritu=0;		//配列の添え字ポインタ（孤立牌）
	int p_yuukou=0;		//配列の添え字ポインタ（有効牌）
	int syanten=NormalSyanten();   	//現在の牌のシャンテン数 
	NormalYuukou->clear();//初期化 
	NotKoritu ();
	while(not_koritu[p_koritu] != 0){
		//否孤立牌を追加
		tehai[not_koritu[p_koritu]]++;
		//現在値と比較
		if(NormalSyanten() <syanten)
			NormalYuukou->push_back(not_koritu[p_koritu]);
		//追加した否孤立牌をマイナス
		tehai[not_koritu[p_koritu]]--;
		p_koritu++;
	}
	return true;
}

/*
* チートイツの有効牌
*/
bool Syanten::TiitoiYuukou (vector<int>  TiitoiYuukou [])
{
	if(error_check()) return false;

	int i=0;//配列の添え字ポインタ（孤立牌）
	int syanten=TiitoiSyanten();  //現在の牌のシャンテン数 
	TiitoiYuukou->clear();//初期化 
	while(i<=37){
		//否孤立牌を追加
		for(;!tehai[i];i++);if(i>=38) continue;
		tehai[i]++;
		//現在値と比較
		if(TiitoiSyanten() <syanten)
		TiitoiYuukou->push_back(i);
		//追加した否孤立牌をマイナス
		tehai[i]--;
		i++;
	}	
	return true;
}

/*
* 国士無双の有効牌
*/ 
bool Syanten::KokusiYuukou (vector<int>  KokusiYuukou [])
{
	if(error_check()) return false;

	int i=0;
	int syanten=KokusiSyanten();//現在の牌のシャンテン数
	KokusiYuukou->clear();//初期化 
	int yaotyuu[13]={1,9,11,19,21,29,31,32,33,34,35,36,37};
	for(;i<13;i++){
		//否孤立牌を追加
		tehai[yaotyuu[i]]++;
		//現在値と比較
		if(KokusiSyanten() <syanten)
			KokusiYuukou->push_back(yaotyuu[i]);
		//追加した否孤立牌をマイナス
		tehai[yaotyuu[i]]--;
	}
	return true;
}

bool Syanten::NormalDown (vector<int> NormalDown[]){
  int syanten=NormalSyanten()+1;
  NormalDown->clear();
  for(int i=0;i<=37;i++){
    if(tehai[i]){
      tehai[i]--;
      if(NormalSyanten()<syanten){
	NormalDown->push_back(i);
      }
      tehai[i]++;
    }
  }
  return true;
}

bool Syanten::KokusiDown (vector<int> KokusiDown[]){
  int syanten=KokusiSyanten()+1;
  KokusiDown->clear();
  for(int i=0;i<=37;i++){
    if(tehai[i]){
      tehai[i]--;
      if(KokusiSyanten()<syanten){
	KokusiDown->push_back(i);
      }
      tehai[i]++;
    }
  }
  return true;
}

bool Syanten::TiitoiDown (vector<int> TiitoiDown[]){
  int syanten=TiitoiSyanten()+1;
  TiitoiDown->clear();
  for(int i=0;i<=37;i++){
    if(tehai[i]){
      tehai[i]--;
      if(TiitoiSyanten()<syanten){
	TiitoiDown->push_back(i);
      }
      tehai[i]++;
    }
  }
  return true;
}
