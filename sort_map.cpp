#include <iostream>
#include <string>
#include <map>

using namespace std;

struct student
{
    int m_id;
    string m_name;
};

struct animal
{
    bool operator<(const animal & other)const
    {
        if(this->m_size < other.m_size)
            return true;
        else
            return (this->m_name.size() < other.m_name.size());
    }

    int m_size;
    string m_name;
};
class sort
{
public:
    bool operator()(const student & l1,const student & l2)
    {
        if(l1.m_id < l2.m_id)
            return true;
        else
            return (l1.m_name.size() < l2.m_name.size());
    }
};
int main()
{
    map<student, int, sort> studentObj;
    student l_first{1, "li ming"}, l_second{2, "zhang san"};
    studentObj[l_first] = 5;
    studentObj.insert(map<student, int, sort>::value_type(l_second, 6));

    for(auto p = studentObj.begin(); p != studentObj.end(); p++)
        cout << p->first.m_id << endl;

    map<animal, int> animalObject;
    animal bear{10, "bear"}, tiger{100, "tiger"};
//    animalObject.insert(pair<animal, int>(bear, 1));
    animalObject[bear] = 1;
    animalObject.insert(map<animal, int>::value_type(tiger, 2));
    for(auto p = animalObject.begin(); p != animalObject.end(); p++)
        cout << p->first.m_size << endl;

    return 0;
}
