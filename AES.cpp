#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct AESnum{
   int bit[64];
   int len;
   int turntobit(int num)
   {
       len = 0;
       for(int i = 0;i < 32; i++)
       {
           bit[i] = (num>>i) & 1;
           if(bit[i])
           len = i + 1;
       }
   }
   ll turntodec()
   {
       ll res = 0;
       for(int i = 0; i < len; i++)
       {
           res += ((ll)bit[i]<<i);
       }
       return res;
   }
   AESnum(int x)
   {
       turntobit(x);
   }
   AESnum()
   {
       memset(bit,0,sizeof(bit));
       len = 0;
   }
   AESnum operator +(AESnum x)
   {
        AESnum c;
        c.len = max(len,x.len);
        for(int i = 0; i < c.len;i++)
        {
            c.bit[i] = bit[i] ^ x.bit[i];
        }           
        return c;
   }
   AESnum operator *(AESnum x)
   {
       AESnum c;
       for(int i = 0; i < len; i++)
        for(int j = 0; j < x.len;j++)
        {
            c.bit[i+j] ^= bit[i]&x.bit[j];
        }
        for(int i = 63; i >=0; i--)
        {
            if(c.bit[i])
            {
                c.len = i + 1;
                break;
            }
        }
        return  c;
   }
};
int main()
{
    int x,y;
    cin >> x >> y;
    AESnum a(x),b(y);
    AESnum c;
    c = a + b;
    printf("%xH\n",c.turntodec());
    c = a * b;
    printf("%xH\n",c.turntodec());
    system("pause");
    return 0;
}