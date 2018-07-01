//Now using hash table

class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        int i,j;
        vector<int> emp;
        int totallength=0;
        for(i=0;i<words.size();i++) totallength+=words[i].length(); // this is key to deal with numerous "a"s
        if(words.empty()||s==""||s.length()<totallength) return emp;
        vector<int> result;
        int len = words[0].length();
        map<string,int> map1;
        for(i=0;i<words.size();i++){
            if(map1.find(words[i])==map1.end()) map1[words[i]]=1;
            else map1[words[i]] +=1;
        }
        map<string,int>::iterator iter = map1.begin();
        //while(iter!=map1.end()) {cout<<"we have "<<iter->first<<" with "<<iter->second<<endl;iter++;}
        for(i=0;i<s.length()-totallength+1;i++){
            int p=i;
            string matchword=s.substr(p,len);
            map<string,int> map2=map1;
            bool flagfailed=false;
            while(!map2.empty()){
                matchword=s.substr(p,len);
                if(map2.find(matchword)==map2.end()) {flagfailed=true;break;}
                map2[matchword]-=1;
                if(map2[matchword]==0) map2.erase(matchword);
                p=p+len;
            }
            if(flagfailed==false) result.push_back(i);
        }
        return result;
    }
};


/*
class Solution {//oh, i havn't notice that the words are of the same length...hmmm
public:
    bool search(vector<bool*> &match,bool matched[], vector<string>& words, int startloc,int StrLen){
        int i,j;
        bool allmatched=true;
        for(i=0;i<words.size();i++) if(matched[i]==false) allmatched=false;
        if(allmatched==true) {cout<<"cheers, find it"<<endl;return true;}
        if(startloc>=StrLen) return false;
        bool flag=false;
        for(i=0;i<words.size();i++){
            if(matched[i]==false&&match[i][startloc]==true){
                //cout<<"mataching at word "<<i<<" at loc"<<startloc<<endl;
                bool *matched1= new bool[words.size()];
                for(j=0;j<words.size();j++) matched1[j]=matched[j];
                matched1[i]=true;
                if(search(match,matched1,words,startloc+words[i].length(),StrLen)==true) {flag=true;break;}
            }
        }
        return flag;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int i,j;
        int totallength=0;
        for(i=0;i<words.size();i++) totallength+=words[i].length(); // this is key to deal with numerous "a"s
        if(words.empty()||s==""||s.length()<totallength) {
            vector<int>  emp; return emp;
        }
        int *len = new int[words.size()];
        for(i=0;i<words.size();i++){
            len[i]=words[i].length();
        }
        vector<bool*> match;
        for(i=0;i<words.size();i++){
            bool *p = new bool[s.length()];//p is the match place of the word in the string
            for(j=0;j<s.length();j++) p[j]=false;
            string theword=words[i];
            string s1=s;
            int deleted=0;
            while(s1.find(theword)!=string::npos){
                p[s1.find(theword)+deleted]=true;
                deleted+=s1.find(theword)+1;
                s1=s1.substr(s1.find(theword)+1,string::npos);
                //cout<<"s1 is "<<s1<<endl;
            }
            //cout<<"we have a match list, which is";
            //for(j=0;j<s.length();j++) cout<<p[j]<<" ";
            //cout<<endl;
            match.push_back(p);
        }
        vector<int> result;
        bool *matched= new bool[words.size()];
        //int totallength=0;
        //for(i=0;i<words.size();i++) totallength+=words[i].length(); // this is key to deal with numerous "a"s //still not good enough...hmmm, the "a"s is too much, stupid test case i think
        for(i=0;i<s.length()-totallength+1;i++){
            for(j=0;j<words.size();j++){
                matched[j]=false;
            }
            //cout<<"let's check"<<endl;
            //cin>>j;
            if(search(match,matched,words,i,s.length())==true) result.push_back(i);
        }
        return result;
    }
};
*/
