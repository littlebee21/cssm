#include "viewer.h"

int display_main_ui()
{
    int op = -1;
/*    
1.  修改自身登录密码
2.  添加新学生
3.  查阅自身信息
4.  删除学生（输入学号）
5.  查阅指定学生信息（输入学号）（密码不打印）
6.  修改自己的信息（姓名、性别、三门功课成绩）
7.  按学号从低到高查看所有学生信息（密码不打印）
8.  按数学成绩从高到低查看所有学生信息（密码不打印）
9.  按语文成绩从高到低查看所有学生信息（密码不打印）
10.  按英语成绩从高到低查看所有学生信息（密码不打印）
11.  按总分从高到低查看所有学生信息（密码不打印）
*/
	printf("\n");
    printf("Please select your operation:\n");
    printf("1. login\n");
    printf("2. Add 5 new student\n");
    printf("3. change passwd\n");
    printf("4. Query your information\n");
    printf("5. remove stu\n");
    printf("6. change self info\n");
    printf("7. id sort\n");
    printf("8. eng sort\n");
    printf("9. math sort\n");
    printf("10. chn sort\n");
    printf("11. all sort\n");
    printf("12. get student information by id\n");
    printf("0. Exit\n");
    scanf("%d",&op);
    
    while(getchar()!='\n')
    {        
    }
    
    return op;
}


/*input_username函数定义*/
int get_username(char *pout)
{
    printf("Please input your name:\n");
    scanf("%s",pout);
    
    while(getchar()!='\n')
    {        
    }
    return 0;
}
/*input_password函数定义*/
/*input_id函数定义*/


void print_errmsg(char *pstr)
{
    printf("%s",pstr);
}


void show_login_fail(){
    printf("login fail, login again\n");
}
void show_passwd_not_right(){
    printf("passwd is not right,input again\n");
}
void show_no_this_stud(){
    printf("no such student,login again\n");
}
void show_login_success(){
    printf("login success,\n");
}

int get_login_stud_passwd(char *passwd){
    printf("Please input your passwd:\n");
    scanf("%s",passwd);
    
    while(getchar()!='\n')
    {        
    }
    return 0;
}

int show_input_new_passwd(char *passwd){
    printf("Please input your new passwd:\n");
    scanf("%s",passwd);
    
    while(getchar()!='\n')
    {        
    }
    return 0;
}

int show_input_new_info(struct stu_node *p_stu){
    printf("Please input your new name:\n");
    scanf("%s",p_stu->data.name);
    
    while(getchar()!='\n')
    {        
    }
    
    printf("Please input your new sex:\n");
    scanf("%c",&p_stu->data.sex);
    while(getchar()!='\n')
    {        
    }

    printf("Please input your new chn_score:\n");
    scanf("%f",&p_stu->data.chn_score);
    while(getchar()!='\n')
    {        
    }

    printf("Please input your new math_score:\n");
    scanf("%f",&p_stu->data.math_score);
    while(getchar()!='\n')
    {        
    }

    printf("Please input your new eng_score:\n");
    scanf("%f",&p_stu->data.eng_score);
    while(getchar()!='\n')
    {        
    }
    return 0;
}

void show_change_success(){
    printf("change success\n");
}


int show_one_stu_infor(struct stulist_head *phead,struct stu_node *pnode){
	if(node_is_in(phead,pnode) != NULL ){
		printf("id %d\n ",pnode->data.id);
		printf("name %s\n ",pnode->data.name);
		printf("passwd ***\n ");
		printf("sex %c\n",pnode->data.sex);
		printf("chn_score %f\n",pnode->data.chn_score);
		printf("math_score %f\n",pnode->data.math_score);
		printf("eng_score %f\n",pnode->data.eng_score);
	}
	return 0;
}

int show_all_stu_info(struct stulist_head *phead, struct stu_node **ppnode){
    int i = 0;
    while( i < phead->len){
        printf("id %d\n ",(*(ppnode+i))->data.id);
		printf("name %s\n ",(*(ppnode+i))->data.name);
		printf("passwd ***\n ");
		printf("sex %c\n",(*(ppnode+i))->data.sex);
		printf("chn_score %f\n",(*(ppnode+i))->data.chn_score);
		printf("math_score %f\n",(*(ppnode+i))->data.math_score);
		printf("eng_score %f\n",(*(ppnode+i))->data.eng_score);
        printf("\n");
        i++;
    }
    return 0;
}

int show_get_id(int *number){
    printf("Please input id you want deleta:\n");
    scanf("%d",number);
    return 0;
}

int show_delete_fail(){
    printf("delete fail\n");
}
int show_delete_success(){
    printf("delete success\n");
}
/*print_all_student_byid函数定义*/
/*print_all_student_aftersort函数定义*/
//。。。。。
