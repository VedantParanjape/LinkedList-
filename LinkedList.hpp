//******************************// 
// Created by Vedant Paranjape  //
// LinkedList Template Library  //
// Build v1.0                   //
// 19:19 4/11/2017 IST          //
//******************************//

#include <iostream>

template <typename T>
class LinkedList
{
	private:
	    struct Node
	    {
	    	T data;
	    	Node* next;
		};
		Node* Init;           //store initial value
        Node* Current;        //current node(last node)
        Node* New;            //used to store a new node
        Node* temp;           //used for traversal operation
        int counter;         
        int Scounter;
        int NumberOfElements; //number of nodes
    
	public:
	    LinkedList();           //constructor
	    int size_ll();          // returns siz of linked list
	    void add(T dat);        // function to add elements
		T& operator[](int Location);   // function to return elements
		void showall();         // function to output all values
        void del(int loc);      // function to delete a node
        ~LinkedList();          // destructor
};

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
LinkedList<T>::LinkedList()
{
	Init = new Node;
	Current = new Node;
    Init = Current;
	counter = 0;
	Scounter = 1;
	NumberOfElements = 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int LinkedList<T>::size_ll()
{
	return NumberOfElements;
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::add(T dat)
{
	if(counter != 0)
	 {
		New = new Node;
		Current->next = New;
		Current = New;
		Current->data = dat;
		Current->next = 0;
		NumberOfElements++;
	 }
			
	if(counter == 0)
	 {
		Current->data = dat;
		Current->next = 0;
		counter = 1;
		NumberOfElements++;
     }
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T& LinkedList<T>::operator[](int Location)
{
	T* returnval;
	temp = Init;
		   	
	if(Location > 0)
	 {
		while(temp->next != 0)
	     {
		   	if(Scounter == Location)
		   	 {
		   	    returnval = &temp->data;
		   	    Scounter = 1;
				break; 	  	
			 }
			 temp = temp->next;
			 Scounter++;
		 }
				
	     if(Scounter == NumberOfElements)
	      {
		     returnval =  &temp->data;	
	      }
	 }
	return *returnval;
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::showall()
{
	temp = Init;
		   
    while(temp->next != 0)
	{
		std::cout<<temp->data<<std::endl;
		temp = temp->next;
	}
	std::cout<<temp->data<<std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::del(int loc)
{		
	Node* temp_next;
	int count = 0;
			
	temp = Init;
	temp_next = temp->next;
		    
	if(loc == 1)
	{
		Init = Init->next;	
		NumberOfElements--;
	}
			
	if(loc == NumberOfElements)
	{
		while(1)
		{
		    if(temp_next->next == 0)
			 {
				temp->next = 0;
				Current = temp;
				NumberOfElements--;
				break;
			 }
			 
			 temp = temp->next;
			 temp_next = temp->next;
		}
	}
			
	if(loc != 1 && loc != NumberOfElements)
	 { 
		while(temp->next != 0)
	    {
	    	count++;
	    	if(count == loc-1 && loc < NumberOfElements && loc > 1)
	    	{
		   		temp->next = temp_next->next;
		   		NumberOfElements--;
		   		count = 0;
		   		temp_next = 0;
		   		break;
			}
				
			temp = temp->next;
			temp_next = temp->next;
		} 
	 }
}	
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
LinkedList<T>::~LinkedList()
{
	int loopval = NumberOfElements;
   for(int i=0;i<=loopval;i++)
   {
      del(i);   	
   }
   exit(0);
}	
///////////////////////////////////////////////////////////////////////////////////////////////
