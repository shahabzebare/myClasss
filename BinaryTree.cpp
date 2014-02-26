/*
* @author shahab zebari
* Binary Tree class
* Copyrights for You,Me and Us.
*/


template <class T>
class Tree
{
	struct node
	{
		node * lift;
		T data;
		node * right;
	};
	node * root;
	int item;
public:
	Tree()
	{
		root = NULL;
		item = 0;
	}

	bool isEmpty(){return root==NULL;}

	void insert(T data)
	{
		node *p = new node;
		p->data = data;
		p->right = NULL;
		p->lift = NULL;
		char op;
		if(isEmpty())
			root = p;
		else
		{
			node *q = root;
			node *parent;
			while (q!=NULL)
			{
				parent = q;
				cout<<"insert or right (l,r) : ";
				cin>>op;
				if(op=='l' || op=='L')
					q = q->lift;
				else
					q = q->right;
			}//end loop

			if(op=='l' || op=='L')
				parent->lift = p;
			else 
				parent->right = p;
			item++;
		}//end big else 
	}//end function

	void Delete()
	{
		if(isEmpty())
			throw "ERROR : UnderFlow";
		else 
		{
			node *q = root;
			char op;
			node *parent;
			while (q->left!=NULL || q->right!=NULL)
			{
				parent = q;
				cout<<"insert or right (l,r) : ";
				cin>>op;
				if(x=='l' && q->left!=NULL)
					q = q->left;
				if(x=='r' && q->right !=NULL)
					q = q->right;
			}//end loop
			if(x=='l')
				parent->left = NULL;
			else 
				parent->right = NULL;
			delete q;
			item--;
		}//end big else
	}//end function

	void printInOrder()
	{
		printIN(root);
	}

	void printPostOrder()
	{
		printPost(root);
	}

	void printPreOrder()
	{
		printPre(root);
	}

	void Clear(){
		clear(root);
		item=0;
		root=NULL;
	}

	~Tree(){Clear();}

	int getItems(){return item;}
private:
	void printIN(node *p)
	{
		if(p==NULL)
			return;
		printIN(p->lift);
		cout<<p->data<<"   ";
		printIN(p->right);
	}

	void printPost(node *p)
	{
		if(p==NULL)
			return;
		printIN(p->lift);
		printIN(p->right);
		cout<<p->data<<"   ";
	}

	void clear(node *p)
	{
		if(p==NULL)
			return;
		printIN(p->lift);
		printIN(p->right);
		delete p;
	}
	void printPre(node *p)
	{
		if(p==NULL)
			return;
		cout<<p->data<<"   ";
		printIN(p->lift);
		printIN(p->right);
	}
};
