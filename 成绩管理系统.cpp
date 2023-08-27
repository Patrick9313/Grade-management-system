#include<iostream>
#define MAXN 61
using namespace std;
char *bixiu[] = { "必修1", "必修2", "必修3", "必修4", "必修5", "必修6" };
char *xuanxiu[] = { "选修1", "选修2", "选修3", "选修4" };
float score[MAXN][10];
float epsilon = 0.01;
float weight[10] = { 0.15, 0.15, 0.15, 0.15, 0.15, 0.15, 0.05, 0.05, 0.05, 0.05 };
int n;

void statbixiu()
{
    for (int i = 0; i < 6; i++)
    {
        float ave = 0;
        for (int j = 0; j < n; j++)
        {
            ave += score[j][i];
        }

        cout<<bixiu[i]<<"的平均成绩是"<<ave/n<<endl;
    }
}

void statxuanxiu()
{
    for (int i = 0; i < 4; i++)
    {
        float ave = 0;
        int m = 0;
        for (int j = 0; j < n; j++)
        {
            if (score[j][i + 6] >= epsilon)
            {
                ave += score[j][i + 6];
                m++;
            }
        }
        if (m == 0)

            cout<<xuanxiu[i]<<"没有人选"<<endl;
        else

            cout<<xuanxiu[i]<<"的平均成绩是"<<ave/m<<endl;
    }
}

float calcscore(int id)
{
    float sum = 0;
    for (int i = 0; i < 10; i++)
        sum += score[id][i] * weight[i];
    return sum;
}

void award()
{
    int order[MAXN];
    int rank[MAXN];
    for (int i = 0; i < n; i++)
    {
        order[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (calcscore(order[j]) < calcscore(order[j + 1]))
            {
                int t = order[j];
                order[j] = order[j + 1];
                order[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        rank[order[i]] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {

        cout<<i+1<<"号学生是第"<<rank[i]<<"名"<<endl;
    }
}

int main()
{
    cout<<"请输入学生人数（<=60人）：";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            cout<<"请输入第"<<i+1<<"个学生的"<<bixiu[j]<<"的成绩";
            cin>>score[i][j];
        }
        for (int j = 0; j < 4; j++)
        {

            cout<<"请输入第"<<i+1<<"个学生的"<<xuanxiu[j]<<"的成绩（如果没有选，请输入0）：";
            cin>>score[i][j+6];
        }
    }
    statbixiu();
    statxuanxiu();
    award();
    return 0;
}

