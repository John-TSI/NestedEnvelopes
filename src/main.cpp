// https://leetcode.com/problems/russian-doll-envelopes/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	std::vector<std::vector<int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
	std::cout << Solution().maxEnvelopes(envelopes);  // 3

	std::vector<std::vector<int>> envelopes2{{1,1},{1,1},{1,1}};
	std::cout << Solution().maxEnvelopes(envelopes2);  // 1

	std::vector<std::vector<int>> envelopes3{{50,53},{72,45},{52,68},{77,81},{48,89}};
	std::cout << Solution().maxEnvelopes(envelopes3);  // 3

	return 0;
}

