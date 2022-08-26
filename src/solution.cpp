#include<algorithm>
#include"../inc/solution.hpp"


// idea: sort envelopes by decreasing width, then find the longest decreasing subsequence (LDS) of their heights
int Solution::maxEnvelopes(std::vector<std::vector<int>>& envelopes)
{
    std::sort( envelopes.begin(), envelopes.end(), 
        [](const auto& p1, const auto& p2){ return p1[0] >= p2[0]; }  // eval policy sorts widths in dec order
    );

    int maxWidth{envelopes[0][0]};  // width of longest ('outermost') envelope
    std::vector<int> heights{envelopes[0][1]};  // store subsequence of decreasing heights
    for(int i{1}; i<envelopes.size(); ++i)
    {
        if(envelopes[i][0] == maxWidth || envelopes[i][1] == heights.back()){ continue; }  // nested envs cannot have any equal dimensions
        if(envelopes[i][1] > heights.back())  // found a taller envelope than current shortest
        {
            heights.pop_back();
            heights.push_back(envelopes[i][1]);
        }
        else{ heights.push_back(envelopes[i][1]); }  // found a shorter envelope, append its height to subsequence
    }
    // 'heights' contains the LDS of heights, its length is largest possible number of nested envelopes
    return heights.size();
}