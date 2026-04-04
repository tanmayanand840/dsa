/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
       unordered_map<int,Employee*>mpp;
       for(int i=0;i<employees.size();i++){
          mpp[employees[i]->id]=employees[i];
       } 
       queue<Employee*>q;
       q.push(mpp[id]);
       int total=0;
       total+=mpp[id]->importance;
       while(!q.empty()){
         auto it=q.front();
         q.pop();
         for(auto itr:it->subordinates){
                total+=mpp[itr]->importance;
                q.push(mpp[itr]);
         }
       }
       return total;
    }
};