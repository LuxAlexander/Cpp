#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#define size 4

void splitnumber(int,int[]);
bool sameNumber(int*, bool&);
void createMinMax(int [], int [], int []);
void arraytoint(int [], int [], int&, int&);

using namespace std;

int main() {

    int startingnumber=99999;
    int zahlen[size],min[size],max[size];
    bool valid=true,end=false;
    int minzahl=0,maxzahl=0,zahl=0,tempzahl=-1;

     do{
        valid=true;
        cout << "Bitte eine "<<size<<" stellige ganzzahl mit unterschiedlichen zahlen\n";
        cin >> startingnumber;

         if(startingnumber>(pow(10,size)-1)) {
             valid=false;
         }else {
             splitnumber(startingnumber, zahlen);
             sameNumber(zahlen, valid);
         }
    }while(valid==false);

    while (end==false){
        minzahl=0,maxzahl=0;

        createMinMax(zahlen, min, max);
        arraytoint(min, max, minzahl, maxzahl);

        cout << "maxzahl: "<<maxzahl << endl;
        cout << "minzahl: "<<minzahl << endl;

        zahl=maxzahl-minzahl;
        splitnumber(zahl, zahlen);

        cout << "Zahl: "<<zahl << endl;

        if (tempzahl==zahl) {
            end=true;
        }
        tempzahl=zahl;
    }

    return 0;
}


void splitnumber(int startingnumber, int zahlen[size]) {
    int temp=startingnumber;

    for(int i=0;i<size-1;i++) {
        zahlen[i]=temp%10;
        temp=temp/10;
    }
    zahlen[size-1]=temp;
}

bool sameNumber(int zahlen[size], bool &valid) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if((zahlen[i]==zahlen[j])&& j!=i) {
                cout <<"Gleiche Zahlen vermeiden"<<endl;
                return valid=false;
            }
        }
    }
    return valid;
}

void arraytoint(int min[size], int max[size], int &minzahl, int &maxzahl) {
    for (int i=0; i<size; i++) {
        minzahl+=pow(10, size-1-i)*min[i];
        maxzahl+=pow(10, size-1-i)*max[i];
    }
}

void createMinMax(int zahlen[size], int min[size], int max[size]) {
    int n=size;//arrays given to functions are degraded to pointers and size while be harder to get
    // Sort the array using std::sort()
    sort(zahlen, zahlen + size);
    copy(zahlen, zahlen + size, min);

    sort(zahlen, zahlen + size, greater<int>());//
    copy(zahlen, zahlen + size, max);
}