//student_list.h
#ifndef VIEW_H
#define VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student_list.h"

void show_login_fail();
void show_passwd_not_right();
void show_no_this_stud();
void show_login_success();

int get_username(char *pout);
int get_login_stud_passwd(char *passwd);

int display_main_ui();
void print_errmsg(char *pstr);


int show_input_new_passwd(char *passwd);
void show_change_success();

int show_one_stu_infor(struct stulist_head *phead,struct stu_node *pnode);

int show_get_id(int *number);
int show_delete_fail();
int show_delete_success();

int show_input_new_info(struct stu_node *p_stu);

int show_all_stu_info(struct stulist_head *phead, struct stu_node **ppnode);
//wait



#endif
