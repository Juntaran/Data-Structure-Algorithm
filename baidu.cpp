//
// Created by Administrator on 2016/7/14.
//

/*
 *
    ��ķ�տ�ʼѧϰӢ�ĵ��ʣ��Ե�������ܸ���Ȥ��
    �������ķһ�鵥�ʣ����ܹ�Ѹ��ȷ���Ƿ���Խ���Щ����������һ���б��У�ʹ�ø��б����κε��ʵ�����ĸ��ǰһ���ʵ�Ϊ��ĸ��ͬ��
    ���ܱ�дһ��������������ķ�����ж���

    ��������:

    �����������������ݡ�
    ����ÿ��������ݣ���һ��Ϊһ��������n��������n�����ʡ�
    Ȼ����n���ַ���������n�����ʡ�
    ��֤��
    2<=n<=200,ÿ�����ʳ��ȴ���1��С�ڵ���10,�����е��ʶ�����Сд��ĸ��ɡ�

    ��������:
    3
    abc
    cdefg
    ghijkl
    4
    abc
    cdef
    fghijk
    xyz

    �������:
    Yes
    No
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
//    while ( cin >> n )
    cin >> n;
    {
        if ( !(n>=2 && n<=200) )
        {
            return false;
        }
        vector<string> vc(n);
        for ( int i=0; i<n; i++ )
        {
            cin >> vc[i];
        }
        bool flag = true;
        for ( int i=0; i<n; i++ )
        {
            int length = vc[i].size();
            if ( vc[i][length-1] == vc[i+1][0] )
            {
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if ( flag )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}