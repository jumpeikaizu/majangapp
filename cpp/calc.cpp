#include"agari.h"
int my_pow(int a,int b){
	int res=1;
	for(int i=0;i<b;i++){
		res*=a;
	}
	return res;
}

int point(int num,int hu){
	if(hu!=25)
		hu=(hu%10>0)?hu+10-hu%10 : hu;
	int kihon=hu*my_pow(2,num+2);
	if(kihon>=2000)
		kihon=2000;
	if(num==5)
		kihon=2000;
	if(num>=6)
		kihon=3000;
	if(num>=8)
		kihon=4000;
	if(num>=11)
		kihon=6000;
	if(num>=13)
		kihon=8000*(num/13);

	int res=kihon*6;
	res=(res%100>0)?res+100-res%100 : res;
	
	return res;
}

int agari::calc(int dora){
/*	cout<<"turn : "<<agari_turn<<endl;;
	cout<<"last tsumo: "<<last_kind<<endl;
	cout<<"atama: "<<atama<<endl;
	for(int j=0;j<mentsu.size();j++){
				cout<<mentsu[j]<<" ";
			}
	cout<<endl;
	*/
	
	
	bool yakuman=false;
//	if(last_kind==0){              //今回はスルー
//		cout<<"enter last kind\n";
//		cin>>last_kind;
//	}
	
	int hu=22;//とりあえずツモしか考えない

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==SYUNTSU){
			if(mentsu[i*2+1]%10==1 && last_kind%10==3){
				hu=24;
				break;
			}
			if(mentsu[i*2+1]%10==7 && last_kind%10==7){
				hu=24;
				break;
			}
			if(mentsu[i*2+1]%10+1==last_kind%10){
				hu=24;
				break;
			}
		}
	}
	if(atama==last_kind)
		hu=24;

	if(atama==31 || atama==35 || atama==36 || atama==37)
		hu+=2;
	if(atama==31)
		hu+=2;

	for(int i=0;i<4;i++){
		if(mentsu[i*2]==ANKO){
			if(mentsu[i*2+1]%10==1 || mentsu[i*2+1]%10==9 || mentsu[i*2+1]>30)
				hu+=8;
			else hu+=4;
		}
	}

	int num=hansuu(dora);

//	cout<<point(num,hu)<<endl;
	return point(num,hu);
}

int agari::hansuu(int dora){
  int num=0;
	if(mentsu[0]==KOKUSHI){
	        num=13;
		return num;
	}

	if(mentsu[0]==TITOI){
		num+=2;

		if(titoi_tuiso()){
			num=13;
			return num;
		}

		if(titoi_tanyao())
			num++;

		if(titoi_tinitsu())
			num+=6;
		else if(titoi_honitsu())
			num+=3;

		if(titoi_honroutou())
			num+=2;
		num++;
		return num;
	}

	if(tinroutou())
		num+=13;	

	if(daisangen())
		num+=13;

	if(tuiso())
		num+=13;
	if(daisusi()){
		num+=13;
	}else if(syoususi())
		num+=13;
	if(ryuiso())
		num+=13;
	if(suanko())
		num+=13;
	if(tyuren())
		num+=13;

	if(num>=13){
		return num;
	}
	if(ton())
		num+=2;

	if(hatsu())
		num++;
	if(haku())
		num++;
	if(tyun())
		num++;
	if(pinhu()){
		num++;
	}
	if(tanyao())
		num++;

	if(zyuntyan())
		num+=3;
	else if(honroutou())
		num+=2;
	else if(tyanta())
		num+=2;

	if(ikkitukan())
		num+=2;

	if(sansyokudoukou())
		num+=2;

	if(sansyokudouzyun())
		num+=2;

	if(toitoi())
		num+=2;

	if(sanankou())
		num+=2;

	if(syousangen())
		num+=2;

	if(ryanpeko()){
		num+=3;
	}else if(ipeko())
		num++;

	if(tinitsu()){
		num+=6;
	}else if(honitsu())
		num+=3;
	num+=count_dora(dora);
	num++;

	return num;
}
