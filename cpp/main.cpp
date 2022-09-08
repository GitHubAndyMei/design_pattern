#include <iostream>
#include <vector>

#include "DecoratorPattern.h"
#include "FacadePattern.h"
#include "AdapterPattern.h"
#include "BridgePattern.h"
#include "FlyweightPattern.h"
#include "FilterPattern.h"
#include "ProxyPattern.h"
#include "BuilderPattern.h"
#include "ChainResponsibilityPattern.h"
#include "CommandPattern.h"
#include "InterpreterPattern.h"
// #include "IteratorPattern.h"
#include "StrategyPattern.h"
#include "TemplatePattern.h"

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::vector<std::vector<int>> threeSumVec;

        size_t len = nums.size();
        for(size_t i = 0; i < len; i++)
        {
            for(size_t j = 0; j < len; j++)
            {
                for(size_t k = 0; k < len; k++)
                {
                    if(i != j && i != k && j != k && 0 == (nums[i] + nums[j] + nums[k]))
                    {
						int maxNum = 0;
						int minNum = 0;
						int midNum = 0;
						maxNum = std::max(nums[i], nums[j]);
						maxNum = std::max(nums[k], maxNum);
						minNum = std::min(nums[i], nums[j]);
						minNum = std::min(nums[k], minNum);
						midNum = -(maxNum + minNum);

						bool isEqual{false};
						for(const auto& numVec: threeSumVec)
						{
							if( numVec[0] == maxNum &&
								numVec[1] == midNum &&
								numVec[2] == minNum )
							{
								isEqual = true;
								std::cout<<"is equal!"<<std::endl;
								break;
							}
						}

						if(!isEqual)
						{
							std::vector<int> threeNumVec;
							threeNumVec.push_back(maxNum);
							threeNumVec.push_back(midNum);
							threeNumVec.push_back(minNum);

							threeSumVec.push_back(threeNumVec);
						}
                    }
                }
            }
        }

        return threeSumVec;
    }
};

int main()
{
	TestDecoratorPattern();
	TestFacadePattern();
	TestAdapterPattern();
	TestFlyWeightPattern();
	TestBridgePattern();
	TestFileterPattern();
	TestProxyPattern();
	TestBuilderPattern();
	TestChainResponsibilityPattern();
	TestCommandPattern();
	TestInterpreterPattern();
	//TestIteratorPattern();
	TestStrategyPattern();
	TestTemlatePattern();

	/*
	std::vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	Solution oSolution = Solution();
	oSolution.threeSum(nums);
	*/
	return 0;
}
