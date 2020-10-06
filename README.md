# LinkedList++
LinkedList++ is a C++ Linked List template class library.
This is a simple plug and play library. There is no need to compile it using cmake or anything. Just include it in your code with correct path and create a class object and use it to store data in a linked list.

It has member functions:
```
1. node* createnode(T data) ----- creates a new node and returns its location as pointer to its location, pass data to be stored into it as argument

2. LinkedList () ---------------- class constructor

3. void add(T data) ------------- function to add nodes to the linked list

4. T& operator[](int location) -- operator overloaded function to pass node data as a reference, can be used to reassign and extract values

5. void del(int location) ------- function to delete node of linked list 

6. int size() ------------------- function to return size of linked list
```
Example code:

```
#include "LinkedList++.hpp"
#include <iostream>

int menu()
{
	int option = 0;
	
	system("cls");
	std::cout<<"1. Add node \n"
	         <<"2. Change node data \n"
	         <<"3. Delete node \n"
	         <<"4. Show size \n"
	         <<"5. Show node data \n"
	         <<"6. Exit \n";
	std::cin>>option;
	
	return option;	    
} 

int main()
{
	LinkedList<int> list;
	int  loc = 0;
	auto data = 0;
	
	do
	{
		switch(menu())
		{
			case 1:
				std::cout<<"Enter node data: ";
				std::cin>>data;
				list.add(data);
				break;
				
				case 2:
					std::cout<<"Enter node location: ";
					std::cin>>loc;
					std::cout<<"Enter node data: ";
					std::cin>>data;
					list[loc] = data;
					break;
					
					case 3:
						std::cout<<"Enter node location: ";
						std::cin>>loc;
						list.del(loc);
						break;
						
						case 4:
							std::cout<<"Size of linked list is "<<list.size()<<"\n";
							break;
							
							case 5:
								std::cout<<"Enter the node location: ";
								std::cin>>loc;
							    std::cout<<list[loc]<<"\n";
							    system("pause");
							    break;
							    
							    case 6:
							    	exit(0);
							    	break;
		}
	}while(1);
}
```

1) Sravan Chittupalli