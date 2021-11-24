#include <bits/stdc++.h>
using namespace std;

// Build in function

void max_many_parameters(){
    int a = 2, b=3,c=3;
    cout << max({a,b,c}) << endl;
}

void number_of_Bits(){
    int a=3;
    cout << __builtin_popcount(a) << endl;
}


void convert_String_to_integer(){
    string s = "121";
    int a = atol(s);
    cout << a << "\n";

    //strtod() , string float to double
    // atof(), string to double
    // strtoll(), string to ll
}

void divider(){

    div_t result = div(51,6);

    cout << result.quot << endl;
    cout << result.rem << endl;

    // ldiv_t for ll

}

void fill_increase_value(){
    vector<int> a(10);
    iota(a.begin(),a.end(), 3);
    for (auto c:a) cout<< c << " ";
    cout << "\n";
}

// minmax
// minmax_element
// accumulate // some 



// Cpp_17

// inline variables
struct S1{int x;};
inline S1 x1 = S1{321};


struct S {
  S() : id{count++} {}
  ~S() { count--; }
  int id;
  static inline int count{0}; // declare and initialize count to 0 within the class
};


void structured_bindings(){
    pair <int ,int> i = {2,4};
    auto [x,y] = i;


    std::unordered_map<std::string, int> mapping {
    {"a", 1},
    {"b", 2},
    {"c", 3}
    };

    // Destructure by reference.
    for (const auto& [key, value] : mapping) {
    // Do something with key and value
    }
}

void splicing_maps_sets(){

    // Moving elements from one map to another
    std::map<int, string> src {{1, "one"}, {2, "two"}, {3, "buckle my shoe"}};
    std::map<int, string> dst {{3, "three"}};
    dst.insert(src.extract(src.find(1))); // Cheap remove and insert of { 1, "one" } from `src` to `dst`.
    dst.insert(src.extract(2)); // Cheap remove and insert of { 2, "two" } from `src` to `dst`.
    // dst == { { 1, "one" }, { 2, "two" }, { 3, "three" } };
    

    // Inserting an entire set
    std::set<int> src2 {1, 3, 5};
    std::set<int> dst2 {2, 4, 5};
    dst2.merge(src2);
    // src == { 5 }
    // dst == { 1, 2, 3, 4, 5 }


    // Changing the key of a map element
    std::map<int, string> m {{1, "one"}, {2, "two"}, {3, "three"}};
    auto e = m.extract(2);
    e.key() = 4;
    m.insert(std::move(e));
    // m == { { 1, "one" }, { 3, "three" }, { 4, "two" } }
}


// Cpp_14
void binary_literals(){
    int x = 0b110;
    int y = 0b1111'1111;
    cout << x << "\n";
}

void lambda(){
    auto identity = []         (auto x) mutable {return x; };
    //Type Name   CaptureCluse parameter optional   body
    //            new variable
    auto factory = [](int i) { return i * 10; };
    auto f = [x = factory(2)] { return x; }; // returns 20

    auto generator = [x = 0] () mutable {
    // this would not compile without 'mutable' as we are modifying x on each call
    return x++;
    };
    auto a = generator(); // == 0
    auto b = generator(); // == 1
    auto c = generator(); // == 2
}

//Templates


// Cpp_11
void _tie(){
    string yes, no;
    tie(yes,no,ignore) = make_tuple("ES","ES",12);
    cout << yes << "\n";
}






int main(){
    binary_literals();
}