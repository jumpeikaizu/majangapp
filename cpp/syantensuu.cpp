#include "syantensuu.h"

//�R���X�g���N�^
Syanten::Syanten(){
	fuurosuu=0;

	//��Ɨp
	int key;
	int pattern1_m;
	int pattern1_t;
	int pattern2_m;
	int pattern2_t;
	int index=1,indexloop=0;
	vector<int> tmp;

	//�V�����e���t�@�C���ǂݍ���
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

//���g�N���A
void Syanten::clear()
{
	for(int i=0;i<38;i++){
		tehai[i]=0;
	}
	tehai[38]=-1;
	fuurosuu=0;
}

//��v�Z�b�g
void Syanten::set_tehai(int t[])
{
	for(int i=0;i<38;i++){
		tehai[i]=t[i];
	}
	tehai[38]=-1;
}

//�G���[�`�F�b�N
bool Syanten::error_check()
{
	int tmp=0;
	for(int i=0;i<38;i++){
		tmp+=tehai[i];
	}
	if(tmp%3!=1||tmp>=14||tmp<1) return true;
	return false;
}

//���m�V�����e��
int Syanten::KokusiSyanten()
{
	int kokusi_toitu=0,syanten_kokusi=13,i;             
	//�V���v
	for(i=1;i<30;i++){        
		if(i%10==1||i%10==9||i%20==1||i%20==9){	   
			if(tehai[i])
				syanten_kokusi--;
			if(tehai[i] >=2 && kokusi_toitu==0)
				kokusi_toitu=1;	
		}
	}             
	//���v
	for(i=31;i<38;i++){      
		if(tehai[i]){	        
			syanten_kokusi--;
			if(tehai[i] >=2 && kokusi_toitu==0)
				kokusi_toitu=1;			            
		}
	}             
	//��
	syanten_kokusi-= kokusi_toitu;             
	return syanten_kokusi;
}

//�`�[�g�C�V�����e��
int Syanten::TiitoiSyanten()
{
	int i=1,toitu=0,syurui=0,syanten_tiitoi;
	//�g�C�c���𐔂���
	for(;i<=37;i++){ 
		for(;!tehai[i];i++);
		if(i>=38) continue;
		syurui++;
		if(tehai[i] >=2)
		toitu++;
	}
	syanten_tiitoi=6-toitu;
	//�S���������l��
	if(syurui<7)
		syanten_tiitoi+= 7-syurui;
	return syanten_tiitoi;
}

//�ʏ��V�����e��
int Syanten::NormalSyanten()
{
	int result=99;
	int tmpresult=0;
	for(int i=1;i<38;i++)
	{
		//�������o��
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
    //�t�[���Ȃ��Ȃ�
	
	if(fuurosuu == 0){
        tmpresult=checkNormalSyanten();   //�������Ɖ��肵�Čv�Z
		if(tmpresult < result){
			result=tmpresult;
		}
	}


	return result;
}

//Check�V�����e��
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


//�Ǘ��v
void Syanten::NotKoritu ()
{
	int work[38];//��Ɨp
	int i=0,p=0;
	//�z�񏉊���
	memset(work,0,sizeof(work));
	memset(not_koritu,0,sizeof(not_koritu));
	//�v�Z
	for(;i<=37;i++){ 
		for(;!tehai[i];i++);if(i>=38) continue;
		//���v
		if(i<30){
			if(i%10==1) work[i]=work[i+1]=work[i+2]=1;
			else if(i%10==2) work[i]=work[i+1]=work[i+2]=work[i-1]=1;
			else if(i%10>=3 &&i%10<=7) work[i]=work[i-1]=work[i+1]=work[i-2]=work[i+2] =1;
			else if(i%10==8) work[i]=work[i+1]=work[i-2]=work[i-1]=1;
			else if(i%10==9) work[i]=work[i-1]=work[i-2]=1;             
		}
		//���v
		else if(i>30) work[i]=1;
	}
	//���ʂ��i�[
	for(i=0;i<=37;i++){ 
		for(;!work[i];i++);if(i>=38) continue;
		if(tehai[i]<4){
		  not_koritu[p++]=i;
		}
	}
}

/*
* �ʏ��̗L���v
*/ 
bool Syanten::NormalYuukou (vector<int>  NormalYuukou[])
{
	if(error_check()) return false;

	int p_koritu=0;		//�z��̓Y�����|�C���^�i�Ǘ��v�j
	int p_yuukou=0;		//�z��̓Y�����|�C���^�i�L���v�j
	int syanten=NormalSyanten();   	//���݂̔v�̃V�����e���� 
	NormalYuukou->clear();//������ 
	NotKoritu ();
	while(not_koritu[p_koritu] != 0){
		//�یǗ��v��ǉ�
		tehai[not_koritu[p_koritu]]++;
		//���ݒl�Ɣ�r
		if(NormalSyanten() <syanten)
			NormalYuukou->push_back(not_koritu[p_koritu]);
		//�ǉ������یǗ��v���}�C�i�X
		tehai[not_koritu[p_koritu]]--;
		p_koritu++;
	}
	return true;
}

/*
* �`�[�g�C�c�̗L���v
*/
bool Syanten::TiitoiYuukou (vector<int>  TiitoiYuukou [])
{
	if(error_check()) return false;

	int i=0;//�z��̓Y�����|�C���^�i�Ǘ��v�j
	int syanten=TiitoiSyanten();  //���݂̔v�̃V�����e���� 
	TiitoiYuukou->clear();//������ 
	while(i<=37){
		//�یǗ��v��ǉ�
		for(;!tehai[i];i++);if(i>=38) continue;
		tehai[i]++;
		//���ݒl�Ɣ�r
		if(TiitoiSyanten() <syanten)
		TiitoiYuukou->push_back(i);
		//�ǉ������یǗ��v���}�C�i�X
		tehai[i]--;
		i++;
	}	
	return true;
}

/*
* ���m���o�̗L���v
*/ 
bool Syanten::KokusiYuukou (vector<int>  KokusiYuukou [])
{
	if(error_check()) return false;

	int i=0;
	int syanten=KokusiSyanten();//���݂̔v�̃V�����e����
	KokusiYuukou->clear();//������ 
	int yaotyuu[13]={1,9,11,19,21,29,31,32,33,34,35,36,37};
	for(;i<13;i++){
		//�یǗ��v��ǉ�
		tehai[yaotyuu[i]]++;
		//���ݒl�Ɣ�r
		if(KokusiSyanten() <syanten)
			KokusiYuukou->push_back(yaotyuu[i]);
		//�ǉ������یǗ��v���}�C�i�X
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
