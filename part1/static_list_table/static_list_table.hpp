#include<iostream>
#include<stdlib.h>
#include<stdio.h>


#define	ElemType	int
#define	MAX_LEN		10
class Sqlist{
	ElemType elem[MAX_LEN];
	int index_next;
public:
	Sqlist(int index = 0);
	Sqlist(const Sqlist &src);
	bool IsEmpty();
	void ClearList();
	/*
	 *	将线性表中的第index的元素返回给data所指的空间
	 * */
	void GetElem(int index, ElemType *data);
	/*
	 *	查找表中的元素为data的下标,
	 *		如果找到: 返回index
	 *		没找到	  返回-1
	 * */
	int LocateElem(ElemType data);
	/*
	 *	给表中插入一个数据
	 *		如果表已经满了, --未插入
	 *		如果表为空	--直接插入
	 *		
	 *		如果数据index >= MAX_LEN || index < 0	--未插入
	 *		如果其他: 则向后移动数据并插入.
	 * */
	bool ListInsert(int index, ElemType data);
	/*
	 *	删除表中的一个数据.
	 *		如果表中为空, 则直接退出
	 *
	 * */
	bool ListDelete(int index, ElemType *data);
	int ListLength();
	bool IsFull();
	void ShowList();
};
