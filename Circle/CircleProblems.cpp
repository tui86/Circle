#include "CircleProblems.h"
#include "Circle.h"
#include "Ring.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
void CircleProblems::ProblemA(const string filename)
{
    ifstream ifile("data.txt");
    int n;
    ifile>>n;
    int x, y, r;
    Circle* c = new Circle [n];
    for(int i=0; i<n; i++)
    {
        ifile>>c[i];
    }
    ifile.close();
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!(c[i]<c[j]))
            {
                Circle temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    cout<<"Các đường tròn sau khi được sắp xếp:\n";
    for(int i=0; i<n; i++)
    {
        cout<<c[i]<<endl;
    }
    delete [] c;
}

void CircleProblems::ProblemB(const string filename)
{
    ifstream ifile("data.txt");
    int n;
    ifile>>n;
    int x, y, r;
    Circle* c = new Circle [n];
    for(int i=0; i<n; i++)
    {
        ifile>>c[i];
    }
    ifile.close();
    vector <Circle> tiepxuc;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((c[i]^c[j]))
            {
                if((count(tiepxuc.begin(), tiepxuc.end(), c[i])==0))
                {
                    tiepxuc.push_back(c[i]);
                }
            }
        }
    }
    cout<<"Các đường tròn tiếp xúc với ít nhất một đường tròn khác là:\n";
    for(int i=0; i<tiepxuc.size(); i++)
    {
        cout<<tiepxuc[i]<<endl;
    }
    delete [] c;
}

void CircleProblems::ProblemC(const string filename)
{  
    ifstream ifile("data.txt");
    int n;
    ifile>>n;
    int x, y, r;
    Circle* c = new Circle [n];
    for(int i=0; i<n; i++)
    {
        ifile>>c[i];
    }
    ifile.close();
    int soring=0;
    vector <Ring> ring;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((c[i]==c[j])&&(c[i].getR()!=c[j].getR())) 
            {
                ring.push_back(Ring(c[i], c[j].getR()));
                soring++;
            }
        }
    }
    cout<<"Số lượng nhẫn có trong tệp tin là: "<<soring<<endl;
    delete [] c;
}

void CircleProblems::ProblemD(const string filename)
{
    ifstream ifile("data.txt");
    int n;
    ifile>>n;
    int x, y, r;
    Circle* c = new Circle [n];
    for(int i=0; i<n; i++)
    {
        ifile>>c[i];
    }
    ifile.close();
    for(int i=0; i<n; i++)
    {
        ifile>>c[i];
    }
    ifile.close();
    int soring=0;
    vector <Ring> ring;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if((c[i]==c[j])&&(c[i].getR()!=c[j].getR())) 
            {
                ring.push_back(Ring(c[i], c[j].getR()));
                soring++;
            }
        }
    }
    vector<int> dodaynhan;
    for (int i=0; i<ring.size(); i++)
    {
        dodaynhan.push_back(ring[i].width(ring[i]));
    }
    int max=dodaynhan[0];
    for(int i=1; i<dodaynhan.size(); i++)
    {
        if (max<dodaynhan[i]) max = dodaynhan[i];
    }
    cout<<"Nhẫn có độ dày lớn nhất là:\n";
    for(int i=0; i<ring.size(); i++)
    {
        if(max==dodaynhan[i]) cout<<ring[i]<<endl;
    }
    delete [] c;
}
