class Solution {
public:
    int minimumLength(string s) {
        deque<char>pq;
     if(s.size()==1)return 1;
    for(auto&it:s)pq.push_back(it);

    //gquiz.push_back(10);

    char x = pq.front();

    char y = pq.back();

    while(!pq.empty()&&x==y) {

    while(!pq.empty()&&pq.front()==x )pq.pop_front();

    while(!pq.empty()&&pq.back()==y)pq .pop_back();

    if(pq.size()>1){

    x = pq.front(); y = pq.back();

    }else break;

    }

    return pq.size();
    }
};