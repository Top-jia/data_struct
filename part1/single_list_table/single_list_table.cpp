#include"single_list_table.hpp"

Slist* Shead::buySlist()
{
	Slist *p_head = (Slist*)malloc(sizeof(Slist) * 1);
	assert(p_head);
	memset(p_head, '\0', sizeof(Slist)*1);
	p_head->info = (chars)malloc(sizeof(char)* STR_LEN);
	assert(p_head->info);
	memset(p_head->info, '\0', sizeof(char) * STR_LEN);
	return p_head;
}

void Shead::freeSlist(Slist *ptr)
{
	if(NULL != ptr)
	{
		free(ptr->info);
		free(ptr);
	}
}

Slist* Shead::CreateSlist(const chars str)
{
	if(str != NULL)
	{
		Slist *ptr = buySlist();
		strncpy(ptr->info, str, STR_LEN-1);
		return ptr;
	}
}

bool Shead::HeadInsert(Slist *ptr)
{
	if(ptr == NULL)	
	{
		return false;
	}
	if(head->next == NULL)
	{
		head->next = ptr;
	}
	else
	{
		ptr->next = head->next;
		head->next = ptr;
	}
	return true;
}

Shead::Shead(Slist *ptr = NULL , unsigned int number = 0):head(ptr), number(0)
{
	head = buySlist();
}

Shead::Shead(const chars const *str, unsigned int p_number):number(p_number)
{
	head = buySlist();
	for(int i = 0; i < p_number; i++)
	{
		Slist *ptr = CreateSlist(str[i]);
		HeadInsert(ptr);
	}
}
bool Shead::TailInsert(Slist *ptr)
{
	if(ptr == NULL)	
	{
		return false;
	}

	Slist *s_ptr = head;
	while(s_ptr->next != NULL)
	{
		s_ptr = s_ptr->next;
	}
	s_ptr->next = ptr;
	return true;
}


Shead::Shead(const Shead &src)
{
	if(&src == this || src.number == 0)
	{
	}
	else
	{
		this->head = buySlist();
		this->number = 0;
		for(Slist *ptr = src.head->next; ptr != NULL; ptr = ptr->next)
		{
			Slist *s_ptr = CreateSlist(ptr->info);
			TailInsert(s_ptr);
			number++;
		}
	}
}

bool Shead::HeadDelete()
{
	Slist *tmp = head->next;
	if(tmp == NULL)
	{
		return false;
	}
	else
	{
		head->next = tmp->next;
		freeSlist(tmp);
		return true;
	}
}

Shead::~Shead()
{
	while(HeadDelete()){number--;}
	freeSlist(head);
	head = NULL;
}


bool Shead::GetElem(int i , chars str)
{
	if(i < 0 || i > number) 
	{
		return false;
	}
	Slist *ptr = head->next;
	for(int j = 0; j < i; j++)
	{
		ptr = ptr->next;
	}
	if(ptr != NULL)
	{
		strncpy(str, ptr->info, strlen(ptr->info));
		return true;
	}
	return false;
}

void Shead::ShowSlist()
{
	Slist *ptr = head->next;
	int i = 0;
	while(ptr != NULL)
	{
		std::cout << "the elem of index = " << i << " data = " << ptr->info << std::endl;
		ptr = ptr->next;
		i++;
	}
}

unsigned int Shead::GetLengthSlist()
{
	return number;
}

/*
 *	合并后, 要保证src的存在(进行无序的合并).
 * */
bool Shead::MergeSlist(const Shead &src)
{
	if(&src == this || src.number == 0) 
	{
		return false;
	}
	for(Slist *ptr = src.head->next; ptr != NULL; ptr = ptr->next)
	{
		Slist *dsp = CreateSlist(ptr->info);
		HeadInsert(dsp);
		number++;
	}
	return true;
}

bool Shead::TailDelete()
{
	if(head->next == NULL)
	{
		return false;		
	}
	Slist *ptr = head->next;
	Slist *tmp = ptr;

	while(ptr != NULL && ptr->next != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	/*
	 *	没有元素, 只有头结点
	 * */
	if(ptr != NULL)
	{
		/*
		 *	有一个元素
		 * */
		if(tmp == ptr)
		{
			freeSlist(ptr);
			head->next = NULL;
			return true;
		}
		freeSlist(ptr);
		tmp->next = NULL;
	}
	return true;
}
/*
 *	这个应该为选择排序
 * */
void Shead::SortSlist()
{
	if(head->next == NULL || head->next->next == NULL)
	{
		return ;
	}

	Slist *pptr = head->next;
	for(int i = 0; i < number - 1; i++)
	{
		Slist *ptr = pptr->next;
		for(int j = 0; j < number - i -1; j++)
		{	
			if(strncmp(pptr->info, ptr->info, STR_LEN) < 0)
			{
				if(pptr == head->next)
				{
					head->next = ptr;
					pptr->next = ptr->next;
					ptr->next = pptr;
					continue;
				}
				Slist *s_ptr = head->next;
				while(s_ptr->next != pptr)
				{
					s_ptr = s_ptr->next;
				}
				s_ptr->next = ptr;
				pptr->next  = ptr->next;
				ptr->next = pptr;
				continue;
			}
			ptr = ptr->next;
		}
	}
}

/*
 *	这个为冒泡排序
 * */
void Shead::SortSlistBubble()
{
	if(head->next == NULL || head->next->next == NULL)
	{
		return ;	
	}
	Slist *pptr = head->next;
	Slist *ptr  = head->next;
	for(; pptr != NULL; pptr = pptr->next)
	{
		for(; ptr != NULL; ptr = ptr->next)
		{
			if(strncmp(pptr->info, ptr->info) > 0)
			{
				if(pptr == head->next)
				{
					head->next = ptr;
					pptr->next = ptr->next;
					ptr->next = pptr;
				}
			}
		}
	}

}

Slist* Shead::Reverse(Slist *ptr, Slist *pptr)
{
	if(pptr == NULL)
	{
		return ptr;
	}

	Slist *sptr =  Reverse(ptr->next, pptr->next);
	ptr->next = NULL;
	pptr->next = ptr;
	return sptr;
}

void Shead::ReverseSlist()
{
	if(head->next == NULL || head->next->next == NULL)
	{
		return ;
	}
	head->next = Reverse(head->next, head->next->next);
}
