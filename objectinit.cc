///
///@date   2016-04-19 20:08:27
///
 
 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class point
{
	public:
		point(int,int);
		point& operator=(const point &);
		void print();
	private:
		int _ix;
		int _iy;
};

point::point(int x=0,int y=0)
:_ix(x)
,_iy(y)
{
}

point& point::operator=(const point &p1)  //运算符重载不是构造  没有初始化列表
{
	_ix=p1._ix;
	_iy=p1._iy;
}

void point::print()
{
	cout<<"("<<_ix<<","<<_iy<<")"<<endl;
}

class line
{
	public:                     //可以用缺省构造函数 会自动调用point类的构造函数初始化数据成员
		line(int ,int,int ,int );
		line(const line&);
		line &operator=(const line &);
#if 0	
		:p1(x1,y1)
		,p2(x2,y2)
		{
		}
#endif	
		void print();
	private:
		point p1;
		point p2;
};

line::line(const line &l1)             
:p1(l1.p1)
,p2(l1.p2)
{
}

line& line::operator=(const line &l1)
{
	p1=(l1.p1);
	p2=(l1.p2);
}	

#if 1
line::line(int x1=0,int y1=0,int x2=0,int y2=0)  
:p1(x1,x2)								//对象类成员在初始化列表初始化
,p2(x2,y2)
{
}
#endif

void line::print()
{
	p1.print();
	cout<<" to "<<endl;
	p2.print();
}

int main()
{
	line line1(1,2,3,4);
	line1.print();

	cout<<"===================================="<<endl;
	line l1;
	l1=line1;
	l1.print();

	cout<<"===================================="<<endl;
	line l2(line1);
	l2.print();
	return 0;
}
