///
///@date   2016-04-19 16:51:11
///
 
 
 
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class computer
{
public:
	computer();
	computer(char *name,float price,int year,float pprice);
	computer(const computer &);
	computer &operator=(const computer&);
	~computer();
	void print()const;				//const成员函数
	void print();
	static void printtotalprice(); //静态成员函数
private:
	static int _totalprice;
	float _price;
	char *_name;
	const int _year;
	float& _pprice;
};

int computer:: _totalprice=0;  //静态成员在此赋初值

void computer::printtotalprice() //定义静态成员函数，只能访问静态成员
{
	cout<<"totalprice"<<_totalprice<<endl;
}

computer& computer::operator=(const computer &pc)
{                                         //运算符重载函数不是构造函数，原对象的const成员
										  //不能被改变
	cout<<"operator="<<endl;
	_price=pc._price;
	_name=new char[strlen(pc._name)+1];
	strcpy(_name,pc._name);
	_totalprice+=pc._price;
}

computer::computer()
:_price(0)
,_year(1970)
,_pprice(_price)
{
	cout<<"computer()"<<endl;
	_name=new char[1];	
	_totalprice+=_price;
}

computer::computer(char *name,float price=0,int year=1970,float pprice=1)
:_price(price)
,_year(year)
,_pprice(pprice)                   //引用数据成员初始化只能在初始化列表进行
{
	cout<<"computer(char*,float)"<<endl;
	_name=new char[strlen(name)+1];
	strcpy(_name,name);
	_totalprice+=_price;
}

computer::computer(const computer &pc)
:_price(pc._price)
,_year(pc._year)
,_pprice(pc._pprice)
{
	cout<<"cpy gouzaohanshu"<<endl;
	_name=new char[strlen(pc._name)+1];
	strcpy(_name,pc._name);
	_totalprice+=pc._totalprice;
}

computer::~computer()
{
	cout<<"~computer"<<endl;
	delete []_name;
}


void computer::print()const
{
	cout<<"const _price"<<endl;
	cout<<_price<<endl;
	cout<<_year<<endl;
	cout<<"pprice="<<_pprice<<endl;
	cout<<"totalprice="<<_totalprice<<endl;
}

void computer::print()
{
	cout<<"price"<<endl;
	cout<<_price<<endl;
	cout<<_year<<endl;
	cout<<"pprice"<<_pprice<<endl;
	cout<<"totalprice="<<_totalprice<<endl;
}

int main()
{
	char name[]="ThinkPad";
	computer pc(name,5100,2010,100);
	pc.print();
	
	cout<<"==========================="<<endl;;

	const computer pc1(pc);            //声明一个const对象
									   //该对象只能调用const成员函数
	pc1.print();

	cout<<"==========================="<<endl;
	computer pc3;
	pc3=pc1;            //pc1的_year成员不会复制给pc3
	pc3.print();

	pc3.printtotalprice();//静态成员函数可以通过类名访问也可通过实例对象访问

	return 0;
}
