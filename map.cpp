#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string, int> MY_MAP;
typedef MY_MAP::iterator MAP_ITER;

int main()
{
    //MY_MAP my_map["c"] = 3;
    MY_MAP my_map;
    map<string,int> a={{"e",5},{"e",6}};//a[e]=5
    cout<< a.size() << endl;

    for(auto p = a.begin(); p != a.end(); p++)
    {
        cout<< "my_map[" << p->first << "] = " << p->second << endl;
        }
    my_map["b"] = 2;
    my_map["b"] = 5;//changed
    my_map.insert(map<string, int>::value_type("a", 1));
    my_map.insert(pair<string, int>("c", 3));
    my_map.insert(pair<string, int>("c", 7));//did not work, my_map["c"] is still 3.
    my_map.insert(pair<string, int>("d", 4));
    my_map.insert(pair<string, int>("e", 5));
    cout<<" the size of my_map is " << my_map.size() << endl;

    MAP_ITER mapIter, resultsIter;
    for(mapIter = my_map.begin(); mapIter != my_map.end(); mapIter++)
    {
        cout<< "my_map[" << mapIter->first << "] = " << mapIter->second << endl;
        if(mapIter->second == 5)
            my_map.erase(mapIter);//??
        resultsIter = my_map.find("a");
        if( resultsIter != my_map.end())
        {
            //my_map.erase(resultsIter);//both is ok
            my_map.erase("a");
            //cout<< "results of my_map[" << resultsIter->first << "] = " << resultsIter->second << endl;
        }
        else
        {
            cout<<" not found in my_map of key with a" << endl;
        }
    }

    cout<<" the size of my_map before erase is " << my_map.size() << endl;
    my_map.erase(my_map.begin(), my_map.end());
    cout<<" the size of my_map after erase is " << my_map.size() << endl;


    map <int, int> m1, m2, m3;
    map <int, int>::iterator m1_Iter;

    m1.insert ( pair <int, int>  ( 1, 10 ) );
    m1.insert ( pair <int, int>  ( 2, 20 ) );
    m1.insert ( pair <int, int>  ( 3, 30 ) );
    m2.insert ( pair <int, int>  ( 10, 100 ) );
    m2.insert ( pair <int, int>  ( 20, 200 ) );
    m3.insert ( pair <int, int>  ( 30, 300 ) );

    cout << "The original map m1 is:";
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter->second;
    cout   << "." << endl;

    // This is the member function version of swap
    //m2 is said to be the argument map; m1 the target map
    m1.swap( m2 );

    cout << "After swapping with m2, map m1 is:";
    for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
    cout << " " << m1_Iter -> second;
    cout  << "." << endl;
    cout << "After swapping with m2, map m2 is:";
    for ( m1_Iter = m2.begin( ); m1_Iter != m2.end( ); m1_Iter++ )
    cout << " " << m1_Iter -> second;
    cout  << "." << endl;

    return 0;
}
