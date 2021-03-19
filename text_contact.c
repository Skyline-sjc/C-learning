#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADRR_MAX 30
#define MAX 1000
#define N 1000
//通讯录
//保存1000个人信息：名字、年龄、电话、性别、住址
//功能：1、增加个人信息；2、删除个人信息（指定的）；3、查找指定联系人；4、修改指定的联系人信息
//5、显示通讯录中所有人的信息；6、排序所有人的信息；7、退出
//类型的定义放在头文件里
typedef struct PeoInfo
{
    char name[NAME_MAX];
    int age;
    char sex[SEX_MAX];
    char tele[TELE_MAX];
    char adrr[ADRR_MAX];
} Peoinfo; //描述个人信息的结构体
typedef struct contact
{
    Peoinfo *data;
    int sz;         //表示当前存放的人的信息个数
    int max_people; //表示最多存放人数
} contact;
enum option //利用枚举增加程序可读性
{
    exit,    //0
    add,     //1
    del,     //2
    search,  //3
    modify,  //4
    show,    //5
    sort,    //6
    clean,   //7
    create,  //8
    enlarge, //9
    save     //10
};
void menu();
void InitContact(contact *);              //初始化通讯录
void AddContact(contact *);               //增加个人信息
void ShowContact(contact *);              //可视化通讯录
void DelContact(contact *);               //删除个人信息
int FindPeoInfoByName(contact *, char *); //寻找个人信息
void SearchContact(contact *);            //寻找个人
void ModifyContact(contact *);            //修改个人信息
void SortContact(contact *);              //按姓名字典序排序
void CleanContact(contact *);             //清空通讯录
int EnlargeContact(contact *);            //扩容通讯录
void SaveContact(contact *);              //将通讯录信息储存
void LoadContact(contact *);              //加载已经储存的通讯录
void CheckContact(contact *);             //检查通讯录是否已经装载满
int main()
{
    int input = 0;
    contact con;
    InitContact(&con);
    LoadContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case add:
            AddContact(&con);
            break;
        case del:
            DelContact(&con);
            break;
        case search:
            SearchContact(&con);
            break;
        case modify:
            ModifyContact(&con);
            break;
        case sort:
            SortContact(&con);
            break;
        case show:
            ShowContact(&con);
            break;
        case clean:
            CleanContact(&con);
        case create:
            InitContact(&con);
        case enlarge:
            EnlargeContact(&con);
        case save:
            SaveContact(&con);
        case exit:
            break;
        }
    } while (input);
}
void menu()
{
    printf("*********************************\n");
    printf("*******1.add       2.del*********\n");
    printf("*******3.search    4.modify******\n");
    printf("*******5.show      6.sort********\n");
    printf("*******7.clean     8.create******\n");
    printf("*******9.enlarge   10.save*******\n");
    printf("*******0.exit      **************\n");
    printf("*********************************\n");
}
void InitContact(contact *pc)
{
    pc->sz = 0;
    printf("请输入你需要的通讯录大小:>\n");
    scanf("%d", &(pc->max_people));
    pc->data = (Peoinfo *)malloc(sizeof(Peoinfo) * pc->max_people);
    if (pc->data == NULL)
    {
        printf("创建失败\n");
    }
    else
    {
        printf("创建成功\n");
    }
}
void AddContact(contact *pc)
{
    CheckContact(pc);
    printf("请输入名字:>");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入年龄:>");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("请输入性别:>");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入电话:>");
    scanf("%s", pc->data[pc->sz].tele);
    printf("请输入地址:>");
    scanf("%s", pc->data[pc->sz].adrr);
    pc->sz += 1;
    printf("添加成功\n");
}
void ShowContact(contact *pc)
{
    int i = 0;
    printf("%15s\t %5s\t %5s\t %12s\t %20s\n", "名字", "年龄", "性别", "电话", "地址");
    for (i = 0; i < pc->sz; i++)
    {
        printf("%15s\t %d\t %5s\t %12s\t %20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].adrr);
    }
}
int FindPeoInfoByName(contact *pc, char *name) //封装查找过程
{
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        if (pc->data[i].name == name)
        {
            return i; //如果找到返回地址
        }
    }
    if (i == pc->sz)
    {
        return -1; //未找到返回-1
    }
}
void DelContact(contact *pc)
{
    char name[NAME_MAX] = {0};
    if (pc->sz == 0)
    {
        printf("通讯录为空,无法删除\n");
    }
    else
    {
        printf("请输入要删除人的名字:>\n");
        scanf("%s", name);
        int pos = FindPeoInfoByName(pc, name); //找到个人数据
        if (pos == -1)
        {
            printf("被删除的人不存在\n");
        }
        else
        {
            //删除
            int j = 0;
            for (j = pos; j < pc->sz - 1; j++)
            {
                pc->data[j] = pc->data[j + 1]; //整体前移
            }
        }
    }
}
void SearchContact(contact *pc)
{
    char name[NAME_MAX];
    scanf("%s", name);
    int pos = FindPeoInfoByName(pc, name);
    if (pos == -1)
    {
        printf("查无此人！\n");
    }
    else
    {
        printf("%s\t %s\t %s\t %s\t %s\n", "名字", "年龄", "性别", "电话", "地址");
        printf("%s\t %d\t %s\t %s\t %s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].adrr);
    }
}
void ModifyContact(contact *pc)
{
    char name[NAME_MAX];
    scanf("%s", name);
    int pos = FindPeoInfoByName(pc, name);
    if (pos == -1)
    {
        printf("要修改的人不存在\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", pc->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", &(pc->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", pc->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", pc->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", pc->data[pos].adrr);
        printf("修改成功\n");
    }
}
void SortContact(contact *pc) //冒泡排序，此处可更改为快速排序以减少时间消耗
{
    int i = 0, j = 0;
    Peoinfo temp;
    for (i = 0; i < pc->sz; i++)
    {
        int flag = 1;
        for (j = 0; j < pc->sz - 1 - i; j++)
        {
            if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
            {
                temp = pc->data[j];
                pc->data[j] = pc->data[j + 1];
                pc->data[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}
void CleanContact(contact *pc) //直接释放动态开辟的空间
{
    free(pc->data);
    pc->sz = 0;
    printf("清空完成\n");
}
int EnlargeContact(contact *pc)//更改为int类型防止扩容失败造成程序的崩溃
{
    Peoinfo *temp = NULL;
    temp = (Peoinfo *)realloc(pc->data, pc->max_people * 2);
    if (temp == NULL)
    {
        printf("扩容失败\n");
        return 0;
    }
    else
    {
        pc->data = temp;
        pc->max_people *= 2;
        return 1;
    }
}
void SaveContact(contact *pc)
{
    FILE *pfOUT = fopen("C:\\Users\\user\\Desktop\\contact.dat", "wb");
    if (pfOUT == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    int i = 0;
    for (i = 0; i < pc->sz; i++)
    {
        fwrite(pc->data + 1, sizeof(Peoinfo), 1, pfOUT);//循环输入通讯录到文件
    }
    printf("保存成功\n");
}
void LoadContact(contact *pc)
{
    FILE *pfIN = fopen("C:\\Users\\user\\Desktop\\contact.dat", "rb");
    if (pfIN == NULL)
    {
        printf("LoadContact::%s\n", strerror(errno));//优化，便于用户理解错误发生原因
        return;
    }
    Peoinfo temp = {0};
    while (fread(&temp, sizeof(Peoinfo), 1, pfIN))//利用循环添加文件中的已有通讯录
    {
        CheckContact(pc);
        pc->data[pc->sz] = temp;
        pc->sz++;
    }
}
void CheckContact(contact *pc)
{
    if (pc->sz == pc->max_people)
    {
        int temp = EnlargeContact(pc);
        while (temp == 0)//利用循环反复扩容直至成功
        {
            temp = EnlargeContact(pc);
        }
        printf("扩容成功\n");
    }
    else
    {
        return;
    }
}