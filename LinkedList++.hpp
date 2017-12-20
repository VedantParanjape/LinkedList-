//*******************************//
//   Made By: Vedant Paranjape   //
//   LinkedList++                //
//   18 December 2017            //
//   16:55 IST                   //
//*******************************//

////////////// class definiton //////////////////////////////////////////////
template<typename T>
class LinkedList{                        //linkedlist class
	private:                             //private data members
		struct node                      //definiton of structure node
		{
 			T data;                      //data variable
			node* next;                  //next node pointer
		};
		node* h;                         //pointer pointing to head of linked list
		node* n;                         //pointer pointing to newly created node
		node* t;
		node* createnode(T data);       //function to create new node, pack them with data and return the pointer to the location
		int size_ll;                    //variable to store size of linked list 
		
	public:
	    LinkedList();                   //constructor
		void add(T data);               //function prototype to add new node to the linked list
		T& operator[](int location);    //operator overloading to access the contents of linked list just like a array
		void del(int location);         //function to delete the node
		int size();	                    //function to return the size of linked list
};
////////////////////////////////////////////////////////////////////////////


/////////////////// constructor //////////////////////////////////////
template<typename T>
LinkedList<T>::LinkedList()            
{
	h = nullptr;                  //intialize the values of the variables
	n = nullptr;
	t = nullptr;
	size_ll = 0;
}
/////////////////////////////////////////////////////////////////////

///////////////// create node function /////////////////////////////
template<typename T>
typename LinkedList<T>::node* LinkedList<T>::createnode(T data)
{ 
	n = new node;                //create new node
	n->data = data;              //set the data
	n->next = nullptr;
	
	return n;                    //return the pointer of the new node
}
////////////////////////////////////////////////////////////////////

////////////// add node ///////////////////////////////////////////
template<typename T>
void LinkedList<T>::add(T data)
{
	if(h == nullptr)              
	{
		h = createnode(data);
		t = h;
		size_ll++;
	}
	else
	{
		t->next = createnode(data);
		t = t->next;
		size_ll++;
	}
}
////////////////////////////////////////////////////////////////////

//////////// operator overloaded function to return the value /////
template<typename T>
T& LinkedList<T>::operator[](int location)
{
	int counter = 0;
	node* s = nullptr;
	s = h;
	T* returnval;
	
	while(s != nullptr)
	{
		counter++;
		if((counter-1) == location)
		{
			returnval = &s->data;
		}
		s = s->next;
	}

	return *returnval;
}
//////////////////////////////////////////////////////////////////

///////////// delete node ///////////////////////////////////////
template<typename T>
void LinkedList<T>::del(int location)
{
	int counter = 0;
	node* d = nullptr;
	node* d_next = nullptr;
	d = h;
	
	if(location == 0)
	{
		h = h->next;
		delete d;
	}
	
	while(d != nullptr)
	{
		counter++;
		if(counter == location)
		{
			d_next = d->next;
			d->next = d_next->next;
			delete d_next;
		}
		d = d->next;
	}
	size_ll--;
}
///////////////////////////////////////////////////////////////////

///////////// return linked list size /////////////////////////////
template<typename T>
int LinkedList<T>::size()
{
	return size_ll;
}
//////////////////////////////////////////////////////////////////
