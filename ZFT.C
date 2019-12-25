#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bios.h>
#include <dos.h>

#define PI 3.1415926
#define xo 240 			/*饼图圆心x坐标*/
#define yo 240			/*饼图圆心y坐标*/
#define R 210			/*饼图半径*/
#define zfx 70			/*直方图原点x坐标*/
#define zfy 320			/*直方图原点y坐标*/

int init();
int read_mouse();
void cursor_set(),newxy();
void cursor_on();
void cursor_off();
void cursor_to_xy();

union
{
	int key;
	char c[2];
}u;

int S,HZKflag;                 /* S:汉字点阵数 */
char HZK[16];  /*汉字字库路径及文件名*/

void empty()
{
	while(bioskey(1))
		bioskey(0);
}

void cursor_to_xy(unsigned int x,unsigned int y)
{
	union REGS r;
	struct SREGS s;
	r.x.ax=4;
	r.x.cx=x;
	r.x.dx=y;
	int86x(0x33,&r,&r,&s);
}

void cursor_set(int x,int y)
{

	union REGS r;
	struct SREGS s;
	unsigned int pattern[32]={
	/*屏幕掩码*/
	0x3fff,0x1fff,0x0fff,0x07ff,0x03ff,0x01ff,0x00ff,0x007f,
	0x003f,0x001f,0x01ff,0x10ff,0x30ff,0xf87f,0xf87f,0xfc3f,
	/*光标屏蔽*/
	0x0000,0x4000,0x6000,0x7000,0x7800,0x7c00,0x7e00,0x7f00,
	0x7f80,0x7fc0,0x6c00,0x4600,0x0600,0x0300,0x0300,0x0180};
	r.x.ax=9;
	r.x.bx=x;
	r.x.cx=y;
	r.x.dx=FP_OFF(pattern);
	s.es=FP_SEG(pattern);
	int86x(0x33,&r,&r,&s);
}

void cursor_on()
{
	union REGS r;
	struct SREGS s;
	r.x.ax=1;
	int86x(0x33,&r,&r,&s);
}

void cursor_off()
{
	union REGS r;
	struct SREGS s;
	r.x.ax=2;
	int86x(0x33,&r,&r,&s);
}

int init(int xmin,int xmax,int ymin,int ymax)  /*初始化函数 */
{
	union REGS regs;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	if(regs.x.ax == 0)
		return 0;         /* 返回0 表示鼠标或鼠标驱动程序未安装 */
	regs.x.ax=7;
	regs.x.cx=xmin;
	regs.x.dx=xmax;
	int86(51,&regs,&regs);
	regs.x.ax=8;
	regs.x.cx=ymin;
	regs.x.dx=ymax;
	int86(51,&regs,&regs);
	return -1;         /* 表示鼠标器和驱动程序已安装 */
}

int read_mouse(int *mx,int *my,int *mbutton)
{
	union REGS regs;
	int x0=*mx, y0=*my, button0=*mbutton;
	int xnew, ynew;
	do
	{
		regs.x.ax=3;
		int86(0x33,&regs,&regs);
		xnew=regs.x.cx;
		ynew=regs.x.dx;
		*mbutton=regs.x.bx;

		u.key=bioskey(1);
		if(u.key)
		{
			empty();
			/*if((u.c[1]==31)||(u.c[1]==25)||(u.c[1]==49)||(u.c[1]==45))*/
			break;
		}
	}while(xnew == x0 && ynew == y0 && *mbutton == button0);
	*mx=xnew;
	*my=ynew;
	switch(*mbutton)
	{
		case 0:   return 0;
		case 1:   return 1;
		case 2:   return 2;
		case 3:   return 3;
		default:  return 4;
	}
}

void newxy(int *mx,int *my,int *mbutt)
{
	int ch,xx0=*mx,yy0=*my;
	ch=read_mouse(&xx0,&yy0,mbutt);
	*mx=xx0;
	*my=yy0;
}

void dispoint(int x,int y,char *p,int color)
{
	int  i, j;
	FILE *fp;
	char  qh, wh;
	long  offset;
	char  mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	char buffer[72],mid[2]={0},hz[3]={0};

	S=24;
	HZKflag=1;
	strcpy(HZK,"\\tc\\hzk24s");

	if (( fp = fopen(HZK,"rb")) == NULL)
	{
		closegraph();
		printf("hzk error\n");
		printf("dispoint\n");
		exit(1);
	}

	while(*p!='\0')
	{
		if(0<*p&&*p<128)
		{
			mid[0]=*p;
			p++;
			setcolor(color);
			settextjustify(0,2);
			settextstyle(0,0,S/8);
			outtextxy(x,y,mid);
		}
		else
		{
			qh = *p - 0xa0-15;          /*计算区号*/
			p++;
			wh = *p - 0xa0;          /*计算位号*/
			p++;
			offset = (94L * (qh -1) + wh - 1) * S * S / 8;   /*计算地址码*/
			fseek(fp,offset,0);
			fread(buffer,S*S/8,1,fp);
			for ( i = 0; i < S; i++)
			{
				for ( j = 0; j < S; j++)
					if (((buffer[S/8*i+j/8]) & mask[j%8]) != 0)
						putpixel(x+i, y+j, color);
			}
		}
		x+=S+5;      /*下一个汉字的坐标（横向显示），字间距为5像素*/
	}
	fclose(fp);
}

union U
{
	short m;
	char c[2];
};

void disphz(long x, long y, char *str, int color)   /*s是汉字机内码地址*/
{
	char  far  *p;
	char  mask[]={0x01,0x02,0x04,0x08};
	long  i, j, n;
	FILE *fp;
	char qh,wh;
	long offset;
	char *buffer,mid[2]={0};

	buffer=(char *)malloc(S*S/8*sizeof(char));
	if(buffer==NULL)
	{
		closegraph();
		printf("malloc error\n");
		exit(0);
	}
	if (( fp = fopen(HZK,"rb")) == NULL)
	{
		closegraph();
		printf("hzk error\n");
		printf("disphz\n");
		exit(1);
	}

	while(*str!='\0')
	{
		if(0<*str&&*str<128)
		{
			mid[0]=*str;
			str++;
			setcolor(color);
			settextjustify(0,2);
			settextstyle(0,0,S/8);
			outtextxy(x,y,mid);
			x+=S;      /*下一个汉字的坐标（横向显示），字间距为2像素*/
		}
		else
		{
			qh = *str - 0xa0;
			if(HZKflag)
				qh-=15;
			str++;			 /*计算区号*/
			wh = *str - 0xa0;                          /*计算位号*/
			str++;
			offset = (94L*(qh -1) + wh -1) * S * S /8;   /*计算地址码*/
			fseek(fp,offset,0);
			fread(buffer, S *S /8,1, fp);

			outportb(0x3ce, 4);   /*使口地址0x3cf对应读位面选择寄存器*/
			outportb(0x3c4, 2);   /*使口地址0x3c5对应颜色位面写允许寄存器*/

			p = (char far*)(0xa0000000L+80*y + x/8);
			if(x%8==0)
			{
				for( i = 0; i<S; i++)
					for( j = 0; j<S/8; j++)
						for(n = 0; n<4; n++)             /*n表示要操作的位面号*/
						{
							outportb(0x3cf,n);           /*使位面n可读*/
							outportb(0x3c5, mask[n]);    /*使位面n（仅位面n）可写*/
							if((color&mask[n])!=0)
								*(p+80*i+j)|=buffer[S*i/8+j];
							else
								*(p+80*i+j)&=~(buffer[S*i/8+j]);
						}
			}
			else
			{
				union U w;
				for( i = 0; i<S; i++)
					for( j = 0; j<S/8; j++)
					{
						w.c[0]=buffer[S*i/8+j];
						w.c[1]=0;
						w.m=(w.m<<(8-x%8));
						for(n = 0; n<4; n++)             /*n表示要操作的位面号*/
						{
							outportb(0x3cf,n);           /*使位面n可读*/
							outportb(0x3c5, mask[n]);    /*使位面n（仅位面n）可写*/
							if((color&mask[n])!=0)
							{
								*(p+80*i+j)|=w.c[1];
								*(p+80*i+j+1)|=w.c[0];
							}
							else
							{
								*(p+80*i+j)&=~w.c[1];
								*(p+80*i+j+1)&=~w.c[0];
							}
						}
					}

			}
			outportb(0x3cf,0);
			outportb(0x3c5,0xf);
			x+=S+5;      /*下一个汉字的坐标（横向显示），字间距为5像素*/
		}
	}
	free(buffer);
	fclose(fp);
}

void force_F(void)
{
	float x=0,*yPoint=&x;
}

void button(int x,int y)
{
	setcolor(YELLOW);
	setfillstyle(1,LIGHTGRAY);
	bar3d(x,y,x+140,y+40,5,1);
}

void prtext(int x,int y,char *p,int flag)
{
	cursor_off();
	if(flag)
		dispoint(x,y,p,BLACK);
	else
		dispoint(x,y,p,WHITE);
	cursor_on();
}

void prsbtext(int x,int y,char *p)
{
	cursor_off();
	dispoint(x,y,p,RED);
	cursor_on();
}

int iskey(int code)
{
	if(kbhit())
	{
		u.key=bioskey(0);
		if(u.c[1]==code)
			return 1;
	}
	return 0;
}

void save_pic()
{
	FILE *fp;
	int i;
	long j;
	char far *p;
	fp=fopen("pic.dat","wb");
	for(i=0;i<4;i++)
	{
		outportb(0x3ce,4);
		outportb(0x3cf,i);
		p=(char far *)0xa0000000L;
		for(j=0;j<38400L;j++)
		{
			fputc(*p,fp);
			p++;
		}
	}
	fclose(fp);
	outportb(0x3cf,0);
}

void load_pic()
{
	FILE *fp;
	int k[4]={1,2,4,8};
	long i,j,num;
	char far *p;
	fp=fopen("pic.dat","rb");
	for(num=0;num<480;num+=2)
	{

		if(iskey(1))
			break;
		for(i=0;i<4;i++)
		{
			outportb(0x3c4,2);
			outportb(0x3c5,k[i]);
			p=(char far *)0xa0000000L;
			rewind(fp);
			fseek(fp,(long)(80*num+38400*i),0);
			for(j=0;j<38400-(80*num);j++)
			{
				*p=getc(fp);
				p++;
			}
		}
		outportb(0x3c5,0xf);
		delay(1000);
	}
	fclose(fp);

}

void mysound(unsigned int freq)
{
	union{
		int divisor;
		char c[2];
	}count;
	char bits;
	count.divisor=1193180/freq;
	outportb(0x43,0xb6);
	outportb(0x42,count.c[0]);
	outportb(0x42,count.c[1]);
	bits=inportb(0x61);
	outportb(0x61,bits|3);
	delay(25000);
	outportb(0x61,bits&0xfc);
	outportb(0x61,bits);
}

void stnew()
{
	int i,x,y;
	char str[4][3]={"程","序","作","业"};
	setcolor(RED);
	setfillstyle(1,GREEN);
	rectangle(20,20,620,460);
	floodfill(21,21,RED);
	setcolor(BLACK);
	setfillstyle(1,BROWN);
	rectangle(180,250,480,420);
	floodfill(201,281,BLACK);
	y=150;
	x=176;
	setfillstyle(1,BLUE);
	for(i=0;i<5;i++)
	{
		circle(x,y,36);
		floodfill(x,y,BLACK);
		x+=72;
	}
	setcolor(YELLOW);
	settextstyle(1,0,7);
	settextjustify(1,1);
	outtextxy(178,143,"C");

	S=48;
	HZKflag=1;
	strcpy(HZK,"\\tc\\HZK48s");

	y=150;
	x=248;
	for(i=0;i<4;i++)
	{
		disphz(x-24,y-24,str[i],YELLOW);
		x+=72;
	}

	S=16;
	HZKflag=0;
	strcpy(HZK,"\\tc\\HZK16");

	disphz(190,260,"程序功能:",YELLOW);
	disphz(190,280,"1.显示学生成绩直方图",YELLOW);
	disphz(190,300,"2.显示各分数段圆饼图",YELLOW);
	disphz(190,320,"注意:",YELLOW);
	disphz(190,340,"1.打字动画可以按空格键跳过",YELLOW);
	disphz(190,360,"2.滚动动画可以按ESC键跳过",YELLOW);
	disphz(190,380,"3.DOS下正常显示鼠标",YELLOW);
	disphz(190,400,"  WINxp不显示但是可以用",YELLOW);

	disphz(260,430,"按任意键继续",BLUE);

	while(!kbhit())
		;
	empty();
	cleardevice();
}

typedef struct
{
    char flag;
    char time[3];
    long ku_num;
    int kuai;
    int jilu_size;
    char kong[20];
}Head;
typedef struct
{
    char name[11];
    char type;
    long start;
    char width;
    char place;
    char kong[14];
}ku_file;
typedef struct
{
	char flag;
	char name[10];
	float math;
	float comp;
	float eng;
	float sum;
}STU;

int main()
{
	FILE *fp;
	Head head;
	ku_file file[5];
	int i,j,k,n,x,y,gmode,gdriver=DETECT,a,b,c,d,e,start,flag1,flag2,key,num,cursor,point,len;
	STU t,student[200];
	int SBP,SBN,SBS,SBX;
	int buttons,sbx,sby,oldx,oldy;
	char score[3]="10";
	char rank[5]={0};
	char math[16],name[10],english[16],computer[16],wj[105]={0},zhanbi[7],temp;
	char messg[5][33]={
						"  这个C程序是我老师给我们的作","业,用于读取数据库文件,计算学生",
						"的排名,以及生成直方图和饼图,此","程序显示每页三个人的直方图,并可","以切换页面"};
	char flag,Author[]="作者:谭剑",Data[]="2019/04/17",mid[2]={0},hz[3]={0};
	a=b=c=d=e=0;

	registerbgidriver(EGAVGA_driver);
	registerbgifont(triplex_font);
	registerbgifont(small_font);
	initgraph(&gdriver,&gmode,"");
	cleardevice();

	stnew();

	settextjustify(0,1);
	settextstyle(0,0,2);

	dispoint(20,100,"请输入文件名,回车结束输入:",WHITE);

	rectangle(18,140,516,180);
	setfillstyle(1,WHITE);
	floodfill(21,141,WHITE);
	setcolor(LIGHTCYAN);
	settextstyle(0,0,2);
	outtextxy(315,263,"C:\\tc\\test.dbf");
	outtextxy(134,305,".dbf");
	outtextxy(375,342,"100");

	dispoint(20,220,"提示:",LIGHTRED);
	dispoint(84,260,"1.文件名例如:",LIGHTRED);
	dispoint(84,300,"2.  可以省略",LIGHTRED);
	dispoint(84,340,"3.文件名最大长度:",LIGHTRED);

	settextstyle(0,0,2);

	while(1)
	{
		settextjustify(1,1);
		num=point=cursor=0;
		while(1)
		{
			key=bioskey(2);
			if(key&128)    		/***Insert key***/
				while(!kbhit())			/**|**/
				{
					setcolor(BLACK);
					line(20+cursor*16,147,20+cursor*16,170);
					delay(30000);
					setcolor(WHITE);
					line(20+cursor*16,147,20+cursor*16,170);
					delay(30000);
				}
			else
				while(!kbhit())			/**_**/
				{
					setcolor(BLACK);
					outtextxy(28+cursor*16,162,"_");
					outtextxy(28+cursor*16,163,"_");
					delay(30000);
					setcolor(WHITE);
					outtextxy(28+cursor*16,162,"_");
					outtextxy(28+cursor*16,163,"_");
					delay(30000);
				}
			u.key=bioskey(0);
			temp=u.c[0];
			if(('A'<=temp&&temp<='Z')||('a'<=temp&&temp<='z')||(temp=='_')||(temp=='\\')||(temp==':')||(temp=='.')||('0'<=temp&&temp<='9'))
			{
				if(num>=100)
				{
					for(i=0;i<5;i++)
					{
						empty();
						dispoint(240,400,"文件名太长",LIGHTRED);
						delay(30000);
						dispoint(240,400,"文件名太长",BLACK);
						delay(30000);
					}
				}
				else if(key&128)    		/***|***/
				{
					setcolor(WHITE);
					if(cursor==30||(cursor==29&&(num!=point)))
						for(i=point-cursor,j=0;wj[i]&&j<cursor;j++,i++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					else
						for(i=point,j=cursor;wj[i]&&j<30;j++,i++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					len=strlen(wj);
					for(i=len+1;i>point;i--)
					{
						wj[i]=wj[i-1];
					}
					wj[point]=temp;
					num++;
					point++;

					setcolor(LIGHTCYAN);
					if(cursor==30||cursor==29&&(num!=point))
						for(i=point-cursor,j=0;wj[i]&&j<cursor;i++,j++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					else
						for(i=point-1,j=cursor;wj[i]&&j<30;j++,i++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					if(cursor<30)
						cursor++;
					if(cursor==30&&(point<num))
						cursor=29;
				}
				else		/***_***/
				{
					setcolor(WHITE);
					if(cursor==30||(cursor==29&&(num!=point)&&num!=point+1))
						for(i=point-cursor,j=0;wj[i]&&j<30;j++,i++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					else
					{
						mid[0]=wj[point];
						outtextxy(28+cursor*16,160,mid);
					}

					wj[point]=temp;
					if(point==num)
						num++;
					point++;

					setcolor(LIGHTCYAN);
					if(cursor==30||cursor==29&&(num!=point))
						for(i=point-cursor,j=0;wj[i]&&j<30;i++,j++)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					else
					{
						mid[0]=wj[point-1];
						outtextxy(28+cursor*16,160,mid);
					}

					if(cursor<30)
						cursor++;
					if(cursor==30&&(point<num))
						cursor=29;
				}
			}

			if((u.c[1]==211||u.c[1]==83)&&(!temp)&&num>0&&point<num)		/***delete key***/
			{
				num--;
				setcolor(WHITE);
				for(i=point,j=cursor;wj[i]&&j<30;i++,j++)
				{
					mid[0]=wj[i];
					outtextxy(28+j*16,160,mid);
				}
				setcolor(LIGHTCYAN);
				for(i=point+1,j=cursor;wj[i]&&j<30;i++,j++)
				{
					mid[0]=wj[i];
					outtextxy(28+j*16,160,mid);
				}
				for(i=point;wj[i];i++)
					wj[i]=wj[i+1];
			}

			if(u.c[1]==14&&point>0)			/***backspace key***/
			{
				num--;
				point--;
				if(point<30&&(point-cursor<0))
				{
					cursor--;
					setcolor(WHITE);
					for(i=point,j=cursor;wj[i]&&j<30;i++,j++)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
					setcolor(LIGHTCYAN);
					for(i=point+1,j=cursor;wj[i]&&j<30;i++,j++)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
				}
				else
				{
					setcolor(WHITE);
					for(i=point,j=cursor-1;j>=0;i--,j--)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
					setcolor(LIGHTCYAN);
					for(i=point-1,j=cursor-1;j>=0;i--,j--)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
				}
				for(i=point;wj[i];i++)
					wj[i]=wj[i+1];
			}
			wj[num]=0;

			if(u.c[1]==28&&wj[0])		/***Enter to end***/
				break;

			if((!temp)&&(u.c[1]==203||u.c[1]==75)&&(point>0))		/***光标左移***/
			{
				if(cursor==0)
				{
					setcolor(WHITE);
					for(i=point,j=0;i<point+30;i++,j++)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
					point--;
					setcolor(LIGHTCYAN);
					for(i=point,j=0;i<point+30;i++,j++)
					{
						mid[0]=wj[i];
						outtextxy(28+j*16,160,mid);
					}
				}
				else
				{
					cursor--;
					point--;
				}
			}
			if((cursor!=30)&&(!temp)&&(u.c[1]==205||u.c[1]==77)&&(point<num))		/***光标右移***/
			{
				if(cursor==29)
				{
					if(point+1==num)
					{
						point++;
						cursor=30;
					}
					else
					{
						setcolor(WHITE);
						for(i=point,j=29;i>=point-29;i--,j--)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
						point++;
						setcolor(LIGHTCYAN);
						for(i=point,j=29;i>=point-29;i--,j--)
						{
							mid[0]=wj[i];
							outtextxy(28+j*16,160,mid);
						}
					}
				}
				else
				{
					cursor++;
					point++;
				}
			}

		}

		if(strrchr(wj,'.')==NULL)
			strcat(wj,".dbf");
		fp=fopen(wj,"rb");
		if(fp!=NULL)
			break;
		for(i=0;i<5;i++)
		{
			dispoint(235,400,"没有找到文件",LIGHTRED);
			delay(30000);
			dispoint(235,400,"没有找到文件",BLACK);
			delay(30000);
		}
		while(1)
		{
			dispoint(235,400,"1:重新输入",WHITE);
			dispoint(265,440,"2:退出",WHITE);
			u.key=bioskey(0);
			flag=u.c[0];
			if(flag=='1')
				break;
			if(flag=='2')
			{
				closegraph();
				return 0;
			}
		}
		dispoint(235,400,"1:重新输入",BLACK);
		dispoint(265,440,"2:退出",BLACK);
		setcolor(WHITE);
		settextstyle(0,0,2);
		settextjustify(1,1);
		for(i=point-cursor,j=0;wj[i]&&j<30;i++,j++)				/***清空输入框***/
		{
			mid[0]=wj[i];
			outtextxy(28+j*16,160,mid);
		}
		wj[0]=0;
	}

	fread(&head,32,1,fp);
	n=(head.kuai-33)/32;
	for(i=0;i<n;i++)
    {
        fread(&file[0],32,1,fp);
        if(!strcmp(file[0].name,"姓名"))
            k=1;
		else if(!strcmp(file[0].name,"数学"))
            k=2;
        else if(!strcmp(file[0].name,"计算机"))
            k=3;
        else if(!strcmp(file[0].name,"英语"))
            k=4;
		else
            k=0;
        if(k)
            file[k]=file[0];
    }
	i=0;
    for(k=0;k<(int)head.ku_num;k++)
    {
        fseek(fp,(long)(head.kuai+k*head.jilu_size),0);
        student[i].flag=fgetc(fp);
		if(student[i].flag=='*')
			continue;
        fseek(fp,(long)(file[1].start-1),1);
        fgets(name,file[1].width+1,fp);
        for(j=file[1].width-1;j>=0;j--)
            if(name[j]==32)
                name[j]=0;
            else
                break;
        strcpy(student[i].name,name);
		fseek(fp,(long)(head.kuai+k*head.jilu_size+file[2].start),0);
		fgets(math,file[2].width+1,fp);
		student[i].math=(float)atof(math);
        fseek(fp,(long)(head.kuai+k*head.jilu_size+file[3].start),0);
		fgets(computer,file[3].width+1,fp);
		student[i].comp=(float)atof(computer);
		fseek(fp,(long)(head.kuai+k*head.jilu_size+file[4].start),0);
		fgets(english,file[4].width+1,fp);
		student[i].eng=(float)atof(english);
        student[i].sum=student[i].math+student[i].comp+student[i].eng;
		if(student[i].sum/3.0<60)
			a++;
		else if(student[i].sum/3.0<70)
			b++;
		else if(student[i].sum/3.0<80)
			c++;
		else if(student[i].sum/3.0<90)
			d++;
		else
			e++;
		i++;
    }
    n=i;

	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(student[k].sum<student[j].sum)
				k=j;
		t=student[k],student[k]=student[i],student[i]=t;
	}

	fclose(fp);

	cleardevice();
	/**打开鼠标**/

	if(init(0, 630,0, 463)==0 )     /*调用init 函数对鼠标器初始化*/
	{
		printf("Mouse or Mouse Driver Absent,P1ease install!");
		delay(5000);
		closegraph();
		exit(1);
	}
	sbx=349;
	sby=415;

	/*直方图*/

		/*直角坐标和刻度*/
	setcolor(WHITE);
	settextjustify(0,1);
	
	line(zfx,zfy+1,zfx,zfy-200-30);
	line(zfx,zfy-200-30,zfx-5,zfy-200-20);
	line(zfx,zfy-200-30,zfx+5,zfy-200-20);


	S=16;
	HZKflag=0;
	strcpy(HZK,"\\tc\\HZK16");

	disphz(zfx-60,zfy-200-40,"分数",WHITE);
	settextstyle(1,0,1);
	line(zfx,zfy+1,zfx+520,zfy+1);
	line(zfx+520,zfy+1,zfx+510,zfy-5);
	line(zfx+520,zfy+1,zfx+510,zfy+7);

	outtextxy(zfx-20,zfy+10,"0");
	settextjustify(0,1);
	for(i=1;i<10;i++)
	{
		score[0]=48+i;
		line(zfx,zfy-i*20,zfx+5,zfy-i*20);
		outtextxy(zfx-24,zfy-i*20,score);
	}
	line(zfx,zfy-200,zfx+5,zfy-200);
	outtextxy(zfx-32,zfy-200,"100");

		/*图例*/

	setcolor(LIGHTGREEN);
	rectangle(500,10,630,80);

	setcolor(WHITE);
	rectangle(510,20,540,30);
	rectangle(510,40,540,50);
	rectangle(510,60,540,70);

	setfillstyle(1,GREEN);
	floodfill(511,21,WHITE);
	disphz(560,18,"数学",GREEN);

	setfillstyle(1,MAGENTA);
	floodfill(511,41,WHITE);
	disphz(560,38,"计算机",MAGENTA);

	setfillstyle(1,DARKGRAY);
	floodfill(511,61,WHITE);
	disphz(560,58,"英语",DARKGRAY);

	S=40;
	HZKflag=1;
	strcpy(HZK,"\\tc\\HZK40s");

	disphz(140,40,"学生成绩示意图",YELLOW);
		/*柱状图*/

	setviewport(zfx+40,zfy-220,zfx+500,zfy+150,0);

	button(0,290);
	button(170,290);
	button(340,290);
	setviewport(zfx+20,zfy-220,zfx+500,zfy+50,0);

	settextjustify(0,2);
	settextstyle(0,0,S/8);

	cursor_set(0,0);
	cursor_on();
	cursor_to_xy(sbx,sby);                 /*置鼠标光标在P键*/          

	for(j=0;j<(n/3+!!(n%3));)
	{
		cursor_off();
		clearviewport();
		setcolor(WHITE);
		line(0,221,480,221);
		i=j*3;
		if((n-i)<=3)
		{
			k=n-i;
			flag2=0;
		}
		else
		{
			k=3;
			flag2=1;
		}
		if(j==0)
			flag1=0;
		else
			flag1=1;
		for(i;i<j*3+k;i++)
		{
			x=20+(i%3)*160;
			y=220;
			setcolor(RED);
			setfillstyle(1,GREEN);
			bar3d(x,y-student[i].math*2,x+40,y,20,1);
			floodfill(x+3,y-student[i].math*2-1,RED);
			floodfill(x+41,y-2,RED);

			setcolor(BLUE);
			setfillstyle(1,MAGENTA);
			bar3d(x+40,y-student[i].comp*2,x+80,y,20,1);
			floodfill(x+43,y-student[i].comp*2-1,BLUE);
			floodfill(x+81,y-2,BLUE);

			setcolor(YELLOW);
			setfillstyle(1,DARKGRAY);
			bar3d(x+80,y-student[i].eng*2,x+120,y,20,1);
			floodfill(x+83,y-student[i].eng*2-1,YELLOW);
			floodfill(x+121,y-2,YELLOW);

			settextstyle(1,0,3);

			sprintf(rank,"%d",i+1);
			strcat(rank,".\0");
			outtextxy(x+5,y+15,rank);
			dispoint(x+40,y+17,student[i].name,RED);
		}

		setcolor(WHITE);
		line(0,221,480,221);
		
		if(110<=sbx&&sbx<=250&&399<=sby&&sby<=430)
			prsbtext(25,y+78,"前页(P)");
		else
			prtext(25,y+78,"前页(P)",flag1);
		if(278<=sbx&&sbx<=420&&399<=sby&&sby<=430)
			prsbtext(195,y+78,"后页(N)");
		else
			prtext(195,y+78,"后页(N)",flag2);
		prtext(365,y+78,"跳过(S)",1);

		SBP=SBN=SBS=0;

		cursor_on();

		while(1)
		{
			oldx=sbx,oldy=sby;
			newxy(&sbx,&sby,&buttons);
			if((u.c[1]==31)||(u.c[1]==25&&flag1)||(u.c[1]==49&&flag2))
				break;
			else if(110<=sbx&&sbx<=250&&399<=sby&&sby<=430)
			{
				if(flag1)
				{
					if(!(110<=oldx&&oldx<=250&&399<=oldy&&oldy<=430))
						prsbtext(25,y+78,"前页(P)");
					/*prtext(195,y+78,"后页(N)",flag2);*/
					if(buttons==1)
					{
						SBP=1;
						break;
					}
				}
				else
					prtext(25,y+78,"前页(P)",flag1);
			}
			else if(278<=sbx&&sbx<=420&&399<=sby&&sby<=430)
			{
				if(flag2)
				{
					if(!(278<=oldx&&oldx<=420&&399<=oldy&&oldy<=430))
						prsbtext(195,y+78,"后页(N)");
					if(buttons==1)
					{
						SBN=1;
						break;
					}
				}
				else
					prtext(195,y+78,"后页(N)",flag2);
			}
			else if(450<=sbx&&sbx<=590&&399<=sby&&sby<=430)
			{
				if(!(450<=oldx&&oldx<=590&&399<=oldy&&oldy<=430))
					prsbtext(365,y+78,"跳过(S)");
				if(buttons==1)
				{
					SBS=1;
					break;
				}
			}
			else
			{
				if((110<=oldx&&oldx<=250&&399<=oldy&&oldy<=430)||(278<=oldx&&oldx<=420&&399<=oldy&&oldy<=430)||(450<=oldx&&oldx<=590&&399<=oldy&&oldy<=430))
				{
					prtext(25,y+78,"前页(P)",flag1);
					prtext(195,y+78,"后页(N)",flag2);
					prtext(365,y+78,"跳过(S)",1);
				}
			}
		}

		if(u.c[1]==31||SBS)
			break;
		else if((u.c[1]==25||SBP)&&flag1)
			j--;
		else if((u.c[1]==49||SBN)&&flag2)
			j++;

	}
	cursor_off();
	cleardevice();
	
	/*饼状图*/
	setviewport(0,0,639,479,0);
	setcolor(WHITE);
	setfillstyle(1,GREEN);
	settextjustify(0,1);
	settextstyle(3,0,1);

	start=0;
	if(e)
	{
		pieslice(xo,yo,0,(e/(float)n)*360,R-70);
		sprintf(zhanbi,"%.2f",e/(float)n*100);
		moveto(xo+R*cos(PI*e/n),yo-R*sin(PI*e/n));
		outtext(zhanbi);
		outtext("%");
	}
	start+=(e/(float)n)*360;
	if(d)
	{
		setfillstyle(1,RED);
		pieslice(xo,yo,start,start+(d/(float)n)*360,R-70);
		sprintf(zhanbi,"%.2f",d/(float)n*100);
		moveto(xo+R*cos(PI*(2*e+d)/n),yo-R*sin(PI*(2*e+d)/n));
		outtext(zhanbi);
		outtext("%");
	}
	start+=(d/(float)n)*360;
	if(c)
	{
		setfillstyle(1,YELLOW);
		pieslice(xo,yo,start,start+(c/(float)n)*360,R-70);
		sprintf(zhanbi,"%.2f",c/(float)n*100);
		moveto(xo+R*cos(2*PI*(e+d+0.5*c)/n),yo-R*sin(2*PI*(e+d+0.5*c)/n));
		outtext(zhanbi);
		outtext("%");
	}
	start+=(c/(float)n)*360;
	if(b)
	{
		setfillstyle(1,BLUE);
		pieslice(xo,yo,start,start+(b/(float)n)*360,R-70);
		sprintf(zhanbi,"%.2f",b/(float)n*100);
		moveto(xo+R*cos(2*PI*(e+d+c+0.5*b)/n),yo-R*sin(2*PI*(e+d+c+0.5*b)/n));
		outtext(zhanbi);
		outtext("%");
	}
	start+=(b/(float)n)*360;
	if(a)
	{
		setfillstyle(1,MAGENTA);
		pieslice(xo,yo,start,360,R-70);
		sprintf(zhanbi,"%.2f",a/(float)n*100);
		moveto(xo+R*cos(2*PI*(e+d+c+b+0.5*a)/n),yo-R*sin(2*PI*(e+d+c+b+0.5*a)/n));
		outtext(zhanbi);
		outtext("%");
	}

	settextstyle(0,0,2);

	setcolor(LIGHTGREEN);
	rectangle(500,10,630,120);

	setcolor(WHITE);
	rectangle(510,20,540,30);
	rectangle(510,40,540,50);
	rectangle(510,60,540,70);
	rectangle(510,80,540,90);
	rectangle(510,100,540,110);

	setcolor(YELLOW);
	settextjustify(0,1);
	settextstyle(0,0,1);

	setfillstyle(1,MAGENTA);
	floodfill(511,21,WHITE);
	outtextxy(560,25," 0-59");

	setfillstyle(1,BLUE);
	floodfill(511,41,WHITE);
	outtextxy(560,45,"60-69");

	setfillstyle(1,YELLOW);
	floodfill(511,61,WHITE);
	outtextxy(560,65,"70-79");

	setfillstyle(1,RED);
	floodfill(511,81,WHITE);
	outtextxy(560,85,"80-89");

	setfillstyle(1,GREEN);
	floodfill(511,101,WHITE);
	outtextxy(560,105,"90-");

	button(xo+230,yo+170);
	prtext(xo+235,yo+178,"退出(X)",1);
	cursor_on();

	while(1)
	{
		oldx=sbx,oldy=sby;
		newxy(&sbx,&sby,&buttons);
		if(u.c[1]==45)
			break;
		else if(470<=sbx&&sbx<=610&&410<=sby&&sby<=450)
			{
				if(!(470<=oldx&&oldx<=610&&410<=oldy&&oldy<=450))
					prsbtext(xo+235,yo+178,"退出(X)");
				if(buttons==1)
				{
					SBP=1;
					break;
				}
			}
		else
		{
			if(470<=oldx&&oldx<=610&&410<=oldy&&oldy<=450)
				prtext(xo+235,yo+178,"退出(X)",1);
		}
	}
	cursor_off();
	cleardevice();

	flag=0;
	for(j=0;j<5;j++)
	{
		x=40;
		for(i=0;messg[j][i];i++)
		{
			if(iskey(57))
			{
				flag=1;
				break;
			}
			x+=24;
			y=64+j*30;
			if(0<messg[j][i]&&messg[j][i]<128)
			{
				mid[0]=messg[j][i];
				dispoint(x,y,mid,BLUE);

			}
			else
			{
				hz[0]=messg[j][i];
				hz[1]=messg[j][i+1];
				i++;
				dispoint(x,y,hz,BLUE);
			}
			mysound(262);
			delay(30000);
			x+=5;
		}
		if(flag)
			break;
	}
	x=208;
	for(i=0;Author[i];i++)
	{
		if(iskey(57)||flag)
		{
			flag=1;
			break;
		}
		x+=24;
		y=64+(j+3)*30;
		if(0<Author[i]&&Author[i]<128)
		{
			mid[0]=Author[i];
			dispoint(x,y,mid,BLUE);

		}
		else
		{
			hz[0]=Author[i];
			hz[1]=Author[i+1];
			i++;
			dispoint(x,y,hz,BLUE);
		}
		x+=5;
		mysound(262);
		delay(30000);
	}
	for(i=0;Data[i];i++)
	{
		if(iskey(57)||flag)
		{
			flag=1;
			break;
		}
		moveto(185+i*24,64+(j+4)*30);
		mid[0]=Data[i];
		outtext(mid);
		mysound(262);
		delay(30000);
	}
	if(iskey(57)||flag)
	{
		for(i=j;i<5;i++)
			dispoint(64,64+i*30,messg[i],BLUE);
		dispoint(232,64+(i+3)*30,Author,BLUE);
		outtextxy(185,64+(i+4)*30,Data);
	}

	save_pic();
	empty();

	load_pic();
	empty();
	cleardevice();

	setcolor(LIGHTRED);
	settextstyle(1,0,10);
	settextjustify(1,1);
	outtextxy(320,240,"The End");
	sleep(2);

	closegraph();
	return 0;
}