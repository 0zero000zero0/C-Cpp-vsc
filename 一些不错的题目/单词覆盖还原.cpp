// P1321 in:..boyogirlyy..bogirl  out:4 \n 2
#include <cstdio>
char s[256], *sex[] = { "boy", "girl" }, count[2];
int  main()
{
    scanf( "%s", s );
    for ( int i = 0; i < 2; ++i )
        for ( char *p = s; *p; ++p )
            for ( char *q = sex[i], *r = p; *q && *r; ++q, ++r )
                if ( *q == *r )
                {
                    ++count[i];
                    break;
                }
    // 由于每次遍历时s,q都会被重置并且二者同时加一,因此不会出现单独的单词boy不会单多次计入
    // 例如遍历到boy时,第一次*q==*r=='b'计数器加一,下一轮循环时r为o但是q为b,二者同时加不会重复
    for ( int i = 0; i < 2; ++i )
        printf( "%d\n", count[i] );
    return 0;
}