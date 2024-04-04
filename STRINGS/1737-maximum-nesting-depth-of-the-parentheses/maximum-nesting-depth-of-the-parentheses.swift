class Solution {
    func maxDepth(_ s: String) -> Int {
        var st = [Int]()
        var maxCounter = 0
        
        for char in s {
            if char == "(" {
                st.append(1)
            } else if char == ")" {
                st.popLast()
            }
            maxCounter = max(maxCounter, st.count)
        }
        
        return maxCounter
    }
}
