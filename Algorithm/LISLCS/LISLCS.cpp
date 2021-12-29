
// These code applicable to  Sequences of dinstinct elements only .

int LIS(vector<ll>& Arr){
    if(Arr.size()==0) return 0;

    vector<int> tail;
    tail.push_back(Arr[0]);
 
    for (int i = 1; i < Arr.size(); i++) {
 
        if (Arr[i] > tail.back())
            tail.push_back(Arr[i]);
 
        else if (Arr[i] < tail[0])
            tail[0] = Arr[i];
 
        else {
            auto it = lower_bound(tail.begin(),
                                  tail.end(),
                                  Arr[i]);
            *it = Arr[i];
        }
    }
    return (int)tail.size();
}

// O( (n+m) log n) 
int LCS(vector<ll>& firstArr, vector<ll>& secondArr)
{
    // n = size of firstArr
    // m = size of secondArr

    // Maps elements of firstArr[] to their respective index
    // O(n log n)
    unordered_map<ll, ll> mp;
    rep (i,0,firstArr.size())
        mp[firstArr[i]] = i;
    
    // Stores the indices of firstArr that is common elements between both array
    // O(m log n)
    vector<int> seq_of_pos;
    rep (i,0,secondArr.size()){
        if (mp.find(secondArr[i]) != mp.end()) 
            seq_of_pos.push_back(mp[secondArr[i]]);
    }

    // This is true because with the condition that in secondArr it is confirm to between increasing, we can find the longest increasing of first array and that is the common one.
    // O(common log k)
    return LIS(seq_of_pos)
}