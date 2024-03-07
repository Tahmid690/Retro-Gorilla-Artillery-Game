# include "iGraphics.h"
#include<windows.h>

#include<iostream>
using namespace std;

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

int building_chk[1500][1000];
int main_menu=1,options=0;
int game_on=0;
int round_no=0;
int skin=0;
int game_running=0;
int obj_move=0,player_turn=0;
double tim=0;
int wind_mod=rand()%100;
int destruction_mode=1;
double velocity1=0,angle1=0;
double velocity2=0,angle2=0;
double velocity=0,angle=0;
int wind=0;
int gor_cnt=0;
int sound=1;
int skin_menu=0;

int skin_bkg[3][10]={{153,204,207},
				   {204,255,209},
				   {255,229,230}};

int alter[3][10]={{0,0,0},
				   {0,0,0},
				   {0,0,0}};

int skin_build_col1[3][10]={{0,0,21},
				   {0,102,23},
				   {102,0,57}};
int skin_build_col2[3][10]={{0,0,148},
				   {128,204,151},
				   {255,102,188}};
int skin_build_col3[3][10]={{0,0,58},
				   {0,51,60},
				   {51,0,85}};


double cpx,cpy;
double inicpx1,inicpy1;
double inicpx2,inicpy2;

int score_1=0,score_2=0;
int round_over=0;

double descpx[1000],descpy[1005];
int desidx=0;

int game_mode=1;
int tmp_cnt=0;
int tot_round=1;
int downmode=0;

int cpu_err_set=15;
double dmg=25;
int dmg_lvl=20;
int pts1,pts2;
int down[15];

int fg_flg=0;

int upflg=0,uv=0,uidx=0;

int is_building(double px,double py){
	int cx=px,cy=py;
	if(px<=0 || px>=1300) return 1;
	if(py>700) return 0;
	int ret=0;
	for(int i=cx;i<=cx+43;i++){
		for(int j=cy;j<=cy+43;j++){
			if(building_chk[i][j]) ret = building_chk[i][j];
		}	
	}
	return ret;
}


void background_skin(){
	iSetColor(skin_bkg[0][skin],skin_bkg[1][skin],skin_bkg[2][skin]);
	iFilledRectangle(0,0,1300,700);
}

void buildings_round1(){
	if(!game_running || game_mode) memset(building_chk,0,sizeof building_chk);
	if(!game_running) memset(down,0,sizeof down);
	int build_height[]={300,150,210,180,320,250,80,230,380,190,310,140,120};
	if(!game_running){
		cpx=40,cpy=301;
		inicpx1=cpx,inicpy1=cpy;
		inicpx2=1300-60,inicpy2=121;

		score_1=score_2=0;
	}
	
	int rc=0,gc=0,bc=0;
	for(int xc=0;xc<1300;xc+=100){
		if(xc%3==0) iSetColor(skin_build_col1[0][skin],skin_build_col1[1][skin],skin_build_col1[2][skin]);
		else if(xc%3==1) iSetColor(skin_build_col2[0][skin],skin_build_col2[1][skin],skin_build_col2[2][skin]);
		else if(xc%3==2) iSetColor(skin_build_col3[0][skin],skin_build_col3[1][skin],skin_build_col3[2][skin]);
		
		iFilledRectangle(xc,0,100,build_height[xc/100]+down[xc/100]);

		//pixel_marking
		if(!game_running){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}
		if(game_mode){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100]+down[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}


		//Windows

		for(int j=xc+10;j<xc+100-10;j+=20){
			for(int k=10;k<build_height[j/100]+down[j/100]-10;k+=20){
				iSetColor(224,224,224); 
				iFilledRectangle(j,k,10,10);
			}
		}
		
	}
	

	
}

void buildings_round2(){
	// printf("%d\n",round_no);
	if(!game_running || game_mode) memset(building_chk,0,sizeof building_chk);
	if(!game_running) memset(down,0,sizeof down);
	int build_height[]={140,100,250,250,90,120,130,400,120,150,200,140,150};
	if(!game_running){
		cpx=40,cpy=141;
		inicpx1=cpx,inicpy1=cpy;
		inicpx2=1300-60,inicpy2=151;
	}
	
	int rc=0,gc=0,bc=0;
	for(int xc=0;xc<1300;xc+=100){
		if(xc%3==0) iSetColor(skin_build_col1[0][skin],skin_build_col1[1][skin],skin_build_col1[2][skin]);
		else if(xc%3==1) iSetColor(skin_build_col2[0][skin],skin_build_col2[1][skin],skin_build_col2[2][skin]);
		else if(xc%3==2) iSetColor(skin_build_col3[0][skin],skin_build_col3[1][skin],skin_build_col3[2][skin]);
		
		iFilledRectangle(xc,0,100,build_height[xc/100]+down[xc/100]);

		//pixel_marking
		if(!game_running){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}

		if(game_mode){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100]+down[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}
		//Windows

		for(int j=xc+10;j<xc+100-10;j+=20){
			for(int k=10;k<build_height[j/100]+down[j/100]-10;k+=20){
				iSetColor(224,224,224); 
				iFilledRectangle(j,k,10,10);
			}
		}
		
	}
	


	
}

void buildings_round3(){
	if(!game_running || game_mode) memset(building_chk,0,sizeof building_chk);
	if(!game_running) memset(down,0,sizeof down);
	int build_height[]={170,150,180,150,120,180,400,380,430,450,440,370,360};
	if(!game_running){
		cpx=40,cpy=171;
		inicpx1=cpx,inicpy1=cpy;
		inicpx2=1300-60,inicpy2=361;
	}
	
	int rc=0,gc=0,bc=0;
	for(int xc=0;xc<1300;xc+=100){
		if(xc%3==0) iSetColor(skin_build_col1[0][skin],skin_build_col1[1][skin],skin_build_col1[2][skin]);
		else if(xc%3==1) iSetColor(skin_build_col2[0][skin],skin_build_col2[1][skin],skin_build_col2[2][skin]);
		else if(xc%3==2) iSetColor(skin_build_col3[0][skin],skin_build_col3[1][skin],skin_build_col3[2][skin]);
		
		iFilledRectangle(xc,0,100,build_height[xc/100]+down[xc/100]);

		//pixel_marking
		if(!game_running){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}
		if(game_mode){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100]+down[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}

		//Windows

		for(int j=xc+10;j<xc+100-10;j+=20){
			for(int k=10;k<build_height[j/100]+down[j/100]-10;k+=20){
				iSetColor(224,224,224); 
				iFilledRectangle(j,k,10,10);
			}
		}
		
	}
	


	
}

void buildings_round4(){
	if(!game_running || game_mode) memset(building_chk,0,sizeof building_chk);
	if(!game_running) memset(down,0,sizeof down);
	int build_height[]={140,100,250,250,320,600,280,100,180,250,140,140,120};
	if(!game_running){
		cpx=40,cpy=141;
		inicpx1=cpx,inicpy1=cpy;
		inicpx2=1300-60,inicpy2=121;
	}
	
	int rc=0,gc=0,bc=0;
	for(int xc=0;xc<1300;xc+=100){
		if(xc%3==0) iSetColor(skin_build_col1[0][skin],skin_build_col1[1][skin],skin_build_col1[2][skin]);
		else if(xc%3==1) iSetColor(skin_build_col2[0][skin],skin_build_col2[1][skin],skin_build_col2[2][skin]);
		else if(xc%3==2) iSetColor(skin_build_col3[0][skin],skin_build_col3[1][skin],skin_build_col3[2][skin]);
		
		iFilledRectangle(xc,0,100,build_height[xc/100]+down[xc/100]);

		//pixel_marking
		if(!game_running){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}
		if(game_mode){
			for(int i=xc;i<xc+100;i++){
				for(int j=0;j<=build_height[xc/100]+down[xc/100];j++){
					building_chk[i][j]=i/100+1;
				} 
			}
		}

		//Windows

		for(int j=xc+10;j<xc+100-10;j+=20){
			for(int k=10;k<build_height[j/100]+down[j/100]-10;k+=20){
				iSetColor(224,224,224); 
				iFilledRectangle(j,k,10,10);
			}
		}
		
	}
	

	
}

void building_draw(){
	switch(round_no){
		case 1:
			buildings_round1();
			break;
		case 2:
			if(tot_round>=2) buildings_round2();
			break;
		case 3:
			if(tot_round>=3) buildings_round3();
			break;
		case 4:
			if(tot_round>=4) buildings_round4();
			break;
		default:
			break;
		}
}

void calc_path(){
	tim+=0.1;
	if(player_turn==0){
		cpx=inicpx1+(velocity*cos(angle*acos(-1)/180.0)+wind)*tim;
		cpy=inicpy1+velocity*sin(angle*acos(-1)/180.0)*tim-0.5*9.8*tim*tim;
	}
	else{
		cpx=inicpx2-(velocity*cos((angle)*acos(-1)/180.0)+wind)*tim;
		cpy=inicpy2+velocity*sin((angle)*acos(-1)/180.0)*tim-0.5*9.8*tim*tim;
	}
	// if(!game_mode || !player_turn) return;
	// if(!player_turn) printf("%lf %lf\n",cpx,cpy);
	// printf("%lf %lf\n",velocity,angle);
}

void show_tracjectory(){
	if(obj_move) return;

	double tmpx,tmpy;
	for(double r=30;r<=200;r+=20){
		if(player_turn==0){
			tmpx=r*cos((angle)*acos(-1)/180.0)+cpx+15;
			tmpy=r*sin((angle)*acos(-1)/180.0)+cpy+10;
		}
		else{
			tmpx=-r*cos((angle)*acos(-1)/180.0)+cpx;
			tmpy=r*sin((angle)*acos(-1)/180.0)+cpy;			
		}
	iSetColor(255,255,255);
	iFilledCircle(tmpx,tmpy,2);
	// printf("%lf %lf\n",tmpx,tmpy);
	}
	
}

void show_data(){
	iSetColor(alter[0][0],alter[1][0],alter[2][0]);
	if(player_turn==0){
		velocity1=velocity;
		angle1=angle;
	}
	else{
		velocity2=velocity;
		angle2=angle;
	}
	char pr[100];
	sprintf(pr,"Velocity : %0.2lf",velocity2);
	iText(1150,630,pr);
	sprintf(pr,"Angle : %0.2lf",angle2);
	iText(1150,610,pr);
	if(!game_mode) sprintf(pr,"Points : %d",pts2);
	if(!game_mode) iText(1150,590,pr);

	sprintf(pr,"Velocity : %0.2lf",velocity1);
	iText(40,630,pr);
	sprintf(pr,"Angle : %0.2lf",angle1);
	iText(40,610,pr);
	sprintf(pr,"Points : %d",pts1);
	iText(40,590,pr);

	// sprintf(pr,"X-axis : %0.2lf",cpx);
	// iText(1100,610,pr);
	// sprintf(pr,"Y-axis : %0.2lf",cpy);
	// iText(1100,590,pr);
	int ttm=15;
	iSetColor(0,0,0);
	iFilledRectangle(40,670-ttm,80,20);
	sprintf(pr,"%d : %d",score_1,score_2);
	iSetColor(255,255,255);
	iText(59,676-ttm,pr);

	if(wind!=0){
		if(wind>0) iShowBMP(650,670-ttm,"Pics//ria.png");
		else if(wind<0) iShowBMP(650,670-ttm,"Pics//lea.png");
	}
}

void show_destruction(){
	for(int i=0;i<desidx;i++){
			// printf("%lf %lf\n",descpx[i],descpy[i]);
			iSetColor(skin_bkg[0][skin],skin_bkg[1][skin],skin_bkg[2][skin]);
			// iSetColor(0,0,0);
			iFilledCircle(descpx[i],descpy[i],dmg);
	}
	// cout << endl;
}

void calc_cpu(){
	double cpu_angle=rand();
	while(cpu_angle<20 || cpu_angle>80) cpu_angle=rand();
	double dx=inicpx2-inicpx1,dy=inicpy1-inicpy2;
	double cpu_v;
	double theta=(cpu_angle*acos(-1.0)/180.0);
	cpu_v=sqrt((9.8*dx*dx)/((dx*tan(theta)-dy)*2.0*cos(theta)*cos(theta)));
	
	double err=100;
	while(err<0 || err>cpu_err_set) err=rand();
	int tx=rand()%2;
	if(tx && cpu_v-err>20) velocity=cpu_v-err;
	else if(cpu_v+err<140) velocity=cpu_v+err;
	else calc_cpu();

	angle=cpu_angle;
}

int downflg=0,dv=0,didx;
void chk_stop(){
	
	double destx,desty;
	if(player_turn==0){
		destx=inicpx2;
		desty=inicpy2;
		if(max(destx+43,cpx+43)-min(destx,cpx)<=2*43 && max(desty+43,cpy+43)-min(desty,cpy)<=2*43){
			score_1++;
			player_turn=0;
			obj_move=0;
			velocity=0;
			angle=0;
			tim=0;
			game_running=0;
			round_no++;
			printf("%d %d",score_1,score_2);
			round_over=1;
			desidx=0;
			tmp_cnt=0;
			return;
		}

	}
	else{
		destx=inicpx1;
		desty=inicpy1;
		// printf("%lf %lf \t %lf %lf\n",cpx,cpy,destx,desty);
		if(max(destx+43,cpx+43)-min(destx,cpx)<=2*43 && max(desty+43,cpy+43)-min(desty,cpy)<=2*43){
			score_2++;
			player_turn=0;
			obj_move=0;
			velocity=0;
			angle=0;
			tim=0;
			game_running=0;
			round_no++;
			tmp_cnt=0;
			desidx=0;
			round_over=2;
			printf("%d %d %d",score_1,score_2,round_no);
			return;
		}
	}
	
	
	if(!is_building(cpx,cpy)) return;
	
	

	
	if(cpx<0 || cpx>1300 || cpy<0 || cpy>1800){
		
		if(player_turn==1){
			cpx=inicpx1;
			cpy=inicpy1;
		}
		else{
			cpx=inicpx2;
			cpy=inicpy2;
		}
		obj_move=0;
		velocity=0;
		angle=0;
		tim=0;
		player_turn^=1;
		return;
	} 
	 
	if(!destruction_mode){
		if(!player_turn) cpx+=43;
		descpx[desidx]=cpx;
		descpy[desidx++]=cpy;
		tmp_cnt=0;
		for(int i=cpx-dmg;i<=cpx+dmg;i++){
			for(int j=cpy-dmg;j<=cpy+dmg;j++){
				if((i-cpx)*(i-cpx)+(j-cpy)*(j-cpy)<=dmg*dmg) building_chk[i][j]=0;
			} 
		}
	}
	else{
		double pp;
		pp=is_building(cpx,cpy)-1;
		int xp=(int)pp;
		downflg=1;
		dv=dmg_lvl;
		didx=xp;
	}
	

	if(player_turn==1){
		cpx=inicpx1;
		cpy=inicpy1;
	}
	else{
		cpx=inicpx2;
		cpy=inicpy2;
	}
	// printf("%lf %lf %d\n",cpx,cpy,player_turn);
	obj_move=0;
	velocity=0;
	angle=0;
	tim=0;
	player_turn^=1;

	// printf("%lf %lf %d\n",cpx,cpy,player_turn);
}

void objshow(){
	if(obj_move){
		if(cpx>=620 && cpx<=620+100 && cpy>=550 && cpy<=550+100){
			if(!player_turn) pts1+=100;
			else pts2+=100;
		}
		// cout << pts1 << " " << pts2 << endl;
		iShowBMP2(cpx,cpy,"Pics//kdk.png",0);
	} 
	char xd[10];
	if(!player_turn){
		sprintf(xd,"gor//g11c.png");
		iShowBMP2(1200,inicpy2,xd,0);
		if(!gor_cnt){
			if(obj_move) sprintf(xd,"gor//g11.png");
			else sprintf(xd,"gor//g1.png");
			iShowBMP2(0,inicpy1,xd,0);
		}
	} 
	else{
		sprintf(xd,"gor//g11.png");
		iShowBMP2(0,inicpy1,xd,0);
		if(!gor_cnt){
			if(obj_move) sprintf(xd,"gor//g11c.png");
			else sprintf(xd,"gor//g1c.png");
			iShowBMP2(1200,inicpy2,xd,0);
		}
	}
	
	 
	// if(player_turn==0) iShowBMP2(inicpx2,inicpy2,"Pics//kdk.png",0);
	// else iShowBMP2(inicpx1,inicpy1,"Pics//kdk.png",0);
	iShowBMP2(1200,650,"Pics//back.png",0);

	if(game_on) iShowBMP2(120,650,"Pics//hint.png",0);
	if(game_on && !game_mode) iShowBMP2(1100,650,"Pics//hint.png",0);
}


void draw_main_menu(){
	// printf("%d %d %d\n",game_mode,tot_round,wind);
	if(game_mode){
		if(tot_round==1){
			if(wind) iShowBMP(0,0,"Menu//2.png");
			else iShowBMP(0,0,"Menu//1.png");
		}

		if(tot_round==2){
			if(wind) iShowBMP(0,0,"Menu//4.png");
			else iShowBMP(0,0,"Menu//3.png");
		}
		if(tot_round==3){
			if(wind) iShowBMP(0,0,"Menu//6.png");
			else iShowBMP(0,0,"Menu//5.png");
		}
		if(tot_round==4){
			if(wind) iShowBMP(0,0,"Menu//7.png");
			else iShowBMP(0,0,"Menu//8.png");
		}
	}
	else{
		if(tot_round==1){
			if(wind) iShowBMP(0,0,"Menu//10.png");
			else iShowBMP(0,0,"Menu//9.png");
		}

		if(tot_round==2){
			if(wind) iShowBMP(0,0,"Menu//12.png");
			else iShowBMP(0,0,"Menu//11.png");
		}
		if(tot_round==3){
			if(wind) iShowBMP(0,0,"Menu//14.png");
			else iShowBMP(0,0,"Menu//13.png");
		}
		if(tot_round==4){
			if(wind) iShowBMP(0,0,"Menu//15.png");
			else iShowBMP(0,0,"Menu//16.png");
		}
	}
	

	
}

void draw_opt(){
	// cout << cpu_err_set << endl;

	iShowBMP(0,0,"Pics//opt.png");
	if(destruction_mode) iShowBMP2(830,507,"Opt_menu//d2.png",0);
	else iShowBMP2(830,507,"Opt_menu//d1.png",0); 

	if(dmg_lvl==20) iShowBMP2(830,445,"Opt_menu//m1.png",0);
	else if(dmg_lvl==40) iShowBMP2(830,445,"Opt_menu//m2.png",0);
	else iShowBMP2(830,445,"Opt_menu//m3.png",0);

	if(sound) iShowBMP2(830,380,"Opt_menu//s1.png",0);
	else iShowBMP2(830,380,"Opt_menu//s2.png",0);

	if(cpu_err_set==15) iShowBMP2(830,320,"Opt_menu//c1.png",0);
	else if(cpu_err_set==10) iShowBMP2(830,320,"Opt_menu//c2.png",0);
	else iShowBMP2(830,320,"Opt_menu//c3.png",0);



}

int game_finish(){
	if(score_1*2>tot_round){
		if(tmp_cnt<25){
			
			iShowBMP(0,0,"Pics//111.png");
			Sleep(2);
			tmp_cnt++;
			if(tmp_cnt==25){
				score_1=0;
				score_2=0;
				main_menu=1;
				game_on=0;
			}
			// cout << 1 << endl;
			// if(sound) PlaySound("win.wav",NULL,SND_ASYNC);
			return 1;
		}
	}
	else if(score_2*2>tot_round){
		if(tmp_cnt<25){
			
			iShowBMP(0,0,"Pics//222.png");
			Sleep(2);
			tmp_cnt++;
			if(tmp_cnt==25){
				score_1=0;
				score_2=0;
				main_menu=1;
				game_on=0;
			}
			// cout << 1 << endl;
			// if(sound) PlaySound("win.wav",NULL,SND_ASYNC);
			return 1;
		}
	}

	if(round_no>tot_round){
		if(tmp_cnt<25){
			
			iShowBMP(0,0,"Pics//333.png");
			Sleep(2);
			tmp_cnt++;
			if(tmp_cnt==25){
				score_1=0;
				score_2=0;
				main_menu=1;
				game_on=0;
			}
			// cout << 1 << endl;
			
			return 1;
		}
	}
	// cout << 1 << endl;
	return 0;
}

int counter=0;


void gorilla_move(){
	char xd[10];
	if(!player_turn){
		sprintf(xd,"gor//g%d.png",gor_cnt);
		iShowBMP2(0,inicpy1-1,xd,0);
	} 
	else{
		sprintf(xd,"gor//g%dc.png",gor_cnt);
		iShowBMP2(1200,inicpy2-1,xd,0);
	} 
	gor_cnt++;
	if(gor_cnt==7){
		gor_cnt=0;
		obj_move=1;
		tim=0;
		if(sound) PlaySound("throw.wav",NULL,SND_ASYNC);
	}
	Sleep(50);
}

int about=0;


void iDraw() {
	iClear();
	if(about){
		iShowBMP(0,0,"Pics//about.png");
		iShowBMP2(1200,650,"Pics//back.png",0);
		return;
	}

	if(skin_menu){
		if(skin==0) iShowBMP(0,0,"Pics//blue_skin.png");
		else if(skin==1) iShowBMP(0,0,"Pics//green_skin.png");
		else iShowBMP(0,0,"Pics//monochrome_skin.png");
		iShowBMP2(1200,650,"Pics//back.png",0);
		return;
	}
	
	// printf("%d\n",obj_move);
	// if(player_turn) printf("%lf %lf\n",cpx,cpy);
	// cout << dv << " " << downflg << " " << didx << endl;
	//Game_Finish
	if(game_finish()){
		// if(sound) PlaySound("win.wav",NULL,SND_ASYNC);
		return;
	}
	

	if(main_menu){
		draw_main_menu();
	}	

	if(options){
		draw_opt();
	}
	if(tmp_cnt<25 && round_over){
		if(round_over==1){
			
			iShowBMP(0,0,"Pics//11.jpg");
			// if(sound) PlaySound("win.wav",NULL,SND_ASYNC);
		}
		else{
			
			iShowBMP(0,0,"Pics//22.jpg");
			// if(sound) PlaySound("win.wav",NULL,SND_ASYNC);
		}
		Sleep(2);
		tmp_cnt++;
		if(tmp_cnt==25) round_over=0;
		return;
	}



	

	if(game_on){
		// cout << gor_cnt << endl;
		background_skin();
		building_draw();
		iShowBMP2(620,550,"Pics//sun.png",0);
		game_running=1;
		
		
		if(obj_move) calc_path(); 
		

		if(destruction_mode==0){
			show_destruction();
			Sleep(5);
			if(velocity<0.000001 && game_mode && player_turn){
				counter=0;
				calc_cpu();
				// printf("%d\n",player_turn);
				// printf("%lf %lf\n",velocity,angle);
				// Sleep(10);
				return;
			}
			chk_stop();
		}
		else{
			
			if(!downflg) chk_stop();
			if(velocity<0.000001 && game_mode && player_turn){
				counter=0;
				calc_cpu();
				printf("%d\n",player_turn);
				printf("%lf %lf\n",velocity,angle);
				Sleep(10);
				return;
			}
			if(downflg && dv){
				down[didx]--;
				if(didx==0) inicpy1--;
				if(didx==12) inicpy2--;
				dv--;
				if(dv==0) downflg=0;
			}
			Sleep(5);
		}

		if(!obj_move) show_tracjectory(); 
		objshow();
		show_data();
		if(gor_cnt){
			gorilla_move();
			return;
		}
		
		if(upflg && uv){
				down[uidx]++;
				if(uidx==0) inicpy1++;
				if(uidx==12) inicpy2++;
				uv--;
				if(uv==0) upflg=0;
		}
		if(velocity>1 && game_mode && player_turn && counter<100){
				counter++;
				if(counter==100) gor_cnt=1;
				return;
		}
		
		
	}


	
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	
	// printf("x = %d, y= %d\n",mx,my);

	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	cout << mx << " " << my << " clk\n";
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// if(main_menu && mx>=870 && mx<=1020 && my>=600 && my<=630){
		// 	game_mode=1;
		// }
		
		if(main_menu && mx>=745 && mx<=910 && my>=238 && my<=300){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			main_menu=0;
			game_on=1;
			round_no=1;
		}
		if(main_menu && mx>=760 && mx<=915 && my>=320 && my<=372){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			options=1;
			main_menu=0;
		}
		if(options && mx>=807 && mx<=925 && my>=212 && my<=266){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			options=0;
			main_menu=1;
		}
		if(main_menu && mx>=965 && mx<=1020 && my>=495 && my<=530){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			wind=rand()%10;
			if(rand()%2) wind*=-1;
		}
		if(main_menu && mx>=865 && mx<=935 && my>=495 && my<=530){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			wind=0;
		}
		if(main_menu && mx>=870 && mx<=895 && my>=550 && my<=580){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			tot_round=1;
		}
		if(main_menu && mx>=920 && mx<=950 && my>=550 && my<=580){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			tot_round=2;
		}
		if(main_menu && mx>=980 && mx<=1010 && my>=550 && my<=580){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			tot_round=3;
		}
		if(main_menu && mx>=1030 && mx<=1070 && my>=550 && my<=580){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			tot_round=4;
		}
		if(main_menu && mx>=670 && mx<=830 && my>=605 && my<=655){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			game_mode=1;
		}
		if(main_menu && mx>=890 && mx<=1050 && my>=605 && my<=655){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			game_mode=0;
		}
		if((game_on || about || skin_menu) && mx>=1205 && mx<=1277 && my>=657 && my<=678){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			// cout << game_on << endl;
			main_menu=1;
			game_on=0;
			velocity=0;
			tim=0;
			angle=0;
			round_no=0;
			gor_cnt=0;
			player_turn=0;
			game_running=0;
			obj_move=0;
			round_over=0;
			score_1=score_2=0;
			counter=0;
			game_mode=1;
			tmp_cnt=0;
			tot_round=1;
			downmode=0;
			if(about) about=0;
			if(skin_menu) skin_menu=0;
		}

		if(options && mx>=830 && mx<=930 && my>=512 && my<=550){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			destruction_mode^=1;
		}
		if(options && mx>=830 && mx<=930 && my>=452 && my<=490){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			dmg_lvl+=20;
			if(dmg_lvl==80) dmg_lvl=20;
		}
		if(options && mx>=830 && mx<=930 && my>=385 && my<=421){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			sound^=1;
		}
		if(options && mx>=830 && mx<=930 && my>=327 && my<=364){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			cpu_err_set-=5;
			if(cpu_err_set==0) cpu_err_set=15;
		}
		if(main_menu  && mx>=1188 && mx<=1288 && my>=668 && my<=700){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			about=1;
			main_menu=0;
		}
		if(about  && mx>=1200 && mx<=1280 && my>=655 && my<=682){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			about=0;
			main_menu=1;
		}
		if(main_menu  && mx>=875 && mx<=995 && my>=400 && my<=448){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			skin_menu=1;
			main_menu=0;
		}

		if(skin_menu && mx>=350 && mx<=515 && my>=225 && my<=280){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			skin=0;
		}
		if(skin_menu && mx>=685 && mx<=850 && my>=225 && my<=280){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			skin=1;
		}
		if(skin_menu && mx>=1023 && mx<=1186 && my>=225 && my<=280){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			skin=2;
		}
		if(!game_mode && game_on && mx>=1105 && mx<=1195 && my>=655 && my<=675){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			upflg=1;
			uidx=12;
			uv=pts2/10;
			uv= uv+inicpy2 > 500 ? 0 : uv;
			pts2=0;
		}
		if(game_on && mx>=125 && mx<=220 && my>=655 && my<=675){
			if(sound) PlaySound("click.wav",NULL,SND_ASYNC);
			upflg=1;
			uidx=0;
			uv=pts1/10;
			uv= uv+inicpy1 > 500 ? 0 : uv;
			pts1=0;
		}
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(game_on){
		if (key == ' '){
			// obj_move=1;
			// tim=0;
			gor_cnt=1;
			// if(sound) PlaySound("throw.wav",NULL,SND_ASYNC);
		}
		
	}


	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if(game_on){
		if (key == GLUT_KEY_RIGHT){
			if(!game_mode || !player_turn) if(velocity<200) velocity+=5;
		}
		if( key == GLUT_KEY_UP){
			if(!game_mode || !player_turn) if(angle<90) angle++;
		}
		if (key == GLUT_KEY_LEFT){
			if(!game_mode || !player_turn) if(velocity>0) velocity-=5;
		}
		if( key == GLUT_KEY_DOWN){
			if(!game_mode || !player_turn) if(angle>0) angle--;
		}
	}
	//place your codes for other keys here
}


int main() {
	//place your own initialization codes here.
	iInitialize(1300, 700, "Retro Gorilla Atrillery Game");
	return 0;
}
