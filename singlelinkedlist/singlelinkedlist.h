#ifndef _INITLIST_H_
#define _INITLIST_H_

/**
* @brief 构造一个节点类型结构体
*/ 
typedef struct Node
{
	struct Node * NextNode;
	void *data;
}Node_t, *LinkList_t;

#define E_OK	0
#define E_ERROR -1

/**
* @brief L传进去的是一个双重指针，需要需改LinkList的内容，即修改LinkList存储的地址.
* @param L
* @return 成功返回E_OK 其它返回E_ERROR
*/
int init_linklist(LinkList_t *L);

/**
* @brief 释放链表
* @param L
* @return 链表释放成功返回E_OK 其它返回失败
*/
int detect_linklist(LinkList_t * L);

/**
* @brief 从链表头插入节点
* @param L
* @param data
* @return 插入成功返回E_OK 其它返回E_ERROR
* @note data为void类型指针,具体由使用者解析 
*/
int insert_to_head(LinkList_t L, void *data);

/**
* @brief 从链表尾插入节点
* @param L
* @param data
* @return 插入成功返回E_OK,其它返回E_ERROR
* @note data为void类型指针,具体由使用者解析 
*/
int insert_to_tail(LinkList_t L, void *data);

/**
* @brief 根据节点索引遍历链表
* @param L
* @param index
* @return 找到返回Node 其它返回NULL
*/
Node_t* find_from_index(LinkList_t L, int index);

/**
* @brief 根据data遍历链表节点
* @param L
* @param data 这里可以是其它类型数据
* @return 找到返回Node 其它返回NULL
*/
Node_t* find_from_data(LinkList_t L, int data);

/**
* @brief 打印链表节点
* @param L
*/
void print_list(LinkList_t L);

/**
* @brief 链表反转
* @param L
* @return 成功返回E_OK 其它返回E_ERROR
*/
int ListOrderRollback(LinkList_t *L);



#endif