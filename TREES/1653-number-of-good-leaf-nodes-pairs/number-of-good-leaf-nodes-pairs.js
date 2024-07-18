var countPairs = function(root, distance) {
    let goodPairs = 0;
    
    // Depth function to compute depths of leaf nodes and count pairs
    function dfs(node) {
        if (!node) return new Map(); // Return an empty map if node is null
        
        // If node is a leaf, return a map with depth 1 for this leaf
        if (!node.left && !node.right) {
            let depthMap = new Map();
            depthMap.set(node, 1);
            return depthMap;
        }
        
        // Recursively calculate depths and count good pairs for left and right subtrees
        let leftDepths = dfs(node.left);
        let rightDepths = dfs(node.right);
        
        // Merge left and right subtree depth maps
        let mergedMap = new Map();
        
        // Compute good pairs between left and right subtree leaf nodes
        for (let [lNode, lDepth] of leftDepths) {
            for (let [rNode, rDepth] of rightDepths) {
                let pathLength = lDepth + rDepth;
                if (pathLength <= distance) {
                    goodPairs++;
                }
            }
        }
        
        // Update the merged depth map with depths from left and right subtrees
        for (let [lNode, lDepth] of leftDepths) {
            mergedMap.set(lNode, lDepth + 1);
        }
        for (let [rNode, rDepth] of rightDepths) {
            mergedMap.set(rNode, rDepth + 1);
        }
        
        return mergedMap; // Return the merged depth map for the current subtree
    }
    
    // Start DFS from the root node
    dfs(root);
    
    return goodPairs;
};
