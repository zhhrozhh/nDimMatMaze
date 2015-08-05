#ifndef NDMAZE
#define NDMAZE
#include<iostream>
#include<vector>
#include<map>
#include<string>
#define dg cout<<__LINE__<<endl;fflush(stdout) 
using namespace std;
class Pos{
    public:
        bool usf;
        vector<int>pos;
        Pos();
        Pos(vector<int>p);
        string toString();

};
class Maze{
    public:
        Maze(vector<int>s);
        vector<bool>maze;
        map<string,int>stp;
        vector<int>scale;
        vector<int>fscale;
        Pos ini;
        Pos fin;
        map<string,vector<Pos> >stvp;
        bool gt(Pos p);
        Pos move(Pos p,int d);
        vector<Pos>path();
        void visit(Pos p);
};
#endif

