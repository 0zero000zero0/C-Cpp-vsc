#include <bits/stdc++.h>

using namespace std;
void transformToLower( string &s )
{
    transform( s.begin(), s.end(), s.begin(), []( char c ) { return tolower( c ); } );
}
int main()
{
    // 定义两个字符串
    string source;
    string instance;
    getline( cin, source );
    getline( cin, instance );
    transformToLower( source );
    transformToLower( instance );
    // 因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
    // 把单词之间隔开
    source = ' ' + source + ' ';
    instance = ' ' + instance + ' ';
    // 先看看会不会找不到，用a.find()和string::npos
    if ( instance.find( source ) == string::npos )
    {
        cout << -1 << endl;
    }
    // 如果找得到
    else
    {
        int firstPlace = instance.find( source );
        int beta = instance.find( source ), cnt = 0;  // 计数器初始化为0
        while ( beta != string::npos )
        {
            ++cnt;                                     // 计数器
            beta = instance.find( source, beta + 1 );  // 从下一个位置开始找
        }
        cout << cnt << " " << firstPlace << endl;  // 输出第一个和总共有几个
    }
    return 0;
    // 函数返回值为0，结束整个程序
}