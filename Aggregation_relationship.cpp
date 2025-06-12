/* One object contains another, but the contained object can outlive the container

Can exist independently */

/* Similar to association, but often semantically stronger (like a class section has students). The key is no deletion or lifetime control by the Teacher. */

class Student {
    std::string name;
public:
    Student(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
};

class Teacher {
    std::vector<Student*> students;  // not owning
public:
    void addStudent(Student* student) { students.push_back(student); }
    void showStudents() {
        for (auto s : students)
            std::cout << "Teaches: " << s->getName() << std::endl;
    }
};
