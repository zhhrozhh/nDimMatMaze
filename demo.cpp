#include"ndmaze.h"
    extern int sxx;
int main(){
    vector<int>s= {4,4,4};
    Maze m(s);
    m.maze = {true,true,true,true,
            true,true,true,true,
            true,true,true,true,
            true,true,true,true,

true,true,true,true,
true,true,true,true,
true,true,true,true,
true,true,true,true,

true,true,true,true,
true,true,true,true,
true,true,true,true,
true,true,true,true,

true,true,true,true,
true,true,true,true,
true,true,true,true,
true,true,true,true};
    vector<int> ini = {1,1,1};

    m.ini=Pos(ini);
    m.fin=Pos(s);

    vector<Pos>p = m.path();

    for(size_t i=0;i<p.size();i++)
        cout<<p[i].toString()<<" -> ";
}
