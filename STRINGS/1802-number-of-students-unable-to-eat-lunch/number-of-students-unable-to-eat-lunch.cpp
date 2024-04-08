class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwichStack;
        queue<int> studentQueue;

        for (int i = sandwiches.size() - 1; i >= 0; --i)
            sandwichStack.push(sandwiches[i]);
        for (int student : students)
            studentQueue.push(student);
        
        int unableToEat = 0;
        int studentsLeft = students.size();
        
        while (!studentQueue.empty()) {
            if (studentQueue.front() == sandwichStack.top()) {
                // If the student's preference matches the top sandwich, they can eat
                studentQueue.pop();
                sandwichStack.pop();
                studentsLeft--;
                unableToEat = 0; // Reset unableToEat counter
            } else {
                // If the student's preference doesn't match, move the student to the end of the queue
                int frontStudent = studentQueue.front();
                studentQueue.pop();
                studentQueue.push(frontStudent);
                unableToEat++;
            }
            
            // If all students have been through the queue without eating, break the loop
            if (unableToEat == studentsLeft)
                break;
        }
        
        return studentsLeft;
    }
};
