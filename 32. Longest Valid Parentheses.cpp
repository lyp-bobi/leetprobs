class Solution {
public:
    int longestValidParentheses(string s) {
        int* p =new int[s.length()];
        int i,j;
        for(i=0;i<s.length();i++){
            if(s[i]=='(') p[i]=(i==0)?1:p[i-1]+1;
            if(s[i]==')') p[i]=(i==0)?-1:p[i-1]-1;
        }
        int count=0,maxcount=0;
        //i=-1;
        //cout<<i<<s.length()<<" "<<(i<(int)s.length())<<endl;
        for(i=-1;i<(int)s.length();i++){ //i=-1 to check with place 0
            count=0;
            for(j=1;i+j<s.length();j++){//if we find two pointer a and b with same p value, then a+1 to be is a valid parenthesis
                if(i==-1){
                    if(p[i+j]>=0) count++;
                    if(p[i+j]==0){
                        if(count>maxcount) maxcount=count;
                    }
                    if(p[i+j]<0) break;
                }
                else{
                    if(p[i+j]>=p[i]) count++;
                    if(p[i+j]==p[i]){
                        if(count>maxcount) maxcount=count;
                    }
                    if(p[i+j]<p[i]) break;
                }

            }
            //cout<<endl;
        }
        return maxcount;
    }
};
