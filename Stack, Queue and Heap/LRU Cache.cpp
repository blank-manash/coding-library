// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{
public:
    unordered_map<int,int> m;
    unordered_map<int,list<int> :: iterator> mit;
    list<int> q;
    int size;
public:
    LRUCache(int cap)
    {
        size = cap;
        // constructor for cache
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(m.find(key) == m.end() or m[key] == -1) return -1;
        auto it = mit[key];
        q.erase(it);
        int x = *it;
        q.push_back(x);
        mit[key] = prev(q.end());
        return m[key];
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if( m.find(key) != m.end()) {

            m.erase(key);
            auto it = mit[key];
            mit.erase(key);
            q.erase(it);
        }
        if(q.size() < size) {
            
            q.push_back(key);
            m[key] = value;
            mit[key] = prev(q.end());
            return;
        }
        else {
            int x = q.front();
            q.pop_front();
            m.erase(x);
            mit.erase(x);
            q.push_back(key);
            m[key] = value;
            mit[key] = prev(q.end());
            return;
        }
    }
};

// { Driver Code Starts.

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends