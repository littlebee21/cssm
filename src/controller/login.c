#include "login.h"

//op.c
/*login函数定义*/
struct stu_node *login(struct stulist_head *phead)
{   
    char name[NAME_LEN] = "\0";
    char passwd[PASS_LEN] = "\0";
    struct stu_node * pstu_node = NULL;
    get_username(name);

	if(phead->pfirst == NULL){
		insert_stu(phead);
	}

    //让他可以重复登陆三次
    int i = 0;
    for(i=0;i<3;i++){
        get_login_stud_passwd(passwd);

		pstu_node = search_stu_by_name(phead,name);
        if(pstu_node == NULL){
            show_no_this_stud();
            return NULL;
        }
        if(strcmp(pstu_node->data.passwd,passwd) != 0){
            show_passwd_not_right();
            continue;
        }
        show_login_success();
        return pstu_node;
    }
    show_login_fail();
    return NULL;
}

//插入5个人的数据
int insert_stu(struct stulist_head * phead){
    struct stu_data *pdata = NULL;
    struct stu_node *pnode =  NULL;
    pdata = (struct stu_data *)malloc(sizeof(struct stu_data));

    pdata->id = 1;
    strcpy(pdata->name,"li");
    strcpy(pdata->passwd,"123456");
    pdata->sex = 'm';
    pdata->chn_score = 98;
    pdata->math_score  = 99;
    pdata->eng_score = 66;
	pnode = create_stu_node(pdata);
    insert_stu_node_attail(phead,pnode);

    pdata->id = 2;
    strcpy(pdata->name,"wang");
    strcpy(pdata->passwd,"123456");
    pdata->sex = 'm';
    pdata->chn_score = 47;
    pdata->math_score  = 39;
    pdata->eng_score = 66;
	pnode = create_stu_node(pdata);
    insert_stu_node_attail(phead,pnode);

    pdata->id = 3;
    strcpy(pdata->name,"zhao");
    strcpy(pdata->passwd,"123456");
    pdata->sex = 'm';
    pdata->chn_score = 78;
    pdata->math_score  = 53;
    pdata->eng_score = 92;
	pnode = create_stu_node(pdata);
    insert_stu_node_attail(phead,pnode);


    pdata->id = 4;
    strcpy(pdata->name,"gao");
    strcpy(pdata->passwd,"123456");
    pdata->sex = 'm';
    pdata->chn_score = 18;
    pdata->math_score  = 59;
    pdata->eng_score = 26;
	pnode = create_stu_node(pdata);
    insert_stu_node_attail(phead,pnode);

    pdata->id = 5;
    strcpy(pdata->name,"qiu");
    strcpy(pdata->passwd,"123456");
    pdata->sex = 'm';
    pdata->chn_score = 77;
    pdata->math_score  = 59;
    pdata->eng_score = 76;
	pnode = create_stu_node(pdata);
    insert_stu_node_attail(phead,pnode);

    return 0;
}


//修改自身的登录密码
int change_passwd(struct stulist_head *phead,struct stu_node *p_stu){
    if(p_stu == NULL){
        login(phead);
    }
    if(phead->pfirst == NULL){
        insert_stu(phead);
    }
    char passwd[30] = "\0";
    show_input_new_passwd(passwd);
    strcpy(p_stu->data.passwd,passwd);
    show_change_success();
    return 0;
}

//获取个人数据 ，通过节点
void get_myinfo(struct stulist_head *phead,struct stu_node *p_stu){
    //没登陆，去登陆
    if(p_stu == NULL){
        login(phead);
    }
    if(phead->pfirst == NULL){
        insert_stu(phead);
    }
    show_one_stu_infor(phead,p_stu);
}



int remove_stu(struct stulist_head *phead,struct stu_node *p_stu){
     //没登陆，去登陆
    if(p_stu == NULL){
        login(phead);
    }
    if(phead->pfirst == NULL){
        insert_stu(phead);
    }
    int id = 0;//用于记录学号
    show_get_id(&id);
	printf("remove id is %d\n",id);
    struct stu_node *pnode = NULL;
    pnode = search_stu_by_id(phead,id);
    if(pnode == NULL){
        show_delete_fail();
        return -1;
    }
    remove_stu_node(phead,pnode);
    if(destroy_stu_node(pnode) ==0)
        show_delete_success();
    return 0;
}


//通过学号的方式获取信息
int get_stu_info(struct stulist_head *phead,struct stu_node *p_stu){
    //没登陆，去登陆
    if(p_stu == NULL){
        login(phead);
    }
    if(phead->pfirst == NULL){
        insert_stu(phead);
    }
    int number = 0;//用于记录学号
    show_get_id(&number);

    struct stu_node *pnode = NULL;
    pnode = search_stu_by_id(phead,number);
    if(pnode == NULL){
        printf("no such people\n");
        return -1;
    }
    show_one_stu_infor(phead,pnode);
    return 0;
}


//修改自身信息
int change_info(struct stulist_head *phead,struct stu_node *p_stu){
    if(p_stu == NULL){
        login(phead);
    }
    if(phead->pfirst == NULL){
        insert_stu(phead);
    }
    if(show_input_new_info(p_stu) != 0){
        return -1;
    }
    show_change_success();
    return 0;
}

//id
int printf_sort_by_id(struct stulist_head *phead){
	//分配内存空间数组
	struct stu_node **ppnode =NULL;
	ppnode = (struct stu_node **)malloc(phead->len * sizeof(struct stu_node *));
	if(ppnode == NULL){
		return -1;
		printf("malloc fail\n");
	}
	memset(ppnode,0,sizeof(phead->len * sizeof(struct stu_node *)));
    //对链表数组进行排序
    sort_by_id(phead,ppnode);
    //对链表进行打印
    show_all_stu_info(phead,ppnode);
	printf("show success\n");
	free(ppnode);
	return 0;
}

//语文
int printf_sort_by_chn_score(struct stulist_head *phead){
	//分配内存空间数组
	struct stu_node **ppnode =NULL;
	ppnode = (struct stu_node **)malloc(phead->len * sizeof(struct stu_node *));
	if(ppnode == NULL){
		return -1;
		printf("malloc fail\n");
	}
	memset(ppnode,0,sizeof(phead->len * sizeof(struct stu_node *)));
    //对链表数组进行排序
    sort_by_chn_score(phead,ppnode);
    //对链表进行打印
    show_all_stu_info(phead,ppnode);
	free(ppnode);
	return 0;
}

//英语
int printf_sort_by_eng_score(struct stulist_head *phead){
	//分配内存空间数组
	struct stu_node **ppnode =NULL;
	ppnode = (struct stu_node **)malloc(phead->len * sizeof(struct stu_node *));
	if(ppnode == NULL){
		return -1;
		printf("malloc fail\n");
	}
	memset(ppnode,0,sizeof(phead->len * sizeof(struct stu_node *)));
    //对链表数组进行排序
    sort_by_eng_score(phead,ppnode);
    //对链表进行打印
    show_all_stu_info(phead,ppnode);
	free(ppnode);
	return 0;
}

//数学
int printf_sort_by_math_score(struct stulist_head *phead){
	//分配内存空间数组
	struct stu_node **ppnode =NULL;
	ppnode = (struct stu_node **)malloc(phead->len * sizeof(struct stu_node *));
	if(ppnode == NULL){
		return -1;
		printf("malloc fail\n");
	}
	memset(ppnode,0,sizeof(phead->len * sizeof(struct stu_node *)));
    //对链表数组进行排序
    sort_by_math_score(phead,ppnode);
    //对链表进行打印
    show_all_stu_info(phead,ppnode);
	free(ppnode);
	return 0;
}
//总分
int printf_sort_by_all_score(struct stulist_head *phead){
	//分配内存空间数组
	struct stu_node **ppnode =NULL;
	ppnode = (struct stu_node **)malloc(phead->len * sizeof(struct stu_node *));
	if(ppnode == NULL){
		return -1;
		printf("malloc fail\n");
	}
	memset(ppnode,0,sizeof(phead->len * sizeof(struct stu_node *)));
    //对链表数组进行排序
    sort_by_all_score(phead,ppnode);
    //对链表进行打印
    show_all_stu_info(phead,ppnode);
	free(ppnode);
	return 0;
}
