#include <bits/stdc++.h>
using namespace std;
// P1957
int main()
{
    char k;
    int  n, x, y;
    cin >> n;
    string s;
    for ( int i = 1; i <= n; i++ )
    {
        ostringstream oss;
        cin >> s;
        if ( isalpha( s[0] ) )
        {
            k = s[0];
            cin >> x >> y;
        }
        else
        {
            x = stoi( s );
            cin >> y;
        }
        if ( k == 'a' )
        {
            oss << x << "+" << y << "=" << x + y;
        }
        else if ( k == 'b' )
        {
            oss << x << "-" << y << "=" << x - y;
        }
        else
        {
            oss << x << "*" << y << "=" << x * y;
        }
        cout << oss.str() << endl << oss.str().length() << endl;
    }
    return 0;
}
