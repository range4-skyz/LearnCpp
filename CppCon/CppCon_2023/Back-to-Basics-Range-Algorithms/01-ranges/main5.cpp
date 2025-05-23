
// Introducing of std::iter_swap() (C++11)

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <string>
#include <vector>

struct Person {
    std::string firstname;
    std::string lastname;
    int         age;
};

bool isChild(Person const &p) {
    if (p.age < 18) {
        return true;
    }
    return false;
}

int main() {
    std::vector<Person> table = {
      Person {     "Homer",    "Simpson",  38},
      Person {     "Marge",    "Simpson",  34},
      Person {      "Bart",    "Simpson",  10},
      Person {      "Lisa",    "Simpson",   8},
      Person {    "Maggie",    "Simpson",   1},
      Person {      "Hans",    "Moleman",  33},
      Person {     "Ralph",     "Wiggum",   8},
      Person {  "Milhouse", "Van Houten",  10},
      Person {       "Ned",   "Flanders",  60},
      Person {      "Jeff",  "Albertson",  45},
      Person {"Montgomery",      "Burns", 104},
      /*many more Simpsons characters */
    };

    auto first = std::begin(table);
    auto last = std::end(table);

    // Put all the children to the beginning of the vector
    while (first != last && isChild(*first)) {
        ++first;
    }

    if (first != last) {
        for (auto pos = std::next(first); pos != last; ++pos) {
            if (std::predicate(*pos)) {
                std::iter_swap(pos, first); // *
                ++first;
            }
        }
    }

    return EXIT_SUCCESS;
}
