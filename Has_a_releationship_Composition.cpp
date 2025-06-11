/* One class has a component	Report has a Printer */

#include <iostream>
using namespace std;

// Component class
class Printer {
public:
    void print() {
        cout << "Printing document..." << endl;
    }
};

// Main class that "has a" Printer
class Report {
private:
    Printer printer;  // Composition: Report "has a" Printer

public:
    void generate() {
        cout << "Generating report..." << endl;
        printer.print();  // Delegates printing to Printer class
    }
};

int main() {
    Report report;
    report.generate();

    return 0;
}
