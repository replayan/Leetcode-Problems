📜 **Linked List Basics** 📜

1. **Linked List**: A linear data structure composed of nodes. Each node stores data and a reference (pointer) to the next node.

2. **Types of Linked Lists**:
   - Single Linked List: Nodes have one reference to the next node.
   - Doubly Linked List: Nodes have references to both next and previous nodes.
   - Circular Linked List: Last node points back to the first (single or double).

3. **Common Operations**:
   - Insertion: Adding a new node.
   - Deletion: Removing a node.
   - Traversal: Iterating through the list.

👉 **Single Linked List in Java** 👈

**Insertion**:
- **At the Beginning**:
   ```java
   public void insertAtBeginning(int data) {
       Node newNode = new Node(data);
       newNode.next = head;
       head = newNode;
   }
   ```
- **At the End**:
   ```java
   public void insertAtEnd(int data) {
       Node newNode = new Node(data);
       if (head == null) {
           head = newNode;
           return;
       }
       Node current = head;
       while (current.next != null) {
           current = current.next;
       }
       current.next = newNode;
   }
   ```
- **In the Middle**:
   ```java
   public void insertInMiddle(int data, int position) {
       Node newNode = new Node(data);
       Node current = head;
       int count = 1;
       while (count < position - 1) {
           current = current.next;
           count++;
       }
       newNode.next = current.next;
       current.next = newNode;
   }
   ```

**Deletion**:
- **At the Beginning**:
   ```java
   public void deleteAtBeginning() {
       if (head != null) {
           head = head.next;
       }
   }
   ```
- **At the End**:
   ```java
   public void deleteAtEnd() {
       if (head == null || head.next == null) {
           head = null;
           return;
       }
       Node current = head;
       while (current.next.next != null) {
           current = current.next;
       }
       current.next = null;
   }
   ```
- **In the Middle**:
   ```java
   public void deleteInMiddle(int position) {
       if (head == null)
           return;
       if (position == 1) {
           head = head.next;
           return;
       }
       Node current = head;
       int count = 1;
       while (count < position - 1) {
           current = current.next;
           count++;
       }
       if (current == null || current.next == null)
           return;
       current.next = current.next.next;
   }
   ```

👉 **Doubly Linked List in Java** 👈

**Insertion**:
- **At the Beginning**:
   ```java
   public void insertAtBeginning(int data) {
       Node newNode = new Node(data);
       newNode.next = head;
       if (head != null) {
           head.prev = newNode;
       }
       head = newNode;
   }
   ```
- **At the End**:
   ```java
   public void insertAtEnd(int data) {
       Node newNode = new Node(data);
       if (head == null) {
           head = newNode;
           return;
       }
       Node current = head;
       while (current.next != null) {
           current = current.next;
       }
       current.next = newNode;
       newNode.prev = current;
   }
   ```
- **In the Middle**:
   ```java
   public void insertInMiddle(int data, int position) {
       Node newNode = new Node(data);
       Node current = head;
       int count = 1;
       while (count < position - 1) {
           current = current.next;
           count++;
       }
       newNode.next = current.next;
       if (current.next != null) {
           current.next.prev = newNode;
       }
       current.next = newNode;
       newNode.prev = current;
   }
   ```

**Deletion**:
- **At the Beginning**:
   ```java
   public void deleteAtBeginning() {
       if (head != null) {
           head = head.next;
           if (head != null) {
               head.prev = null;
           }
       }
   }
   ```
- **At the End**:
   ```java
   public void deleteAtEnd() {
       if (head == null || head.next == null) {
           head = null;
           return;
       }
       Node current = head;
       while (current.next != null) {
           current = current.next;
       }
       current.prev.next = null;
   }
   ```
- **In the Middle**:
   ```java
   public void deleteInMiddle(int position) {
       if (head == null)
           return;
       if (position == 1) {
           head = head.next;
           if (head != null) {
               head.prev = null;
           }
           return;
       }
       Node current = head;
       int count = 1;
       while (count < position - 1) {
           current = current.next;
           count++;
       }
       if (current == null || current.next == null)
           return;
       current.next = current.next.next;
       if (current.next != null) {
           current.next.prev = current;
       }
   }
   ```

👉 **Circular Linked List in Java** 👈

**Insertion**:
- **At the Beginning**:
   ```java
   public void insertAtBeginning(int data) {
       Node newNode = new Node(data);
       if (head == null) {
           head = newNode;
           head.next = head; // Make it point to itself
       } else {
           newNode.next = head;
           Node current = head;
           while (current.next != head) {
               current = current.next;
           }
           current.next = newNode;
           head = newNode;
       }
   }
   ```
- **At the End**:
   ```java
   public void insertAtEnd(int data) {
       Node newNode = new Node(data);
       if (head == null) {
           head = newNode;
           head.next = head; // Make it point to itself
       } else {
           Node current = head;
           while (current.next != head) {
               current = current.next;
           }
           current.next = newNode;
           newNode.next = head;
       }
   }
   ```
- **In the Middle**:
   ```java
   public void insertInMiddle(int data, int position) {
       Node newNode = new Node(data);
       if (position == 1) {
           insertAtBeginning(data);
           return;
       }
       Node current = head;
       int count = 1;
       while (count < position - 1 && current.next != head) {
           current = current.next;
           count++;
       }
       newNode.next = current.next;
       current.next = newNode;
   }
   ```

**Deletion**:
- **At the Beginning**

:
   ```java
   public void deleteAtBeginning() {
       if (head == null || head.next == head) {
           head = null;
           return;
       }
       Node current = head;
       while (current.next != head) {
           current = current.next;
       }
       head = head.next;
       current.next = head;
   }
   ```
- **At the End**:
   ```java
   public void deleteAtEnd() {
       if (head == null || head.next == head) {
           head = null;
           return;
       }
       Node current = head;
       Node previous = null;
       while (current.next != head) {
           previous = current;
           current = current.next;
       }
       previous.next = head;
   }
   ```
- **In the Middle**:
   ```java
   public void deleteInMiddle(int position) {
       if (head == null || head.next == head)
           return;
       if (position == 1) {
           deleteAtBeginning();
           return;
       }
       Node current = head;
       int count = 1;
       while (count < position - 1 && current.next != head) {
           current = current.next;
           count++;
       }
       current.next = current.next.next;
   }
   ```
