class MyStack {
private:
    vector<int> data;

public:
    // MyStack() {
        
    // }
    
    void push(int x) {
        data.push_back(x); 
    }
    
    int pop() {
        if (!empty()) {
            int topElement = data.back(); 
            data.pop_back(); 
            return topElement;
        }
        return -1; 
    }
    
    int top() {
        if (!empty()) {
            return data.back(); 
        }
        return -1; 
    }
    
    bool empty() {
        return data.empty(); 
    }
};
