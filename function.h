#include<stdio.h>
#include<string.h>
void print_menu()
{
    printf("************学生成绩系统菜单***********************\n");
    printf("*\t1. 按姓名排序，输出                       *\n");
    printf("*\t2. 按平均成绩排序，输出                   *\n");
    printf("*\t3. 输出给定学院学生                       *\n");
    printf("*\t4. 添加学生及其成绩                       *\n");
    printf("*\t5. 修改给定学生成绩信息                   *\n");
    printf("*\t6. 按姓名查询学生，输出                   *\n");
    printf("*\t7. 删除学生成绩                           *\n");
    printf("*\t8. 修改系统密码                           *\n");
    printf("*\t9. 输出挂科学生信息并强调其挂掉的科目     *\n");
    printf("*\t0. 返回上一级菜单                         *\n");
    printf("***************************************************\n");
    
}
void choose_menu()
{   
    void log_in();
    void print_menu();
    void choose_menu();
    print_menu();

    int option;
    printf("请输入数字0-9进入菜单:\n");
    scanf("%d",&option);
    
    switch(option)
    {   
        case 1:
        {
            printf("1");
            break;
        }
        case 2:
        {
            //
            break;
        }
        case 3:
        {
            //
            break;
        }
        case 4:
        {
            //
            break;
        }
        case 5:
        {
            //
            break;
        }
        case 6:
        {
            //
            break;
        }
        case 7:
        {
            //
            break;
        }
        case 8:
        {
            //
            break;
        }
        case 9:
        {
            //
            break;
        }
        case 0:
        {
            log_in();
            choose_menu();
            break;
        }

        
        


        
    }
}
void log_in()
{   
    FILE *fp_p;
    char password[32],password_get[32];
    fp_p=fopen("password.txt","r+");
    // if(fp_p==NULL)
    // {
    //     printf("文件打开失败,请输入密码\n");
    //     scanf("%s",password);
    //     fclose(fp_p);
    //     fp_p=fopen("password.txt","w+");
    //     fprintf(fp_p,"%s",password);
    // }
    fscanf(fp_p,"%s",password);

    printf("你好,请输入登录密码:\n");
    scanf("%s",password_get);

    while(strcmp(password,password_get)!=0)
    {
        printf("密码错误,请重新输入:\n");
        scanf("%s",password_get);

    }

    printf("密码正确,登录成功!\n");
    fclose(fp_p);
    

}


// void get_password()
// {
//     FILE *fp_p;
//     char password[32];

//     fp_p=fopen("password.txt","r+");
//     if(fp_p==NULL)
//     {
//         printf("文件打开失败,请输入密码\n");
//         scanf("%s",password);
//         fp_p=fopen("password.txt","w+");
//         fprintf(fp_p,password);
    


//     }


//     fclose(fp_p);
// }
