void insert_bottom(int x, stack<int> &s) {
    if(s.empty()) s.push(x);
    else {
        int xx = s.top(); s.pop();
        insert_bottom(x,s);
        s.push(xx);
    }
}
//Insert bottom method

void StackQueue :: push(int x)
 {
     if(s1.empty()) s1.push(x);
     else insert_bottom(x,s1);
        
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code  
        if(s1.empty()) return -1;
        int x = s1.top(); s1.pop();
        return x;
}