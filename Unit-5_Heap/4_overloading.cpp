/*
Input 1 :
Hello
helllooo
5
Output 1 :
Hellohelllooo
HelloHelloHelloHelloHello
helllooohelllooohelllooohelllooohelllooo
*/

#include<iostream>
#include<string>
using namespace std;
class Mystring{
    private:
    string str;
    public:
    Mystring(const string &s) : str(s) {}
    Mystring operator+(const Mystring &other){  //whenever class ka private variable ka data type same ho jaaye desired ooutput ka datatype se tab we can make overload operator with class name and return type.
        return Mystring(str + other.str);
    }
    const string& getstring() const {
        return str;
    }
    void operator*(int n) {
        for(int i=0;i<n;i++){
            cout<<str;
        }
    }
};
int main(){
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int rep;
    cin>>rep;
    Mystring fstr(str1);
    Mystring lstr(str2);
    Mystring final= str1 + str2;
    cout<<final.getstring()<<endl;  
    fstr * rep;
    cout<<endl;
    lstr * rep;
    cout<<endl;
    return 0;

}