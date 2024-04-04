/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function(s) {
    let st = [];
    let maxCounter = 0;
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            st.push(i);
        } else if (s[i] === ')') {
            st.pop();
        }
        maxCounter = Math.max(maxCounter, st.length);
    }
    
    return maxCounter;
};
