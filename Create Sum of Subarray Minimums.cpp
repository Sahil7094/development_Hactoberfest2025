class Solution {
public:
    vector<int> getnsl(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]= st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> getnsr(vector<int>& arr, int n){
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=n;
            }
            else{
                res[i]= st.top();
            }
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int m = 1e9+7;
        vector<int> nsl = getnsl(arr,n);
        vector<int> nsr = getnsr(arr,n);
        long long sum = 0;
        for(int i=0; i<n; i++){
            long long left_side = i-nsl[i];
            long long right_side = nsr[i]-i;
            long long total_way = left_side*right_side;
            long long total_sum = arr[i]*total_way;
            sum = (sum + total_sum)%m;

        }
        return sum;
    }
};
