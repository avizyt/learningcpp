#include <iostream>
#include <vector>

using namespace std;

struct Person
{
    string name;
    int age;

    Person(const string &name, int age) : name(name), age(age) {}
};

int main()
{
    // vector<Person> people;

    // // Using emplace_back to insert at the end
    // people.emplace_back("Alice", 25);

    // // Using emplace to insert at a specific position
    // auto it = people.begin() + 1; // Insert after the first element
    // people.emplace(it, "Bob", 30);

    // for (const auto &person : people)
    // {
    //     cout << person.name << " (" << person.age << ")" << endl;
    // }

    vector<int> entry = {10, 20, 30, 40, 50};

    vector<pair<int, int>> events;

    for (int time : entry)
    {
        events.emplace_back(time, 1);
    }
    // Print the events
    for (const auto &event : events)
    {
        cout << "Time: " << event.first << ", Event Type: " << event.second << endl;
    }

    return 0;
}
