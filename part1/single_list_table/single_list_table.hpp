#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define chars	char *
#define	STR_LEN	15
typedef struct single_link_list{
	chars info;
	struct single_link_list *next;
}Slist;

class Shead{
	private:
		Slist *head;
		unsigned int number;

		static Slist* buySlist();
		static void freeSlist(Slist *ptr);
		static Slist* Reverse(Slist *ptr, Slist *pptr);
	public:
		Shead(Slist *p_head, unsigned int p_number);
		Shead(const chars const *ptr, unsigned int p_number);
		Shead(const Shead &src);
		~Shead();

		void ShowSlist();
		Slist* CreateSlist(const chars str);
		unsigned int GetLengthSlist();
		bool HeadInsert(Slist *ptr);
		bool HeadDelete();
		bool TailInsert(Slist *ptr);
		bool TailDelete();

		bool GetElem(int i, chars str);
		
		bool MergeSlist(const Shead &src);
		void SortSlist();
		void ReverseSlist();
};


