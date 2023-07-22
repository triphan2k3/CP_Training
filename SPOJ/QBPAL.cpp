#include <iostream>

using namespace std;

string s;
string dp[130][130];

string add(string a,string b)
{
    while (a.length()<b.length()) a="0"+a;
    while (a.length()>b.length()) b="0"+b;
    int t=a.length();
    int temp;
    int carry=0;
    string c="";
    for (int i=t-1;i>=0;i--)
    {
        temp=carry+int(a[i])+int(b[i])-2*48;
        carry=temp/10;
        c=char(temp%10+48)+c;
    }
    if (carry!=0) c="1"+c;
    return c;
}
string sub(string a,string b)
{
    while (a.length()<b.length()) a="0"+a;
    while (a.length()>b.length()) b="0"+b;
    int t=a.length();
    int temp;
    int carry=0;
    string c="";
    for (int i=t-1;i>=0;i--)
    {
        temp=int(a[i])-int(b[i])-carry;
        if (temp<0)
        {
            carry=1;
            temp+=10;
        } else carry=0;
        c=char(temp+48)+c;
    }
    while (c[0]=='0'&&c.length()>1)
        c.erase(0,1);
    return c;
}
int main()
{
    cin >>s;
    int t=s.length();
    for (int i=0;i<t;i++)
        dp[i][i]="1";



    int k;
    string s2;
    for (int i=2;i<=t;i++)
        for (int j=0;j<=t-i;j++)
    {
        k=j+i-1;
        s2=add(dp[j+1][k],dp[j][k-1]);
        if (s[j]!=s[k])
             dp[j][k]=sub(s2,dp[j+1][k-1]);
        else dp[j][k]=add(s2,"1");
    }
    cout << dp[0][t-1];
}
