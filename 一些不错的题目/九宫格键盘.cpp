#include <cstdio>
int  sum, i, n;
char x, a[] = { 'a', 'p', 't', 'w', 'z' + 1 };
// 边界以九宫格键盘上键帽上的数字为分割,2-6上只有3个字母,对应的字母是a-o,因此分割是q.这样就把整个字母表分成了4个区间,只需要取余区间中键帽上的个数就能找到按下的次数(不过要+1)
int main()
{
    while ( scanf( "%c", &x ) != EOF )
        if ( x >= 'a' )
        {
            for ( i = 0; i < 4 && x >= a[i + 1]; ++i )  // 寻找区间
                ;
            sum += ( x - a[i] ) % ( ( i & 1 ) + 3 ) + 1;
            // i&1:首先如果i=0,也就是在第一个区间中,那么直接加3就能找到每一个键帽上的字母个数,如果在后面的区间里,i&1判断是否为奇数,如果是奇数,那么就有4个字母,i&1的结果也就是1,如果为偶数,i&1结果是0,对应数字8上面有3个字母.
        }
        else if ( x == ' ' )
            ++sum;
    printf( "%d", sum );
    return 0;
}