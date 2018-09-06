#include"single_list_table.hpp"

int main()
{
	const chars const str[] = {"hello", "jia", "world", "top", "leangth", "lucy"};
	Shead note(str, sizeof(str)/sizeof(str[0]));
	note.ShowSlist();
	std::cout << "the length of note = " << note.GetLengthSlist() << std::endl;
	Shead t_note(note);
	t_note.ShowSlist();
	/*
	 * 测试头删和未删, 求长度
	for(int i = 0; i < note.GetLengthSlist(); i++)
	{
		std::cout << "the loop of index = " << i << std::endl;
		note.HeadDelete();
		note.ShowSlist();
		std::cout << "----------------" << std::endl;
		t_node.TailDelete();
		t_node.ShowSlist();
	}

	char buffer[STR_LEN];
	for(int i = 0; i <note.GetLengthSlist(); i++)
	{
		memset(buffer, '\0', STR_LEN);
		note.GetElem(i, buffer);
		std::cout << "the elem of index = " << i << " data = "  << buffer << std::endl;
	}
	*/
	/*
	std::cout << "Test Merge data " << std::endl;
	note.MergeSlist(t_note);
	note.ShowSlist();

	std::cout << "Test Reverse data " << std::endl;
	t_note.ReverseSlist();
	t_note.ShowSlist();
	*/
	std::cout << "Test Sort data" << std::endl;
	t_note.SortSlistBubble();
	t_note.ShowSlist();
	return 0;
} 
