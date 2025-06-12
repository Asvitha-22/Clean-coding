#include <string>
#include<iostream>
using namespace std;

class Icon {
public:
    virtual std::string move() = 0;
    virtual std::string flair() = 0;
    virtual ~Icon() = default;
};

class SpinnerIcon : public Icon {
    bool clockwise;
    bool expand;

public:
    SpinnerIcon(bool cw, bool ex) : clockwise(cw), expand(ex) {}

    std::string move() override {
        return clockwise ? "Spinning clockwise" : "Spinning counterclockwise";
    }

    std::string flair() override {
        return expand ? "Flairing with expansion" : "Flairing without expansion";
    }
};

class SliderIcon : public Icon {
    bool vertical;
    int distance;

public:
    SliderIcon(bool vert, int dist) : vertical(vert), distance(dist) {}

    std::string move() override {
        return vertical ? "Sliding vertically" : "Sliding horizontally";
    }

    std::string flair() override {
        return "Slider flair";
    }
};

class HopperIcon : public Icon {
    bool visible;
    int xcoord, ycoord;

public:
    HopperIcon(bool vis, int x, int y) : visible(vis), xcoord(x), ycoord(y) {}

    std::string move() override {
        return "Hopping to (" + std::to_string(xcoord) + ", " + std::to_string(ycoord) + ")";
    }

    std::string flair() override {
        return visible ? "Hopper flair visible" : "Hopper flair hidden";
    }
};
int main() {
    SpinnerIcon icon1(true, false);      // allocated on the stack
    SliderIcon icon2(false, 10);         // stack
    HopperIcon icon3(true, 5, 5);        // stack

    std::cout << icon1.move() << std::endl;
    std::cout << icon2.flair() << std::endl;
    std::cout << icon3.move() << std::endl;

    // No need to delete anything — automatic cleanup
    return 0;
}
