
class game{
    vector<vector<int>> arr;
    int turn;
    int moves;
    bool state;
    public:
    game();
    game(vector<vector<int>> carr,int _new,int turn,int cmoves);
    void render();
    void toggle_turn();
    int game_state();
    void user_entry(int x);
    bool get_state(){
        return state;
    }
    void declare_result();
    int assign();
    vector<vector<int>> get_grid();
};