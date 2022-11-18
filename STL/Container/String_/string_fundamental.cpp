#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

void test1() {
    // char const *s;
    string s;
    s = "abc132";
    // cout<<s[s.size()-1]<<endl;
    // int a = 100;
    cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
}

void t2() {
    string s1{};
    s1.push_back('2');
    s1.append("abcde", 5);
    s1 = "ios"
         "bac";
    cout << s1 << endl;
}

int main(int argc, char const *argv[]) {
    /* test1(); */
    t2();
    return 0;
}
