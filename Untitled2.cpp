#include "LinkedList.hpp"
#include <iostream>
using namespace std;

main()
{
	LinkedList<int> list;
	int number0;
	int number1;
	
	cout<<"Enter two number to be stored in the linked list"<<endl;
	cin>>number0>>number1;
	
	list.add(number0);
	list.add(number1);
	list.add(34);
	list.showall();
	cout<<list.size_ll();
	cout<<endl;
	cout<<&list[1]<<endl;
	cout<<list[2]<<endl;
	cout<<list[3]<<endl;
	list.del(1);
	list.showall();
	list.~LinkedList();
}
