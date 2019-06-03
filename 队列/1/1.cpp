#include"iostream"
#include"string"
using namespace std;

const size = 100;
template<class datatype>
struct node
{
	datatype data;
	node<datatype> *left;
	node<datatype> *right;
};

template < class datatype>
class bitree
{
public:
	bitree(){ root = creat(root); }
	~bitree(){ del(root); }
	void preorder(){ preorder(root); }
	void midorder(){ midorder(root); }
	void endorder(){ endorder(root); }
	void leorder()
	{
		int first,rear;
		node<datatype>* q[size];
		first = rear = -1;	
		if(root == NULL)return;
		q[++rear]=root;
		while(first != rear)
		{
			node<datatype> *p;
			p = q[++first];
			cout<<p->data;
			if(p->left != NULL)q[++rear] = p->left;
			if(p->right != NULL)q[++rear] = p->right;
		}
	}

private:
	node<datatype> *root;
	node<datatype> *creat(node<datatype>* bt)
	{
		char ch;
		cin >> ch;
		if (ch == '#')bt=NULL;
		else
		{
			bt = new node<datatype>;
			bt->data = ch;
			bt->left = creat(bt->left);
			bt->right = creat(bt->right);
		}
		return bt;
	}

	void preorder(node<datatype> * bt)
	{
		if (bt == NULL) return;
		else
		{
			cout << bt->data;
			preorder(bt->left);
			preorder(bt->right);
		}
	}

	void midorder(node<datatype> *bt)
	{
		if (bt == NULL)return;
		else
		{
			midorder(bt->left);
			cout << bt->data;
			midorder(bt->right);
		}
	}

	void endorder(node<datatype> *bt)
	{
		if (bt == NULL)return;
		else
		{
			midorder(bt->left);
			midorder(bt->right);
			cout << bt->data;
		}
	}

	void del(node<datatype> *bt)
	{
		if (bt != NULL)
		{
			del(bt->left);
			del(bt->right);
			delete bt;
		}
	}
};

int main()
{

	cout<<"请输入你的数，按#结束"<<endl;
  	bitree<char> a;
	cout << "前序遍历" << endl;
	a.preorder();
	cout << "中序遍历" << endl;
	a.midorder();
	cout << "后序遍历" << endl;
	a.endorder();
	cout << "层序遍历" << endl;
	a.leorder();

//	std::system("pause");
	return 0;
}