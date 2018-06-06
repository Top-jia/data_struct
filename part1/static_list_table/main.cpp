#include"static_list_table.hpp"

int main()
{
	Sqlist mylist;
	int array[] = {8, 9, 2, 4, 7, 6};
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		mylist.ListInsert(i, array[i]);
	}
	mylist.ShowList();
	/*
	 *	寻找7, 4 3元素
	 * */
	std::cout << "look for 7 elem of index = " << mylist.LocateElem(7) << std::endl;
	std::cout << "look for 4 elem of index = " << mylist.LocateElem(4) << std::endl;
	std::cout << "look for 3 elem of index = " << mylist.LocateElem(3) << std::endl;

	for(int i = 0; i < mylist.ListLength(); i++)
	{
		ElemType data;
		mylist.GetElem(i, &data);
		std::cout << "GetElem index =  " << i << " data = " << data << std::endl;
	}

	for(int i = 0; i < mylist.ListLength();)
	{
		mylist.ShowList();
		std::cout << "delete a elem for mylist " << std::endl;
		ElemType self;
		mylist.ListDelete(i, &self);
		std::cout << "delete data = " << self << std::endl;
	}
	mylist.ClearList();
	mylist.ShowList();
	return 0;
}
