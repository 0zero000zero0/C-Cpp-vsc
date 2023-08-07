#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
struct fantastic
{
    int size, ans[9999];
    fantastic()
    {
        memset( ans, 0, sizeof( ans ) );
        size = 1;
    }
    fantastic operator=( const char *num )  // 重载=,实现string to int
    {
        size = strlen( num );
        for ( int i = 0; i < size; ++i )
            ans[i] = num[size - i - 1] - '0';
        return *this;
    }
    fantastic operator=( const int num )  // int to int[]
    {
        char a[9999];
        sprintf( a, "%d", num );
        *this = a;  // 调用上面的stoi
        return *this;
    }
    fantastic( const int num )
    {
        *this = num;
    }
    fantastic( const char *num )
    {
        *this = num;
    }
    fantastic operator+( const fantastic &a )  // 重载 “+” 的运算
    {
        fantastic temp;
        temp.size = max( size, a.size ) + 1;  // 竖式模拟
        for ( int i = 0, t = 0; i < temp.size; ++i )
        {
            temp.ans[i] = ans[i] + a.ans[i] + t;
            t = temp.ans[i] / 10;
            temp.ans[i] = temp.ans[i] % 10;
        }
        if ( temp.ans[temp.size - 1] == 0 )
            --temp.size;
        return temp;
    }
    fantastic operator*( const fantastic &x )  // 然后再来波 “*” 的运算
    {
        fantastic temp;
        temp.size = size + x.size;  // 又是我们熟悉的竖式模拟
        for ( int i = 0; i < size; ++i )
            for ( int j = 0; j < x.size; ++j )
            {
                temp.ans[i + j] += ans[i] * x.ans[j];
                temp.ans[i + j + 1] += temp.ans[i + j] / 10;
                temp.ans[i + j] %= 10;
            }
        if ( temp.ans[temp.size - 1] == 0 )
            --temp.size;
        return temp;
    }
};
ostream &operator<<( ostream &out, const fantastic &x )  // 重载输出
{
    for ( int i = x.size - 1; i >= 0; --i )
        cout << x.ans[i];
    return out;
}
istream &operator>>( istream &in, fantastic &x )  // 重载输入
{
    char num[9999];
    in >> num;
    x = num;
    return in;
}
int main()
{
    int       n = 5;
    fantastic ans = 0, num = 1;
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        num = num * i;
        ans = ans + num;
    }
    cout << ans << endl;
}