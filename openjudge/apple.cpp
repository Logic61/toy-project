#include<iostream>

int m,n,ans=0;

void solve(int a,int b,int maximum)
{
    if(b == 0)
    {
        return;
    }

    for(int j = 1; j <=a; j += 1)
    {
        if(j > maximum)
        {
            break;
        }

        a -= j;

        if(a == 0)
        {
            ans += 1;
            a+=j;
            continue;
        }
        else if(a < 0)
        {
            break;
        }

        solve(a,b-1,j);

        a+=j;
    }    
}

int main()
{
    int time;
    std::cin >> time;
    for(int i = 0; i < time; ++i)
    {
        ans = 0;
        std::cin >> m >> n;
        solve(m,n,m);
        std::cout << ans << std::endl;
    }

    return 0;
}