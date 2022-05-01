#include "student_list.h"

//ok
struct stulist_head *create_stulist_head(){
	struct stulist_head *pnew = NULL;
	pnew = (struct stulist_head *)malloc(sizeof(struct stulist_head));
	if(NULL == pnew)
	{
		return NULL;
	}
	memset(pnew,0,sizeof(struct stulist_head));
	return pnew;
}

//清空表：将所有节点空间释放，置头节点的len成员为0，pfirst成员为NULL
int clear_stulist_head(struct stulist_head *phead)
{
	struct stu_node *ptemp = NULL;
	struct stu_node *pnext = NULL;

	ptemp = phead->pfirst;

	while(ptemp != NULL)
	{
		pnext = ptemp->pnext;
		destroy_stu_node(ptemp);
		ptemp = pnext; 
	}

	memset(phead,0,sizeof(struct stulist_head));
	return 0;
}

int destroy_stulist_head(struct stulist_head * phead){
	clear_stulist_head(phead);
	free(phead);
	phead = NULL;

}

struct stu_node *create_stu_node(struct stu_data *pdata)
{
	struct stu_node *pnew = NULL;
	/*1. 定义一个struct stu_node *类型的指针用来存放新节点空间的地址*/

	/*2. 动态分配一个节点所需的空间*/
	pnew = (struct stu_node *)malloc(sizeof(struct stu_node));
	if(NULL == pnew)
	{
		return NULL;
	}
	memcpy(&pnew->data,pdata,sizeof(struct stu_data));
	return pnew;
}

//ok
int destroy_stu_node(struct stu_node *pnode){
	free(pnode);
	pnode = NULL;
	return 0;
}

//ok
int insert_stu_node_attail(struct stulist_head *phead,struct stu_node *pnew)
{
	if(is_empty_linklist(phead)){
		phead->pfirst = pnew;
		phead->len++;
		return 0;
	}
	struct stu_node * ptmp = phead->pfirst;
	while(ptmp->pnext != NULL){
		ptmp = ptmp->pnext;
	}
	ptmp->pnext = pnew;
	phead->len++;
	return 0;
}

//get a stu_node 's prenode
struct stu_node *get_pre_node(struct stulist_head *phead,struct stu_node *pnode){
	if(is_empty_linklist(phead) || phead->len == 1){
		return NULL;
	}
	struct stu_node *ptmp = phead->pfirst;
	while(ptmp->pnext != pnode){
		ptmp = ptmp->pnext;
	}
	return ptmp;
}

struct stu_node *node_is_in(struct stulist_head *phead, struct stu_node *pnode){
	struct stu_node * ptmp = phead->pfirst;
	while( ptmp!= NULL && ptmp != pnode){
		ptmp = ptmp->pnext;
	}
	if(ptmp == NULL)
		return NULL;
	else 
		return ptmp;
}
struct stu_node * remove_at_head(struct stulist_head *phead){
	if(is_empty_linklist(phead)){
		printf("no such stu_node\n");
		return NULL;
	}	
	struct stu_node *ptmp = phead->pfirst->pnext;
	struct stu_node *pret = phead->pfirst;
	phead->pfirst = ptmp;
	pret->pnext = NULL;
	phead->len--;
	return pret;
}

//移除特定节点
int remove_stu_node(struct stulist_head *phead,struct stu_node *pnode){
	if(is_empty_linklist(phead)){
		printf("no such stu_node\n");
		return -1;
	}

	if(node_is_in(phead,pnode) == NULL){
		return -1;
	}

	if(phead->len == 1){
		if(pnode == phead->pfirst){
			remove_at_head(phead);
		}
	}

	struct stu_node *pnode_pre = get_pre_node(phead,pnode);
	pnode_pre->pnext = pnode->pnext;
	pnode->pnext = NULL;
	phead->len--;
}
//ok
struct stu_node * search_stu_by_name(struct stulist_head *phead,char *pname){
	struct stu_node *ptemp = NULL;
	ptemp = phead->pfirst;
	while(ptemp != NULL)
	{
		if(strcmp(ptemp->data.name,pname) == 0)
		{
			break;
		}
		ptemp = ptemp->pnext;
	}
	return ptemp;
}
//ok
struct stu_node * search_stu_by_id(struct stulist_head *phead,int id){
	struct stu_node *ptemp = NULL;
	ptemp = phead->pfirst;
	while(ptemp != NULL)
	{
		if(ptemp->data.id == id)
		{
			break;
		}
		ptemp = ptemp->pnext;
	}
	return ptemp;
}
/*
   static struct stu_node *get_last_node(struct stulist_head *phead)
   {
   struct stu_node *plast = NULL;

   if(is_empty_linklist(phead))
   {
   return NULL;
   }

   plast = phead->pfirst;
   while(plast->pnext != NULL)
   {
   plast = plast->pnext;
   }

   return plast;
   }
   */


//判空
int is_empty_linklist(struct stulist_head *phead)
{
	return phead->pfirst == NULL ? 1 : 0;
}

//对于id的比较
int comp_id(const void* pv1,const void *pv2){
	return (*(struct stu_node **)pv2)->data.id - (*(struct stu_node **)pv1)->data.id;
}


int sort_by_id(struct stulist_head *phead,struct stu_node **ppnode){
	//开始将链表的地址放入到线性表中
	struct stu_node *ptmp= phead->pfirst;
	int i=0;
	while(ptmp != NULL){
		*(ppnode+i) = ptmp;
		ptmp = ptmp->pnext;
		i++;
	}
	//对链表的地址进行排序
	qsort(ppnode,phead->len,sizeof(struct stu_node *),comp_id);
	return 0;
}


//对于语文成绩的比较
int comp_chn_score(const void* pv1,const void *pv2){
	if(((*(struct stu_node **)pv1)->data.chn_score - \
		(*(struct stu_node **)pv2)->data.chn_score) > 0)
		return 1;
	else if(((*(struct stu_node **)pv1)->data.chn_score - \
			 (*(struct stu_node **)pv2)->data.chn_score) < 0)
		return -1;
	else 
		return 0;
}

//语文
int sort_by_chn_score(struct stulist_head *phead,struct stu_node **ppnode){
	//开始将链表的地址放入到线性表中
	struct stu_node *ptmp= phead->pfirst;
	int i = 0;
	while(ptmp != NULL){
		*(ppnode+i) = ptmp;
		ptmp = ptmp->pnext;
		i++;
	}
	//对链表的地址进行排序
	qsort(ppnode,phead->len,sizeof(struct stu_node *),comp_chn_score);
	return 0;
}

//对于英语成绩的比较
int comp_eng_score(const void* pv1,const void *pv2){
	if( (*(struct stu_node **)pv1)->data.eng_score > \
		(*(struct stu_node **)pv2)->data.eng_score){
		return 1;
	}
	else if((*(struct stu_node **)pv1)->data.eng_score < \
			(*(struct stu_node **)pv2)->data.eng_score){
		return -1;
	}
	else {
		return 0;
	}
}
//英语
int sort_by_eng_score(struct stulist_head *phead,struct stu_node **ppnode){
	//开始将链表的地址放入到线性表中
	struct stu_node *ptmp= phead->pfirst;
	int i = 0;
	while(ptmp != NULL){
		*(ppnode+i) = ptmp;
		ptmp = ptmp->pnext;
		i++;
	}
	//对链表的地址进行排序
	qsort(ppnode,phead->len,sizeof(struct stu_node *),comp_eng_score);
	return 0;
}


//对于数学成绩的比较
int comp_math_score(const void* pv1,const void *pv2){
	if(((*(struct stu_node **)pv1)->data.math_score - \
		(*(struct stu_node **)pv2)->data.math_score) > 0)
		return 1;
	else if(((*(struct stu_node **)pv1)->data.math_score - \
		(*(struct stu_node **)pv2)->data.math_score) < 0)
		return -1;
	else 
		return 0;
}

//数学
int sort_by_math_score(struct stulist_head *phead,struct stu_node **ppnode){
	//开始将链表的地址放入到线性表中
	struct stu_node *ptmp= phead->pfirst;
	int i = 0;
	while(ptmp != NULL){
		*(ppnode+i) = ptmp;
		ptmp = ptmp->pnext;
		i++;
	}
	//对链表的地址进行排序
	qsort(ppnode,phead->len,sizeof(struct stu_node *),comp_math_score);
	return 0;
}

//对于所有成绩的比较
int comp_all_score(const void* pv1,const void *pv2){
	if(((*(struct stu_node **)pv1)->data.eng_score + \
			(*(struct stu_node **)pv1)->data.math_score + \
			(*(struct stu_node **)pv1)->data.chn_score - \
			(*(struct stu_node **)pv2)->data.eng_score - \
			(*(struct stu_node **)pv2)->data.math_score  -\
			(*(struct stu_node **)pv2)->data.chn_score) > 0)
		return 1;
	else if (((*(struct stu_node **)pv1)->data.eng_score + \
			(*(struct stu_node **)pv1)->data.math_score + \
			(*(struct stu_node **)pv1)->data.chn_score - \
			(*(struct stu_node **)pv2)->data.eng_score - \
			(*(struct stu_node **)pv2)->data.math_score  -\
			(*(struct stu_node **)pv2)->data.chn_score) < 0)
		return -1;
	else 
		return 0;
}

//总分
int sort_by_all_score(struct stulist_head *phead,struct stu_node **ppnode){
	//开始将链表的地址放入到线性表中
	struct stu_node *ptmp= phead->pfirst;
	int i = 0;
	while(ptmp != NULL){
		*(ppnode+i) = ptmp;
		ptmp = ptmp->pnext;
		i++;
	}
	//对链表的地址进行排序
	qsort(ppnode,phead->len,sizeof(struct stu_node *),comp_all_score);
	return 0;
}

