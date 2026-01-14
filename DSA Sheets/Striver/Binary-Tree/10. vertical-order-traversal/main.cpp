#include <bits/stdc++.h>
using namespace std;

// In map the first 'int' stores vertical and the second 'int' stores level of the Tree and the multiset inside the map stores the nodes at a given vertical and level!

//As we go left the vertical will decrease by 1 and level will increase by 1!
//As we go left the vertical will increase by 1 and level will increase by 1!

//Everything else is same as Level-order traversal of tree

vector<vector<int>> verticalTraversal(TreeNode* root) {
	map<int,map<int,multiset<int>>> mp;

	queue<pair<TreeNode*,pair<int,int>>>q;
	q.push({root,{0,0}});

	while(!q.empty()){
		auto t=q.front();
		q.pop();

		TreeNode* node=t.first;
		int verti=t.second.first;
		int level=t.second.second;
		mp[verti][level].insert(node->val);

		if(node->left) q.push({node->left,{verti-1,level+1}});
		if(node->right) q.push({node->right,{verti+1,level+1}});
	}
	
	vector<vector<int>> ans;
	for(auto i:mp){
		vector<int>ver;
		for(auto j:i.second){
			for(auto k:j.second) ver.push_back(k);
		}  
		ans.push_back(ver);
	}

	return ans;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif


	return 0;
}