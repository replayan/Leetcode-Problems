function maxDepth(s: string): number {
    let st: number[] = [];
    let maxCounter: number = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            st.push(i);
        } else if (s[i] === ')') {
            st.pop();
        }
        maxCounter = Math.max(maxCounter, st.length);
    }
    
    return maxCounter;
}
