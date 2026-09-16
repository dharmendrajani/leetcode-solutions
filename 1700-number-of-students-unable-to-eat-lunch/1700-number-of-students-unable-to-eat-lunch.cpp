class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for(int x : students)
            q.push(x);

        int i = 0;
        int failed = 0;

        while(!q.empty() && failed < q.size()) {

            if(q.front() == sandwiches[i]) {
                q.pop();
                i++;
                failed = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                failed++;
            }
        }

        return q.size();
    }
};