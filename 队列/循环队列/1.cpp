#include<iostream>
using namespace std;

const int size=5;

template<class datatype>

class cir
{
public:
	cir()
	{
		front=rear=size-1;
	}
	~cir(){}
	void push(datatype x)
	{
		if((rear+1)%size==front)throw"队满";
		rear=(rear+1)%size;
		data[rear]=x;
	}
	datatype pop()
	{
		if(front==rear)throw"队满";
		front=(front+1)%size;
		return data[front];
	}
	datatype get()
	{
		int i;
		if(front==rear)throw"下溢";
		i=(front+1)%size;
		return data[i];
	}
	int empty()
	{
		if(rear==front)
			return 1;
		else
			return 0;
	}
private:
	int rear,front;
	datatype data[size];
};

int main()
{
	cir<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
//	a.push(5);
	cout<<"队列的队头元素："<<a.get()<<endl;
	cout<<"输出队列：";
//	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop()<<endl;
	cout<<"判断队列是否为空："<<a.empty()<<endl;
	return 0;
}



	