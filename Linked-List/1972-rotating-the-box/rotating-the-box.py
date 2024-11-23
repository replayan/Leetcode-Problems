class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        # Get the dimensions of the box
        m, n = len(box), len(box[0])
        
        # Step 1: Simulate the effect of gravity within each row
        for row in box:
            # I start at the end of the row to process it from right to left
            empty = n - 1  # This keeps track of the nearest empty spot
            for col in range(n - 1, -1, -1):
                if row[col] == '#':  # I found a stone
                    # Swap the stone with the nearest empty spot
                    row[col], row[empty] = row[empty], row[col]
                    empty -= 1  # Move the empty pointer left
                elif row[col] == '*':  # I found an obstacle
                    # Update the nearest empty spot to just before this obstacle
                    empty = col - 1
        
        # Step 2: Rotate the box 90 degrees clockwise
        # To do this, I first transpose the matrix and then reverse the rows
        rotated_box = [[box[m - 1 - i][j] for i in range(m)] for j in range(n)]
        
        # Return the final rotated box
        return rotated_box
