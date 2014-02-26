/*
* @author shahab zebari
* Queue class
* Copyrights for You,Me and Us.
*/

template <class  T>
class Queue
{
private:
	int size;
	T *arr;
	int tell,head;
public:
	/*
	* This is default constructor
	*/
	Queue()
	{
		size = 10;           
		arr = new T[size];
		tell=0;
		head=0;
	}

	/*
	*	This is constructor With 1 Arg
	*/
	Queue(int s)
	{
		size = s;
		arr = new T[size];
		tell=0;
		head=0;
	}

	/*
	 *  This Method is used to find out whether Queue is Empty or not
	 */
	bool isEmpty(){return tell==head;}
	/*
	 *  This Method is used to find out whether Queue is Full or not
	 */
	bool isFull(){return tell=size;}

	/*
	*  This Method used to Add data in to Queue
	*/
	void enQueue(T data)
	{
		if(isFull())
			throw "ERROR : OverFlow";
		else
		{
			this->arr[this->tell] = data;
			this->tell++;
		}
	}

	/*
	*  This Method used to Remove Data form Queue 
	*/
	T deQueue()
	{
		if(isEmpty())
			throw "ERROR : underFlow";
		else
		{
			T data = this->arr[this->head];
			this->arr[this->head] = NULL;
			this->head++;
			return data;
		}
	}

	/*
	* This Mehtod usde to Print All Data form Queue
	*/
	void print()
	{
		if(isEmpty())
			cout<<"The Queue is Empty\n";
		else
		{
			for (int i = head; i < tell; i++)
				cout<<arr[i]<<"     ";
			cout<<endl;
		}
	}

	/*
	* This Method used to CLear All data form Queue
	*/
	void clear()
	{
		if(!isEmpty())
		{
			for(int i=head;i<tell;i++)
				this->arr[i] = NULL;
			tell = 0;
			head = 0;
		}//End if
	}//End function

	/*
	* This Method used To return value of Size
	*/
	int Size(){return size;}

	/*
	*  This Method used to return value of head
	*/
	int Head(){return head;}

	/*
	*  This Method used to return value of tell
	*/
	int Tell(){return tell;}

	/*
	* This Method used to return top value 
	*/
	T topValue(){return arr[tell-1];}

	~Queue()
	{
	  delete []arr;
	}
};


