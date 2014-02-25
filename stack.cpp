/*
* @author shahab zebari 
* stack class 
*/

/*
*
*/

template<class T>
class Stack
{
private:
	T *s;      // The Pointer to create new Array 
	int size;  // The Stack Size 
	int top;   // Top pointer 
public:
	
	/*
	* This is default constructor
	*/
	Stack()
	{
		this->size = 10;              // Any default value you can write in her e.g(10)
		this->s = new T[this->size];  // initialization New Array
		this->top = 0;                // initialization a top pointer 
	}
	/*
	*	This is constructor With 1 Arg
	*/
	Stack(int a)
	{
		this->size = a;               // initialization Size 
		this->s = new T[this->size];  // initialization New Array
		this->top = 0;				  // initialization a top pointer
	}

	/*
	 *  This Method is used to find out whether Stack is Empty or not
	 */
	bool isEmpty(){return this->top==0;}
	/*
	 *  This Method is used to find out whether Stack is Full or not
	 */
	bool isFull() {return this->top==size-1;}

	/*
	*  This Method used to Add data in to Stack
	*/
	void push(T value)
	{
		if(this->isFull())
			throw "ERROR : The Stack is full\n";
		else
		{
			this->s[this->top] = value;
			this->top++;
		}//End if
	}//End function

	/*
	*  This Method used to Remove Data form Stack
	*/
	T pop()
	{
		if(this->isEmpty())
			throw "ERROR : The Stack is Empty\n";
		else
		{
			this->top--;
			T value = this->s[this->top];
			this->s[this->top] = NULL;
			return value;
		}//End if
	}//End function

	/*
	* This Method used to CLear All data form Stack
	*/
	void clear()
	{
		if(!this->isEmpty())
		{
			for(int i=0;i<this->top;i++)
				this->s[i] = NULL;
			this->top = 0;
		}//End if
	}//End function

	/*
	* This Mehtod usde to Print All Data form Stack
	*/
	void print()
	{
		if(this->isEmpty())
			throw "ERROR : The Stack is Empty\n";
		else
		{
			for (int i = 0; i < this->top; i++)
				cout<<this->s[i]<<"    ";
			cout<<"\n\n";
		}//End if
	}//End function
	
	/*
	* This Method used To return value of Size
	*/
	int Size(){return this->size;}

	/*
	*  This Method used to return value of top
	*/
	int Top(){return this->top;}

	/*
	* This Method used to return top value 
	*/
	T topValue(){return this->s[this->top-1];}
};
