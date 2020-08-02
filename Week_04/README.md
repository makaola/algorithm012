DFS和BFS：
深度优先和广度优先。
树一般用深度优先遍历，代码实现相对比较简单。而且树的结构是适合用递归实现深度优先遍历的。
深度优先有递归和非递归的方式，非递归就需要手动维护一个栈。
//C/C++
//递归写法：
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}

//C/C++
//非递归写法：
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
广度优先代码实现相对比较麻烦一些，但使用场景也比较多，比如图中从起点到终点最短路径的长度。
// C/C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}

很多问题当画出状态树之后就可以按照深度优先或者广度优先的方法。

贪心算法：
贪心算法是局部最优，不能回退。动态规划是可以回退的。
贪心算法是比较高效的。

二分查找：
1、单调 2、存在上下界 3、能够索引访问
C/C++

int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
利用二分法向中间进行夹逼

int binarySearch(const vector<int>& nums) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (left == right) return mid; //这里的判断条件if(nums[left]<=nums[right]) return left;
		if (nums[mid] > nums[0]) left = mid + 1;
		else right = mid;  //这里不是mid-1
	}
	
	return -1;
}
