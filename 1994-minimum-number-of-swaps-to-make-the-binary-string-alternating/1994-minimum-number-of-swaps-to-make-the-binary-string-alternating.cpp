class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int ct11=0;
        int ct00=0;
        if(s=="1" || s=="0"){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ct11++;
            }
            else{
                ct00++;
            }
        }
        if(n%2==0 && ct11!=ct00){
            return -1;
        }
        else if(n%2!=0 && abs(ct11-ct00)!=1){
            return -1;
        }
        else{
            if(n%2==0){
                int k=0;
                int ct1=1;
                for(int i=0;i<n;i++){
                    if((s[i]-'0')==ct1){
                        ct1=abs(ct1-1);
                        continue;
                    }
                    else{
                        k++;
                        ct1=abs(ct1-1);
                    }
                }
                int kk=0;
                int ct=0;
                for(int i=0;i<n;i++){
                    if((s[i]-'0')==ct){
                        ct=abs(ct-1);
                        continue;
                    }
                    else{
                        kk++;
                        ct=abs(ct-1);
                    }
                }
                return min(k/2,kk/2);
            }
            else{
                if(ct11>ct00){
                    int k=0;
                    int ct1=1;
                    for(int i=0;i<n;i++){
                        if((s[i]-'0')==ct1){
                            ct1=abs(ct1-1);
                            continue;
                        }
                        else{
                            k++;
                            ct1=abs(ct1-1);
                        }
                    }
                    return k/2;
                }
                else{
                    int kk=0;
                    int ct=0;
                    for(int i=0;i<n;i++){
                        if((s[i]-'0')==ct){
                            ct=abs(ct-1);
                            continue;
                        }
                        else{
                            kk++;
                            ct=abs(ct-1);
                        }
                    }
                    return kk/2;
                }
            }
        }
        return 0;
    }
};