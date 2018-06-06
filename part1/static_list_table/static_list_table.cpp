#include"static_list_table.hpp"

Sqlist::Sqlist(int index):index_next(index)
{
	for(int i = 0; i < MAX_LEN; i++)
	{
		elem[i] = -1;
	}
}

Sqlist::Sqlist(const Sqlist &src):index_next(src.index_next)
{
	for(int i = 0; i < index_next; i++)
	{
		elem[i] = src.elem[i];
	}
}

void Sqlist::ClearList()
{
	if(IsEmpty())
	{
		return ;
	}
	for(int i = 0; i < index_next; i++)
	{
		elem[i] = -1;
	}
	index_next = 0;
}

void Sqlist::GetElem(int index, ElemType *data)
{
	if(IsEmpty() || index_next - 1 < index)
	{
		*data = -1;
	}
	*data = elem[index];
}

int Sqlist::LocateElem(ElemType data)
{
	for(int i = 0; i < index_next; i++)
	{
		if(elem[i] == data)
		{
			return i;
		}
	}
	return -1;
}

bool Sqlist::IsEmpty()
{
	return index_next == 0 ? true: false;
}

bool Sqlist::IsFull()
{
	return index_next - 1 == MAX_LEN ? true : false;
}

bool Sqlist::ListInsert(int index, ElemType data)
{
	if(index < 0 || index >= MAX_LEN || IsFull())
	{
		return false;
	}
	else
	{
		if(index_next  <= index)
		{
			elem[index_next++] = data;
			return true;
		}
		int i = index_next;
		for(; i != index - 1; i--)
		{
			elem[i] = elem[i-1];
		}
		elem[index] = data;
		index_next++;
	}
	return true;
}

bool Sqlist::ListDelete(int index, ElemType *data)
{
	if(IsEmpty() || index < 0 || index >= index_next)
	{
		return false;
	}
	*data = elem[index];
	index_next--;
	for(int i = index; i < index_next; i++)
	{
		elem[i] = elem[i+1];
		if(i == index_next - 1)
		{
			return true;
		}
	}
}

int Sqlist::ListLength()
{
	if(IsEmpty())
	{
		return 0;
	}
	return index_next;
}

void Sqlist::ShowList()
{
	for(int i = 0; i < index_next; i++)
	{
		std::cout << "the elem of index = " << i << ", data = " << elem[i] << std::endl;
	}
	std::cout << std::endl;
}
