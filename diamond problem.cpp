#include<bits/stdc++.h>
using namespace std;
class person{
	public:
		person(){
			cout<<"person() is called"<<"\n";
		}
		person(int x){
			cout<<"person int() is called"<<"\n";
		}
};

class student: virtual public person{
	public:
		student(int x): person(x){
			cout<<"student int() is called"<<"\n";
		}
		
};
class faculty: virtual public person{
	public:
		faculty(int x):person(x){
			cout<<"faculty int() is called"<<"\n";
		}
};

class result:public student, public faculty{
	public:
		result(int x): student(x),faculty(x){
			cout<<"result is called"<<"\n";
		}
};

int main(){
	result r(4);
	
}
