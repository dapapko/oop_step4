#include <string>
#include <iostream>
using namespace std;

class Tiger
{
    int age; // Age of tiger
    int size; // Size of tiger (in metres)
    int speed; // Speed of tiger (metres per second)
    string breed; // Breed (Bengal, Amur or smth like that)
    string skinColour; // Colour of skin (black, white or orange)
    bool isHungry; // A tiger can be hungry or not

    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "The tiger is running. Speed: " << speed << endl;
    }

public:
    // Friendly operator function for output. Definition.
    friend ostream& operator<<(ostream& output, const Tiger& T);
    // hunting
    void hunt(int t_speed = 30) {
        if (!isHungry) cout << "Tiger is not hungry, so he don't hunt" << endl;
        else {
            if (age < 2) cout << "Tiger is hungry, he makes known about it tigress" << endl;
            else {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(t_speed);
            }
        }
    }

    // Default constructor with default values of  arguments
    Tiger(int t_age=7, int t_size=9, int t_speed=0, string t_breed= "bengal", string t_skinColour = "white", bool t_isHungry= true):
        age(t_age), speed(t_speed), breed(t_breed), skinColour(t_skinColour), size(t_size), isHungry(t_isHungry)
    {
     
    }

    // copying constructor
    Tiger(Tiger const& instance) :
        age(instance.age), size(instance.size),
        speed(instance.speed), breed(instance.breed),
        skinColour(instance.skinColour), isHungry(instance.isHungry)
    {}
};

// Friendly operator function for output. Implementation.
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.skinColour << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    // Calling default constructor
    Tiger t1(10, 5);
    // Calling public function
    t1.hunt();
    // Tiger t2 is a copy of t1
    Tiger t2 = t1;
    // Visualization
    cout << t1 << endl;
    cout << t2;
    // Calling method of the class
    t1.hunt(50);
}
