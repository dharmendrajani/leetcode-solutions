class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int totTime = 0;

        while(!q.empty()) {
            int person = q.front();
            q.pop();

            tickets[person]--;
            totTime++;

            if(person == k && tickets[person] == 0) {
                return totTime;
            }

            if(tickets[person] > 0) {
                q.push(person);
            }
        }

        return totTime;
    }
};