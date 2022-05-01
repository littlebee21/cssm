#ifndef LOGIN_H
#define LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student_list.h"
#include "viewer.h"

struct stu_node *login(struct stulist_head *phead);
int insert_stu(struct stulist_head * phead);
int change_passwd(struct stulist_head *phead,struct stu_node *p_stu);
void get_myinfo(struct stulist_head *phead,struct stu_node *p_stu);

int remove_stu(struct stulist_head *phead,struct stu_node *p_stu);
int get_stu_info(struct stulist_head *phead,struct stu_node *p_stu);

int change_info(struct stulist_head *phead,struct stu_node *p_stu);

int printf_sort_by_id(struct stulist_head *phead);
int printf_sort_by_chn_score(struct stulist_head *phead);
int printf_sort_by_eng_score(struct stulist_head *phead);
int printf_sort_by_math_score(struct stulist_head *phead);
int printf_sort_by_all_score(struct stulist_head *phead);

#endif
