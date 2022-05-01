#include "main.h"


int mainloop(struct stulist_head *phead);

//main.c
int main(int argc,char *argv[])
{
    //int ret = 0;
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
        op = display_main_ui();
        switch(op)
        {
            case 1://进行登录
                p_stu = login(phead);
                break;
            case 2://插入假的数据
                insert_stu(phead);
                break;
            case 3://修改自身的登录密码
                change_passwd(phead,p_stu);
                break;
            case 4://查阅自身信息
                get_myinfo(phead,p_stu);
                break;
            case 5://删除学生
                remove_stu(phead,p_stu);
                break;
            case 6://修改个人信息
                change_info(phead,p_stu);
                break;
            case 7://按照学号低到高
                printf_sort_by_id(phead);
                break;
            case 8://英语
                printf_sort_by_eng_score(phead);
                break;
            case 9://数学
                printf_sort_by_math_score(phead);
                break;
            case 10://语文
                printf_sort_by_chn_score(phead);
                break;
            case 11://总分
                printf_sort_by_all_score(phead);
                break;
            case 12://获取学生信息
                remove_stu(phead,p_stu);
                break;
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

