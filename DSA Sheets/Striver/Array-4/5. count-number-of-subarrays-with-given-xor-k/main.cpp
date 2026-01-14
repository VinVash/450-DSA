int subarraysXor(vector<int> &arr, int x) {
    int n = arr.size();
    
    unordered_map<int, int> freq;
    
    int count = 0, xorr = 0;
    
    for(auto it: arr) {
        xorr = xorr ^ it;
        
        if(xorr == x)
            count++;
        
        if(freq.find(xorr ^ x) != freq.end()) // found y
            count += freq[xorr ^ x];
        
        freq[xorr] += 1;
    }
    
    return count;
}