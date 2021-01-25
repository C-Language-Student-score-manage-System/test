#include<stdio.h>
#include<string.h>
struct collage
{
    int collage_id;
    char collage_name[32];
};
struct sex
{
    int sex_id;
    char sex_name[32];
};
struct score
{
    int score_id;
    char score_name[32];
};
typedef struct stu
{
    long stu_id;
    char stu_name[32];
    struct score;
    struct sex;
    struct collage;
}STU[1024];
