
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

//シャンテン数を返すクラス(HashTable版)
class Syanten{

	void mentu_cut(int);//メンツ抜き関数
	void taatu_cut(int);//ターツ抜き関数

	int tehai[39];
	int mentu;		//メンツ数
	int toitu;		//トイツ数
	int kouho;		//ターツ数
	int fuurosuu;		//フーロ数
	int temp;		//シャンテン数（計算用）
	int syanten_normal;	//シャンテン数（結果用）

        void NotKoritu();
	int not_koritu[38];//孤立牌でない牌格納用

	bool error_check();


public:
	Syanten();//コンストラクタ
	int NormalSyanten();//通常手シャンテン
	int KokusiSyanten();//国士シャンテン
	int TiitoiSyanten();//チートイシャンテン
  
  	bool NormalYuukou (vector<int> NormalYuukou[]);//通常手有効牌
	bool TiitoiYuukou (vector<int> TiitoiYuukou[]);//国士有効牌
	bool KokusiYuukou (vector<int> KokusiYuukou[]);//チートイ有効牌

  bool NormalDown (vector<int> NormalDown[]);
  bool KokusiDown (vector<int> KokusiDown[]);
  bool TiitoiDown (vector<int> TiitoiDown[]);
  
	void set_tehai(int t[]);//手牌セット（int[38]以上、赤統合済み）
	void set_fuurosuu(int a){fuurosuu=a;}//フーロ数
	void clear();//中身クリア
	//通常シャンテン作業用
	int checkNormalSyanten();
	map<int, vector<int> > map_; 
};

#endif
