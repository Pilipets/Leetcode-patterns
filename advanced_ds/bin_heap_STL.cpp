// Binary Heap or Priority Queue
//
// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
//

// STL heap
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};


// STL custom comparator
//

// 1
//
auto compare = [](Node a, Node b) { return a.foo < b.foo; }
std::priority_queue<Node, std::vector<Node>, decltype(compare)> openSet(compare);

// 2
//
class Node;
bool Compare(Node a, Node b);

std::priority_queue<Node, std::vector<Node>, decltype(&Compare)> openSet(Compare);

// 3
//
std::priority_queue<Foo, std::vector<Foo>, std::function<bool(Foo, Foo)>> pq(Compare);


// STL make_heap, pop_heap, push_heap, sort_heap - push/pop from the end
//
int main()
{
    print("Max heap");
 
    std::vector<int> v{3, 2, 4, 1, 5, 9};
    print("initially, v", v);
 
    std::make_heap(v.begin(), v.end());
    print("after make_heap, v", v);
 
    std::pop_heap(v.begin(), v.end());
    print("after pop_heap, v", v);
 
    auto top = v.back();
    v.pop_back();
    print("former top element", {top});
    print("after removing the former top element, v", v);

    v.push_back(6);
    println("after push_back: ", v);
 
    std::push_heap(v.begin(), v.end());
    println("after push_heap: ", v);
}