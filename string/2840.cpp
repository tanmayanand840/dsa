class Solution {
public:
    bool checkStrings(string s1, string s2) {
       vector<char>odd1,odd2,even1,even2;
       int n=s1.length();
       for(int i= 0;i<n;i++){
        if(i&1){
            odd1.push_back(s1[i]);
            odd2.push_back(s2[i]);
        }else{
            even1.push_back(s1[i]);
            even2.push_back(s2[i]);
        }
       } 
       sort(odd1.begin(),odd1.end());
       sort(odd2.begin(),odd2.end());
       sort(even1.begin(),even1.end());
       sort(even2.begin(),even2.end());
       if(odd1!=odd2)return false;
       if(even1!=even2)return false;
       return true;
    }
};