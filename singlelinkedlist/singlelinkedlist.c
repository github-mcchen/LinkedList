#include "singlelinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

/**
* @brief L传进去的是一个双重指针，需要需改LinkList的内容，即修改LinkList存储的地址.
* @param L
* @return 成功返回E_OK 其它返回E_ERROR
*/
int init_linklist(LinkList_t *L)
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
	p->NextNode = NULL;
	p->data = NULL;
	*L = p;
	return E_OK;
}

/**
* @brief 释放链表
* @param L
* @return 链表释放成功返回E_OK 其它返回失败
*/
int detect_linklist(LinkList_t * L)
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
	Node_t *p;
	
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
	if (NULL == L->NextNode)
	{
		p->NextNode = NULL;
		L->NextNode = p;
	}
	else
	{
		p->NextNode = L->NextNode;
		L->NextNode = p;
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
	Node_t *p;
	Node_t *tmp;
	
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
	p->NextNode = NULL;
	
	tmp = L;
	
	while (tmp->NextNode)
	{
		tmp = tmp->NextNode;
	}
	
	tmp->NextNode = p;
	
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
	Node_t* p;
	int i = 0;
	
	if (0 >= index || NULL == L)
	{
		return NULL;
	}
	
	p = L;
	while (NULL != p->NextNode && i < index)
	{
		p = p->NextNode;
		i++;
	}
	return (i==index?p:NULL);
}

/**
* @brief 根据data遍历链表节点
* @param L
* @param data 这里可以是其它类型数据
* @return 找到返回Node 其它返回NULL
*/
Node_t* find_from_data(LinkList_t L, int data)
{
	Node_t* p;
	
	if (NULL == L)
	{
		return NULL;
	}
	p = L->NextNode;
	while (p)
	{
		if (data == *(int*)p->data)
		{
			return p;
		}
		p = p->NextNode;
	}
	return NULL;
}

/**
* @brief 打印链表节点
* @param L
*/
void print_list(LinkList_t L)
{
	Node_t* p;

	p = L->NextNode;
	
	while(NULL != p)
	{
		printf("%d ", *(int*)p->data);
		p = p->NextNode;
	}
	printf("\n");
}

/**
* @brief 链表反转
* @param L
* @return 成功返回E_OK 其它返回E_ERROR
*/
int ListOrderRollback(LinkList_t *L)
{
	Node_t *tmp_node, *f_node, *h_node;
	
	tmp_node = (*L)->NextNode;
	f_node = NULL;
	
	while(tmp_node->NextNode != NULL)
	{
		h_node = tmp_node->NextNode;
		tmp_node->NextNode = f_node;
		f_node = tmp_node;
		tmp_node = h_node;
	}
	tmp_node->NextNode = f_node;
	(*L)->NextNode = tmp_node;
	return E_OK;
}


int main(void)
{
	LinkList_t L = NULL;
	int i;
	int head_data = 1;
	int tail_data = 2;
	Node_t *p = NULL;
	init_linklist(&L);
	printf("TO init the L the pointer is %p\n", L);
	
	for (i = 0; i < 10; i++)
	{
		insert_to_head(L, (char*)&head_data);
		insert_to_tail(L, (char*)&tail_data);
	}
	i = 0;
	p = L->NextNode;
	while (p)
	{
		printf("Node[%d]->data = %d\n", i, *(int*)p->data);
		p = p->NextNode;
		i++;
	}
	print_list(L);
	ListOrderRollback(&L);
	print_list(L);
	return E_OK;
}