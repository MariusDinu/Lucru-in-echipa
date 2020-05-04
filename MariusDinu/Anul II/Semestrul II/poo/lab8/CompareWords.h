#pragma once

class CompareWords
{
public:
	bool operator()(const pair<string, int>& strPair1, const pair<string, int>& strPair2)
	{
		if (strPair1.second < strPair2.second)
			return true;
		else if (strPair1.second == strPair2.second)
			return(strPair2.first < strPair1.first);
		else
			return false;
	}
};