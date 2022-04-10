#include<iostream>
#include<string>
#include<vector>

using namespace std;

int scoreweight[4];

class Student{
    public:
        Student(string name_);
        string get_name();
        void set_lab(int w, int s);
        void set_hw(int w, int s);
        void set_prj(int s);
        void set_exam(int s);
        void print_score();
        void print_score_detail();
    private:
        string name;
        int hw[10];
        int lab[10];
        int prj;
        int exam;
};

int main(){
    vector<Student> students;

    for(int i=0;i<4;i++)    scoreweight[i] = i+1;

    while(1)
    {
        int i;
        string oper;
        cin >> oper;
        
        if(oper == "add")
        {
            string name;
            cin >> name;
            Student student(name);
            students.push_back(student);
        }
        else if(oper == "setlab")
        {
            string name;
            int w, s;
            cin >> name >> w >> s;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].set_lab(w, s);
                    break;
                }
            }
        }
        else if(oper == "sethw")
        {
            string name;
            int w, s;
            cin >> name >> w >> s;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].set_hw(w, s);
                    break;
                }
            }
        }
        else if(oper == "setprj")
        {
            string name;
            int s;
            cin >> name >> s;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].set_prj(s);
                    break;
                }
            }
        }
        else if(oper == "setexam")
        {
            string name;
            int s;
            cin >> name >> s;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].set_exam(s);
                    break;
                }
            }
        }
        else if(oper == "setscoreweight")
        {
            int labratio, hwratio, prjratio, examratio;
            cin >> labratio >> hwratio >> prjratio >> examratio;
            scoreweight[0] = labratio;
            scoreweight[1] = hwratio;
            scoreweight[2] = prjratio;
            scoreweight[3] = examratio;
        }
        else if(oper == "printscore")
        {
            string name;
            cin >> name;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].print_score();
                    break;
                }
            }
        }
        else if(oper == "printscoredetail")
        {
            string name;
            cin >> name;
            for(i=0;i<students.size();i++)
            {
                if(students[i].get_name() == name)
                {
                    students[i].print_score_detail();
                    break;
                }
            }
        }
        else if(oper == "exit")
        {
            break;
        }
        else
        {
            cout << "no operation";
        }
    }
}

Student::Student(string name_)
{
    name = name_;
    for(int i=0;i<10;i++)
    {
        hw[i] = 0;
        lab[i] = 0;
    }
    prj = 0;
    exam = 0;
}

string Student::get_name(){return name;}
void Student::set_lab(int w, int s){lab[w] = s;}
void Student::set_hw(int w, int s){hw[w] = s;}
void Student::set_prj(int s){prj = s;}
void Student::set_exam(int s){exam = s;}
void Student::print_score()
{
    int sum = 0;
    int i;
    for(i=0;i<10;i++)    sum += lab[i] * scoreweight[0];
    for(i=0;i<10;i++)    sum += hw[i] * scoreweight[1];
    sum += prj * scoreweight[2];
    sum += exam * scoreweight[3];
    cout << sum << " ";
}
void Student::print_score_detail()
{
    for(int i = 0;i <10;i++)    cout << lab[i] << " ";
    for(int i = 0;i <10;i++)    cout << hw[i] << " ";
    cout << prj << " ";
    cout << exam << " ";
}






