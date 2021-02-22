#include<iostream>
#include<vector>
using namespace std;
#include"game.hpp"

void render(int arr[][3]);
int main(){
    game *new_in=new game();
    while(true)
    {
        cout << "\x1B[2J\x1B[H";
        cout<<"\n\nEnter a number from 1-9:\n\n";
        new_in->render();
        cout<<"\n\n";

        //user's turn
        int n;
        cin>>n;
        new_in->toggle_turn();
        new_in->user_entry(n);
        if(new_in->get_state()==false||new_in->game_state()!=0){
            new_in->declare_result();
            break;
        }
        new_in->render();
        //computer assignment
        new_in->assign();
        new_in->toggle_turn();
        if(new_in->get_state()==false||new_in->game_state()!=0){
            new_in->render();
            new_in->declare_result();
            break;
        }
        // break;
    }
}