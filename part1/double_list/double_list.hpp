#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdio.h>
#define chars	char *
#define	STR_LEN	15

typedef struct double_list{
	chars info;
	struct double_list *next;
}Dlist;

class Shead{
	private:
		Dlist *head;
		unsigned int number;

		static Dlist* buyDlist();
		static void freeSlist(Dlist *ptr);
		static Dlist* Reverse(Dlist *ptr, Dlist *pptr);
	public:
		Shead(Dlist *p_head, unsigned int p_number);
		Shead(const chars const *ptr, unsigned int p_number);
		Shead(const Shead &src);
		~Shead();

		void ShowSlist();
		Dlist* CreateSlist(const chars str);
		unsigned int GetLengthDlist();
		bool HeadInsert(Dlist *ptr);
		bool HeadDelete();
		bool TailInsert(Dlist *ptr);
		bool TailDelete();

		bool GetElem(int i, chars str);
		
		bool MergeSlist(const Shead &src);
		void SortSlist();
		void ReverseSlist();
		void SortSlistBubble();
};


