///
///@date   2016-04-19 21:19:09
///
 
 
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class point
{
public:
	point(int,int);
	void print();
private:
	int _ix;
	int _iy;
};

point::point(int x=0,int y=0)
:_ix(x)
,_iy(y)
{}

void point::print()
{
	cout<<"("<<_ix<<","<<_iy<<")"<<endl;
}

int main()
{
	point *p=new point[4];//={point(1,2),point(3,4)};
	p[0].print();
	p[1].print();
	p[2].print();
	p[3].print();
}
