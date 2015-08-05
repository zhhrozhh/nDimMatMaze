#include"ndmaze.h"
Pos::Pos(){
    pos=vector<int>();
    usf=false;
}
Pos::Pos(vector<int>p){
    pos=p;
    usf=true;
}
string Pos::toString(){
    if(!usf)return "x";
    string res = to_string(pos[0]);
    for(size_t i=1;i<pos.size();i++)
        res += ("x"+to_string(pos[i]));
    return res;
}
Maze::Maze(vector<int>s){
    scale=s;
    int res=1;
    for(size_t i=0;i<s.size();i++){
        fscale.push_back(res);
        res = res * s[i];
    }
}
bool Maze::gt(Pos p){
    if(!p.usf)return false;
    int sum = 0;
    for(size_t i=0;i<scale.size();i++)
        sum+=(p.pos[i]-1)*fscale[i];
    if(sum >maze.size()||sum<0)return false;
    return maze[sum];
}
Pos Maze::move(Pos p,int d){
    if(!gt(p))return Pos();
    Pos tem = p;
    tem.pos[abs(d)-1]+=(d>0?1:-1);
    if(tem.pos[abs(d)-1]>scale[abs(d)-1]||tem.pos[abs(d)-1]<1)return Pos();
    if (gt(tem))return tem;
    return Pos();
}
vector<Pos>Maze::path(){
    stvp=map<string,vector<Pos> >();
    stp=map<string,int>();
    stp[ini.toString()]=0;
    visit(ini);
    vector<Pos>res;
    if(stp.find(fin.toString())==stp.end())return res;
    Pos itr = fin;
    while(itr.toString()!=ini.toString()){
        res.push_back(itr);
        if(stp[itr.toString()]==1){
            res.push_back(ini);
            break;
        }
        for(int i=1;i<=scale.size();i++){
            Pos ti=move(itr,i);
            if(stp[ti.toString()]==stp[itr.toString()]-1){
                itr=ti;
                break;
            }
            Pos tni=move(itr,-i);
            if(stp[tni.toString()]==stp[itr.toString()]-1){
                itr=tni;
                break;
            }
        }
    }
    return res;
}
void Maze::visit(Pos p){
    vector<Pos>toV;
    string pss = p.toString();
    if(stvp.find(pss)==stvp.end()){
        for(int i=1;i<=scale.size();i++){
            toV.push_back(move(p,i));
            toV.push_back(move(p,-i));
        }
        stvp[pss]=toV;
    }
    else toV = stvp[pss];
    for(size_t i=0;i<toV.size();i++){
        if(gt(toV[i])){
            string tovis = toV[i].toString();
            if(stp.find(tovis)==stp.end()||stp[tovis]>stp[pss]+1){
                stp[tovis]=stp[pss]+1;
                visit(toV[i]);
            }
        }
    }
}

