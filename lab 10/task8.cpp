#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream outfile("config.txt");
    outfile<<"AAAAABBBBBCCCCC";
    outfile.close();
    cout<<"file content before: AAAAABBBBBCCCCC"<<endl;

    fstream  out("config.txt",ios::in| ios::out);
    if (!out) {
        cerr << "Error opening file for update!" << endl;
        exit(1);
    }
    out.seekp(5,ios::beg);
    out<<"XXXXX";

    out.seekp(0);
     string content;
      getline(out, content,'\0');
      cout<<"Final  content after over-writing: "<<content<<endl;
      out.close();

      return 0;

} 
