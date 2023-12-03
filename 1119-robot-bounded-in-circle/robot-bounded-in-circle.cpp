class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<pair<int, int>, char> start = {{0, 0}, 'N'};
        pair<pair<int, int>, char> curr = start;

        for (auto it : instructions) {
            if (it == 'G') {
                if (curr.second == 'N')
                    curr.first.first += 1;
                else if (curr.second == 'S')
                    curr.first.first += -1;
                else if (curr.second == 'E')
                    curr.first.second += 1;
                else
                    curr.first.second += -1;
            } else if (it == 'L') {
                if (curr.second == 'N')
                    curr.second = 'W';
                else if (curr.second == 'W')
                    curr.second = 'S';
                else if (curr.second == 'S')
                    curr.second = 'E';
                else
                    curr.second = 'N';
            } else {
                if (curr.second == 'N')
                    curr.second = 'E';
                else if (curr.second == 'E')
                    curr.second = 'S';
                else if (curr.second == 'S')
                    curr.second = 'W';
                else
                    curr.second = 'N';
            }
        }
        return (start.first == curr.first) || (start.second != curr.second);
    }
};
