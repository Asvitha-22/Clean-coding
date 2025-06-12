/* One object owns another and is responsible for its lifetime

Parts do not exist independently */

/* Teacher owns its Students. When Teacher is destroyed, so are the Students. This is tight coupling. */

class Student {
    std::string name;
public:
    Student(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
};

class Teacher {
    std::vector<Student> students;  // owns the students
public:
    void addStudent(const std::string& name) {
        students.emplace_back(name);  // creates and stores internally
    }

    void showStudents() {
        for (const auto& s : students)
            std::cout << "Teaches: " << s.getName() << std::endl;
    }
};
