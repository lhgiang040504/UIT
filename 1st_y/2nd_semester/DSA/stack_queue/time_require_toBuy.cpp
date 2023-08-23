int timeRequiredToBuy(vector<int>& tickets, int k) {
    int n = tickets.size();
    int require = tickets[k];
    int time = 0;
    
    queue<bool> local;
    queue<int> q;
     
    for (int j = 0; j < n; j++) {
        if(j == k) {    local.push(true);    }
        else {    local.push(false);    }
        q.push(tickets[j]);
    }
        
    while((!q.empty()) && (require > 0)) {
        if(local.front() == true) {    require --;    }

        if(q.front() > 1) {
            q.push(q.front() - 1);
            local.push(local.front());
        }
        local.pop();
        q.pop();
        time ++;  
    }
    return time;
}