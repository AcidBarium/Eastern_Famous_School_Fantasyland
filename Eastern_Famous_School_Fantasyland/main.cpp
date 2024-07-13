#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "MSIMG32.LIB")

#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <mmsystem.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

typedef long long ll;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define Endl endl
#define ednl endl
#define eldn endl
#define dnel endl
#define enndl endl
#define Ednl endl
#define Edml endl
#define llmax 9223372036854775807
#define intmax 2147483647
#define PI 3.141592653589793238462643383279502884197
using namespace std;
#pragma comment(lib, "winmm.lib")

const int screenWidth = 1200;            //��Ļ��С
const int screenHeight = 800;
const int FRAME = 60;					//֡��
IMAGE imgStart, imgDUTbigger, imgDUTcartoon, imgChosePartBackground, imgTheGirlIsPraying, imgLeftGame, imgBehindBK, LOGO;//��Ϸ���õ�����Ƭ
IMAGE imgleftGame2;
IMAGE imgHP, imgBoom;
IMAGE imgChar1, imgChar2, imgChar, imgMineEnergyBall;
IMAGE imgcloud1, imgcloud2, imgcloud3;
IMAGE imgBlueBullet, imgRedBullet, imgPurpleBullet,imgYellowBullet;
IMAGE imgMoney, imgPoint;
IMAGE imgHPpoint, imgBoomPoint;
IMAGE imgWuHanDaXueSmall,imgBeiJingHangKong,imgBeiJingLiGong,imgBeiJingShiFan,imgDaLianHaiShi;
IMAGE imgDianZiKeJi, imgDongBei, imgDongNan, imgFuDan, imgHaErBinGongCheng, imgHaErBinGongYe, imgHuaDongShiFan;
IMAGE imgHuaKe, imgHuaNanLiGong, imgHuNanDaXue, imgJiLin, imgNanJing, imgNanKai;
IMAGE imgShanDong, imgShangJiao, imgSiChuan, imgTianJin, imgTongJi, imgXiaMen, imgXiAnDianZiKeJi;
IMAGE imgXiAnJiaoTong, imgxiBeiGongYe, imgZheJiang, imgZhengZhou, imgZhongGuoRenMin, imgZhongKe, imgZhongNan, imgZhongShan;
IMAGE imgYUANSHEN;
IMAGE imgQingHuaBoss, imgBeiDaBoss;

bool running = true;                           //ÿһ����Ϸѭ���ٷ�ָ�����б�
ExMessage msg;                                 //��Ϣ����ٷ�ָ����־
bool isGameOver = false;                       //�ǳ��ؼ��ı��������Ϊtrueֱ�ӵ����һ����
bool isCharNormal;


void BGMstart(int a)    //�������֣�a=0ʱ�ر�
{
	if (a)
	{
		mciSendString("open audio\\start.mp3 alias BGM", 0, 0, 0);
		mciSendString("play BGM repeat", 0, 0, 0);
	}	
	else
		mciSendString("close BGM ", 0, 0, 0);
}

void BGMpartOne(int a)
{
	
	if (a)
	{
		mciSendString("open audio\\part_1.mp3 alias BGM3", 0, 0, 0);
		mciSendString("play BGM3 repeat", 0, 0, 0);
	}
	else
		mciSendString("close BGM3 ", 0, 0, 0);
}

void BGMpartOneBoss(int a)
{
	
	if (a)
	{
		mciSendString("open audio\\part_1_boss.mp3 alias BGMpartOneBoss", 0, 0, 0);
		mciSendString("play BGMpartOneBoss repeat", 0, 0, 0);
	}	
	else
		mciSendString("close BGMpartOneBoss ", 0, 0, 0);
}

void BGMpartTwo(int a)
{
	if (a)
	{
		mciSendString("open audio\\part_2.mp3 alias BGMpartTwo", 0, 0, 0);
		mciSendString("play BGMpartTwo repeat", 0, 0, 0);
	}
	else
		mciSendString("close BGMpartTwo ", 0, 0, 0);
}

void BGMpartTwoBoss(int a)
{
	if (a)
	{
		mciSendString("open audio\\part_2_boss.mp3 alias BGMpartTwoBoss", 0, 0, 0);
		mciSendString("play BGMpartTwoBoss repeat", 0, 0, 0);
	}
	else
		mciSendString("close BGMpartTwoBoss ", 0, 0, 0);
}

void BGMlast(int a)
{
	if (a)
	{
		mciSendString("open audio\\last.mp3 alias BGMlast", 0, 0, 0);
		mciSendString("play BGMlast repeat", 0, 0, 0);
	}
	else
		mciSendString("close BGMlast ", 0, 0, 0);
}


void outTextCenter(int x, int y, string ss)   //�������ַ�
{
	int Textwidth = textwidth(ss.c_str());
	int Textheight = textheight(ss.c_str());
	outtextxy(x - Textwidth / 2, y - Textheight / 2, ss.c_str());
}

//��ʾ͸��ͼƬ
void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}




class CLOUD
{
	ll cnt;
	IMAGE imgShow;
	int x;
public:
	void chushihua()
	{
		x = 0;
		cnt = 0;
	}

	void show()
	{
		cnt++;
		if (cnt % 1200 == 0)
		{
			cnt = 0;
			int option = rand() % 3;
			if (option == 0)
				imgShow = imgcloud1;
			else if (option == 1)
				imgShow = imgcloud2;
			else if (option == 2)
				imgShow = imgcloud3;
			x = rand() % 380 - 530;
		}
		putimage_alpha(x, cnt-300, &imgShow);
		//circle(x, cnt, 5);
	}

}cloud;

class shangHaiXiaoguo
{
public:
	int x;
	int y;
	int cnt;
	bool isOK;  //true ��ʾ���Ч��������

	shangHaiXiaoguo(int xx,int yy)
	{
		x = xx;
		y = yy; 
		cnt = 0;
		isOK = true;
	}
	void chushihua(int xx, int yy)
	{
		x = xx;
		y = yy;
		cnt = 0;
		isOK = true;
	}
	bool show()
	{
		if (cnt < 25)
		{
			cnt++;
			setlinecolor(RGB(200, 200, 200));
			setlinestyle(1, 1);
			solidcircle(x, y, 10 + cnt);
		}
		else
			isOK = false;
		return isOK;
	}
};

vector<shangHaiXiaoguo>hurtXiaoGuoList;

class mainBULLET
{
public :
	int x;
	int y;
	int v;
	int option;             //����ģʽ���ӵ�����  1�ǵ�����2�����Ϸ���3�����ϣ�4�������ϣ�5��������
	int r;                   //�ӵ���С
	void chushihua(int xx, int yy,int optionn)
	{
		r = 20;             //�ӵ���С
		v = 20;
		x = xx;
		y = yy;
		option = optionn;
	}

	void calshot()      //1�ǵ�����2�����Ϸ���3�����ϣ�4�������ϣ�5��������
	{
		if (option == 1)
			y -= v;
		else if (option == 2)
		{
			x += v * cos(PI / 18.0 * 8.0);
			y -= v * sin(PI / 18.0 * 8.0);
		}
		else if (option == 3)
		{
			x -= v * cos(PI / 18.0 * 8.0);
			y -= v * sin(PI / 18.0 * 8.0);
		}
		else if (option == 4)
		{
			x += v * cos(PI / 18 * 7.0);
			y -= v * sin(PI / 18 * 7.0);
		}
		else if (option == 5)
		{
			x -= v * cos(PI / 18 * 7.0);
			y -= v * sin(PI / 18 * 7.0);
		}
	}

	bool isNeedDelete()    //�ɳ���Ļ�򷵻�1
	{
		if (x >= 300 + r || x <= -580 - r)
			return true;
		if (y <= 20 || y >= 780 + r)
			return true;
		return false;

	}

	bool pengZhuangJianCe( int againstX,int againstY,int againstR )
	{
		if(sqrt(    1.0*(x-againstX)* (x - againstX)  +1.0 * (y-againstY) * (y - againstY)   )   <=(againstR+r)  )
			return true;
		return false;
	}

	void show()
	{
		putimage_alpha(x - r, y - r, &imgMineEnergyBall);
	}
};
vector<mainBULLET> mainBulletList;  //�����ӵ��б�


class BOOMMMMM
{
public:
	int x;
	int y;
	ll timeCNT;

	void chushihua()
	{
		x = 300;
		timeCNT = 120;
		y = 20;
	}
	void calAndMove()
	{
		timeCNT--;
		if (x >= -250)
			x += (-24);
		else if (x >= -580)
			x += (-5);
		else
			x += (-24);
		putimage_alpha(x, 20, &imgYUANSHEN);
	}

	bool isNeedDelete()
	{
		if (timeCNT > 0)
			return false;
		return true;
	}

};

vector<BOOMMMMM>boomList;


class mainRole    //�����࣬DUT
{
private:
	ll shootZhen;
public:
	int x;
	int y;
	int vx;
	int vy;
	int HP;
	int Boom;
	int GkLuquScore;
	ll MoneyEveryYear;
	int r;
	int moveXmodel;
	int moveYmodel;
	ll dutGolenBodyCnt;            //����Ч��
	struct dir
	{
		bool left;
		bool right;
		bool up;
		bool down;
	}direction;
	void chushihua()              //��ʼ��
	{
		shootZhen = 0;    //���֡

		direction.down = false;    //��������
		direction.up = false;
		direction.right = false;
		direction.left = false;

		x = -140;                                     //����
		y = 700;
		vx = 7;                                      //�ٶ�
		vy = 7;
		moveXmodel = 0;                         //�ƶ�ģʽ 1��2�ң�1�ϣ�2��, 0����
		moveYmodel = 0;                         //�ƶ�ģʽ 1��2�ң�1�ϣ�2��, 0����
		
		r = 10;
		dutGolenBodyCnt =120;                   //�����ʼ2s�Ľ����ڼ����ƶ����������
	}
	void pengZhuangJianCe()           //��ײ���
	{
		if (x + r >= 300)x = 300 - r;
		if (x - r <= -580)x = -580 + r;
		if (y - r <= 20)y = 20 + r;
		if (y + r >= 780)y = 780 - r;
	}
	void claMovemode()                 //�����ɫλ��
	{
		if (dutGolenBodyCnt)
			dutGolenBodyCnt--;          //һֱ�ѽ���Ч������0ֹͣ��

		if (direction.up && direction.down)
			moveYmodel = 0;
		else if (direction.up)
			moveYmodel = 1;
		else if (direction.down)
			moveYmodel = 2;
		else
			moveYmodel = 0;

		if (direction.right && direction.left)
			moveXmodel = 0;
		else if (direction.left)
			moveXmodel = 1;
		else if (direction.right)
			moveXmodel = 2;
		else
			moveXmodel = 0;
	}

	void move(int optionx,int optiony)          //1��2�ң�1�ϣ�2��, 0����  //�ı�xy
	{
		int vxtemp = vx, vytemp = vy;
		if (optionx == 1) vxtemp *= -1;
		else if (optionx == 2) vxtemp *= 1;
		else if (optionx == 0) vxtemp *= 0;

		if (optiony == 1) vytemp *= -1;
		else if (optiony == 2) vytemp *= 1;
		else if (optiony == 0) vytemp *= 0;

		if (optionx && optiony)
		{
			x += vxtemp / 1.414;
			y += vytemp / 1.414;
		}
		else
		{
			x += vxtemp;
			y += vytemp;
		}
	}
	void show()             //չʾ��ɫͼ��
	{
		putimage_alpha(x - 30, y - 30, &imgChar);
		//circle(x, y, r);                           //��ʾ�ж���
	}

	void getHert()
	{
		                   // ��û���Ľ�ɫ����Ч��
		HP--;
	}

	void useTechnology()
	{
		if (Boom > 0)
		{
			mciSendString("play BGMxiaoZhang from 0", 0, 0, 0);
			Boom--;
			BOOMMMMM temp;
			temp.chushihua();
			boomList.push_back(temp);
		}
		
	}
	void shoot()  //�����ӵ�
	{
		if (shootZhen == 0)
			mciSendString("play BGMshoot0 from 0", 0, 0, 0);   //������Ч
		else if(shootZhen==5)
			mciSendString("play BGMshoot1 from 0", 0, 0, 0);
		else if (shootZhen == 10)
			mciSendString("play BGMshoot2 from 0", 0, 0, 0);
		shootZhen++;
		shootZhen %= 15;
		
		if (MoneyEveryYear >= 0&&!(shootZhen%5))
		{
			mainBULLET temp;
			temp.chushihua(x, y - 20, 1);
			mainBulletList.push_back(temp);
		}
		if (MoneyEveryYear >= 25000 && !(shootZhen % 5))
		{
			mainBULLET temp2 ,temp3;
			temp2.chushihua(x, y - 20, 2);
			temp3.chushihua(x, y - 20, 3);
			mainBulletList.push_back(temp2);
			mainBulletList.push_back(temp3);
		}
		if (MoneyEveryYear >= 50000 && !(shootZhen % 5))
		{
			mainBULLET temp4, temp5;
			temp4.chushihua(x, y - 20, 4);
			temp5.chushihua(x, y - 20, 5);
			mainBulletList.push_back(temp4);
			mainBulletList.push_back(temp5);
		}
	}

}DUT;

class againstBullet
{
private:
	double vx;
	double vy;
	double xa;
	double ya;
	IMAGE img;
	float xReal;
	float yReal;
public:
	int x;
	int y;
	int r;

	void chushihua(int xx, int yy, double vxx, double vyy, double xaa, double yaa,IMAGE *imgg)
	{
		xReal = xx;
		yReal = yy;
		x = xx;
		y = yy;
		vx = vxx;
		vy = vyy;
		xa = xaa;
		ya = yaa;
		img = *imgg;
		r = 9;
	}


	void calMove()
	{
		vx += xa;
		vy += ya;
		/*
		if (vx > 0)
			x += ceil(vx);
		else if (vx < 0)
			x += floor(vx);
		if (vy > 0)
			y += ceil(vy);
		else if (vy < 0)
			y += floor(vy);*/

		xReal += vx;
		yReal += vy;
		x = xReal;
		y = yReal;

	}

	bool isNeedDelete()    //�ɳ���Ļ�򷵻�1
	{
		if (x >= 300 + r || x <= -580 - r)
			return true;
		if (y <= 20 || y >= 780 + r)
			return true;
		return false;

	}

	bool pengZhuangJianCe(int againstX, int againstY, int againstR)
	{
		if (sqrt(1.0 * (x - againstX) * (x - againstX) + 1.0 * (y - againstY) * (y - againstY)) <= (againstR + r))
			return true;
		return false;
	}

	void show()
	{
		putimage_alpha(x - r, y - r, &img);
	}

};


vector<againstBullet>againstBulletList;


class againstRolesmall
{
private:
	int dieTimeCnt;
	int HP;
	double vx;
	double vy;
	double xa;                 //���ٶ�
	double ya;
	IMAGE imgRole;
	ll saveTimeCnt;
	

public:
	int x;
	int y;
	int r;
	ll isShoot;           //�ж�С���Ƿ����ӵ�,�����ٶȶ����У�ÿ֡�Ӽӣ���ĳ��ȡ�����ж��Ƿ����ӵ�
	int shotModel;
	
	void chushihua(int xx, int yy, int Vx, int Vy, double xaa, double yaa, IMAGE* img, ll savetimecnt = llmax, int shotOption = 1,int hpp=2)  //�з�С����ʼ��
	{
		HP = hpp;
		r = 22;
		x = xx;
		y = yy;
		vx = Vx;
		vy = Vy;
		xa = xaa;
		ya = yaa;
		imgRole = *img;
		dieTimeCnt = 0;
		isShoot = 0;
		shotModel = shotOption;
		saveTimeCnt = savetimecnt;
	}
	void calMove()
	{
		saveTimeCnt--;
		if (saveTimeCnt >= 0)
		{
			vx += xa;
			vy += ya;
			x += vx;
			y += vy;
			isShoot++;
			if (isShoot >= 1000000000)
				isShoot = 0;
		}
		
	}

	bool isNeedDelet()    //�ɳ���Ļ�򷵻�1
	{
		if (x >= 300 + r || x <= -580 - r)
			return true;
		if (y <= 20 || y >= 780 + r)
			return true;
		return false;

	}

	//С�ֵĻ���Ŀǰֻ�����������������ӵ������ٶ��ӵ�

	void shoot(int option)   //�ǳ���Ļ�����ڵ����ģʽ��С�ֵ�
	{
		if (option == 1)        //�����
		{
			againstBullet temp;
			int xCha = DUT.x - x;
			int yCha = DUT.y - y;
			double vxTemp = 2.0 * xCha / sqrt(1.0 * xCha * xCha + 1.0 * yCha * yCha);
			double vyTemp = 2.0 * yCha / sqrt(1.0 * xCha * xCha + 1.0 * yCha * yCha);
			temp.chushihua(x, y, vxTemp, vyTemp, 0, 0, &imgBlueBullet);                       //��ɫ�����ӵ�
			againstBulletList.push_back(temp);                   //�������ӵ��ŵ��ӵ��б���
		}
		else if (option == 2)   //���
		{
			againstBullet temp[5];
			rep(i, 0, 5)
			{
				int xxxRand = rand() % 5-2;
				int yyyRand = rand() % 5-1;
				xxxRand = xxxRand ? xxxRand : 1;
				yyyRand = yyyRand ? yyyRand : 1;
				temp[i].chushihua(x, y, xxxRand,yyyRand , 0, 0, &imgRedBullet);
				againstBulletList.push_back(temp[i]);
			}
		}
		else if (option == 3)
		{
			againstBullet temp;
			int xCha = DUT.x - x;
			int yCha = DUT.y - y;
			double vxTemp = 0.5 * xCha / sqrt(1.0 * xCha * xCha + 1.0 * yCha * yCha);
			double vyTemp = 0.5 * yCha / sqrt(1.0 * xCha * xCha + 1.0 * yCha * yCha);
			temp.chushihua(x, y, -vxTemp, -vyTemp, 0.15*vxTemp, 0.15 * vyTemp, &imgPurpleBullet);                //��ɫ�����ӵ�
			againstBulletList.push_back(temp);                   //�������ӵ��ŵ��ӵ��б���
		}


	}

	bool gethurt()            //����trueֱ�Ӵ�����
	{
		HP--;
		if (HP <= 0)
			return true;
		return false;
	}

	void show()
	{
		putimage_alpha(x - r, y - r, &imgRole);
	}

	bool dieShow()            //��͸�˷���true
	{
		setlinestyle(1, 1);
		if (dieTimeCnt < 10)
		{
			circle(x, y, r + dieTimeCnt);
			return false;
		}
		return true;
	}

};

vector<againstRolesmall>againstRoleLiveList;
vector<againstRolesmall>againstRoleDIEList;

class BOSS
{
private:
	ll oriHP;
	int x;
	int y;
	int r;
	
	double vy;
	double ax;
	double ay;
	float xReal;
	float yReal;
	IMAGE imgRole;
	ll cnt;
	ll shootcnt;
	int optionSevenCnt;
	int optionEightCnt;
public:
	ll HP;
	double vx;
	void chushihua(int xx, int yy, IMAGE* img)
	{
		optionSevenCnt = 0;
		optionEightCnt = 0;
		shootcnt = 0;
		cnt = 0;
		vx = 2;
		r = 40;
		x = xx;
		y = yy;
		xReal = x;
		yReal = y;
		HP = 1500;
		oriHP = HP;
		imgRole = *img;
	}

	bool pengzhuangjiance(int againstX, int againstY,int againstR)
	{
		if ((x - againstX) * (x - againstX) + (y - againstY) * (y - againstY) <= (againstR + r) * (againstR + r))
		{
			HP--;
			return true;
		}
			
		return false;
	}

	void shot(int option)//1תȦ��2�༤�⣬3������,4 ͬʱһ��Ȧ,5 ����ѣ�6ɢ��ǹ
	{
		shootcnt++;
		if (option == 1)
		{
			optionEightCnt = 0;
			double vvvv = 4;
			againstBullet temp,temp2;
			double theta = 2.0 * PI / 60.0 * (cnt % 60);
			temp.chushihua(x +1.0* r * cos(theta), y +1.0* r * sin(theta), vvvv * cos(theta), vvvv * sin(theta), 0, 0, &imgRedBullet);
			temp2.chushihua(x - 1.0 * r * cos(theta), y - 1.0 * r * sin(theta), -vvvv * cos(theta), -vvvv * sin(theta), 0, 0, &imgRedBullet);
			againstBulletList.push_back(temp);
			againstBulletList.push_back(temp2);
		}
		else if (option == 2)
		{
			double vvvv = 3;
			// �����趨��ÿ��������� תһȦ��ʱ�䣬Ϊcnt��ȡģ����
			againstBullet temp1;
			againstBullet temp2;
			againstBullet temp3;
			againstBullet temp4;
			double theta = 2.0 * PI / 90.0 * (cnt%90) ;          
			temp1.chushihua(x +1.0* r * cos(theta), y+1.0 *r* sin(theta), vvvv * cos(theta), vvvv * sin(theta), 0, 0, &imgRedBullet);
			againstBulletList.push_back(temp1);
			temp2.chushihua(x +1.0* r * cos(theta+PI/2.0), y+1.0 *r* sin(theta + PI / 2.0), vvvv * cos(theta + PI / 2.0), vvvv * sin(theta + PI / 2.0), 0, 0, &imgBlueBullet);
			againstBulletList.push_back(temp2);
			temp3.chushihua(x +1.0* r * cos(theta + PI), y +1.0*r* sin(theta + PI ), vvvv * cos(theta + PI ), vvvv * sin(theta + PI ), 0, 0, &imgPurpleBullet);
			againstBulletList.push_back(temp3);
			temp4.chushihua(x +1.0* r * cos(theta +3.0 * PI / 2.0), y+1.0*r * sin(theta +3.0 * PI / 2.0), vvvv * cos(theta + 3.0 * PI / 2.0), vvvv * sin( theta + 3.0 * PI / 2.0), 0, 0, &imgYellowBullet);
			againstBulletList.push_back(temp4);
		}
		else if (option == 3)
		{
			againstBullet temp1;
			againstBullet temp2;
			
			int rand1 = (rand() % 7 - 3);
			int rand2 = (rand() % 7 - 3);
			int rand3 = (rand() % 7 - 3);
			int rand4 = (rand() % 7 - 3);
			rand1 = rand1 ? rand1 : 1;
			rand2 = rand2 ? rand2 : -1;
			rand3 = rand3 ? rand3 : -1;
			rand4 = rand4 ? rand4 : -1;


			temp1.chushihua(x, y, rand1, rand2, 0, 0, &imgRedBullet);
			temp2.chushihua(x, y, rand3, rand4, 0, 0, &imgRedBullet);
			
			againstBulletList.push_back(temp1);
			againstBulletList.push_back(temp2);
			
		}
		else if (option == 4)
		{
			double vv = 4;
			double thetaEv = 2 * PI / 30;
			IMAGE imgbullettemp;
			againstBullet temp[30];
			if (shootcnt % 4 == 0)
				imgbullettemp = imgRedBullet;
			else if (shootcnt % 4 == 1)
				imgbullettemp = imgBlueBullet;
			else if (shootcnt % 4 == 2)
				imgbullettemp = imgPurpleBullet;
			else if (shootcnt % 4 == 3)
				imgbullettemp = imgYellowBullet;
			rep(i, 0, 30)
			{
				temp[i].chushihua(x + 1.0 * r * cos(thetaEv * i), y + 1.0 * r * sin(thetaEv * i), vv * cos(thetaEv * i), vv * sin(thetaEv * i), 0, 0, &imgbullettemp);
				againstBulletList.push_back(temp[i]);
			}
		}
		else if (option == 5)
		{
			double vv = 7;
			double xcha = DUT.x-x;
			double ycha = DUT.y-y;
			againstBullet temp;
			temp.chushihua(x, y,vv* xcha / sqrt(xcha * xcha + ycha * ycha),vv* ycha / sqrt(xcha * xcha + ycha * ycha), 0, 0, &imgBlueBullet);
			againstBulletList.push_back(temp);
		}
		else if (option == 6)
		{
			double ershidu = PI / 180.0 * 20;
			againstBullet temp[3];
			temp[0].chushihua(x, y + r, 0, 5, 0, 0, &imgYellowBullet);
			temp[1].chushihua(x + r * sin(ershidu), y + r * cos(ershidu), 7 * sin(ershidu), 7 * cos(ershidu), 0, 0, &imgYellowBullet);
			temp[2].chushihua(x - r * sin(ershidu), y + r * cos(ershidu), -7 * sin(ershidu), 7 * cos(ershidu), 0, 0, &imgYellowBullet);
			rep(i, 0, 3)againstBulletList.push_back(temp[i]);
		}
		else if (option == 7)              //������Բ
		{
			optionSevenCnt++;
			double yidu = PI / 180.0;
			againstBullet temp[95];
			if (optionSevenCnt % 2)
				rep(i, 0, 95)temp[i].chushihua(-140 + 100 * cos(yidu * i), 30 + 100 * sin(yidu * i), 6 * cos(yidu * i), 6 * sin(yidu * i), 0, 0, &imgBlueBullet);
			else
				rep(i, 0, 95)temp[i].chushihua(-140 + 100 * cos(PI - yidu * i),30+100*sin(PI - yidu * i),6* cos(PI - yidu * i),6* sin(PI - yidu * i),0,0,&imgRedBullet);
			rep(i, 0, 95)againstBulletList.push_back(temp[i]);
		}
		else if (option == 8)
		{
			double yidu = PI / 180.0;
			optionEightCnt++;
			againstBullet temp1, temp2;
			temp1.chushihua(x + r * cos(yidu * optionEightCnt), y + r * sin(yidu * optionEightCnt), 7 * cos(yidu * optionEightCnt), 7 * sin(yidu * optionEightCnt), 0, 0, &imgYellowBullet);
			temp2.chushihua(x + r * cos(PI - yidu * optionEightCnt), y + r * sin(PI - yidu * optionEightCnt), 7 * cos(PI - yidu * optionEightCnt), 7 * sin(PI - yidu * optionEightCnt), 0, 0, &imgYellowBullet);
			againstBulletList.push_back(temp1);
			againstBulletList.push_back(temp2);
			optionEightCnt %= 80;
		}
	}

	void calAndMoveAndShow(int option=1)
	{
		cnt++;
		ax = 0.0002 * (-140 - x);          //�������ӵļ��ٶȺ�λ�Ƴ�����
		if (option == 1)
			vx += ax;                //�����ٶ�
		else
		{
			if (x > -140)
				vx = -1;
			else if (x < -140)
				vx = 1;
			else if (x == -140)
				vx = 0;
		}
		xReal += vx;               //λ��
		yReal += vy;
		x = xReal;
		y = yReal;

		if (y > 100)vy = -1;             //ʹ�õ��˱�����100��������
		if (y < 100)vy = 1;              
		if (y == 100)vy = 0;

		putimage_alpha(x-r, y-r, &imgRole);        //����


		setlinecolor(RGB(200, 200, 200));    //����bossѪ��
		setlinestyle(0,5);
		line(-500, 25, 220, 25);
		setlinecolor(RGB(255, 0, 0));    //����bossѪ��
		setlinestyle(0, 5);
		line(-500, 25, -500.0 + 720.0 / oriHP * HP, 25);
	}

};

vector<BOSS>bossLiveList;


void loadingManythings()                      //ͼƬ���ļ��Ļ����������
{
	//ͼƬ���ļ��Ļ���������򣨿�ͷ��
	loadimage(&imgStart, _T("image\\start.jpg"));    //��Ϸ��ͷͼƬ
	loadimage(&imgDUTbigger, _T("image\\DUTbigger.png"));  //��������ѧ��ͷͼƬ
	loadimage(&imgDUTcartoon, _T("image\\DUTqiLuNuo.png"));  //��������ѧ����9��
	loadimage(&imgChosePartBackground, _T("image\\blueSkyBackground.png")); //ѡ��Ӣ�۽׶εı���ͼƬ
	loadimage(&imgTheGirlIsPraying, _T("image\\theGirlIsPraying.jpg"));     //��Ů�����е�ͼƬ
	loadimage(&imgLeftGame, _T("image\\GameBackground1.jpg"));              //ս�����򱳾�
	loadimage(&imgleftGame2, _T("image\\GameBackground2.jpg"));             //�ڶ���ս������ı���
	loadimage(&imgBehindBK, _T("image\\GameBehindBackground.jpg"));         //�󾰣�����Ϣ��һ���
	loadimage(&LOGO, _T("image\\logo.png"));              //logoͼƬ
	loadimage(&imgHP, _T("image\\redHP.png"));          //�챦ʯѪ����Ƭ
	loadimage(&imgBoom, _T("image\\blueBoom.png"));     //����ʯ������
	loadimage(&imgChar1, _T("image\\DUTchar1.png"));    //������ɫͼ��
	loadimage(&imgChar2, _T("image\\DUTchar2.png"));    //��¶ŵ��ɫͼ��
	loadimage(&imgMineEnergyBall, _T("image\\energyBall.png"));         //���ǵ�������
	loadimage(&imgQingHuaBoss, _T("image\\qingHuaBigBoss.png"));        //�廪��boss
	loadimage(&imgBeiDaBoss, _T("image\\BeiJingDaXueBigBoss.png"));    //�����boss

	loadimage(&imgWuHanDaXueSmall, _T("image\\smallWuHanDaXue.png"));    //С�人��ѧ
	loadimage(&imgBeiJingHangKong, _T("image\\BeiJingHangKong.png"));    //��������
	loadimage(&imgBeiJingLiGong, _T("image\\BeiJingLiGong.png"));
	loadimage(&imgBeiJingShiFan, _T("image\\BeiJingShiFan.png"));
	loadimage(&imgDaLianHaiShi, _T("image\\DaLianHaiShi.png"));
	loadimage(&imgDianZiKeJi, _T("image\\DianZiKeJi.png"));
	loadimage(&imgDongBei, _T("image\\DongBei.png"));
	loadimage(&imgDongNan, _T("image\\DongNan.png"));
	loadimage(&imgFuDan, _T("image\\FuDan.png"));
	loadimage(&imgHaErBinGongCheng, _T("image\\HaErBinGongCheng.png"));
	loadimage(&imgHaErBinGongYe, _T("image\\HaErBinGongYe.png"));
	loadimage(&imgHuaKe, _T("image\\HuaKe.png"));
	loadimage(&imgHuaNanLiGong, _T("image\\HuaNanLiGong.png"));
	loadimage(&imgHuNanDaXue, _T("image\\HuNanDaXue.png"));
	loadimage(&imgJiLin, _T("image\\JiLin.png"));
	loadimage(&imgNanJing, _T("image\\NanJing.png"));
	loadimage(&imgNanKai, _T("image\\NanKai.png"));
	loadimage(&imgShanDong, _T("image\\ShanDong.png"));
	loadimage(&imgShangJiao, _T("image\\ShangJiao.png"));
	loadimage(&imgSiChuan, _T("image\\SiChuan.png"));
	loadimage(&imgTianJin, _T("image\\TianJin.png"));
	loadimage(&imgTongJi, _T("image\\TongJi.png"));
	loadimage(&imgXiaMen, _T("image\\XiaMen.png"));
	loadimage(&imgXiAnDianZiKeJi, _T("image\\XiAnDianZiKeJi.png"));
	loadimage(&imgXiAnJiaoTong, _T("image\\XiAnJiaoTong.png"));
	loadimage(&imgxiBeiGongYe, _T("image\\xiBeiGongYe.png"));
	loadimage(&imgZheJiang, _T("image\\ZheJiang.png"));
	loadimage(&imgZhengZhou, _T("image\\ZhengZhou.png"));
	loadimage(&imgZhongGuoRenMin, _T("image\\ZhongGuoRenMin.png"));
	loadimage(&imgZhongKe, _T("image\\ZhongKe.png"));
	loadimage(&imgZhongNan, _T("image\\ZhongNan.png"));
	loadimage(&imgZhongShan, _T("image\\ZhongShan.png"));



	loadimage(&imgcloud1, _T("image\\cloud1.png"));                        //��������
	loadimage(&imgcloud2, _T("image\\cloud2.png"));
	loadimage(&imgcloud3, _T("image\\cloud3.png"));
	loadimage(&imgBlueBullet, _T("image\\blueBullet.png"));               //���˵�С��ɫ�ӵ�
	loadimage(&imgRedBullet, _T("image\\redBullet.png"));                  //��ɫ�ӵ�
	loadimage(&imgPurpleBullet, _T("image\\purpleBullet.png"));            //��ɫ�ӵ�
	loadimage(&imgYellowBullet, _T("image\\yellowBullet.png"));            //��ɫ�ӵ�
	loadimage(&imgMoney, _T("image\\money.png"));                         //Ǯ����Ƭ
	loadimage(&imgPoint, _T("image\\point.png"));                         //������ͼƬ
	loadimage(&imgHPpoint, _T("image\\pointHP.png"));                  //С�Ŀ��ԳԵ�Ѫ��
	loadimage(&imgBoomPoint, _T("image\\BoomPoint.png"));              //С�Ŀ��ԳԵļ�����
	loadimage(&imgYUANSHEN, _T("image\\ThisISDUT.png"));              //Ԫ��
	
	mciSendString("open audio\\arms01\\8bit_laser1.mp3 alias BGM2", 0, 0, 0);  //�Ǹ�biubiu��ѡ������Ч
	mciSendString("open audio\\arms01\\8bit_shoot1.mp3 alias BGMshoot0", 0, 0, 0);   //�����ӵ�������Ч
	mciSendString("open audio\\arms01\\8bit_shoot1.mp3 alias BGMshoot1", 0, 0, 0);   //�����ӵ�������Ч
	mciSendString("open audio\\arms01\\8bit_shoot1.mp3 alias BGMshoot2", 0, 0, 0);   //�����ӵ�������Ч
	mciSendString("open audio\\arms01\\chorus_of_angels1.mp3 alias BGMxiaoZhang", 0, 0, 0);    //У����bgm
	mciSendString("open audio\\arms01\\destruction1.mp3 alias BGMdie", 0, 0, 0);     //��ɫ����ֵ�������Ч
	mciSendString("open audio\\arms01\\encounting.mp3 alias BGMboss", 0, 0, 0);     //boss�ż��ܵ���Ч
	mciSendString("open audio\\arms01\\lightning.mp3 alias BGMbossOut", 0, 0, 0);   //boss��������Ч
	
	mciSendString("setaudio BGMshoot0 volume to 150", NULL, 0, NULL);        //�����ӵ�������Ч   (���ǵ���������
	mciSendString("setaudio BGMshoot1 volume to 150", NULL, 0, NULL);		//�����ӵ�������Ч
	mciSendString("setaudio BGMshoot2 volume to 150", NULL, 0, NULL);		//�����ӵ�������Ч


	//ͼƬ���ļ��Ļ���������򣨽�β��

}

class dropout
{
private:
	int vy;
	int ay;

public:
	int x;
	int y;
	int option;            //���������ͣ�1���������2����Ǯ,3Ѫ����3���ܰ�

	void chushihua(int xx,int yy)
	{
		x = xx;
		y = yy;
		vy = -15;
		ay = 1;
		option = rand() % 300;
		if (option == 98)
			option = 3;
		else if (option == 99)
			option = 4;
		else
		{
			if (option % 2)
				option = 1;
			else
				option = 2;
		}
	}

	void MoveAndShow()         //һ�μ���λ�ò��Ҳ���ͼƬ
	{
		vy += ay;
		if (vy >= 3)vy = 3;
		y += vy;
		if (option == 2)
			putimage_alpha(x - 10, y - 10, &imgMoney);
		else if (option == 1)
			putimage_alpha(x - 10, y - 10, &imgPoint);
		else if (option == 3)
			putimage_alpha(x - 10, y - 10, &imgHPpoint);
		else if(option==4)
			putimage_alpha(x - 10, y - 10, &imgBoomPoint);

	}

	bool isNeedDelete()
	{
		if (y >= 780 + 10)
			return true;
		return false;
	}

	bool pengZhuangJianCe(int xx, int yy)
	{
		if (xx >= x - 25 && xx <= x + 25 && yy <= y + 25 && yy >= y - 25)
			return true;
		return false;
	}
};

vector<dropout>dropOutThingList;



bool isGoOn()
{
	bool GameMidlleIsGoOn = true;
	bool isShang = true;
	int temp = 200;
	while (GameMidlleIsGoOn)
	{
		DWORD beginTime = GetTickCount64();
		
		settextcolor(RGB(255, 255, 255));
		settextstyle(40, 20, "����");
		string shiFouJixu = "�Ƿ񸴻�? ��ʹ��ᵼ��ѧУ��������";
		string shi = "��";
		string fou = "��";
		outTextCenter(0, 270, shiFouJixu);
		outTextCenter(0, 340, shi);
		outTextCenter(0, 400, fou);

		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)			// ���°����������»س�����һ��, ���Ҽ�ѡ��
			{
				switch (msg.vkcode)
				{
				case VK_RETURN:
					GameMidlleIsGoOn = false;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				case VK_UP:
					isShang = true;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				case VK_DOWN:
					isShang = false;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				}
			}
		}

		setlinestyle(0, 0);

		if (isShang)
		{
			setlinecolor(RGB(81, 149, 222));
			rectangle(-25, 375, 25, 425);
			setlinecolor(WHITE);
			rectangle(-25, 315, 25, 365);
		}	
		else
		{
			setlinecolor(RGB(81, 149, 222));
			rectangle(-25, 315, 25, 365);
			setlinecolor(WHITE);
			rectangle(-25, 375, 25, 425);
			
		}
			


		DWORD endTime = GetTickCount64();                          //��֡��60֡
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / FRAME)
			Sleep(1000 / FRAME - elapsedTime);

		FlushBatchDraw();
		Sleep(16);

	}
	return isShang;
}

void GamePart1()
{
	DWORD partoneBeginTime = GetTickCount64();          //��¼partOne��ʼ��ʱ��
	bool isShot = false;
	bool isBoom = false;
	bool isShift = false;
	ll boomToboomTime = 9999;
	ll partOneCnt = 0;
	int gongjiYuWAng = 200;
	bool isBossOut = true;
	int bossMoveModel = 1;
	int bossShotModel = 1;
	int bossPassCnt = 0;
	ll isoverCnt = llmax;
	while (running)
	{
		partOneCnt++;
		boomToboomTime++;
		DWORD beginTime = GetTickCount64();


		// ��Ϣ����
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)			// ���°�������
			{
				switch (msg.vkcode)
				{
				case VK_SHIFT:
					isShift = true;
					break;

				case VK_UP:
					DUT.direction.up = true;
					break;

				case VK_DOWN:
					DUT.direction.down = true;
					break;

				case VK_LEFT:
					DUT.direction.left = true;
					break;

				case VK_RIGHT:
					DUT.direction.right = true;
					break;
				case 'Z':
				case 'z':
					isShot = true;
					break;
				case 'X':
				case 'x':
					if (boomToboomTime >= 120)
					{
						isBoom = true;
					}	
					break;

				}
			}
			if (msg.message == WM_KEYUP)			// �ɿ���������
			{
				switch (msg.vkcode)
				{
				case VK_SHIFT:
					isShift = false;
					break;
				case VK_UP:
					DUT.direction.up = false;
					break;

				case VK_DOWN:
					DUT.direction.down = false;
					break;

				case VK_LEFT:
					DUT.direction.left = false;
					break;

				case VK_RIGHT:
					DUT.direction.right = false;
					break;

				case 'Z':
				case 'z':
					isShot = false;
					break;

				case 'X':
				case 'x':
					isBoom = false;
					break;
				}
			}
		}

		if (isShift)
		{
			DUT.vx = 3;
			DUT.vy = 3;
			DUT.r = 5;
		}
		else
		{
			DUT.vx = 7;
			DUT.vy = 7;
			DUT.r = 10;
		}
			


		DUT.move(DUT.moveXmodel, DUT.moveYmodel);    //λ�ü���
		DUT.claMovemode();     //��ɫ�˶�ģʽ����


		putimage(-screenWidth / 2, 0, &imgBehindBK);      //����Ĵ�ͼ
		putimage(-screenWidth / 2 + 20, 20, &imgLeftGame);    //�����Ϸ����ͼ
		setlinecolor(RGB(170, 170, 170));                  //��Ϸ�߿�
		setlinestyle(0, 5);
		rectangle(-screenWidth / 2 + 20, 20, 300, 780);
		string stringLuQuScore = "�߿�¼ȡ������Ϊ��";
		string stringHP = "Player��";
		string stringBoom = "Boom��";
		string stringMoneyEveryYear = "��Ͷ�뾭��Ϊ��";
		ostringstream stringTempToNumber;
		stringTempToNumber << DUT.MoneyEveryYear << " Ԫ";
		settextstyle(35, 0, "�����п�");
		settextcolor(YELLOW);
		outtextxy(315, 100, stringMoneyEveryYear.c_str());         //�������Ǯ
		outtextxy(315, 130, stringTempToNumber.str().c_str());
		settextcolor(GREEN);
		outtextxy(315, 180, stringLuQuScore.c_str());          //������
		stringTempToNumber.str("");
		stringTempToNumber << DUT.GkLuquScore;
		outtextxy(315, 210, stringTempToNumber.str().c_str());
		settextcolor(RGB(255, 0, 0));
		outtextxy(315, 260, stringHP.c_str());                  //��ʾѪ��
		_rep(i, 1, DUT.HP) putimage_alpha(285 + textwidth(stringHP.c_str()) + i * 30, 260, &imgHP);
		settextcolor(BLUE);
		outtextxy(315, 300, stringBoom.c_str());             //��ʾ������
		_rep(i, 1, DUT.Boom) putimage_alpha(285 + textwidth(stringBoom.c_str()) + i * 30, 300, &imgBoom);
		putimage_alpha(315, 400, &LOGO);                  //��ʾLOGO

		cloud.show();                                    //��ʾ����

		DUT.pengZhuangJianCe();   //��ɫ��ײ���

		if (isShot)
			DUT.shoot();           //�����ӵ��������ӵ�������mainbulletList��
		DUT.show();           //��ɫλ���ƶ���ʾ

		if (isBoom&&boomToboomTime >= 120)
		{
			boomToboomTime = 0;
			DUT.useTechnology();
			if (!bossLiveList.empty())
				bossLiveList.begin()->HP -= 100;
		}

		



		DWORD partOneNowTime = GetTickCount64();
		DWORD partOnePassTime = partOneNowTime - partoneBeginTime;        //������Ϸ��ʼ��ʱ��

		//�淨����
		
		if (partOnePassTime > 2000 && partOnePassTime <= 20000)
		{
			gongjiYuWAng = 300;
			if (!(partOneCnt % 90))
			{
				int rand1 = rand() % 800 - 550;
				againstRolesmall temp;
				temp.chushihua(rand1, 40, 0, 5, 0, -0.03, &imgDaLianHaiShi, rand() % 30 + 90, 1);               //4ֻһ��
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand1 + 20, 40, 0, 5, 0, -0.03, &imgDongBei, rand() % 30 + 180, 1);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand1 - 20, 40, 0, 5, 0, -0.03, &imgJiLin, rand() % 30 + 270, 1);
				againstRoleLiveList.push_back(temp3);
				againstRolesmall temp4;
				temp4.chushihua(rand1 + 10, 30, 0, 5, 0, -0.03, &imgHaErBinGongCheng, rand() % 30 + 360, 1);
				againstRoleLiveList.push_back(temp4);
			}
		}
		else if (partOnePassTime <= 2000)
		{

		}
		else if (partOnePassTime <= 32000)
		{
			gongjiYuWAng = 200;
			if (!(partOneCnt % 30))                                                 //��������
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 5, 5, -0.1, -0.10, &imgDongNan, llmax, 1);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, -5, 5, 0.1, -0.10, &imgHaErBinGongCheng, llmax, 1);
				againstRoleLiveList.push_back(temp2);
			}
		}
		else if (partOnePassTime <= 48000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 25))                 //���ٷɹ���ɢ��
			{
				againstRolesmall temp;
				temp.chushihua(-580, rand() % 300 + 20, 5, 0, -0.02, -0.03, &imgHaErBinGongYe, 120, 2);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(300, rand() % 300 + 20, -5, 0, 0.02, -0.03, &imgHuaDongShiFan, 120, 2);
				againstRoleLiveList.push_back(temp2);
			}
		}
		else if (partOnePassTime <= 72000)
		{
			gongjiYuWAng = 200;
			if (!(partOneCnt % 50))                        //��ֻһ��
			{
				int rand1 = rand() % 800 - 550;
				againstRolesmall temp;
				temp.chushihua(rand1, 40, 0, 5, 0, -0.03, &imgDaLianHaiShi, rand() % 30 + 90, 1);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand1 + 20, 40, 0, 5, 0, -0.03, &imgDongBei, rand() % 30 + 180, 1);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand1 - 20, 40, 0, 5, 0, -0.03, &imgJiLin, rand() % 30 + 270, 1);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 84000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 30))                         //��������
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 5, 5, -0.1, -0.10, &imgNanJing, llmax, 1);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, -5, 5, 0.1, -0.10, &imgNanKai, llmax, 1);
				againstRoleLiveList.push_back(temp2);
			}
		}
		else if (partOnePassTime <= 96000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 20))           //ˢ��Ƶ��         ֱ��ֱ��
			{
				againstRolesmall temp;
				temp.chushihua(-550, 800, 0, -8, 0, 0, &imgWuHanDaXueSmall, llmax, 1);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(270, 800, 0, -8, 0, 0, &imgBeiJingHangKong, llmax, 1);
				againstRoleLiveList.push_back(temp1);
			}
		}
		else if (partOnePassTime <= 108000)
		{
			gongjiYuWAng = 80;
			if (!(partOneCnt % 30))           //0.5sˢһ����    ˫��
			{
				againstRolesmall temp;
				temp.chushihua(-580, 220, 7, -5, 0, 0.09, &imgBeiJingLiGong, llmax, 2);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(300, 220, -7, -5, 0, 0.09, &imgBeiJingShiFan, llmax, 2);
				againstRoleLiveList.push_back(temp1);
			}
		}
		else if (partOnePassTime <= 120000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 20))           //ˢ��Ƶ��       ֱ��ֱ��
			{
				againstRolesmall temp;
				temp.chushihua(-550, 30, 0, 8, 0, 0, &imgShanDong, llmax, 1);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(270, 30, 0, 8, 0, 0, &imgShangJiao, llmax, 1);
				againstRoleLiveList.push_back(temp1);
			}
		}
		else if (partOnePassTime <= 145000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 30))                         //��������
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 5, 7, 0, -0.1, &imgNanJing, llmax, 2);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, -5, 7, 0, -0.1, &imgNanKai, llmax, 2);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand() % 800 - 550, 30, rand() % 5, 7, 0.1 * (rand() % 3), -0.1, &imgNanKai, llmax, 2);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 155000)
		{
			gongjiYuWAng = 120;
			if (!(partOneCnt % 20))                         //����һ��
			{
				againstRolesmall temp;
				temp.chushihua(-577, 60, 7, 0, 0, 0, &imgFuDan, llmax, 3);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(290, 150, -7, 0, 0, 0, &imgHuaKe, llmax, 3);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(-577, 270, 7, 0, 0, 0, &imgSiChuan, llmax, 3);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 165000)
		{
			gongjiYuWAng = 120;
			if (!(partOneCnt % 20))                         //����һ��
			{
				againstRolesmall temp;
				temp.chushihua(290, 60, -7, 0, 0, 0, &imgTianJin, llmax, 1);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(-577, 150, 7, 0, 0, 0, &imgTongJi, llmax, 1);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(290, 270, -7, 0, 0, 0, &imgXiaMen, llmax, 1);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 175000)
		{
			gongjiYuWAng = 90;
			if (!(partOneCnt % 20))                         //����һ��
			{
				againstRolesmall temp;
				temp.chushihua(-577, 60, 7, 0, 0, 0, &imgXiAnDianZiKeJi, llmax, 2);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(290, 150, -7, 0, 0, 0, &imgXiAnJiaoTong, llmax, 2);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(-577, 270, 7, 0, 0, 0, &imgxiBeiGongYe, llmax, 2);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 180000)
		{

		}
		else if (partOnePassTime <= 200000)   //200000
		{
			if(isBossOut)
			{
				BGMpartOne(0);
				BGMpartOneBoss(1);
				mciSendString("play BGMbossOut from 0", 0, 0, 0);
				isBossOut = false;
				BOSS temp;
				temp.chushihua(-400, 0, &imgBeiDaBoss);
				bossLiveList.push_back(temp);
			}
			if (!(partOneCnt % 3))
				if (!bossLiveList.empty())
					bossLiveList.begin()->shot(3);           //����
		}
		else
		{
			bossPassCnt++;
			if (!(partOneCnt % 900))
			{
				bossShotModel = (bossShotModel + 1) % 6 ;
				//bossShotModel = 4;
				bossPassCnt = 0;
				mciSendString("play BGMboss from 0", 0, 0, 0);
			}		
			if (bossShotModel == 0)
			{
				if (!(partOneCnt % 3))
					if (!bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
			}
			else if (bossShotModel == 1)
			{
				if (!(partOneCnt % 30) && !bossLiveList.empty())   //��Ȧ
				{
					bossLiveList.begin()->shot(4);
					if (!(partOneCnt % 120))
						bossLiveList.begin()->shot(5);     //����
				}
			}
			else if (bossShotModel == 2)
			{
				if (!(partOneCnt % 2))                           //����
					if (!bossLiveList.empty())
						bossLiveList.begin()->shot(2);
			}
			else if (bossShotModel == 3)
			{
				if (bossPassCnt <= 600)
				{
					if (!(partOneCnt % 3)&& !bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
				}
				else
				{
					if (!(partOneCnt % 9)&& !bossLiveList.empty())
						bossLiveList.begin()->shot(6);    //����
				}
			}
			else if (bossShotModel == 4)
			{
				if (!(partOneCnt % 3)&& !bossLiveList.empty())
					bossLiveList.begin()->shot(3);           //����
			}
			else if (bossShotModel == 5)
			{
				if (bossPassCnt <= 450)
				{
					if (!(partOneCnt % 3) && !bossLiveList.empty())
					bossLiveList.begin()->shot(3);           //����
				}
				else
				{
					if (!(partOneCnt % 3) && !bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
				}
				
			}

		}

		

		if(!bossLiveList.empty())
		for (auto it = bossLiveList.begin(); it != bossLiveList.end();)
		{
			if (it->HP > 0)
			{
				for (auto it2 = mainBulletList.begin(); it2 != mainBulletList.end(); )
				{
					if (it->pengzhuangjiance(it2->x, it2->y, it2->r))
					{
						shangHaiXiaoguo temp2(it2->x, it2->y);
						hurtXiaoGuoList.push_back(temp2);
						it2 = mainBulletList.erase(it2);
					}
					else
						it2++;
				}
				it->calAndMoveAndShow(bossMoveModel);
				it++;
			}
			else
			{
				it = bossLiveList.erase(it);
				BGMpartOneBoss(0);
				DUT.GkLuquScore += 150;
				for (auto it3 = againstBulletList.begin(); it3 != againstBulletList.end();)//���ӵ�����
				{
					it3 = againstBulletList.erase(it3);
				}
				isoverCnt = 180;                               //��boss�����˾�ֱ�ӵ�һ�ؽ���
			}
				
		}

		isoverCnt--;
		if (isoverCnt < 0)
			return;
		
		if (!againstRoleLiveList.empty())
			for (auto it = againstRoleLiveList.begin(); it != againstRoleLiveList.end();)
			{
				bool isMingZhong = false;
				if (!mainBulletList.empty())
				{
					for (auto it2 = mainBulletList.begin(); it2 != mainBulletList.end(); )
					{
						if (it2->pengZhuangJianCe(it->x, it->y, it->r))
						{
							isMingZhong = true;
							if (it->gethurt())         //������
							{
								dropout dropTemp;                     //���ɵ�����
								dropTemp.chushihua(it->x, it->y);
								dropOutThingList.push_back(dropTemp);
								shangHaiXiaoguo temp((it->x + it2->x) / 2, (it->y + it->y) / 2);
								hurtXiaoGuoList.push_back(temp);
								//againstRoleDIEList.push_back(*it);
								it = againstRoleLiveList.erase(it);
							}
							it2 = mainBulletList.erase(it2);
							break;
						}
						else
							it2++;
					}
				}
				if (!isMingZhong)
					it++;
			}

		//�з��ӵ�����Ч��
		if (!againstBulletList.empty() && !DUT.dutGolenBodyCnt)    //�������û�н���Ч���͹���
			for (auto it = againstBulletList.begin(); it != againstBulletList.end();)
			{
				bool isMingZhong = false;
				if (it->pengZhuangJianCe(DUT.x, DUT.y, DUT.r))
				{
					shangHaiXiaoguo temp(DUT.x, DUT.y);
					hurtXiaoGuoList.push_back(temp);
					DUT.getHert();
					DUT.chushihua();
					it = againstBulletList.erase(it);

				}
				else
					it++;
			}



		if (!againstRoleLiveList.empty())
			for (auto it = againstRoleLiveList.begin(); it != againstRoleLiveList.end();)             //��ǰ���Ĺ����б�
			{
				if (it->isNeedDelet())                //������ŵ�Խ���ˣ��Ͱ����ӻ�������
				{
					it = againstRoleLiveList.erase(it);
				}
				else
				{
					int isShootRand = rand() % gongjiYuWAng;
					if (isShootRand == 1)
						it->shoot(it->shotModel);
					it->calMove();
					it->show();
					it++;
				}
			}

		if (!hurtXiaoGuoList.empty())
			for (auto it = hurtXiaoGuoList.begin(); it != hurtXiaoGuoList.end();)
			{
				if (it->show())
				{
					it++;
				}
				else
				{
					it = hurtXiaoGuoList.erase(it);
				}
			}

		//�������ƶ����Լ�������⣬�Լ���ײ���
		if (!dropOutThingList.empty())
			for (auto it = dropOutThingList.begin(); it != dropOutThingList.end();)
			{
				if (it->isNeedDelete())
				{
					it = dropOutThingList.erase(it);
				}
				else if (it->pengZhuangJianCe(DUT.x, DUT.y))
				{
					if (it->option == 1)
						DUT.GkLuquScore++;
					else if (it->option == 2)
						DUT.MoneyEveryYear += 1000;
					else if (it->option == 3)
						DUT.HP++;
					else if (it->option == 4)
						DUT.Boom++;
					it = dropOutThingList.erase(it);
				}
				else
				{
					it->MoveAndShow();
					it++;
				}
			}

		//if(!againstRoleDIEList.empty())
		//for (auto it = againstRoleDIEList.begin(); it != againstRoleDIEList.end();)                //���ڲ���ȥ�������Ĺ����б�
		//{
		//	if (it->dieShow())     //��͸�˻᷵��true
		//	{
		//		it = againstRoleDIEList.erase(it);          //��͸�˾Ͱ���ɾ��
		//	}
		//	else
		//	{
		//		it++;
		//	}
		//}


		if (!mainBulletList.empty())
			for (auto it = mainBulletList.begin(); it != mainBulletList.end();)
			{
				if (it->isNeedDelete()) //ATTENTION!! �������ײ��⻹ûд
				{
					it = mainBulletList.erase(it);

				}
				else
				{
					it->calshot();
					it->show();
					it++;
				}
			}

		if (!againstBulletList.empty())
			for (auto it = againstBulletList.begin(); it != againstBulletList.end();)
			{
				if (it->isNeedDelete())
					it = againstBulletList.erase(it);
				else
				{
					it->calMove();
					it->show();
					it++;
				}
			}

		if (!boomList.empty())
			for (auto it = boomList.begin(); it != boomList.end();)
			{
				if (it->isNeedDelete())
				{
					it = boomList.erase(it);
				}
				else
				{
					it->calAndMove();
					for (auto it2 = againstBulletList.begin(); it2 != againstBulletList.end();)
					{
						it2 = againstBulletList.erase(it2);
					}
					for (auto it2 = againstRoleLiveList.begin(); it2 != againstRoleLiveList.end();)
					{
						dropout dropTemp;                     //���ɵ�����
						dropTemp.chushihua(it2->x, it2->y);
						dropOutThingList.push_back(dropTemp);
						shangHaiXiaoguo temp(it2->x, it2->y);    //��ըЧ��
						hurtXiaoGuoList.push_back(temp);
						it2 = againstRoleLiveList.erase(it2);
					}
					it++;
				}
			}


		//�˴���ATTENTION ���ĳ��˳���ѯ�ʣ���дһ��bool����ѯ���Ƿ������
		if (DUT.HP < 0)
		{
			mciSendString("play BGMdie from 0", 0, 0, 0);
			if (isGoOn())
			{
				DUT.HP = 2;
				DUT.Boom = 3;
				DUT.GkLuquScore -= 50;
			}
			else
			{
				isGameOver = true;
				return;
			}
			
			
		}

		FlushBatchDraw();



		DWORD endTime = GetTickCount64();                          //��֡��60֡
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / FRAME)
			Sleep(1000 / FRAME - elapsedTime);
	}

}




void GamePart2()             //�ڶ��صĺ�������ֱ�Ӵ󲿷ָ���ճ����һ��
{

	DWORD partoneBeginTime = GetTickCount64();          //��¼partOne��ʼ��ʱ��
	bool isShot = false;
	bool isBoom = false;
	bool isShift = false;
	ll boomToboomTime = 9999;
	ll partOneCnt = 0;
	int gongjiYuWAng = 200;
	bool isBossOut = true;
	int bossMoveModel = 1;
	int bossShotModel = 1;
	int bossPassCnt = 0;
	ll isoverCnt = llmax;
	bool isBossMove = false;
	while (running)
	{
		partOneCnt++;
		boomToboomTime++;
		DWORD beginTime = GetTickCount64();


		// ��Ϣ����
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)			// ���°�������
			{
				switch (msg.vkcode)
				{
				case VK_SHIFT:
					isShift = true;
					break;

				case VK_UP:
					DUT.direction.up = true;
					break;

				case VK_DOWN:
					DUT.direction.down = true;
					break;

				case VK_LEFT:
					DUT.direction.left = true;
					break;

				case VK_RIGHT:
					DUT.direction.right = true;
					break;
				case 'Z':
				case 'z':
					isShot = true;
					break;
				case 'X':
				case 'x':
					if (boomToboomTime >= 120)
					{
						isBoom = true;
					}
					break;

				}
			}
			if (msg.message == WM_KEYUP)			// �ɿ���������
			{
				switch (msg.vkcode)
				{
				case VK_SHIFT:
					isShift = false;
					break;
				case VK_UP:
					DUT.direction.up = false;
					break;

				case VK_DOWN:
					DUT.direction.down = false;
					break;

				case VK_LEFT:
					DUT.direction.left = false;
					break;

				case VK_RIGHT:
					DUT.direction.right = false;
					break;

				case 'Z':
				case 'z':
					isShot = false;
					break;

				case 'X':
				case 'x':
					isBoom = false;
					break;
				}
			}
		}

		if (isShift)
		{
			DUT.vx = 3;
			DUT.vy = 3;
			DUT.r = 5;
		}
		else
		{
			DUT.vx = 7;
			DUT.vy = 7;
			DUT.r = 10;
		}



		DUT.move(DUT.moveXmodel, DUT.moveYmodel);    //λ�ü���
		DUT.claMovemode();     //��ɫ�˶�ģʽ����


		putimage(-screenWidth / 2, 0, &imgBehindBK);      //����Ĵ�ͼ
		putimage(-screenWidth / 2 + 20, 20, &imgleftGame2);    //�����Ϸ����ͼ
		setlinecolor(RGB(170, 170, 170));                  //��Ϸ�߿�
		setlinestyle(0, 5);
		rectangle(-screenWidth / 2 + 20, 20, 300, 780);
		string stringLuQuScore = "�߿�¼ȡ������Ϊ��";
		string stringHP = "Player��";
		string stringBoom = "Boom��";
		string stringMoneyEveryYear = "��Ͷ�뾭��Ϊ��";
		ostringstream stringTempToNumber;
		stringTempToNumber << DUT.MoneyEveryYear << " Ԫ";
		settextstyle(35, 0, "�����п�");
		settextcolor(YELLOW);
		outtextxy(315, 100, stringMoneyEveryYear.c_str());         //�������Ǯ
		outtextxy(315, 130, stringTempToNumber.str().c_str());
		settextcolor(GREEN);
		outtextxy(315, 180, stringLuQuScore.c_str());          //������
		stringTempToNumber.str("");
		stringTempToNumber << DUT.GkLuquScore;
		outtextxy(315, 210, stringTempToNumber.str().c_str());
		settextcolor(RGB(255, 0, 0));
		outtextxy(315, 260, stringHP.c_str());                  //��ʾѪ��
		_rep(i, 1, DUT.HP) putimage_alpha(285 + textwidth(stringHP.c_str()) + i * 30, 260, &imgHP);
		settextcolor(BLUE);
		outtextxy(315, 300, stringBoom.c_str());             //��ʾ������
		_rep(i, 1, DUT.Boom) putimage_alpha(285 + textwidth(stringBoom.c_str()) + i * 30, 300, &imgBoom);
		putimage_alpha(315, 400, &LOGO);                  //��ʾLOGO

		cloud.show();                                    //��ʾ����

		DUT.pengZhuangJianCe();   //��ɫ��ײ���

		if (isShot)
			DUT.shoot();           //�����ӵ��������ӵ�������mainbulletList��
		DUT.show();           //��ɫλ���ƶ���ʾ

		if (isBoom && boomToboomTime >= 120)
		{
			boomToboomTime = 0;
			DUT.useTechnology();
			if (!bossLiveList.empty())
				bossLiveList.begin()->HP -= 100;
		}


		DWORD partOneNowTime = GetTickCount64();
		DWORD partOnePassTime = partOneNowTime - partoneBeginTime;        //������Ϸ��ʼ��ʱ��

		//�淨����

		if (partOnePassTime > 4000 && partOnePassTime <= 20000)
		{
			gongjiYuWAng = 300;
			if (!(partOneCnt % 90))
			{
				int rand1 = rand() % 800 - 550;
				againstRolesmall temp;
				temp.chushihua(rand1, 40, 0, 5, 0, -0.03, &imgZheJiang, rand() % 30 + 90, 1,6);               //4ֻһ��
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand1 + 20, 40, 0, 5, 0, -0.03, &imgZhengZhou, rand() % 30 + 180, 1,5);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand1 - 20, 40, 0, 5, 0, -0.03, &imgZhongGuoRenMin, rand() % 30 + 270, 1,4);
				againstRoleLiveList.push_back(temp3);
				againstRolesmall temp4;
				temp4.chushihua(rand1 + 10, 30, 0, 5, 0, -0.03, &imgZhongShan, rand() % 30 + 360, 1,4);
				againstRoleLiveList.push_back(temp4);
			}
		}
		else if (partOnePassTime <= 4000)
		{

		}
		else if (partOnePassTime <= 32000)
		{
			gongjiYuWAng = 200;
			if (!(partOneCnt % 30))                                                 //����,���
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 5, 5, -0.1, 0, &imgDongNan, llmax, 1,5);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, -5, 5, 0.1, 0, &imgTongJi, llmax, 1,5);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand() % 30 - 140, 30, 0, 5, 0, 0, &imgBeiJingHangKong, llmax, 2, 5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 48000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 25))                 //���ٷɹ���ɢ��
			{
				againstRolesmall temp;
				temp.chushihua(-580, rand() % 300 + 20, 5, 0, -0.02, -0.03, &imgHaErBinGongYe, 120, 2);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(300, rand() % 300 + 20, -5, 0, 0.02, -0.03, &imgHuaDongShiFan, 120, 2);
				againstRoleLiveList.push_back(temp2);

			}
		}
		else if (partOnePassTime <= 60000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 20))
			{
				againstRolesmall temp1;
				againstRolesmall temp2;
				againstRolesmall temp3;
				temp1.chushihua(-580, 220, 7, -5, 0, 0.09, &imgShangJiao, llmax, 2);
				temp2.chushihua(-580, 120, 7, 5, 0, -0.09, &imgXiaMen, llmax, 2);
				temp3.chushihua(-580, 170, 5, 0, 0, 0, &imgZhongShan, llmax, 3);
				againstRoleLiveList.push_back(temp1);
				againstRoleLiveList.push_back(temp2);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 72000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 50))                        //��ֻһ��
			{
				int rand1 = rand() % 800 - 550;
				againstRolesmall temp;
				temp.chushihua(rand1, 40, 0, 5, 0, -0.03, &imgDaLianHaiShi, rand() % 30 + 90, 1,5);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand1 + 20, 40, 0, 5, 0, -0.03, &imgDongBei, rand() % 30 + 180, 1,5);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand1 - 20, 40, 0, 5, 0, -0.03, &imgJiLin, rand() % 30 + 270, 1,5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 84000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 30))                        
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 0, 5, 0, -0.10, &imgNanJing, 120, 1);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, 0, 5, 0, -0.10, &imgNanKai, 120, 1);
				againstRoleLiveList.push_back(temp2);
			}
		}
		else if (partOnePassTime <= 100000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 20))           //ˢ��Ƶ��        
			{
				againstRolesmall temp;
				temp.chushihua(-550, 800, 2.5, -4, -0.02, 0, &imgWuHanDaXueSmall, llmax, 1);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(270, 800, -2.5, -4, 0.02, 0, &imgBeiJingHangKong, llmax, 1);
				againstRoleLiveList.push_back(temp1);
			}
		}
		else if (partOnePassTime <= 108000)
		{
			gongjiYuWAng = 80;
			if (!(partOneCnt % 30))           //0.5sˢһ����    ˫��
			{
				againstRolesmall temp;
				temp.chushihua(-580, 220, 7, -5, 0, 0.09, &imgBeiJingLiGong, llmax, 2);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(300, 220, -7, 5, 0, -0.09, &imgZhongGuoRenMin, llmax, 2);
				againstRoleLiveList.push_back(temp1);

				againstRolesmall temp3;
				temp3.chushihua(-140, 30, 0, 5, 0, 0, &imgXiAnJiaoTong, llmax, 1, 5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 120000)
		{
			gongjiYuWAng = 100;
			if (!(partOneCnt % 20))           //ˢ��Ƶ��       X
			{
				againstRolesmall temp;
				temp.chushihua(-550, 30, 3, 5, 0, 0, &imgSiChuan, llmax, 1,5);
				againstRoleLiveList.push_back(temp);

				againstRolesmall temp1;
				temp1.chushihua(270, 30, -3, 5, 0, 0, &imgTianJin, llmax, 1,5);
				againstRoleLiveList.push_back(temp1);
			}
		}
		else if (partOnePassTime <= 145000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 30))                         //��������
			{
				againstRolesmall temp;
				temp.chushihua(rand() % 800 - 550, 30, 5, 7, 0, -0.1, &imgNanJing, llmax, 2,5);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(rand() % 800 - 550, 30, -5, 7, 0, -0.1, &imgNanKai, llmax, 2,5);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(rand() % 800 - 550, 30, rand() % 5, 7, 0.1 * (rand() % 3), -0.1, &imgNanKai, llmax, 2,5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 155000)
		{
			gongjiYuWAng = 120;
			if (!(partOneCnt % 20))                         //����һ��
			{
				againstRolesmall temp;
				temp.chushihua(-577, 60, 7, 0, 0, 0, &imgFuDan, llmax, 3,5);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(-577, 150, 7, 0, 0, 0, &imgHuaKe, llmax, 3);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(-577, 270, 7, 0, 0, 0, &imgSiChuan, llmax, 3,5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 165000)
		{
			gongjiYuWAng = 120;
			if (!(partOneCnt % 20))                         //����һ��
			{
				againstRolesmall temp;
				temp.chushihua(290, 60, -7, 0, 0, 0, &imgTianJin, llmax, 1,5);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(290, 150, -7, 0, 0, 0, &imgTongJi, llmax, 1,5);
				againstRoleLiveList.push_back(temp2);
				againstRolesmall temp3;
				temp3.chushihua(290, 270, -7, 0, 0, 0, &imgXiaMen, llmax, 1,5);
				againstRoleLiveList.push_back(temp3);
			}
		}
		else if (partOnePassTime <= 175000)
		{
			gongjiYuWAng = 150;
			if (!(partOneCnt % 50))                         //����
			{
				againstRolesmall temp;
				temp.chushihua(-140, 30, 0, 7, 0, 0, &imgXiAnDianZiKeJi, llmax, 2);
				againstRoleLiveList.push_back(temp);
				againstRolesmall temp2;
				temp2.chushihua(-190, 30, 0, 7, 0, 0, &imgXiAnJiaoTong, llmax, 2);
				againstRoleLiveList.push_back(temp2);
			}
		}
		else if (partOnePassTime <= 180000)
		{

		}
		else if (partOnePassTime <= 200000)   //200000
		{
			if (isBossOut)
			{
				BGMpartTwo(0);
				BGMpartTwoBoss(1);
				mciSendString("play BGMbossOut from 0", 0, 0, 0);
				isBossOut = false;
				BOSS temp;
				temp.chushihua(-400, 0, &imgQingHuaBoss);
				bossLiveList.push_back(temp);
			}
			if (!(partOneCnt % 3))
				if (!bossLiveList.empty())
					bossLiveList.begin()->shot(3);           //����
		}
		else
		{
			bossPassCnt++;
			if (!(partOneCnt % 900))
			{
				bossShotModel = (bossShotModel + 1) % 8;
				//bossShotModel = 4;
				bossPassCnt = 0;
				mciSendString("play BGMboss from 0", 0, 0, 0);
			}
			if (bossShotModel == 0)
			{
				bossMoveModel = 1;
				if (!bossLiveList.empty() && isBossMove)
				{
					bossLiveList.begin()->vx = 2;
					isBossMove = false;
				}
				if (!(partOneCnt % 3))
					if (!bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
			}
			else if (bossShotModel == 1)
			{
				if (!(partOneCnt % 30) && !bossLiveList.empty())   //��Ȧ
				{
					bossLiveList.begin()->shot(4);
					if (!(partOneCnt % 120))
						bossLiveList.begin()->shot(5);     //����
				}
			}
			else if (bossShotModel == 2)
			{
				if (!(partOneCnt % 2))                           //����
					if (!bossLiveList.empty())
						bossLiveList.begin()->shot(2);
			}
			else if (bossShotModel == 3)
			{
				if (bossPassCnt <= 600)
				{
					if (!(partOneCnt % 3) && !bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
				}
				else
				{
					if (!(partOneCnt % 9) && !bossLiveList.empty())
						bossLiveList.begin()->shot(6);    //����
				}
			}
			else if (bossShotModel == 4)
			{
				if (!(partOneCnt % 3) && !bossLiveList.empty())
					bossLiveList.begin()->shot(3);           //����
			}
			else if (bossShotModel == 5)
			{
				if (bossPassCnt <= 450)
				{
					if (!(partOneCnt % 3) && !bossLiveList.empty())
						bossLiveList.begin()->shot(3);           //����
				}
				else
				{
					if (!(partOneCnt % 3) && !bossLiveList.empty())
						bossLiveList.begin()->shot(1);      //˫��
				}

			}
			else if (bossShotModel == 6)
			{
				bossMoveModel = 0;
				if (!(partOneCnt % 60) && !bossLiveList.empty())
					bossLiveList.begin()->shot(7);           
			}
			else if (bossShotModel == 7)
			{
				isBossMove = true;
				bossMoveModel = 0;
				if (!(partOneCnt % 5) && !bossLiveList.empty())
				{
					bossLiveList.begin()->shot(8);
					if (!(partOneCnt % 120))
						bossLiveList.begin()->shot(5);     //����
				}
					
			}

		}



		if (!bossLiveList.empty())
			for (auto it = bossLiveList.begin(); it != bossLiveList.end();)
			{
				if (it->HP > 0)
				{
					for (auto it2 = mainBulletList.begin(); it2 != mainBulletList.end(); )
					{
						if (it->pengzhuangjiance(it2->x, it2->y, it2->r))
						{
							shangHaiXiaoguo temp2(it2->x, it2->y);
							hurtXiaoGuoList.push_back(temp2);
							it2 = mainBulletList.erase(it2);
						}
						else
							it2++;
					}
					it->calAndMoveAndShow(bossMoveModel);
					it++;
				}
				else
				{
					it = bossLiveList.erase(it);
					BGMpartOneBoss(0);
					DUT.GkLuquScore += 150;
					isoverCnt = 180;
				}

			}

		isoverCnt--;
		if (isoverCnt < 0)
			return;


		if (!againstRoleLiveList.empty())
			for (auto it = againstRoleLiveList.begin(); it != againstRoleLiveList.end();)
			{
				bool isMingZhong = false;
				if (!mainBulletList.empty())
				{
					for (auto it2 = mainBulletList.begin(); it2 != mainBulletList.end(); )
					{
						if (it2->pengZhuangJianCe(it->x, it->y, it->r))
						{
							isMingZhong = true;
							if (it->gethurt())         //������
							{
								dropout dropTemp;                     //���ɵ�����
								dropTemp.chushihua(it->x, it->y);
								dropOutThingList.push_back(dropTemp);
								shangHaiXiaoguo temp((it->x + it2->x) / 2, (it->y + it->y) / 2);
								hurtXiaoGuoList.push_back(temp);
								//againstRoleDIEList.push_back(*it);
								it = againstRoleLiveList.erase(it);
							}
							it2 = mainBulletList.erase(it2);
							break;
						}
						else
							it2++;
					}
				}
				if (!isMingZhong)
					it++;
			}

		//�з��ӵ�����Ч��
		if (!againstBulletList.empty() && !DUT.dutGolenBodyCnt)    //�������û�н���Ч���͹���
			for (auto it = againstBulletList.begin(); it != againstBulletList.end();)
			{
				bool isMingZhong = false;
				if (it->pengZhuangJianCe(DUT.x, DUT.y, DUT.r))
				{
					shangHaiXiaoguo temp(DUT.x, DUT.y);
					hurtXiaoGuoList.push_back(temp);
					DUT.getHert();
					DUT.chushihua();
					it = againstBulletList.erase(it);

				}
				else
					it++;
			}



		if (!againstRoleLiveList.empty())
			for (auto it = againstRoleLiveList.begin(); it != againstRoleLiveList.end();)             //��ǰ���Ĺ����б�
			{
				if (it->isNeedDelet())                //������ŵ�Խ���ˣ��Ͱ����ӻ�������
				{
					it = againstRoleLiveList.erase(it);
				}
				else
				{
					int isShootRand = rand() % gongjiYuWAng;
					if (isShootRand == 1)
						it->shoot(it->shotModel);
					it->calMove();
					it->show();
					it++;
				}
			}

		if (!hurtXiaoGuoList.empty())
			for (auto it = hurtXiaoGuoList.begin(); it != hurtXiaoGuoList.end();)
			{
				if (it->show())
				{
					it++;
				}
				else
				{
					it = hurtXiaoGuoList.erase(it);
				}
			}

		//�������ƶ����Լ�������⣬�Լ���ײ���
		if (!dropOutThingList.empty())
			for (auto it = dropOutThingList.begin(); it != dropOutThingList.end();)
			{
				if (it->isNeedDelete())
				{
					it = dropOutThingList.erase(it);
				}
				else if (it->pengZhuangJianCe(DUT.x, DUT.y))
				{
					if (it->option == 1)
						DUT.GkLuquScore++;
					else if (it->option == 2)
						DUT.MoneyEveryYear += 1000;
					else if (it->option == 3)
						DUT.HP++;
					else if (it->option == 4)
						DUT.Boom++;
					it = dropOutThingList.erase(it);
				}
				else
				{
					it->MoveAndShow();
					it++;
				}
			}

		//if(!againstRoleDIEList.empty())
		//for (auto it = againstRoleDIEList.begin(); it != againstRoleDIEList.end();)                //���ڲ���ȥ�������Ĺ����б�
		//{
		//	if (it->dieShow())     //��͸�˻᷵��true
		//	{
		//		it = againstRoleDIEList.erase(it);          //��͸�˾Ͱ���ɾ��
		//	}
		//	else
		//	{
		//		it++;
		//	}
		//}



		if (!mainBulletList.empty())
			for (auto it = mainBulletList.begin(); it != mainBulletList.end();)
			{
				if (it->isNeedDelete()) //ATTENTION!! �������ײ��⻹ûд
				{
					it = mainBulletList.erase(it);

				}
				else
				{
					it->calshot();
					it->show();
					it++;
				}
			}

		if (!againstBulletList.empty())
			for (auto it = againstBulletList.begin(); it != againstBulletList.end();)
			{
				if (it->isNeedDelete())
					it = againstBulletList.erase(it);
				else
				{
					it->calMove();
					it->show();
					it++;
				}
			}

		if (!boomList.empty())
			for (auto it = boomList.begin(); it != boomList.end();)
			{
				if (it->isNeedDelete())
				{
					it = boomList.erase(it);
				}
				else
				{
					it->calAndMove();
					for (auto it2 = againstBulletList.begin(); it2 != againstBulletList.end();)
					{
						it2 = againstBulletList.erase(it2);
					}
					for (auto it2 = againstRoleLiveList.begin(); it2 != againstRoleLiveList.end();)
					{
						dropout dropTemp;                     //���ɵ�����
						dropTemp.chushihua(it2->x, it2->y);
						dropOutThingList.push_back(dropTemp);
						shangHaiXiaoguo temp(it2->x, it2->y);    //��ըЧ��
						hurtXiaoGuoList.push_back(temp);
						it2 = againstRoleLiveList.erase(it2);
					}
					it++;
				}
			}


		//�˴���ATTENTION ���ĳ��˳���ѯ�ʣ���дһ��bool����ѯ���Ƿ������
		if (DUT.HP < 0)
		{
			mciSendString("play BGMdie from 0", 0, 0, 0);
			if (isGoOn())
			{
				DUT.HP = 2;
				DUT.Boom = 3;
				DUT.GkLuquScore -= 50;
			}
			else
			{
				isGameOver = true;
				return;
			}


		}

		FlushBatchDraw();



		DWORD endTime = GetTickCount64();                          //��֡��60֡
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / FRAME)
			Sleep(1000 / FRAME - elapsedTime);
	}
}


void Game()
{

	//��ʼ�������������ͷ��
	putimage(-screenWidth / 2, 0, &imgStart);			//��ʾ��ʼ�����ͼ��
	BGMstart(1);                                    //���ſ�ͷ����
	string KeyWayStateString = "������ƶ���z�������x������";
	string PressEnterToEnter = "��Enter����ʼ��Ϸ";
	setbkmode(TRANSPARENT);             //�����屳������Ϊ͸����
	settextcolor(BLACK);
	settextstyle(35, 17, "����");
	outTextCenter(0, screenHeight - 40, PressEnterToEnter);
	outTextCenter(0, screenHeight - 75, KeyWayStateString);
	FlushBatchDraw();

	while (running)
	{
		DWORD beginTime = GetTickCount64();
		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)			// ���°����������»س�����һ��
			{
				switch (msg.vkcode)
				{
				case VK_RETURN:
					running = false;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				}
			}
		}
		DWORD endTime = GetTickCount64();                          //��֡��60֡
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / FRAME)
			Sleep(1000 / FRAME - elapsedTime);

	}
	running = true;
	//��ʼ�������������β��

	//----------------------�ָ���-------------------------------------------------------------------------------------------------------------

	//ѡ��������棨��ͷ��


	string leftCharString = "��������ѧ";
	string rightCharString = "̫��������ѧ";
	string chosePartTitle = "��ѡ����Ĵ�ѧ";

	isCharNormal = true;     //���ڽ�ɫѡ��׶ε����������Լ������Ľ�ɫͼƬ���⣬true��ζ��ԭУ�գ�false��Ϊ��¶ŵ��
	bool chosePartisright = false;    //ѡ�񷽿�λ�� ,�ʼ�����
	bool chosePartisleft = true;
	while (running)
	{
		DWORD beginTime = GetTickCount64();

		while (peekmessage(&msg))
		{
			if (msg.message == WM_KEYDOWN)			// ���°����������»س�����һ��, ���Ҽ�ѡ��
			{
				switch (msg.vkcode)
				{
				case VK_RETURN:
					running = false;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				case VK_RIGHT:
					chosePartisright = true;
					chosePartisleft = false;
					isCharNormal = false;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				case VK_LEFT:
					chosePartisleft = true;
					chosePartisright = false;
					isCharNormal = true;
					mciSendString("play BGM2 from 0", 0, 0, 0);
					break;
				}
			}
		}
		cleardevice();								// �����Ļ

		putimage(-screenWidth / 2, 0, &imgChosePartBackground);
		setlinecolor(YELLOW);
		setlinestyle(0, 5);
		if (chosePartisleft && !chosePartisright)
		{
			rectangle(-450, 150, -150, 450);
		}
		else if (!chosePartisleft && chosePartisright)
		{
			rectangle(150, 150, 450, 450);
		}

		putimage_alpha(-450, 150, &imgDUTbigger);                 //�������ͼ��
		putimage_alpha(150, 150, &imgDUTcartoon);               //�����Ҳ�ͼ��

		outTextCenter(0, 40, chosePartTitle);      //��ѡ����Ĵ�ѧ
		outTextCenter(-300, 470, leftCharString);
		outTextCenter(300, 470, rightCharString);


		FlushBatchDraw();

		DWORD endTime = GetTickCount64();                          //��֡��60֡
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / FRAME)
			Sleep(1000 / FRAME - elapsedTime);
	}
	running = true;

	//ѡ��������棨��β��

	//��Ů�������Լ��ر����֣���ͷ��

	BGMstart(0);     //�رտ�ʼҳ���BGM
	putimage(-screenWidth / 2, 0, &imgTheGirlIsPraying);    //��Ů���е�ͼƬ
	settextcolor(WHITE);                       //��Ϸ���
	settextstyle(26, 13, "����");
	string stringTheGameContentIntroduction = "������Ĵ�ѧ�������ɸ�У����Ϊ������ǿ��ѧ��";
	outTextCenter(-300, 40, stringTheGameContentIntroduction);
	if (isCharNormal)
		imgChar = imgChar1;
	else
		imgChar = imgChar2;
	FlushBatchDraw();
	Sleep(2000);


	//��Ů�������Լ��ر����֣���β��

	//----------------------�ָ���---------------------------------------------------------------------------------------------------------

	

	//��һ�� part1    ����ͷ��
	
	BGMpartOne(1);                       //������
	GamePart1();
	BGMpartOne(0);
	BGMpartOneBoss(0);
	if (isGameOver)
		return;
		
	//��һ�� part1    ����β��

	putimage(-screenWidth / 2, 0, &imgTheGirlIsPraying);    //��Ů���е�ͼƬ
	settextcolor(WHITE);                       //��Ϸ���
	settextstyle(26, 13, "����");
	stringTheGameContentIntroduction = "�Ų�ס��ʱ��û��ϵ��Ԫ�����ֵģ�";
	outTextCenter(-300, 40, stringTheGameContentIntroduction);
	FlushBatchDraw();
	Sleep(2000);

	//�ڶ���

	BGMpartTwo(1);
	GamePart2();
	BGMpartTwo(0);
	BGMpartTwoBoss(0);

	//�ڶ��ؽ�β

	return;
}


struct SCHOOL
{
	int score;
	string name;
}school[40];

bool cmp(const SCHOOL& a, const SCHOOL& b)
{
	return a.score > b.score;
}


int main()
{
	initgraph(screenWidth, screenHeight);
	BeginBatchDraw();                                 //˫�����õĿ�ͷ
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "������У������");
	setorigin(screenWidth / 2, 0);                   //�����ĵ������ڻ��������ģ����Ϸ���
	
	DUT.chushihua();                      //���ǳ�ʼ��
	DUT.HP = 2;
	DUT.Boom = 3;
	DUT.GkLuquScore = 200;                               //�߿�¼ȡ�����߳�ʼ��Ϊ300
	DUT.MoneyEveryYear = 0;                           //ÿ�꾭��Ͷ���ʼ��Ϊ0
	cloud.chushihua();
	srand(time(0));
	
	loadingManythings();                               //�����ز�

	Game();
	cout << "������" << ednl;

	school[0].score = 690;
	school[0].name = "�廪��ѧ";
	school[1].score = 685;
	school[1].name = "������ѧ";
	school[2].score = 680;
	school[2].name = "�㽭��ѧ";
	school[3].score = 677;
	school[3].name = "�Ϻ���ͨ��ѧ";
	school[4].score = 675;
	school[4].name = "������ѧ";
	school[5].score = 670;
	school[5].name = "�Ͼ���ѧ";
	school[6].score = 669;
	school[6].name = "�й���ѧ������ѧ";
	school[7].score = 666;
	school[7].name = "���пƼ���ѧ";
	school[8].score = 662;
	school[8].name = "�人��ѧ";
	school[9].score = 658;
	school[9].name = "������ͨ��ѧ";
	school[10].score = 656;
	school[10].name = "��ɽ��ѧ";
	school[11].score = 655;
	school[11].name = "�������պ����ѧ";
	school[12].score = 654;
	school[12].name = "���ϴ�ѧ";
	school[13].score = 651;
	school[13].name = "��������ѧ";
	school[14].score = 650;
	school[14].name = "�Ĵ���ѧ";
	school[15].score = 647;
	school[15].name = "��������ҵ��ѧ";
	school[16].score = 645;
	school[16].name = "ͬ�ô�ѧ";
	school[17].score = 642;
	school[17].name = "�й������ѧ";
	school[18].score = 641;
	school[18].name = "����ʦ����ѧ";
	school[19].score = 640;
	school[19].name = "����ѧ";
	school[20].score = 639;
	school[20].name = "�Ͽ���ѧ";
	school[21].score = 637;
	school[21].name = "ɽ����ѧ";
	school[22].score = 635;
	school[22].name = "������ҵ��ѧ";
	school[23].score = 632;
	school[23].name = "���Ŵ�ѧ";
	school[24].score = 630;
	school[24].name = "���ϴ�ѧ";
	school[25].score = 627;
	school[25].name = "���ִ�ѧ";
	school[26].score = 625;
	school[26].name = "�й�ũҵ��ѧ";
	school[27].score = 624;
	school[27].name = "����ʦ����ѧ";
	school[28].score = 622;
	school[28].name = "��������ѧ";
	if (isCharNormal)
		school[29].name = "��������ѧ";
	else
		school[29].name = "̫��������ѧ";
	school[29].score = DUT.GkLuquScore;

	sort(school, school + 30, cmp);

	BGMlast(1);

	putimage(-screenWidth / 2, 0, &imgChosePartBackground);
	settextcolor(BLACK);
	settextstyle(50, 25, "����");
	string lastPaiming = "������ѧ����";
	string paiming = "����";
	string suxiao = "ѧУ";
	string luqufenshuxian = "¼ȡ������";

	outTextCenter(40, 25, lastPaiming);

	settextstyle(30, 15, "����");
	outtextxy(-550, 120, paiming.c_str());
	outtextxy(-470, 120, suxiao.c_str());
	outtextxy(-180, 120, luqufenshuxian.c_str());

	outtextxy(50, 120, paiming.c_str());
	outtextxy(130, 120, suxiao.c_str());
	outtextxy(420, 120, luqufenshuxian.c_str());

	rep(i, 0, 15)
	{
		ostringstream ss;
		ss << i+1;
		outtextxy(-550, 160 + i * 40, ss.str().c_str());
		outtextxy(-470, 160 + i * 40, school[i].name.c_str());
		ostringstream sss;
		sss << school[i].score;
		outtextxy(-150, 160 + i * 40, sss.str().c_str());
	}
	rep(i, 15, 30)
	{
		ostringstream ss;
		ss << i + 1;
		outtextxy(50, 160 + (i-15) * 40, ss.str().c_str());
		outtextxy(130, 160 + (i - 15) * 40, school[i ].name.c_str());
		ostringstream sss;
		sss << school[i].score;
		outtextxy(450, 160 + (i - 15) * 40, sss.str().c_str());
	}
	FlushBatchDraw();
	
	getchar();

	cleardevice();
	FlushBatchDraw();
	//��������
	

	EndBatchDraw();
	closegraph();
	mciSendString("close BGM2", 0, 0, 0);
	mciSendString("close BGMshoot0", 0, 0, 0);
	mciSendString("close BGMshoot1", 0, 0, 0);
	mciSendString("close BGMshoot2", 0, 0, 0);
	


	Forget_that Just_go;
}