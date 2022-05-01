# 一、项目需求

本项目管理多个学员的信息，每个学员应该包括如下成员属性数据：姓名、密码、学号、性别、数学、语文、英语三门功课成绩

学员登录后可以进行如下操作：

1. ok 登录
2. ok修改自身登录密码
3. ok添加新学生（不登录也可操作，其它功能必须登录后才能进行）
4. ok查阅自身信息
5. ok删除学生（输入学号）
6. ok查阅指定学生信息（输入学号）（密码不打印）
7. ok修改自己的信息（姓名、性别、三门功课成绩）
8. ok按学号从低到高查看所有学生信息（密码不打印）
9. ok按数学成绩从高到低查看所有学生信息（密码不打印）
10. ok按语文成绩从高到低查看所有学生信息（密码不打印）
11. ok按英语成绩从高到低查看所有学生信息（密码不打印）
12. ok按总分从高到低查看所有学生信息（密码不打印）

# 二、项目设计

1. ## 总体思路------MVC模式

   Model模块、Viewer模块、Controller模块

   完成顺序：

   ok1，编写链表的增删改查功能

   ok 2，显示功能

   ok 3，main函数显示主菜单，查找菜单

   头文件包含

   ok4，通过名字+密码登录 login.c login.h

   ok5，插入假的数据

   ok login的测试

   排序：思路：

   1，创建数组，保存地址，通过qsort的方式进行排序，自己写比较
2. ## 源码结构：

   sims\

   inc\  ------- 头文件

   student_list.h

   viewer.h

   model\

   student_list.c

   viewer\

   viewer.c  视图控制函数

   controller\

   main.c  整合文件

   op.c   拼装函数

   controller.h

   sims\

   inc\  ------- 头文件

   student_list.h

   viewer.h

   model\

   student_list.c

   viewer\

   viewer.c  视图控制函数

   controller\

   main.c  整合文件

   op.c   拼装函数

   controller.h

   3.要求：

   a.  不许使用全局变量

   b. 除去viewer.c中外，其它.c不许见scanf

# 三、时间安排

| 时间     | 任务                                   |
| -------- | -------------------------------------- |
| 3.4 晚   | 看文档，理清实现思路                   |
| 3.5 上午 | student_list.c                         |
| 3.5 下午 | controller/main.c  controller/op.c-50% |
| 3.5 晚上 | controller/op.c -50%                   |
| 3.6 上午 | 验证改bug                              |
|          |                                        |
|          |                                        |

# 四、代码示例

```c
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
	int cnt;
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

#endif
```

```c
//main.c
int main(int argc,char *argv[])
{
    int ret = 0;
    struct stulist_head *phead = create_stulist_head();  
  
    mainloop(phead);
 
    destroy_stulist_head(phead);
    phead = NULL;
    return 0;
}

int mainloop(struct stulist_head *phead)
{
    int op = 0;
    int exitflag = 0;
    int ret = 0;
    struct stu_node *p_stu = NULL;//登录成功的学生节点
  
    while(1)
    {
        op = display_main_ui()
        switch(op)
        {
            case 1:
                p_stu = login();
                break;
            case 2:
                break;
            case 3:
                break;
            //.......
            case 0:
                exitflag = 1;
                break;
        }
        if(exitflag)
        {
            break;
        }
    }
  
    return 0;
}
```

```c
//op.c
/*login函数定义*/
struct stu_node *login()
{
    //调用输入名字的函数
    //查找节点
    //调用输入密码的函数
    //。。。。
}

//其它功能函数
```

```c
//view.c

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
    printf("Please select your operation:\n");
    printf("1. Update Password\n");
    printf("2. Add a new student\n");
    printf("3. Query your information\n");
    .......
    printf("0. Exit\n");
    scanf("%d",&op);
  
    while(getchar()!='\n')
    {  
    }
  
    return op;
}


/*input_username函数定义*/
int input_username(char *pout)
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


/*print_all_student_byid函数定义*/
/*print_all_student_aftersort函数定义*/
//。。。。。
```
