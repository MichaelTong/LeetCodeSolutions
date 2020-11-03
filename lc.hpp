#ifndef LC_HPP
#define LC_HPP

/**
 * Common (all the) containers
 */
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * Others
 */
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
#include <random>
#include <cstring>

#include <ostream>
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * The ListNode structure that is used in LeetCode
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * The TreeNode structure that is used in LeetCode
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * The N-ary Tree Node structure that is used in LeetCode
 */
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Master {
  public:
    int guess(string word);
};

using namespace std;

#endif