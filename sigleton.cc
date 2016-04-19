///
///@date   2016-04-19 21:38:32
///
 
 
#include <stdio.h> 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class sigleton
{
public:
	static sigleton* get();
	static void destroy();
private:
	sigleton(){}
	static sigleton* sig;
};

sigleton* sigleton::get()
{
	if(sig==NULL)
	{
		sig=new sigleton;
	}
	return sig;
}

void sigleton::destroy()                          
{
	if(sig!=NULL)			//不为空则delete
	{
		delete sig;
		sig=NULL;
	}
}

sigleton* sigleton::sig=NULL;

int main()
{

	sigleton *s1=sigleton::get();
	sigleton *s2=sigleton::get();

	printf("s1=%p\ns2=%p\n",s1,s2);
	
	sigleton::destroy();
	sigleton::destroy();
	return 0;
}
