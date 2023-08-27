#include<iostream>
#define MAXN 61
using namespace std;
char *bixiu[] = { "����1", "����2", "����3", "����4", "����5", "����6" };
char *xuanxiu[] = { "ѡ��1", "ѡ��2", "ѡ��3", "ѡ��4" };
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

        cout<<bixiu[i]<<"��ƽ���ɼ���"<<ave/n<<endl;
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

            cout<<xuanxiu[i]<<"û����ѡ"<<endl;
        else

            cout<<xuanxiu[i]<<"��ƽ���ɼ���"<<ave/m<<endl;
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

        cout<<i+1<<"��ѧ���ǵ�"<<rank[i]<<"��"<<endl;
    }
}

int main()
{
    cout<<"������ѧ��������<=60�ˣ���";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            cout<<"�������"<<i+1<<"��ѧ����"<<bixiu[j]<<"�ĳɼ�";
            cin>>score[i][j];
        }
        for (int j = 0; j < 4; j++)
        {

            cout<<"�������"<<i+1<<"��ѧ����"<<xuanxiu[j]<<"�ĳɼ������û��ѡ��������0����";
            cin>>score[i][j+6];
        }
    }
    statbixiu();
    statxuanxiu();
    award();
    return 0;
}

