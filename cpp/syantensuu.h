
#pragma once
#ifndef __SYANTEN
#define __SYANTEN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

//�V�����e������Ԃ��N���X(HashTable��)
class Syanten{

	void mentu_cut(int);//�����c�����֐�
	void taatu_cut(int);//�^�[�c�����֐�

	int tehai[39];
	int mentu;		//�����c��
	int toitu;		//�g�C�c��
	int kouho;		//�^�[�c��
	int fuurosuu;		//�t�[����
	int temp;		//�V�����e�����i�v�Z�p�j
	int syanten_normal;	//�V�����e�����i���ʗp�j

        void NotKoritu();
	int not_koritu[38];//�Ǘ��v�łȂ��v�i�[�p

	bool error_check();


public:
	Syanten();//�R���X�g���N�^
	int NormalSyanten();//�ʏ��V�����e��
	int KokusiSyanten();//���m�V�����e��
	int TiitoiSyanten();//�`�[�g�C�V�����e��
  
  	bool NormalYuukou (vector<int> NormalYuukou[]);//�ʏ��L���v
	bool TiitoiYuukou (vector<int> TiitoiYuukou[]);//���m�L���v
	bool KokusiYuukou (vector<int> KokusiYuukou[]);//�`�[�g�C�L���v

  bool NormalDown (vector<int> NormalDown[]);
  bool KokusiDown (vector<int> KokusiDown[]);
  bool TiitoiDown (vector<int> TiitoiDown[]);
  
	void set_tehai(int t[]);//��v�Z�b�g�iint[38]�ȏ�A�ԓ����ς݁j
	void set_fuurosuu(int a){fuurosuu=a;}//�t�[����
	void clear();//���g�N���A
	//�ʏ�V�����e����Ɨp
	int checkNormalSyanten();
	map<int, vector<int> > map_; 
};

#endif
