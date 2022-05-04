#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> compute_lps(string pattern)
{
    vector<int>lps(pattern.size(),0);
    int index=0;
    for(auto i=0;i<pattern.size();)
    {
        if(pattern[i]==pattern[index])
        {
            index++;
            lps[i]=lps[index]+1;
            i++;
        }
        else{
            if(index!=0)
            {
                index=lps[index-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
bool KMP(string pattern,string text)
{
    vector<int>lps=compute_lps(pattern);
    auto i=0,j=0;
    while(i<text.size()&&j<pattern.size())
    {
        if(pattern[j]==text[i])
        {
            i++;j++;
        }
        else{
            if(j!=0)
            {
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==pattern.size())
    return true;
    return false;
}
int main()
{
    string pattern,text;
    cout<<"Enter the pattern and text:\n";
    cin>>pattern;
    cin>>text;
    bool result=KMP(pattern,text);
    if(result)
    cout<<"The pattern is found in the text!"<<endl;
    else
    cout<<"Pattern is not found!"<<endl;
    return 0;
}