#include<bits/stdc++.h>
using namespace std;
class sandhya{
	public:
		virtual void care()
		{
			cout<<"I don't care"<<endl;
		}
};
class X: public sandhya{
	public:
		 void care()
		{
			cout<<"I love X"<<endl;
		}
};
class Y:public sandhya{
	public:
		void care()
		{
			cout<<"I love Y also"<<endl;
		}
};
int main(){
	sandhya *himkha;
	X x;
	Y y;
	himkha=&x;
	himkha->care();
}
