#include "doublelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>


/**
* @brief 初始化双向链表,L传进去的是一个双重指针，需要需改LinkList的内容，即修改LinkList存储的地址.
* @param L
* @return 成功返回E_OK 其它返回E_ERROR
*/
int init_linklist(LinkList_t *L)
{
	LinkList_t p = NULL;
	
	if (NULL == L)
	{
		return E_ERROR;
	}
	
	p = (LinkList_t)malloc(sizeof(**L));
	if (NULL == p)
	{
		return E_ERROR;
	}
	p->Link.Next_List = (Link_t*)p;
	p->Link.Prev_List = (Link_t*)p;
	p->count = 10;
	
	*L = p;
	
	return E_OK;
}

/**
* @brief 释放链表
* @param L
* @return 链表释放成功返回E_OK 其它返回失败
*/
int detect_linklist(LinkList_t *L)
{
	if (NULL == L)
	{
		return E_ERROR;
	}
	
	free(*L);
	*L = NULL;
	return E_OK;
}

/**
* @brief 从链表头插入节点
* @param L
* @param data
* @return 插入成功返回E_OK 其它返回E_ERROR
* @note data为void类型指针,具体由使用者解析 
*/
int insert_to_head(LinkList_t L, void *data)
{
	Node_t *p = NULL;
	
	if (NULL == L)
	{
		return E_ERROR;
	}
	
	p = (Node_t*)malloc(sizeof(Node_t));
	
	if (NULL == p)
	{
		return E_ERROR;
	}
	
	p->data = data;
	if ((Link_t*)L == L->Link.Prev_List || (Link_t*)L == L->Link.Next_List)
	{
		L->Link.Next_List = (Link_t*)p;
		L->Link.Prev_List = (Link_t*)p;
		p->Link.Next_List = (Link_t*)L;
		p->Link.Prev_List = (Link_t*)L;
	}
	else
	{
		p->Link.Next_List = L->Link.Next_List;
		L->Link.Next_List = (Link_t*)p;
		p->Link.Prev_List = (Link_t*)L;
		
	}
	
	return E_OK;
}

/**
* @brief 从链表尾插入节点
* @param L
* @param data
* @return 插入成功返回E_OK,其它返回E_ERROR
* @note data为void类型指针,具体由使用者解析 
*/
int insert_to_tail(LinkList_t L, void *data)
{
	Node_t *p = NULL;
	Link_t *tmp =NULL;
	
	if (NULL == L)
	{
		return E_ERROR;
	}
	
	p = (Node_t*)malloc(sizeof(Node_t));
	
	if (NULL == p)
	{
		return E_ERROR;
	}
	
	p->data = data;
	
	if ((Link_t*)L == L->Link.Prev_List || (Link_t*)L == L->Link.Next_List)
	{
		L->Link.Next_List = (Link_t*)p;
		L->Link.Prev_List = (Link_t*)p;
		p->Link.Next_List = (Link_t*)L;
		p->Link.Prev_List = (Link_t*)L;
	}
	else
	{
		p->Link.Next_List = (Link_t*)L;
		tmp = L->Link.Prev_List;
		tmp->Next_List = (Link_t*)p;
		p->Link.Prev_List = L->Link.Prev_List;
		L->Link.Prev_List = (Link_t*)p;
		
	}
	
	return E_OK;
}

/**
* @brief 根据节点索引遍历链表
* @param L
* @param index
* @return 找到返回Node 其它返回NULL
*/
Node_t* find_from_index(LinkList_t L, int index)
{
	Link_t* p = NULL;
	int i = 1;
	
	if (0 >= index || NULL == L)
	{
		return NULL;
	}
	
	p = L->Link.Next_List;
	while ((Link_t*)L != p && i < index)
	{
		p = p->Next_List;
		i++;
	}
	return (i==index?(Node_t*)p:NULL);
}

/**
* @brief 根据data遍历链表节点
* @param L
* @param data 这里可以是其它类型数据
* @return 找到返回Node 其它返回NULL
*/
Node_t* find_from_data(LinkList_t L, int data)
{
	Link_t* p = NULL;
	Node_t* tmp = NULL;
	
	if (NULL == L)
	{
		return NULL;
	}
	p = L->Link.Next_List;
	while ((Link_t*)L != p)
	{
		tmp = (Node_t*)p;
		if (data == *(int*)tmp->data)
		{
			return (Node_t*)p;
		}
		p = p->Next_List;
	}
	return NULL;
}

/**
* @brief 打印链表节点
* @param L
*/
void print_list(LinkList_t L)
{
	Link_t *p = NULL;;
	Node_t* tmp = NULL;
	int i = 0;
	
	p = L->Link.Next_List;
	
	while((Link_t*)L != p)
	{
		tmp = (Node_t*)p;
		printf("Node[%d].data = %d\n", i++, *(int*)tmp->data);
		p = p->Next_List;
	}
}

int main(void)
{
	LinkList_t L = NULL;
	int head_data[10] = {1,2,3,4,5,6,7,8,9,10};
	int tail_data[10] = {21,22,23,24,25,26,27,28,29,30};
	//int head_data = 100;
	//int tail_data = 200;
	int i;
	Node_t* node = NULL;
	
	if (E_OK == init_linklist(&L))
	{
		printf("pointer of L ---> %p\n", L);
		printf("L->count = %d\n", L->count);
	}
	else
	{
		printf("init_linklist error\n");
		return -1;
	}
	for (i = 0; i < 10; i++)
	{
		insert_to_head(L, (int*)&head_data[i]);
		insert_to_tail(L, (int*)&tail_data[i]);
	}
	print_list(L);
	
	node = find_from_index(L, 13);
	if (NULL != node)
	{
		printf("index-->13-->%p-->data==%d\n", node, *(int*)node->data);
	}
	else
	{
		printf("find index 13 error\n");
	}
	
	node = find_from_data(L, 27);
	if (NULL != node)
	{
		printf("data-->27-->%p--->data == %d\n", node, *(int*)node->data);
	}
	else
	{
		printf("find data 27 node error\n");
	}
	return 0;
}
