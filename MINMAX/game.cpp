#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
#include"game.hpp"

game::game()
{
    vector<int> aux(3,-1);
    for(int i=0;i<3;i++)
    arr.push_back(aux);
    state=true;
    moves=0;
    turn=1;
}

game::game(vector<vector<int>> carr,int _new,int cturn,int cmoves){
    arr=carr;
    arr[_new/3][_new%3]=cturn;
    state=true;
    moves=cmoves+1;
    turn=1-cturn;
}

void game::render(){
    cout<<"\n\n";
    cout<<"+---+---+---+\n";
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++)
        {
            if(arr[j][i]==1)
                cout<<"| X ";
            else if(arr[j][i]==-1)
                cout<<"|   ";
            else cout<<"| O ";
        }
        cout<<"|\n+---+---+---+\n";
    }
}

void game::toggle_turn(){
    turn=1-turn;
    moves++;
    if(moves==9) state=false; 
}

void game::user_entry(int x){
    x--;
    if(arr[x/3][x%3]!=-1)
    {
        cout<<"\n\nPlease enter valid number!\n\n";
        exit(0);
    }
    arr[x/3][x%3]=1;
   
}

vector<vector<int>> game::get_grid(){
    return arr;
}   

int game::game_state(){
    int i;
    //checking rows
    for(i=0;i<3;i++)
    {
        if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
        {
            if(arr[i][0]==1) return 10;
            else if(arr[i][0]==0) return -10;
        }
    }
    //checking columns
    for(i=0;i<3;i++)
    {
        if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
        {
            if(arr[0][i]==1) return 10;
            else if(arr[0][i]==0) return -10;
        }
    }
    //checking diagonals 
    if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])
    {
        if(arr[0][0]==1) return 10;
        else if(arr[0][0]==0) return -10;
    }
    else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
    {
        if(arr[2][0]==1) return 10;
        else if(arr[2][0]==0) return -10;
    }    
    return 0;
}

void game::declare_result(){
    if(game_state()<0)
        cout<<"\n\nComputer won!!\n";
    else if(game_state()>0)
        cout<<"\n\nUser Won\n";
    else cout<<"\n\nDraw!\n";
}

int game::assign()
{
    vector<game*> var_arr;
    vector<int> stats;
    vector<int> index;
    //trying each possibility of insertion
    for(int i=0;i<9;i++)
    {
        if(arr[i/3][i%3]!=-1)
        continue;

        game *new_en=new game(arr,i,turn,moves);
        var_arr.push_back(new_en);
        index.push_back(i);
        
        if(new_en->game_state()!=0)
        stats.push_back(new_en->game_state());
        else 
        stats.push_back(new_en->assign());
    }

    if(stats.size()==0)
    return game_state();

    // if(turn==0)
    // {
        //if there is even a single -10 we'll return it
        //else if there is even a single 0 return it
        //else return 10
        for(int i=0;i<stats.size();i++)
        if(stats[i]==(2*turn-1)*10) {
            arr[index[i]/3][index[i]%3]=turn;
            return (2*turn-1)*10;
        }

        for(int i=0;i<stats.size();i++)
        if(stats[i]==0) {
            arr[index[i]/3][index[i]%3]=turn;
            return 0;
        }

        arr[index[0]/3][index[0]%3]=turn;
        return (1-2*turn)*10;
        
    // }
    /*else{
        //if there is even a single 10 we'll return it
        //else if there is even a single 0 return it
        //else return -10
        for(int i=0;i<stats.size();i++)
        if(stats[i]==10) {
            arr[index[i]/3][index[i]%3]=turn;
            return 10;
        }
        for(int i=0;i<stats.size();i++)
        if(stats[i]==0) {
            arr[index[i]/3][index[i]%3]=turn;
            return 0;
        }
        arr[index[0]/3][index[0]%3]=turn;
        return -10;
    }*/

    
}