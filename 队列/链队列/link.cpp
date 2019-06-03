#include<iostream>
using namespace std;

template<class datatype>
struct node
{
	datatype data;
	node<datatype> *next;
};

template<class datatype>
class linkque
{
public:
	linkque()
	{
		node<datatype> *s;
		s=new node<datatype>;
	//	first=new node<datatype>;
	//	rear=new node<datatype>;
		s->next=NULL;
		first=rear=s;
	}

	~linkque(){}

	void push(datatype x)
	{
		node<datatype> *p;
		p=new node<datatype>;
	//	rear=new node<datatype>;
		p->data=x;	
		p->next=NULL;
		rear->next=p;
		rear=p;
	}

	datatype pop()
	{
		node<datatype> *p;
		datatype x;
	//	first=new node<datatype>;
		p=first->next;     //pָ��first����һ���ڵ㣬��frist����һ���ڵ��ֵΪp
		x=p->data;
		first->next=p->next;
		if(p->next==NULL)rear=first;
		delete p;
		return x;
	}

	datatype get()
	{
		datatype x;
		node<datatype> *p;
		p=new node<datatype>;
		p=first->next;
		x=p->data;
		return x;
	}

	int empty()
	{
		if(first==rear)
			return 1;
		else
			return 0;
	}

private:
	node<datatype> *first,*rear;
};

int main()
{
	linkque<int> a;
	a.push(1);
	a.push(2);
	a.push(4);
	a.push(5);
	cout<<"���е�ͷԪ��Ϊ��"<<a.get()<<endl;
	cout<<"������У�";
	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop()<<endl;
	cout<<"�Ƿ�Ϊ��"<<a.empty()<<endl;
	return 0;
}
