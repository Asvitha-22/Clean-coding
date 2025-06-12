/* "Has a" relationship
Objects are linked but can exist independently */

/* Students are created outside the Teacher. No ownership — if a Student is deleted, Teacher still holds the pointer (can lead to issues unless managed). */

class Student {
    std::string name;
public:
    Student(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
};

class Teacher {
    std::vector<Student*> students;  // just a link
public:
    void addStudent(Student* student) { students.push_back(student); }
    void showStudents() {
        for (auto s : students)
            std::cout << "Teaches: " << s->getName() << std::endl;
    }
};
