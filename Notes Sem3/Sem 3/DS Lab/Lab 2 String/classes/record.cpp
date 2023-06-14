#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
class records{
private:
    char name[30] ;
    long rollno;
    char grade;
    char branch[30];
public:
    write(char name[30] ,long rollno,char grade,char branch[30] ){
        ofstream outfile;
        outfile.open("Record.txt");
        outfile<<name<<rollno<<grade<<branch;
        outfile.close();

    }
    read(){
    ofstream outfile;
        ifstream in("Records.txt");
        char usr[30];
        in >> usr;
        cout << outfile;
        outfile.close();
    }
    store(){
        ofstream outfile;
        char usr[30];
        outfile.open("Record.txt");
        outfile >> usr;
    }
};
int main(){
    records r1;
    r1.write("daksh",21,'b',"It");
    r1.read();

}
