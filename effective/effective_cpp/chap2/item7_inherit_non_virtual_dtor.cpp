#include <iostream>
using namespace std;

class NewString : public string {
public:
    NewString(const string& s) : m_s(s) {}
    string m_s;
};
int main(int argc, char* argv[]) {
    NewString* ns = new NewString("123");
    string* ps;
    ps = ns;
    delete ps;
    return 0;
}
