class Robot {
public:
    int n, m, x = 0, y = 0, dir = 0;
    vector<vector<int>> all_pos;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    string DIR[4] = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        n = height;
        m = width;
        all_pos.push_back({0, 0});
    }

    void step(int num) {
         int cycle = 2 * (m + n - 2);
        if (cycle == 0) return;

        num %= cycle;
        if (num == 0) num = cycle;
        while (num--) {
            if (dir == 0) { // East
                if (x + 1 < m)
                    x++;
                else {
                    dir = (dir + 1) % 4;
                    if (y + 1 < n)
                        y++;
                    else
                        dir = (dir + 1) % 4;
                }
            } 
            else if (dir == 1) { // North
                if (y + 1 < n)
                    y++;
                else {
                    dir = (dir + 1) % 4;
                    if (x - 1 >= 0)
                        x--;
                    else
                        dir = (dir + 1) % 4;
                }
            } 
            else if (dir == 2) { // West
                if (x - 1 >= 0)
                    x--;
                else {
                    dir = (dir + 1) % 4;
                    if (y - 1 >= 0)
                        y--;
                    else
                        dir = (dir + 1) % 4;
                }
            } 
            else { // South
                if (y - 1 >= 0)
                    y--;
                else {
                    dir = (dir + 1) % 4;
                    if (x + 1 < m)
                        x++;
                    else {
                        dir = (dir + 1) % 4;
                        if (y + 1 < n)
                            y++;
                        else
                            dir = (dir + 1) % 4;
                    }
                }
            }

            all_pos.push_back({x, y});
        }
    }

    vector<int> getPos() {
        return all_pos.back();
    }

    string getDir() {
        return DIR[dir];
    }
};