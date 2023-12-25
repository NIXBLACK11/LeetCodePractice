class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> stack;

        for (int a : asteroids) {
            while (!stack.empty() && a < 0 && stack.top() > 0) {
                int diff = a + stack.top();
                if (diff > 0) {
                    a = 0;
                } else if (diff < 0) {
                    stack.pop();
                } else {
                    a = 0;
                    stack.pop();
                }
            }

            if (a != 0) {
                stack.push(a);
            }
        }

        std::vector<int> result(stack.size());
        for (int i = stack.size() - 1; i >= 0; i--) {
            result[i] = stack.top();
            stack.pop();
        }

        return result;
    }
};