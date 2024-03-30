class Solution {
public:
//using base for modulo for preventing the overflow
int base=1e6+7;

//rabin karp algo takes 2 strings as input for matching

int Rabin_karp(string source,string target){
    //if both empty, return -1 as they can't be matched
    if(source==""|| target=="")return -1;

    //take the size of target and power to generate hash function
    int m=target.size();
    int power=1;

    //we make hash function with power of 31 -> max val of power 
    for(int i=0;i<m;i++){
        power=(power*31)%base;
    }

    // initializing target hash value as 0 - this is calculated using the hash function which is defined below
        // this is the hash value for target which we will search in source

        int targetCode=0;

        for(int i=0;i<m;i++){
            // hash functino to find the hash value

            targetCode=(targetCode*31+target[i])%base;
        }

        // this will store the calculated hash Value when traversal will be done in source code
        int hashCode = 0;

        //now traversing through the source to find the matching targetcode values
        for(int i=0;i<source.size();i++){
            //using hash func to find the hash code for string of atleast size of target string
            hashCode=(hashCode*31+source[i])%base;

            if(i<m-1)continue;

            // now we use rolling window, when we exceed the size of target string, even though we add the next character to hashCode
            // the first element from left needs to be removed, which will have power times more value as per hash function

            if(i>=m){
                hashCode=(hashCode-source[i-m]*power)%base;
            }

             // in case value of hashCode becomes neg, we add Base to it, to return to value before module
            if(hashCode < 0) {
                hashCode += base;
            }

            // if in case hashCode and targetCode is same, we compare the strings
            if(hashCode == targetCode) {
                // if source contains a substr of size m which equals target, we return a value not equal to -1
                if(source.substr(i-m+1, m) == target) return i - m + 1;
            }
            
        }
        //otherwise return -1
        return -1;
}
    int repeatedStringMatch(string a, string b) {
        //if same string return 1
        if(a==b)return 1;

         // otherwise, lets have another string source that is formed used string a
        // maintain a count of how many times string a is used

        int count=1;
        string source=a;

        //while size of source is less than b,b cant be a substring of a

        while(source.size()<b.size()){
            count++;
            source+=a;
        }

        //if in case source becomes equal to string b,we return the count
        if(source==b)return count;

        //otherwise we do the string matching
        if(Rabin_karp(source,b)!=-1)return count;
        if(Rabin_karp(source+a,b)!=-1)return count+1;

        //return -1 if we can t form b using any number of a
        return -1;
    }
};