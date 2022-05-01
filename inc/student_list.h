//student_list.h
#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LEN 20
#define PASS_LEN 20
struct stu_data
{
	int id;
	char name[NAME_LEN];//人名不支持空白字符
    char passwd[PASS_LEN];//密码不支持空白字符
    char sex;
    float chn_score;
    float math_score;
    float eng_score;
};

struct stu_node
{
	struct stu_data data;
	
	struct stu_node *pnext;
};

struct stulist_head
{
	int len;
	int lastid;
	
	struct stu_node *pfirst;
};

struct stulist_head *create_stulist_head();
int destroy_stulist_head(struct stulist_head * phead);

struct stu_node *create_stu_node(struct stu_data *pdata);
int destroy_stu_node(struct stu_node *pnode);

int insert_stu_node_attail(struct stulist_head *phead,struct stu_node *pnew);
struct stu_node * search_stu_by_name(struct stulist_head *phead,char *pname);
struct stu_node * search_stu_by_id(struct stulist_head *phead,int id);
int remove_stu_node(struct stulist_head *phead,struct stu_node *pnode);
int is_empty_linklist(struct stulist_head *phead);

struct stu_node *node_is_in(struct stulist_head *phead, struct stu_node *pnode);
int remove_stu_node(struct stulist_head *phead,struct stu_node *pnode);

int sort_by_id(struct stulist_head *phead,struct stu_node **ppnode);
int sort_by_chn_score(struct stulist_head *phead,struct stu_node **ppnode);
int sort_by_eng_score(struct stulist_head *phead,struct stu_node **ppnode);
int sort_by_math_score(struct stulist_head *phead,struct stu_node **ppnode);
int sort_by_all_score(struct stulist_head *phead,struct stu_node **ppnode);

#endif
