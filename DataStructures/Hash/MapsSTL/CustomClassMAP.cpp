#include<iostream>
#include<unordered_map>
using namespace std;

class student
{
    public:
        string first_name;
        string last_name;
        string rollno;

        student(string f, string l, string rno)
        {
            first_name = f;
            last_name = l;
            rollno = rno;
        }

        bool operator ==(const student &s) const
        {
            return rollno == s.rollno?true:false;
        }
};

class HashFn
{
public:
    size_t operator()(const student &s)const
    {
        return s.first_name.length() + s.last_name.length();
    }
};

int main()
{   
    unordered_map<student,int,HashFn> student_map;

    student s1("Prateek","Narang","010");
    student s2("Rahul","Kumar","023");
    student s3("Pratik","Gupta","030");
    student s4("Rahul","Kumar","120");

    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 45;
    student_map[s4] = 11;

    for(auto s:student_map)
    {
        cout << s.first.first_name << " " << s.first.rollno << endl;
        cout << "Marks " << s.second << endl;
    }

   int x = student_map[s3] ;
   cout << x;

    return 0;
}