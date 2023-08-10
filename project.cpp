#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Department
{
private:
    string name;
    double required_GPA;
    int department_capacity;

public:
    // constructors
    Department() {}
    Department(string name, int department_capacity, double required_GPA)
    {
        this->name = name;
        this->department_capacity = department_capacity;
        this->required_GPA = required_GPA;
    }

    // Setters
    void set_name(string name)
    {
        this->name = name;
    }

    void set_required_GPA(double gpa)
    {
        required_GPA = gpa;
    }

    void set_department_capacity(int capacity)
    {
        department_capacity = capacity;
    }

    // Getters
    string get_name()
    {
        return name;
    }

    double get_required_GPA()
    {
        return required_GPA;
    }

    int get_department_capacity()
    {
        return department_capacity;
    }

    // destructor
    ~Department() {}
};

class Person
{
protected:
    int id;
    int age;
    string name;
    char gender;

public:
    // constructors
    Person() {}
    Person(int id, int age, string name, char gender)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->gender = gender;
    }

    // Behavior functions
    virtual void attend() = 0;

    // setters
    void set_id(int id)
    {
        this->id = id;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_gender(char gender)
    {
        this->gender = gender;
    }

    // getters
    int get_id()
    {
        return id;
    }
    int get_age()
    {
        return age;
    }
    string get_name()
    {
        return name;
    }
    char get_gender()
    {
        return gender;
    }

    // destructor
    ~Person() {}
};

class Student : public Person
{               // The class of student
private:        // Access specifier
    int level;  // Attribute (int variable for student level)
    double gpa; // Attribute (double variable for student gpa)

public:
    // Constructors
    Student() {}

    Student(int id, string name, int age, char gender, int level, int gpa)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->level = level;
        this->gpa = gpa;
    }

    // Setters

    void set_level(int level)
    {
        this->level = level;
    }

    void set_gpa(double gpa)
    {
        this->gpa = gpa;
    }

    // getters

    int get_level()
    {

        return level;
    }

    double get_gpa()
    {

        return gpa;
    }

    // Behavior of student
    void study()
    {
        cout << "Student " << name << " attended" << endl;
    }

    void take_exam()
    {
        cout << "Student " << name << " attended" << endl;
    }

    void attend()
    {
        cout << "Student " << name << " attended" << endl;
    }
};

class Professor : public Person
{

private:
    Department *department;
    string degree;
    double salary;

public:
    // constructors

    Professor() {}
    Professor(int id, string name, int age, char gender, Department *department, double salary, string degree)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->department = department;
        this->degree = degree;
        this->salary = salary;
    }

    // Behavior of professor
    void teach() {}

    void make_exam() {}

    void attend()
    {
        cout << "Professor " << name << " attended" << endl;
    }

    // setters
    void set_department(Department *department)
    {
        this->department = department;
    }
    void set_degree(string degree)
    {
        this->degree = degree;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }

    // getters
    Department *get_department()
    {
        return department;
    }
    string get_degree()
    {
        return degree;
    }
    double get_salary()
    {
        return salary;
    }

    // destructor
    ~Professor() {}
};

class Course
{
private:
    string course_name;
    string course_code;
    int course_hours;
    vector<Course *> prerequisites;
    Professor *professor;
    vector<Student *> students;

public:
    // Constructor
    Course() {}
    Course(string course_name, string course_code, int course_hours,
           vector<Course *> prerequisites, Professor *professor, vector<Student *> students)
    {
        this->course_name = course_name;
        this->course_code = course_code;
        this->course_hours = course_hours;
        this->professor = professor;
        this->prerequisites = prerequisites;
        this->students = students;
    }

    // Destructor
    ~Course()
    {
    }

    // Setters
    void set_course_name(string course_name)
    {
        this->course_name = course_name;
    }
    void set_course_code(string course_code)
    {
        this->course_code = course_code;
    }
    void set_course_hours(int course_hours)
    {
        this->course_hours = course_hours;
    }
    void set_prerequisites(vector<Course *> prerequisites)
    {
        this->prerequisites = prerequisites;
    }

    void set_professor(Professor *Professor)
    {
        this->professor = professor;
    }

    void set_student(vector<Student *> students)
    {
        this->students = students;
    }

    // Getters
    string get_course_name()
    {
        return course_name;
    }

    string get_course_code()
    {
        return course_code;
    }

    int get_course_hours()
    {
        return course_hours;
    }

    vector<Course *> get_prerequisites()
    {
        return prerequisites;
    }

    Professor *get_professor()
    {
        return professor;
    }

    vector<Student *> get_students()
    {
        return students;
    }
};

class University
{
private:
    vector<Department> departments;
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;
    static University *instancePtr; // pointer
    University()
    {
        addData();

    } // private constructor

public:
    // deleting copy constructor
    University(const University &obj) = delete;

    // function returns the pointer
    static University *getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }

    // ADD functions
    void add_professor(int id, string name, int age, char gender, Department *department, double salary, string degree)
    {
        Professor obj1(id, name, age, gender, department, salary, degree);
        // Professor obj1(id, name, age, gender, department, salary, degree);
        professors.push_back(obj1);
    }

    void add_courses(string course_name, string course_code, int course_hours, vector<Course *> prerequisites, Professor *professor, vector<Student *> student)
    {
        Course C(course_name, course_code, course_hours, prerequisites, professor, student);
        courses.push_back(C);
    }

    void add_departments(string name, double required_gpa, int capacity)
    {
        Department d(name, required_gpa, capacity);
        departments.push_back(d);
    }

    void add_student(int id, string name, int age, char gender, int level, int gpa)
    {
        Student s1(id, name, age, gender, level, gpa);
        students.push_back(s1);
    };

    // UPDATE functions
    void update_professor(int idd, double new_salary)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].get_id() == idd)
            {
                professors[i].set_salary(new_salary);
                return;
            }
        }
        cout << " not found ";
    }

    void update_student(int idd, double new_gpa)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].get_id() == idd)
            {
                students[i].set_gpa(new_gpa);
                return;
            }
        }
        cout << " not found ";
    }

    void update_department(string namee, int capacity)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].get_name() == namee)
            {
                departments[i].set_department_capacity(capacity);
                return;
            }
        }
        cout << " not found ";
    }

    void update_course(string code, int hours)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_course_code() == code)
            {
                courses[i].set_course_hours(hours);
                return;
            }
        }
        cout << " not found ";
    }

    // DELETE functions
    void delete_professor(int idd)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].get_id() == idd)
            {
                professors.erase(professors.begin() + i);
                cout << "Deleted";
                return;
            }
        }
        cout << " not found ";
    }

    void delete_student(int idd)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].get_id() == idd)
            {
                students.erase(students.begin() + i);
                cout << "Deleted";
                return;
            }
        }
        cout << " not found ";
    }

    void delete_department(string namee)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].get_name() == namee)
            {
                departments.erase(departments.begin() + i);
                cout << "Deleted";
                return;
            }
        }
        cout << " not found ";
    }

    void delete_course(string code)
    {
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].get_course_code() == code)
            {
                courses.erase(courses.begin() + i);
                cout << "Deleted";
                return;
            }
        }
        cout << " not found ";
    }

    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1, "Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2, "Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3, "Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4, "Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5, "Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6, "Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7, "Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8, "Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1, "Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2, "Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3, "Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4, "Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5, "Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);

        vector<Student *> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student *> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course *>(), &p1, st1);
        courses.push_back(c1);
        vector<Course *> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1, &p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for (int i = 0; i < departments.size(); i++)
        {
            cout << "Department: " << departments[i].get_name() << endl;
        }
        for (int i = 0; i < professors.size(); i++)
        {
            cout << "Professor Name: " << professors[i].get_name() << endl;
        }
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Student Name: " << students[i].get_name() << endl;
        }
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course Name: " << courses[i].get_course_name() << endl;
        }
    }
};

University *University::instancePtr = NULL;

int main()
{

    University *uni = University::getInstance();
    uni->printAll();
    uni->delete_course("Net521");
    uni->printAll();

    return 0;
};
