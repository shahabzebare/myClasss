/*
* @author shahab zebari
* Linked List class
* Copyrights for You,Me and Us.
*/

template <class T>
class linkedList
{
private:
	struct node
	{
		T data;
		node * next;
	};

	node * head;
	int size;
public:
    /*
	* This is default constructor
	*/
	linkedList()
	{
		head=NULL;
		size = 0;
	}

	/*
	 *  This Method is used to find out whether linkedlist is Empty or not
	 */
	bool isEmpty(){return head==NULL;}

	/**
	*  This Method used to Add node in to fornt linked list
	*/
	void insertFornt(T data)
	{
		node *p = new node;
		p->data = data;
		p->next = head;
		head = p;
		size++;
	}

	/**
	*  This Method used to Add node in to end linked list
	*/
	void insertEnd(T data)
	{
		if(isEmpty())
			insertFornt();
		else
		{
			node *p = new node;
			p->data = data;

			node *q = head;
			while (q->next!=NULL)
				q = q->next;
			q->next = p;
			size++;
		}
	}
	
	/**
	*  This Method used to Add node in to linked list By index [0 .. . n]
	*/
	void insertM(int place,T data)
	{
		if(isEmpty() || place==0)
			insertFornt();
		else
		{
			node *p = new node;
			p->data = data;
			
			node *q = head;
			while (q->next !=NULL && place>1)
			{
				place--;
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
			size++;
		}
	}
	
	/**
	*  This Method used to delete node form fornt linked list
	*/
	void deleteFornt()
	{
		if(isEmpty())
			throw "ERROR : UnderFlow";
		else
		{
			node *p = head;
			head = head->next;
			delete p;
			size--;
		}
	}

	/**
	*  This Method used to delete node form end linked list
	*/
	void deleteEnd()
	{
	    if(isEmpty())
			throw "ERROR : UnderFlow";
		else if(head->next==NULL)
			deleteFornt();
		else
		{
			node *q = head;
			node *p = q->next;
			while (p->next!=NULL)
			{
				p=p->next;
				q=q->next;
			}
			q->next = NULL;
			delete p;
			size--;
		}
	}

	/**
	*  This Method used to delete node form linked list By index [0 ... n]
	*/
	void deleteM(int place)
	{
		if(isEmpty())
			throw "ERROR : underFlow";
		else if(place==1 || head->next == NULL)
			deleteFornt();
		else
		{
			node *q = head;
			node *p = q->next;
			while (p->next!=NULL && place>1)
			{
				p=p->next;
				q = q->next;
				place--;
			}
			q->next = p->next;
			delete p;
			size--;
		}
	}

	/*
	* This Method used to print data form linked list
	*/
	void print()
	{
		if(isEmpty())
			cout<<"The Linked List Is Empty\n";
		else
		{
			node *q = head;
			while (q!=NULL)
			{
				cout<<q->data<<"    ";
				q=q->next;
			}
			cout<<endl;
		}
	}
	/**
	* This Method Used to return size Of linked List
	*/
	int Size(){return size;}

	/**
	* This Method used to delete All nodes of linked list
	*/
	void clear()
	{
		if(!isEmpty())
		{
			node *p;
			while (head!=NULL)
			{
				p = head;
				head = head->next;
				delete p;
			}
			size = 0;
		}
	}

	/*
	*   This Method used to find node By index [0 .. .. . n]
	*/
	T getByIndex(int place)
	{
		if(isEmpty())
			throw "ERROR : Empty List";
		else
		{
			bool flag = false;
			int i = 0;
			node *q = head;
			while (q!=NULL)
			{
				if(i==place)
				{
					flag = true;
					break;
				}
				i++;
				q=q->next;
			}
			if(flag)
				return q->data;
			else
				throw "ERROR : Index Not Fount";
		}
	}

	~linkedList()
	{
		clear();
	}
};
